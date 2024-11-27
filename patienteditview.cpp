#include "patienteditview.h"
#include "ui_patienteditview.h"
#include "idatabase.h"
#include <QSqlTableModel>

PatientEditView::PatientEditView(QWidget *parent, int index)
    : QWidget(parent)
    , ui(new Ui::PatientEditView)
{
    ui->setupUi(this);

    dataMapper = new QDataWidgetMapper();
    QSqlTableModel *tabModel = IDatabase::getInstance().patientTabModel;
    dataMapper->setModel(IDatabase::getInstance().patientTabModel);
    dataMapper->setSubmitPolicy(QDataWidgetMapper::AutoSubmit);

    //映射字段
    dataMapper->addMapping(ui->inputID, tabModel->fieldIndex("id"));
    dataMapper->addMapping(ui->inputIdCard, tabModel->fieldIndex("id_card"));
    dataMapper->addMapping(ui->inputName, tabModel->fieldIndex("name"));
    dataMapper->addMapping(ui->inputSex, tabModel->fieldIndex("sex"));
    dataMapper->addMapping(ui->inputDate, tabModel->fieldIndex("dob"));
    dataMapper->addMapping(ui->inputHeight, tabModel->fieldIndex("height"));
    dataMapper->addMapping(ui->inputWeight, tabModel->fieldIndex("weight"));
    dataMapper->addMapping(ui->inputPhone, tabModel->fieldIndex("mobilephone"));
    dataMapper->addMapping(ui->inputCreateTime, tabModel->fieldIndex("create_time"));

    dataMapper->setCurrentIndex(index);
}

PatientEditView::~PatientEditView()
{
    delete ui;
}

void PatientEditView::on_btSave_clicked()
{
    IDatabase::getInstance().submitPatient();
    emit goPreviousView();
}


void PatientEditView::on_btCancel_clicked()
{
    IDatabase::getInstance().reverPatient();
    emit goPreviousView();

}

