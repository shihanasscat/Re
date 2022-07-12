#ifndef DBSINGLETON_H
#define DBSINGLETON_H

#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>

class DBSingleton;

class DBSingletonDestroyer{
private:
    DBSingleton* instance;

public:
    ~DBSingletonDestroyer();
    void Initialize(DBSingleton* signleton);
};


class DBSingleton
{
private:
    static DBSingleton* instance;
    static DBSingletonDestroyer destroyer;
    QSqlDatabase db;

protected:
    DBSingleton();
    DBSingleton(const DBSingleton&);
    DBSingleton& operator= (DBSingleton&);
    ~DBSingleton();
    friend class DBSingletonDestroyer;

public:
    static DBSingleton* GetInstance();
    void CloseConnection();
};

#endif // DBSINGLETON_H
