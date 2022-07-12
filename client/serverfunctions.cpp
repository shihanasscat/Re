#include "serverfunctions.h"
#include <QDebug>
#include <bitset>
#include <vector>

/**
 * @brief авторизация по введенными пользователем паролю и логину
 * @param log
 * @param pass
 */
void auth(QString log, QString pass){
    QString res = "auth&" + log + "&" + pass + "&";
    qDebug() << res;
    Client::GetInstance()->SendToServer(res);
    //qDebug() << client::getInstance()->slotServerRead();
    //return client::getInstance()->slotServerRead();
}

/**
 * @brief регистрация по введеным пользователем паролю, логину и почте
 * @param log
 * @param pass
 * @param email
 */
void reg(QString log, QString pass, QString email, QString status, QString name, QString surname){
    QString res = "reg&" + log + "&" + pass + "&" + email + "&" + status + "&" + name + "&" + surname + "&";
    qDebug() << res;
    Client::GetInstance()->SendToServer(res);
}

/**
 * @brief обновление статуса в кабинете пользователя
 * @param n - количество набранных баллов
 * @param upd
 */
void upd_stat(int n, QString upd){
    QString res = "updStat&" + QString::number(n) + "&" + upd + "&";
    qDebug() << res;
    Client::GetInstance()->SendToServer(res);
}
/**
 * @brief get_stat вывод статуса в кабинете пользователя
 * @param n - количество набранных баллов
 */
void get_stat(int n){
    QString res = "getStat&" + QString::number(n) + "&";
    //here
    qDebug() << res;
    Client::GetInstance()->SendToServer(res);
}
/**
 * @brief get_log вывод данных пользователя
 * @param name
 * @param surname
 */
void get_log(QString name, QString surname){
    QString res = "get_log&" + name + "&" + surname + "&";
    qDebug() << res;
    Client::GetInstance()->SendToServer(res);
}

//&resol&group_num&n1&s1&n2&s2&n3&s3&n4&s4&n5&s5&n6&s6&n7&s7&n8&s8&n9&s9&t_name&t_surname&
/**
 * @brief new_group добавление группы
 * @param group_num
 * @param n1 - Имя
 * @param s1 - Фамилия
 * @param n2
 * @param s2
 * @param n3
 * @param s3
 * @param n4
 * @param s4
 * @param n5
 * @param s5
 * @param n6
 * @param s6
 * @param n7
 * @param s7
 * @param n8
 * @param s8
 * @param n9
 * @param s9
 */
void new_group(QString group_num, QString n1, QString s1, QString n2, QString s2, QString n3, QString s3, QString n4, QString s4,
               QString n5, QString s5, QString n6, QString s6, QString n7, QString s7, QString n8, QString s8,
               QString n9, QString s9){
    QString res = "add_group&" + group_num + "&" + n1 + "&" + s1 + "&" + n2 + "&" + s2 + "&" + n3 + "&" + s3 + "&" + n4 + "&" + s4
            + "&" + n5 + "&" + s5 + "&" + n6 + "&" + s6 + "&" + n7 + "&" + s7 + "&" + n8 + "&" + s8 + "&" + n9 + "&" + s9
            + "&";
    qDebug() << res;
    Client::GetInstance()->SendToServer(res);
}
/**
 * @brief check_access проверка доступа преподавателя к группе
 * @param group_num
 */
void check_access(QString group_num){
    QString res = "check_access&" + group_num + "&";
    qDebug() << res;
    Client::GetInstance()->SendToServer(res);
}
/**
 * @brief get_info получение информации по группе
 * @param group
 */
void get_info(QString group){
    QString res = "get_info&" + group + "&";
    qDebug() << res;
    Client::GetInstance()->SendToServer(res);

    //return res;
}
/**
 * @brief get_student получение инфрмации о студенте
 */
void get_student(){
    QString res = "get_student&";
    qDebug() << res;
    Client::GetInstance()->SendToServer(res);
}
/**
 * @brief get_teacher получение информации о преподавателе
 */
void get_teacher(){
    QString res = "get_teacher&";
    qDebug() << res;
    Client::GetInstance()->SendToServer(res);
}
/**
 * @brief get_group получение номера группы
 */
void get_group(){
    QString res = "get_group&";
    qDebug() << res;
    Client::GetInstance()->SendToServer(res);
}

/**
 * @brief автоматическое решение задания 1
 * @param input
 * @return правильный ответ на задание 1
 */
QString solve_task1(QString input){
    qDebug() << "solve_task1 " << input;

    QChar variantIndex = input[0];
    if (variantIndex == '1') return "Да";
    else if (variantIndex == '2') return "Да";
    else if (variantIndex == '3') return "Да";
    else if (variantIndex == '4') return "Да";
    else if (variantIndex == '5') return "Нет";

    return "";
}

/**
 * @brief автоматическое решение задания 2
 * @param input
 * @return правильный ответ на задание 2
 */
QString solve_task2(){
    return "(5,5,1,1,2,6,5)";
}

/**
 * @brief автоматическое решение задания 3
 * @param input
 * @return правильный ответ на задание 3
 */
QString solve_task3()
{
   return "9";
}

QString solve_task4()
{
    return "2";
}

/**
 * @brief автоматическая генерация вектора булевых значений
 * @return вектор булевых значений
 */

QString gen_task1()
{
    QVector<QString> variants =
    {
        "1 вариант: G = (V,E) = (V={1,2,3,4,5,6,7}, E={(1,2),(1,3), (1,4),(2,3),(2,6),(2,7),(3,4),(3,5),(3,7),(5,6),(6,7)}).",
        "2 вариант: G = (V,E) = (V={1,2,3,4,5,6,7}, E={(1,2),(1,4), (1,6),(1,7),(2,4),(2,6),(3,4),(3,5),(3,6),(3,7),(4,5), (5,6),(6,7)}).",
        "3 вариант: G = (V,E) = (V={(1,2,3,4,5,6,7}, E={(1,2),(1,3), (1,4),(1,7),(2,3),(2,4),(2,6),(3,4),(4,5),(4,6),(4,7)}).",
        "4 вариант: G = (V,E)= (V={1,2,3,4,5,6,7}, E={(1,2),(1,3), (1,4),(1,5),(2,3),(2,4),(2,5),(3,4),(4,7),(6,7)}).",
        "5 вариант: G = (V,E) = (V={1,2,3,4,5,6,7}, E={(1,2),(1,3), (1,4),(1,6),(2,3),(2,6),(3,4),(3,6),(3,7),(4,5),(4,7), (5,6),((6,7)}).",
    };

    std::random_device rd;
    std::mt19937 g(rd());
    std::uniform_int_distribution<int> generator(0, variants.size());

    int variantIndex = generator(g);
    qDebug() << "GenTask1: " << variantIndex << " " << variants[variantIndex];

    return variants[variantIndex];
}

/**
 * @brief автоматическая генерация вектора булевых значений
 * @return вектор булевых значений
 */
QString gen_task2(){
    return "T = (V,E)=(V={1,2,3,4,5,6,7,8,9},E={(1,2),(1,7),(1,8)(2,6)(5,6)(3,5)(4,5)(5,9)})";
}

/**
 * @brief автоматическая генерация вектора булевых значений
 * @return вектор булевых значений
 */
QString gen_task3(){
    return "G = (V,E) = (V={v1,v2,v3,v4,v5,v6,v7,v8,v9}, E={{v1,v2},(v1,v7),{v1,v8}, {v1,v9},{v2,v3},{v2,v7},{v2,v9},{v3,v4},{v3,v6},{v3,v9}, (v4,v5), (v4,v6),"
    "{v4,v7},{v5,v6},{v6,v7},{v6,v8},{v6,v9},{v7,v9},{v8,v9}}).\n"
    "Вес wji ребра {vi,vj} или дуги (vi,vj) равен 19(i^2 +j^2 ) + i^2 + j^2 + i+ j по модулю 10 (остаток от деления wij на 10)";
}

/**
 * @brief автоматическая генерация вектора булевых значений
 * @return вектор булевых значений
 */
QString gen_task4(){
    return "G = (V,E) = (V={v1,v2,v3,v4,v5,v6,v7,v8,v9}, E={{v1,v2},(v1,v7),{v1,v8}, {v1,v9},{v2,v3},{v2,v7},{v2,v9},{v3,v4},{v3,v6},{v3,v9}, (v4,v5), (v4,v6),"
           "{v4,v7},{v5,v6},{v6,v7},{v6,v8},{v6,v9},{v7,v9},{v8,v9}}).";
}

/**
 * @brief проверка заданий
 * @param task_num
 * @param ans
 * @param input
 */
bool check_task(int task_num, QString ans, QString input)
{
    QString solution;
    switch(task_num)
    {
    case 1:
        solution = solve_task1(input);
        break;
    case 2:
        solution = solve_task2();
        break;
    case 3:
        solution = solve_task3();
        break;
    case 4:
        solution = solve_task4();
        break;
    }

     if (ans == solution)
     {
         upd_stat(task_num, "+");
         return true;
     }
     else
     {
         upd_stat(task_num, "-");
         return false;
     }
}
