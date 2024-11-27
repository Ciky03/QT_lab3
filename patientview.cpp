#include "patientview.h"
#include "ui_patientview.h"
#include "idatabase.h"

PatientView::PatientView(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PatientView)
{
    ui->setupUi(this);

    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);    //一次选一行
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);      //无法编辑
    ui->tableView->setAlternatingRowColors(true);   //选中行变化颜色

    IDatabase &iDatabase = IDatabase::getInstance();
    if (iDatabase.initPatientModel()) {
        ui->tableView->setModel(iDatabase.patientTabModel);
        ui->tableView->setSelectionModel(iDatabase.thePatinentSelection);
    }
}

PatientView::~PatientView()
{
    delete ui;
}

void PatientView::on_btAdd_clicked()
{
    emit goPatientEditView();
}

