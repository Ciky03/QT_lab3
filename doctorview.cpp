#include "doctorview.h"
#include "ui_doctorview.h"

doctorView::doctorView(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::doctorView)
{
    ui->setupUi(this);
}

doctorView::~doctorView()
{
    delete ui;
}
