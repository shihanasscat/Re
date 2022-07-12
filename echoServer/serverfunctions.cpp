#include <QStringList>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QMap>

#include "serverfunctions.h"

QString loginInfo;

/**
 * @brief деструктор для закрытия базы данных
 */
ServerFunctions::~ServerFunctions() {}

/**
 * @brief конструктор для открытия базы данных
 */
ServerFunctions::ServerFunctions() {
    DBSingleton* instance = DBSingleton::GetInstance();
}

/**
 * @brief 1. Выполняем запрос по поиску имени пользователя в базе данных.
 * 2. Сравниваем полученное имя пользователя и пароль, введённые пользователем, со значениями в базе данных. Если совпадает, статус = "Welcome! ",
 * иначе статус = (by default) "Wrong username or password! "
 * Намеренно не добавлен статус об отсутсвии введенного имени пользователя в базе данных.
 * @param login
 * @param password
 * @return статус попытки входа в аккаунт ("Welcome! "/"Wrong username or password! ")
 */
QString ServerFunctions::AuthenticateUser(QString login, QString password)
{
    QString log_from_db, pass_from_db, status_from_db;

    qDebug() << "authentication";

    QSqlQuery query;
    query.prepare(
        "SELECT * FROM User "
        "WHERE login == :login");
    query.bindValue(":login", Encrypt(login, 1017));
    query.exec();

    QByteArray pas = password.toUtf8();
    QString p = QCryptographicHash::hash(pas, QCryptographicHash::Md5).toHex();
    QString status_teach = "teacher";
    QByteArray st_teach = status_teach.toUtf8();
    QString st = QCryptographicHash::hash(st_teach, QCryptographicHash::Sha224).toHex();
    QString status_st = "student";
    QByteArray st_st = status_st.toUtf8();
    QString ss = QCryptographicHash::hash(st_st, QCryptographicHash::Sha224).toHex();
    QSqlRecord rec = query.record();

    const int loginIndex = rec.indexOf("login");
    const int passwordIndex = rec.indexOf("password");
    const int statusIndex = rec.indexOf("status");

    while(query.next())
    {
        log_from_db = query.value(loginIndex).toString();
        pass_from_db = query.value(passwordIndex).toString();
        status_from_db = query.value(statusIndex).toString();
    }

    qDebug() << log_from_db << "\t" << pass_from_db << "\n";

    QString status = "Wrong username or password! ";
    if (login == Decrypt(log_from_db,1017) && p == pass_from_db)
    {
        if (status_from_db == ss) status = "Welcome! student";
        else if (status_from_db == st) status = "Welcome! teacher";
    }

    return status;
}

/**
 * @brief 1. Проверка наличия логина в базе, если есть - нельзя зарегистрироваться, статус = "This username is already used!".
 * 2. Проверяем добавление в базу данных пользователей. Если успешно, статус = "You have been successfully registered! ",
 * иначе статус = (by default) "You are not registered! ".
 * @param login
 * @param password
 * @param email
 * @return статус регистрации ("This username is already used!"/"You have been successfully registered! "/"You are not registered! ")
 */
QString ServerFunctions::RegisterUser(QString login, QString password, QString email, QString status, QString name, QString surname)
{
    QSqlQuery query;
    QString stat = "You are not registered!";

    QString log_from_db, pass_from_db, email_from_db, status_from_db, name_from_db, surname_from_db;
    query.prepare(
        "SELECT * FROM User "
        "WHERE login == :login");
    query.bindValue(":login", Encrypt(login, 1017));
    query.exec();

    QSqlRecord rec = query.record();
    while(query.next())
    {
        log_from_db = query.value(rec.indexOf("login")).toString();
    }

     if (login == Decrypt(log_from_db, 1017))
     {
         return "This username is already used!";
     }

     QByteArray log = login.toUtf8();
     QString l = QCryptographicHash::hash(log, QCryptographicHash::Md4).toHex();
     if (status == "student")
     {
         query.prepare(
            "INSERT INTO statistic(login) "
            "VALUES (:login)");
         query.bindValue(":login", l);
         query.exec();
     }

     QByteArray pas = password.toUtf8();
     QString p = QCryptographicHash::hash(pas, QCryptographicHash::Md5).toHex();
     QByteArray em = email.toUtf8();
     QString e = QCryptographicHash::hash(em, QCryptographicHash::Md5).toHex();
     QByteArray st = status.toUtf8();
     QString s = QCryptographicHash::hash(st, QCryptographicHash::Sha224).toHex();
     query.prepare(
        "INSERT INTO User(login, password, email, status, name, surname) "
        "VALUES (:login, :password, :email, :status, :name, :surname)");
     query.bindValue(":password",p);
     query.bindValue(":login", Encrypt(login, 1017));
     query.bindValue(":email",e);
     query.bindValue(":status",s);
     query.bindValue(":name", Encrypt(name, 785));
     query.bindValue(":surname", Encrypt(surname, 996));
     query.exec();

     query.prepare(
        "SELECT * FROM User "
        "WHERE login == :login");
     query.bindValue(":login", Encrypt(login, 1017));
     query.exec();

     QSqlRecord record = query.record();
     const int loginIndex = record.indexOf("login");
     const int passwordIndex = record.indexOf("password");
     const int emailIndex = record.indexOf("email");
     const int statusIndex = record.indexOf("status");
     const int nameIndex = record.indexOf("name");
     const int surnameIndex = record.indexOf("surname");

     while (query.next())
     {
         log_from_db = query.value(loginIndex).toString(), pass_from_db = query.value(passwordIndex).toString(),
                 email_from_db = query.value(emailIndex).toString() , status_from_db = query.value(statusIndex).toString(),
                 name_from_db = query.value(nameIndex).toString(), surname_from_db = query.value(surnameIndex).toString();
     }

     qDebug()<<log_from_db <<"\t"<<pass_from_db<<"\t" << email_from_db << status_from_db << "\n";

     if (login == Decrypt(log_from_db, 1017) && p == pass_from_db && e == email_from_db && s == status_from_db && name == Decrypt(name_from_db, 785)
             && surname == Decrypt(surname_from_db, 996)){
          stat = "You have been successfully registered! ";
     }

    return stat;
}

/**
 * @brief myfunctions::updStat
 * @param login
 * @param task_num
 * @param status_of_task
 * @return обновляет статус задания, после его решения/не решения
 */
QString ServerFunctions::UpdateTaskStatus(QString login, QString taskNumber, QString taskStatus)
{
    QSqlQuery query;

    int task = taskNumber.toInt();
    qDebug() << login;

    QByteArray log = login.toUtf8();
    QString l = QCryptographicHash::hash(log, QCryptographicHash::Md4).toHex();

    switch(task)
    {
    case 1:
        query.prepare("UPDATE statistic "
                      "SET task1 = :task1 "
                      "WHERE login == :login");
        query.bindValue(":login", l);
        query.bindValue(":task1", taskStatus);
        query.exec();
        break;
    case 2:
        query.prepare("UPDATE statistic "
                      "SET task2 = :task2 "
                      "WHERE login == :login");
        query.bindValue(":task2", taskStatus);
        query.bindValue(":login", l);
        query.exec();
        break;
    case 3:
        query.prepare("UPDATE statistic "
                      "SET task3 = :task3 "
                      "WHERE login == :login");
        query.bindValue(":login", l);
        query.bindValue(":task3", taskStatus);
        query.exec();
        break;
    case 4:
        query.prepare("UPDATE statistic "
                      "SET task4 = :task4 "
                      "WHERE login == :login");
        query.bindValue(":login", l);
        query.bindValue(":task4", taskStatus);
        query.exec();
        break;
    }

    return "Status has been updated";
}

/**
 * @brief myfunctions::get_stat
 * @param task_num
 * @return возвращает статус задания для отображения статистики
 */
QString ServerFunctions::GetTaskStatus (QString task_num)
{
    QSqlQuery query;
    QByteArray log = loginInfo.toUtf8();
    QString l = QCryptographicHash::hash(log, QCryptographicHash::Md4).toHex();
    QString name_from_db, task1_from_db, task2_from_db, task3_from_db, task4_from_db, stat;

    int task = task_num.toInt();
    query.prepare("SELECT * FROM statistic "
               "WHERE login == :login");
    query.bindValue(":login",l);
    query.exec();

    QSqlRecord rec = query.record();
    const int nameIndex = rec.indexOf("login");
    const int task1Index = rec.indexOf("task1");
    const int task2Index = rec.indexOf("task2");
    const int task3Index = rec.indexOf("task3");
    const int task4Index = rec.indexOf("task4");

    while(query.next())
    {
        name_from_db = query.value(nameIndex).toString(), task1_from_db = query.value(task1Index).toString(),
                task2_from_db = query.value(task2Index).toString(), task3_from_db = query.value(task3Index).toString(),
                task4_from_db = query.value(task4Index).toString();
        qDebug()<<name_from_db <<"\t"<<task1_from_db<<"\t" << task2_from_db << task3_from_db << task4_from_db << "\n";
    }

    switch(task)
    {
        case 1:
        {
                stat = "1&" + task1_from_db;
                break;
        }
        case 2:
        {
                stat = "2&" + task2_from_db;
                break;
        }
        case 3:
        {
                stat = "3&" + task3_from_db;
                break;
        }
        case 4:
        {
                stat = "4&" + task4_from_db;
                break;
        }
    }

    return stat;
}

//Encrypting function and Decrypting
/**
 * @brief myfunctions::Encrypt
 * @param toEncrypt
 * @param key
 * @return зашифрованные данные
 */
QString ServerFunctions::Encrypt(QString toEncrypt, quint32 key)
{
    QByteArray arr(toEncrypt.toUtf8());
    for(int i =0; i<arr.size(); i++)
        arr[i] = arr[i] ^ key;

    return QString::fromLatin1(arr.toBase64());
}

/**
 * @brief myfunctions::Decrypt
 * @param toDecrypt
 * @param key
 * @return расшифрованные данные
 */
QString ServerFunctions::Decrypt(QString toDecrypt, quint32 key)
{
    QByteArray arr = QByteArray::fromBase64(toDecrypt.toLatin1());
    for(int i =0; i<arr.size(); i++)
        arr[i] = arr[i] ^ key;

    return QString::fromUtf8(arr);
}

/**
 * @brief myfunctions::GetUserLogin
 * @param name
 * @param surname
 * @return расшифрованный логин по имени и фамилии
 */
QString ServerFunctions::GetUserLogin(QString name, QString surname)
{
    QString login;
    QSqlQuery query;

    qDebug() << "name=surname" << name << surname;
    query.prepare("SELECT login FROM User "
               "WHERE name == :name AND surname == :surname");
    query.bindValue(":name",Encrypt(name, 785));
    query.bindValue(":surname",Encrypt(surname, 996));
    query.exec();

    QSqlRecord rec = query.record();
    const int loginIndex = rec.indexOf("login");

    while(query.next())
    {
        login = query.value(loginIndex).toString();
    }

    qDebug()<< "login!!!! = " << login  << Decrypt(login,1017)<< "\n";

    return Decrypt(login,1017);
}

/**
 * @brief myfunctions::get_info
 * @param group
 * @return возвращает статистику для учителя: имя, фамилия и статус заданий
 */
QString ServerFunctions::GetUserInfo(QString group)
{
    QString px, p1, p2, p3, p4, p5, p6, p7, p8, p9, status, name, surname, t1, t2, t3, t4;

    status = "";
    QSqlQuery query;
    query.prepare("SELECT * FROM groups "
               "WHERE group_num == :group_num");
    query.bindValue(":group_num",Encrypt(group, 318));
    query.exec();

    QSqlRecord rec = query.record();
    const int p1Index = rec.indexOf("p1");
    const int p2Index = rec.indexOf("p2");
    const int p3Index = rec.indexOf("p3");
    const int p4Index = rec.indexOf("p4");
    const int p5Index = rec.indexOf("p5");
    const int p6Index = rec.indexOf("p6");
    const int p7Index = rec.indexOf("p7");
    const int p8Index = rec.indexOf("p8");
    const int p9Index = rec.indexOf("p9");

    while(query.next())
    {
        p1 = query.value(p1Index).toString(), //-logins
        p2 = query.value(p2Index).toString(),
        p3 = query.value(p3Index).toString(),
        p4 = query.value(p4Index).toString(),
        p5 = query.value(p5Index).toString(),
        p6 = query.value(p6Index).toString(),
        p7 = query.value(p7Index).toString(),
        p8 = query.value(p8Index).toString(),
        p9 = query.value(p9Index).toString();
    }

    QMap<int,QString> ind {{1,Decrypt(p1,318)}, {2,Decrypt(p2,318)}, {3,Decrypt(p3,318)}, {4,Decrypt(p4,318)}, {5,Decrypt(p5,318)}, {6,Decrypt(p6,318)},
                           {7,Decrypt(p7,318)}, {8,Decrypt(p8,318)}, {9,Decrypt(p9,318)}};
    for (int i = 1; i < 10; ++i){

        qDebug() << ind.value(i);
        if(ind.value(i) != "")
        {
            query.prepare("SELECT * FROM User "
                       "WHERE login == :login");
            query.bindValue(":login",Encrypt(ind.value(i), 1017));
            query.exec();

            QSqlRecord mec = query.record();
            const int nameIndex = mec.indexOf("name");
            const int surnameIndex = mec.indexOf("surname");
            while(query.next())
            {
                name = query.value(nameIndex).toString(),
                        surname = query.value(surnameIndex).toString();
            }

            qDebug() << Decrypt(name, 785) << Decrypt(surname, 996);

            QByteArray log = ind.value(i).toUtf8();
            QString l = QCryptographicHash::hash(log, QCryptographicHash::Md4).toHex();
            query.prepare("SELECT * FROM statistic "
                       "WHERE login == :login");
            query.bindValue(":login",l);
            query.exec();

            QSqlRecord cec = query.record();
            const int task1Index = cec.indexOf("task1");
            const int task2Index = cec.indexOf("task2");
            const int task3Index = cec.indexOf("task3");
            const int task4Index = cec.indexOf("task4");

            while(query.next())
            {
                t1 = query.value(task1Index).toString(),
                        t2 = query.value(task2Index).toString(),
                        t3 = query.value(task3Index).toString(),
                        t4 = query.value(task4Index).toString();
            }

            qDebug() <<t1<<"\t" << t2 << t3 << t4 << "\n";
        }
        else
        {
            name = " ";
            surname = " ";
            t1 = " ";
            t2 = " ";
            t3 = " ";
            t4 = " ";
        }

        status += "&" + Decrypt(name, 785) + "&" + Decrypt(surname, 996) + "&" + t1 + "&" + t2 + "&" + t3 + "&" + t4 + "&" + "Q";
    }

    qDebug() << status;

    return status;
}

/**
 * @brief myfunctions::check_student
 * @param login
 * @return отвечает есть ли такой студент уже и является ли этот логин студентом
 */
QString ServerFunctions::CheckStudentExists(QString login)
{
    QString gr, st;
    QString status = "ok";

    QSqlQuery query;
    query.prepare("SELECT group_num FROM groups "
                  "WHERE p1 == :login OR p2 == :login OR p3 == :login OR p4 == :login OR p5 == :login OR p6 == :login OR p7 == :login OR p8 == :login OR p9 == :login");
    query.bindValue(":login", Encrypt(login, 318));
    query.exec();

    QSqlRecord rec = query.record();
    qDebug() << rec;
    const int groupIndex = rec.indexOf("group_num");

    while(query.next())
        gr = query.value(groupIndex).toString();

    qDebug() << "gr" << Decrypt(gr, 318);

    if (Decrypt(gr, 318) != "") status = "no";

    QString status_st = "student";
    QByteArray st_st = status_st.toUtf8();
    QString ss = QCryptographicHash::hash(st_st, QCryptographicHash::Sha224).toHex();

    qDebug() << "log in " << login;
    query.prepare("SELECT * FROM User "
               "WHERE login == :login");
    query.bindValue(":login",Encrypt(login, 1017));
    query.exec();

    QSqlRecord rec1 = query.record();
    const int statusIndex = rec1.indexOf("status");
    while(query.next())
        st = query.value(statusIndex).toString();

    qDebug() << "st" << st;
    qDebug() << "ss" << ss;

    if (st != ss) status = "no";

    return status;
}

//в группу добавляются логины
/**
 * @brief myfunctions::add_group
 * @param group_num
 * @param log_p1 - логин ученика
 * @param log_p2 - логин ученика
 * @param log_p3
 * @param log_p4
 * @param log_p5
 * @param log_p6
 * @param log_p7
 * @param log_p8
 * @param log_p9 - логин ученика
 * @param teacher
 * @return создание группы и добавление в группу логины
 */
QString ServerFunctions::AddGroup(QString group_num, QString log_p1, QString log_p2, QString log_p3,
                               QString log_p4, QString log_p5, QString log_p6, QString log_p7,
                               QString log_p8, QString log_p9, QString teacher)
{
    QString status = "probably has been updated";
    QString group_from_db;
    QMap<int, QString> ind {{1,log_p1}, {2,log_p2}, {3,log_p3}, {4,log_p4}, {5,log_p5}, {6,log_p6}, {7,log_p7}, {8,log_p8}, {9,log_p9}};

    QSqlQuery query;
    query.prepare("SELECT * FROM groups "
                  "WHERE group_num == :group_num");
    query.bindValue(":group_num", Encrypt(group_num, 318));
    query.exec();

    QSqlRecord rec = query.record();
    const int groupIndex = rec.indexOf("group_num");

    while(query.next()) group_from_db = query.value(groupIndex).toString();

    if (Decrypt(group_from_db, 318) == group_num)
    {
        if (CheckUserAccess(group_num) == "allowed")
        {
            query.prepare("DELETE FROM groups "
                          "WHERE group_num == :group_num");
            query.bindValue(":group_num", Encrypt(group_num, 318));
            query.exec();
        }
        else if (CheckUserAccess(group_num) == "not allowed")
        {
            return "You cannot change group!";
        }
    }

    for (int i = 1; i < 10; ++i)
    {
       if (ind.value(i) != "")
       {
           qDebug() << "value" << ind.value(i);

           if (CheckUserAccess(ind.value(i)) == "no")
           {
               qDebug() << "no" << CheckUserAccess(ind.value(i));
               return "One of student exists";
           }
       }
    }

    query.prepare("INSERT INTO groups(group_num, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10) "
                      "VALUES (:group_num, :p1, :p2, :p3, :p4, :p5, :p6, :p7, :p8, :p9, :p10)");
    query.bindValue(":group_num", Encrypt(group_num, 318));
    query.bindValue(":p1", Encrypt(log_p1, 318));
    query.bindValue(":p2", Encrypt(log_p2, 318));
    query.bindValue(":p3", Encrypt(log_p3, 318));
    query.bindValue(":p4", Encrypt(log_p4, 318));
    query.bindValue(":p5", Encrypt(log_p5, 318));
    query.bindValue(":p6", Encrypt(log_p6, 318));
    query.bindValue(":p7", Encrypt(log_p7, 318));
    query.bindValue(":p8", Encrypt(log_p8, 318));
    query.bindValue(":p9", Encrypt(log_p9, 318));
    query.bindValue(":p10", Encrypt(teacher, 318));
    query.exec();

    return status;
}

/**
 * @brief myfunctions::check_access
 * @param group_num
 * @return ответ о том, есть ли у преподавателя доступ к этой группе
 */
QString ServerFunctions::CheckUserAccess(QString group_num)
{
    QString group_from_db;
    QString status = "not allowed";
    QSqlQuery query;

    query.prepare("SELECT group_num FROM groups "
                  "WHERE p10 == :p10");
    query.bindValue(":p10", Encrypt(loginInfo, 318));
    query.exec();
    QSqlRecord rec = query.record();

    qDebug() << rec;

    const int groupIndex = rec.indexOf("group_num");
    while(query.next()) group_from_db = query.value(groupIndex).toString();

    qDebug()<<group_from_db << "\n";

    if (group_num == Decrypt(group_from_db, 318)) status = "allowed";

    return status;
}

/**
 * @brief myfunctions::get_student для статистики студента
 * @return возвращает имя и фамилию студента
 */
QString ServerFunctions::GetStudentInfo()
{
    QString name_from_db, surname_from_db;
    QString status = "&i_student&";
    QSqlQuery query;
    query.prepare("SELECT * FROM User "
                  "WHERE login == :login");
    query.bindValue(":login",  Encrypt(loginInfo, 1017));
    query.exec();

    QSqlRecord rec = query.record();

    const int nameIndex = rec.indexOf("name");
    const int surnameIndex = rec.indexOf("surname");
    while(query.next())
        name_from_db = query.value(nameIndex).toString(), surname_from_db = query.value(surnameIndex).toString();

    status += Decrypt(name_from_db, 785) + " " + Decrypt(surname_from_db, 996) + "&";

    qDebug() << "get_student" << status;

    return status;
}

/**
 * @brief myfunctions::get_teacher для статистики студента
 * @return возвращает имя и фамилию преподавателя
 */
QString ServerFunctions::GetTeacherInfo()
{
    QString log_teacher_from_db, teacherName_from_db, teacherSurname_from_db;
    QString status = "&i_teacher&";
    QSqlQuery query;
    query.prepare("SELECT p10 FROM groups "
                  "WHERE p1 == :login OR p2 == :login OR p3 == :login OR p4 == :login OR p5 == :login OR p6 == :login OR p7 == :login OR p8 == :login OR p9 == :login");
    query.bindValue(":login", Encrypt(loginInfo, 318));
    query.exec();

    QSqlRecord rec = query.record();
    qDebug() << rec;

    const int teacherIndex = rec.indexOf("p10");

    while(query.next())
        log_teacher_from_db = query.value(teacherIndex).toString();

    query.prepare("SELECT * FROM User "
                  "WHERE login == :login");
    query.bindValue(":login", Encrypt(Decrypt(log_teacher_from_db, 318), 1017));
    query.exec();

    QSqlRecord rec1 = query.record();
    qDebug() << rec;

    const int nameIndex = rec1.indexOf("name");
    const int surnameIndex = rec1.indexOf("surname");
    while(query.next())
        teacherName_from_db = query.value(nameIndex).toString(), teacherSurname_from_db = query.value(surnameIndex).toString();
    status += Decrypt(teacherName_from_db, 785) + " " + Decrypt(teacherSurname_from_db, 996) + "&";

    qDebug() << "get_teacher" << status;

    return status;
}

/**
 * @brief myfunctions::get_group для статистики студента
 * @return возвращает номер группы
 */
QString ServerFunctions::GetGroupInfo()
{
    QString group_from_db;
    QString status = "&i_group&";
    QSqlQuery query;
    query.prepare("SELECT group_num FROM groups "
                  "WHERE p1 == :login OR p2 == :login OR p3 == :login OR p4 == :login OR p5 == :login OR p6 == :login OR p7 == :login OR p8 == :login OR p9 == :login");
    query.bindValue(":login", Encrypt(loginInfo, 318));
    query.exec();
    QSqlRecord rec = query.record();
    qDebug() << rec;

    const int nameIndex = rec.indexOf("group_num");
    while(query.next())
        group_from_db = query.value(nameIndex).toString();

    status += Decrypt(group_from_db, 318) + " &";

    qDebug() << "get_group" << status;

    return status;
}

/**
 * @brief 1. Добавляем в список параметры, полученный разбитием строки формата func&username&password&email по &
 * 2. Вызываем функцию по индексу 0 и передаем необходимые параметры по индексам:
 * [1] - username
 * [2] - password
 * [3] - email
 * [4] - status (teacher/student
 * [1] и [2] необходимы для функции auth [4]?
 * [1], [2], [3], [4] необходимы для функции reg
 * @param data_from_client
 * @return статус (полученный в результате выполнения запрашиваемой функции/"Error ")
 */
QString ServerFunctions::ParseUserCredentials(QString data_from_client)
{
    data_from_client = Decrypt(data_from_client, 562);
    qDebug() << "data client" << data_from_client;

    QStringList list = data_from_client.split("&", Qt::SkipEmptyParts);
    if (list[0] == "auth")
    {
        loginInfo = list[1];
        return AuthenticateUser(list[1], list[2]);
    }
    else if (list[0] == "reg")
    {
         return RegisterUser(list[1], list[2], list[3], list[4], list[5], list[6]);
    }
    else if (list[0] == "getStat")
    {
         return GetTaskStatus(list[1]);
    }
    else if (list[0] == "updStat")
    {
        qDebug() << "updStat";
        return UpdateTaskStatus(loginInfo, list[1], list[2]);
    }
    else if (list[0] == "get_log")
    {
        qDebug() << "get_log" << list[1] << list[2];
        return GetUserLogin(list[1], list[2]);
    }
    else if (list[0] == "add_group")
    {
        qDebug() << "add_group";
        return AddGroup(list[1], GetUserLogin(list[2], list[3]), GetUserLogin(list[4], list[5]), GetUserLogin(list[6], list[7]),
                GetUserLogin(list[8], list[9]), GetUserLogin(list[10], list[11]), GetUserLogin(list[12], list[13]), GetUserLogin(list[14], list[15]),
                GetUserLogin(list[16], list[17]), GetUserLogin(list[18], list[19]), loginInfo);
    }
    else if(list[0] == "check_access")
    {
        qDebug() << "check_access";
        return CheckUserAccess(list[1]);
    }
    else if(list[0] == "get_info")
    {
        qDebug() << "info";
        return GetUserInfo(list[1]);
    }
    else if(list[0] == "get_student")
    {
        return GetStudentInfo();
    }
    else if(list[0] == "get_teacher")
    {
        return GetTeacherInfo();
    }
    else if(list[0] == "get_group")
    {
        return GetGroupInfo();
    }

    return "Error ";
}
