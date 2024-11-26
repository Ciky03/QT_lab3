#include "patientview.h"
#include "ui_patientview.h"

patientView::patientView(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::patientView)
{
    ui->setupUi(this);
}

patientView::~patientView()
{
    delete ui;
}
