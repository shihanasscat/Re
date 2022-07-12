#include "dbsingleton.h"

DBSingleton* DBSingleton::instance = nullptr;
DBSingletonDestroyer DBSingleton::destroyer;

/**
 * @brief singleton_db_destroyer::~singleton_db_destroyer деструктор
 */
DBSingletonDestroyer::~DBSingletonDestroyer()
{
    qDebug() << "Singleton deleted";
    delete instance;
}

/**
 * @brief singleton_db_destroyer::initialize копирует ссылку на объект класса singleton_db
 * для последующей работы с ней в классе singleton_db_destroyer
 * @param p
 */
void DBSingletonDestroyer::Initialize(DBSingleton* singleton)
{
    qDebug() << "Singleton Destoyer initialized";
    instance = singleton;
}

/**
 * @brief singleton_db::getInstance создание и сохранение ссылки в аргумент p_instance
 * @return
 */
DBSingleton* DBSingleton::GetInstance()
{
    qDebug() << "Get instance";

    if (!instance)
    {
        instance = new DBSingleton();
        destroyer.Initialize(instance);
    }

    return instance;
}

/**
 * @brief singleton_db::singleton_db конструктор для подключения к БД
 */
DBSingleton::DBSingleton()
{
    qDebug() << "Constructor";

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/WorkDir/Re/DB/DB.db");

    if (!db.open())
    {
        qDebug() << "Error openning DB connection";
    }
    else
    {
        qDebug() << "DB connection opened";
    }
}

/**
 * @brief singleton_db::close_db закрытие БД
 */
void DBSingleton::CloseConnection()
{
    if (db.open())
    {
        db.close();
        qDebug() << "Connection closed";
    }
    else
    {
        qDebug() << "Connection already closed";
    }
}

/**
 * @brief singleton_db::~singleton_db деструктор
 */
DBSingleton::~DBSingleton() {}
