#ifndef CLIENT_H
#define CLIENT_H

#pragma once

#include <QtNetwork>
#include <QByteArray>
#include <QDebug>
#include <QCoreApplication>
#include <QString>
#include <QObject>
#include <QTcpSocket>
#include <QStringList>

class Client;

class ClientDestroyer
{
    private:
        Client* instance;
    public:
        /**
         * @brief clientDestroyer::~clientDestroyer деструктор
         */
        ~ClientDestroyer();

        /**
        * @brief clientDestroyer::initialize копирует ссылку на объект класса client
         * для последующей работы с ней в классе clientDestroyer
        * @param p
        */
        void Initialize(Client* instance);
};


class Client: public QObject
{
    Q_OBJECT

    private:
        static Client* instance;
        static ClientDestroyer destroyer;
        static QTcpSocket* tcpSocket;

    protected:
        /**
         * @brief client::client подключение клиента
         * @param parent
         */
         Client(QObject *parent = nullptr);

         /**
          * @brief client::~client отключение клиента
          */
        ~Client();

        Client(const Client& );
        Client& operator = (Client &);
        friend class ClientDestroyer;

        /**
         * @brief client::encrypt
         * @param toEncrypt
         * @return зашифрованные данные
         */
        QString Encrypt(QString text);

        /**
         * @brief client::decrypt
         * @param toDecrypt
         * @return расшифрованные данные
         */
        QString Decrypt(QString encryptedText);

    public:
        /**
         * @brief client::getInstance создание и сохранение ссылки в аргумент p_instance
         * @return
         */
        static Client* GetInstance();

        /**
         * @brief client::sendToServer отправка запроса на сервер
         * @param message
         */
        void SendToServer(QString message);

signals:
    void log_in_as_student();
    void log_in_as_teacher();
    void wrong_credentials();
    void registered();
    void user_exists();
    void solved_1();
    void solved_2();
    void solved_3();
    void solved_4();
    void not_solved_1();
    void not_solved_2();
    void not_solved_3();
    void not_solved_4();
    void not_yet_1();
    void not_yet_2();
    void not_yet_3();
    void not_yet_4();
    void allowed();
    void not_allow();
    void get_it(QString g);
    void group(QString group);
    void teacher (QString teacher);
    void student (QString student);
    void you_cannot();
    void student_in_group();

public slots:
    /**
     * @brief client::slotServerRead получение ответа от сервера
     */
    void slotServerRead();
};

#endif // CLIENT_H
