#include <QCoreApplication>
#include "tcpserver.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    /**
     * @brief создание объекта сервера, необходимо для запуска
     */
    TcpServer server;

    return app.exec();
}
