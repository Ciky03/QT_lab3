#include "idatabase.h"

void IDatabase::initDatabase()
{
    database = QSqlDatabase::addDatabase("QSQLITE"); // 添加SQL LITE数据库驱动
    QString aFile = "E:/develop/QtProject/Lab3/lab3.db";
    database.setDatabaseName(aFile);    //设置数据库名称

    if (!database.open()) {
        qDebug() << "failed to open database";
    } else
        qDebug() << "open database is ok";
}

QString IDatabase::userLogin(QString username, QString password)
{
    QSqlQuery query;    //查询出当前记录的所有字段
    query.prepare("select username,password from user where username = :USER");
    query.bindValue(":USER", username);
    query.exec();
    if (query.first() && query.value("username").isValid()) {
        QString passwd = query.value("password").toString();
        if (passwd == password) {
            return "login ok";
        } else {
            return "wrong password";
        }
    } else {
        return "wrong username";
    }

}

IDatabase::IDatabase(QObject *parent) : QObject{parent}
{
    initDatabase();
}
