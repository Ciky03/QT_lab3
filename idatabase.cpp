#include "idatabase.h"

void IDatabase::initDatabase()
{
    database = QSqlDatabase::addDatabase("QSQLITE"); // 添加SQL LITE数据库驱动
    QString aFile = "../../../lab3.db";
    database.setDatabaseName(aFile);    //设置数据库名称

    if (!database.open()) {
        qDebug() << "failed to open database";
    } else
        qDebug() << "open database is ok";
}

IDatabase::IDatabase(QObject *parent) : QObject{parent}
{
    initDatabase();
}
