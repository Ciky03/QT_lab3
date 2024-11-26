#include "welcomview.h"
#include "ui_welcomview.h"

welcomView::welcomView(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::welcomView)
{
    ui->setupUi(this);
}

welcomView::~welcomView()
{
    delete ui;
}

void welcomView::on_pushButton_clicked()
{
    emit goDepartmentView();
}


void welcomView::on_pushButton_2_clicked()
{
    emit goDoctorView();
}


void welcomView::on_pushButton_3_clicked()
{
    emit goPatientView();
}

