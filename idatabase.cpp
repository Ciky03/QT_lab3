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

bool IDatabase::initPatientModel()
{
    patientTabModel = new QSqlTableModel(this, database);
    patientTabModel->setTable("patient");   //设置表
    patientTabModel->setEditStrategy(QSqlTableModel::OnManualSubmit); //数据保存方式
    patientTabModel->setSort(patientTabModel->fieldIndex("name"), Qt::AscendingOrder);  //排序

    if (!(patientTabModel->select())) //查询数据库
        return false;

    thePatinentSelection = new QItemSelectionModel(patientTabModel);
    return true;
}

bool IDatabase::searchPatient(QString filter)
{
    patientTabModel->setFilter(filter);
    return patientTabModel->select();
}

bool IDatabase::delectCurrentPatinet()
{
    //获取当前选择单元格的模型索引
    QModelIndex curIndex = thePatinentSelection->currentIndex();
    patientTabModel->removeRow(curIndex.row());
    patientTabModel->submitAll();
    patientTabModel->select();
}

bool IDatabase::submitPatient()
{
    return patientTabModel->submitAll();
}

void IDatabase::reverPatient()
{
    return patientTabModel->revertAll();
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
