#include "client.h"
#include <QDebug>
#include <QCoreApplication>
/**
 * @brief clientDestroyer::~clientDestroyer деструктор
 */
ClientDestroyer::~ClientDestroyer(){
    delete instance;
}
/**
* @brief clientDestroyer::initialize копирует ссылку на объект класса client
 * для последующей работы с ней в классе clientDestroyer
* @param p
*/
void ClientDestroyer::Initialize(Client * p){
    instance = p;
}
/**
 * @brief client::encrypt
 * @param toEncrypt
 * @return зашифрованные данные
 */
QString Client::Encrypt(QString toEncrypt){
    quint32 key = 562;
    QByteArray arr(toEncrypt.toUtf8());
    for(int i =0; i<arr.size(); i++)
        arr[i] = arr[i] ^ key;

    return QString::fromLatin1(arr.toBase64());
}
/**
 * @brief client::decrypt
 * @param toDecrypt
 * @return расшифрованные данные
 */
QString Client::Decrypt(QString toDecrypt)
{
    quint32 key = 562;
    QByteArray arr = QByteArray::fromBase64(toDecrypt.toLatin1());
    for(int i =0; i<arr.size(); i++)
        arr[i] = arr[i] ^ key;

    return QString::fromUtf8(arr);
}
/**
 * @brief client::client подключение клиента
 * @param parent
 */
Client::Client(QObject *parent){
    tcpSocket = new QTcpSocket(this);
    tcpSocket->connectToHost("127.0.0.1", 33333);
    connect(tcpSocket, &QTcpSocket::readyRead, this, &Client::slotServerRead);
}
/**
 * @brief client::~client отключение клиента
 */
Client::~Client(){
    tcpSocket->close();
}
/**
 * @brief client::getInstance создание и сохранение ссылки в аргумент p_instance
 * @return
 */
Client* Client::GetInstance(){
    if (!instance)
    {
        instance = new Client();
        destroyer.Initialize(instance);
    }
    return instance;
}

//encrypting and decrypting example with Ceasar/ to show how the encrypting should work
/**
 * @brief client::sendToServer отправка запроса на сервер
 * @param message
 */
void Client::SendToServer(QString message){
    //qDebug() << "encrypted" << encrypt(message).toUtf8();
    tcpSocket->write(Encrypt(message).toUtf8());
    //mTcpSocket->write(message.toUtf8());
}



/**
 * @brief client::slotServerRead получение ответа от сервера
 */
void Client::slotServerRead(){
    QString array = "";
    while(tcpSocket->bytesAvailable()>0)
    {
        QByteArray res = tcpSocket->readAll();

        array.append(res);
        array = Decrypt(array);

        //mTcpSocket->write(array);
        qDebug()<< array;

        QStringList list = array.split("&", Qt::SkipEmptyParts);

        if (array == "Welcome! student"){
            emit log_in_as_student();
        }
        else if (array == "Welcome! teacher"){
            emit log_in_as_teacher();
        }
        else if (array == "Wrong username or password! "){
            emit wrong_credentials();
        }
        else if (array == "You have been successfully registered! "){
            emit registered();
        }
        else if (array == "This username is already used!"){
            emit user_exists();
        }
        else if (array == "1&+"){
            emit solved_1();
        }
        else if (array == "2&+"){
            emit solved_2();
        }
        else if (array == "3&+"){
            emit solved_3();
        }
        else if (array == "4&+"){
            emit solved_4();
        }
        else if (array == "1&-"){
            emit not_solved_1();
        }
        else if (array == "2&-"){
            emit not_solved_2();
        }
        else if (array == "3&-"){
            emit not_solved_3();
        }
        else if (array == "4&-"){
            emit not_solved_4();
        }
        else if (array == "1&not solved yet"){
            emit not_yet_1();
        }
        else if (array == "2&not solved yet"){
            emit not_yet_2();
        }
        else if (array == "3&not solved yet"){
            emit not_yet_3();
        }
        else if (array == "4&not solved yet"){
            emit not_yet_4();
        }
        else if (array == "allowed"){
            emit allowed();
        }
        else if (array == "not allowed"){
            emit not_allow();
        }
        else if (list.size() > 5){
            emit get_it(array);
        }
        else if (list[0] == "i_student"){
            emit student(list[1]);
        }
        else if (list[0] == "i_teacher"){
            emit teacher(list[1]);
        }
        else if (list[0] == "i_group"){
            emit group(list[1]);
        }
        else if (array == "you cannot change group!"){
            qDebug() << "iuio";
            emit you_cannot();
        }
        else if (array == "one of student exists"){
            emit student_in_group();
        }

    }

}
