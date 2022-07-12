#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QtNetwork>
#include <QByteArray>
#include <QDebug>

class TcpServer : public QObject
{
    Q_OBJECT

public:
    explicit TcpServer(QObject* parent = nullptr);
    ~TcpServer();

public slots:
    /**
     * @brief Функция создания слота для нового подключения
     */
    void CreateNewSlotConnection();

    /**
     * @brief Функция отключения клиента
     */
    void DisconnectSlotConnection();

    /**
     * @brief Функция чтения строки от пользователя
     */
    void ReadSlotConnection();

private:
    QTcpServer* tcpServer;
    QTcpSocket* tcpSocket;

    /**
     * @brief список подключенний, сокетов
     */
    QList<QTcpSocket*> list;
};

#endif // TCPSERVER_H
