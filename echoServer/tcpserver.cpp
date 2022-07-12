#include <QDebug>
#include <QString>
#include <QStringList>
#include <QList>
#include <QCoreApplication>

#include "tcpserver.h"
#include "serverfunctions.h"
#include "serverfunctions.cpp"

/**
 * @brief деструктор для закрытия соединения
 */
TcpServer::~TcpServer()
{
    tcpServer->close();
}

/**
 * @brief конструктор для запуска сервера
 * @param parent
 */
TcpServer::TcpServer(QObject *parent) : QObject(parent)
{
    tcpServer = new QTcpServer(this);
    connect(tcpServer, &QTcpServer::newConnection,
            this, &TcpServer::CreateNewSlotConnection);

    if (!tcpServer->listen(QHostAddress::Any, 33333))
    {
        qDebug() << "Server is not started";
    }
    else
    {
        qDebug() << "Server is started";
    }
}

/**
 * @brief создание слота для нового подключения
 */
void TcpServer::CreateNewSlotConnection()
{
        QTcpSocket* mTcpSocket = tcpServer->nextPendingConnection();
        list.push_back(mTcpSocket);
        qDebug() << "1";

        mTcpSocket->write("Server is running...\r\n");
        connect(mTcpSocket, &QTcpSocket::readyRead, this, &TcpServer::ReadSlotConnection);
        connect(mTcpSocket, &QTcpSocket::disconnected, this, &TcpServer::DisconnectSlotConnection);
}

/**
 * @brief чтение строки от пользователя
 */
void TcpServer::ReadSlotConnection()
{
    ServerFunctions f;
    QTcpSocket* mTcpSocket = (QTcpSocket*)sender();
    QString res = "";
    while(mTcpSocket->bytesAvailable() > 0)
    {
        QByteArray array = mTcpSocket->readAll();
        res.append(array);
    }

    mTcpSocket->write(f.Encrypt(f.ParseUserCredentials(res), 562).toUtf8());
}

/**
 * @brief возможность подключения нескольких клиентов
 */
void TcpServer::DisconnectSlotConnection()
{
    QTcpSocket* mTcpSocket = (QTcpSocket*)sender();
    list.removeAt(list.indexOf(mTcpSocket));
    mTcpSocket->close();

    qDebug() << list.size();

    loginInfo = "";
}
