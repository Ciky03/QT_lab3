#include "masterview.h"
#include "ui_masterview.h"

MasterView::MasterView(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MasterView)
{
    ui->setupUi(this);
}

MasterView::~MasterView()
{
    delete ui;
}

void MasterView::goLoginView()
{

}

void MasterView::goWelcomView()
{

}

void MasterView::goDoctorView()
{

}

void MasterView::goDepartmentView()
{

}

void MasterView::goPatientView()
{

}

void MasterView::goPatientEditView()
{

}

void MasterView::goPreviousView()
{

}
