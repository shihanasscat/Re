#ifndef SERVERFUNCTIONS_H
#define SERVERFUNCTIONS_H
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QCryptographicHash>
#include "dbsingleton.h"

class ServerFunctions
{
private:
    QSqlDatabase *db;

public:
    ServerFunctions();
    ~ServerFunctions();

    /**
     * @brief Функция parsing считывает строку формата func&username&password&email&status,
     * затем вызывает функцию и передает параметры, указанные в строке
     * @param data_from_client, строка формата func&username&password&email
     * @return статус вызванной функции
     */
    QString ParseUserCredentials(QString clientData);

    /**
     * @brief Функция reg отвечает за регистрацию нового пользователя
     * @param login
     * @param password
     * @param email
     * @return статус регистрации
     */
    QString RegisterUser(QString login, QString password, QString email, QString status, QString name, QString surname);

    /**
     * @brief Функция auth отвечает за вход в аккаунт пользователя
     * @param login
     * @param password
     * @return статус входа
     */
    //arceniy
    QString AuthenticateUser(QString login, QString password);

    /**
     * @brief Функция updStat отвечает за обновление статуса решения задачи
     * @param name
     * @param task_num
     * @param status_of_task
     * @return
     */
    QString UpdateTaskStatus(QString name, QString taskNumber, QString taskStatus);

    /**
     * @brief get_stat
     * @param task_num
     * @return
     */
    QString GetTaskStatus (QString taskNumber);

    /**
     * @brief encrypt
     * @param toEncrypt
     * @param key
     * @return зашифрованные данные
     */
    QString Encrypt(QString text, quint32 key);

    /**
     * @brief decrypt
     * @param toDecrypt
     * @param key
     * @return расшифрованные данные
     */
    QString Decrypt(QString encryptedText, quint32 key);

    /**
     * @brief add_group
     * @param group_num
     * @param log_p1
     * @param log_p2
     * @param log_p3
     * @param log_p4
     * @param log_p5
     * @param log_p6
     * @param log_p7
     * @param log_p8
     * @param log_p9
     * @param teacher
     * @return создание группы и добавление в группу логины
     */
    QString AddGroup(QString groupNumber, QString log_p1, QString log_p2, QString log_p3,
                      QString log_p4, QString log_p5, QString log_p6, QString log_p7,
                      QString log_p8, QString log_p9, QString teacher);

    /**
     * @brief get_login
     * @param name
     * @param surname
     * @return
     */
    QString GetUserLogin(QString name, QString surname);

    /**
     * @brief check_access
     * @param group_num
     * @return ответ о том, есть ли такая группа уже или нет
     */
    QString CheckUserAccess(QString groupNumber);

    /**
     * @brief get_info
     * @param group
     * @return возвращает имя, фамилия и заадания
     */
    QString GetUserInfo(QString groupNumber);

    /**
     * @brief get_teacher
     * @return
     */
    QString GetTeacherInfo();

    /**
     * @brief get_student
     * @return
     */
    QString GetStudentInfo();

    /**
     * @brief get_group
     * @return
     */
    QString GetGroupInfo();

    /**
     * @brief check_student
     * @param login
     * @return отвечает есть ли такой стулент уже или нет
     */
    QString CheckStudentExists(QString login);
};

#endif // SERVERFUNCTIONS_H
