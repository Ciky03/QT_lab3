#include "loginview.h"
#include "ui_loginview.h"
#include "idatabase.h"

LoginView::LoginView(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoginView)
{
    ui->setupUi(this);
}

LoginView::~LoginView()
{
    delete ui;
}

void LoginView::on_btSignup_clicked()
{
    QString status = IDatabase::getInstance().userLogin(ui->inputUsername->text(), ui->inputPassword->text());
    qDebug() << status;

    if (status == "login ok")
        emit loginSuccess();
}

