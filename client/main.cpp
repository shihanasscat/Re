#include "mainwindow.h"
#include "client.h"
#include <QApplication>

Client * Client::instance=0;
ClientDestroyer Client::destroyer;
QTcpSocket * Client::tcpSocket;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    /**
     * @brief создание объекта основного окна для последующей работы
     */
    Client::GetInstance();
    //cl->sendToServer("auth&admin&12345&");
    MainWindow w;
    //  w.show();
    return a.exec();
}
