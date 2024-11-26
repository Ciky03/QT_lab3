#include "masterview.h"
#include "ui_masterview.h"

MasterView::MasterView(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MasterView)
{
    ui->setupUi(this);

    // 初始化时跳转到loginView
    goLoginView();
}

MasterView::~MasterView()
{
    delete ui;
}

void MasterView::goLoginView()
{
    // 将loginView压入
    loginview = new LoginView(this);
    pushWidgetToStackView(loginview);

    connect(loginview, SIGNAL(loginSuccess()), this, SLOT(goWelcomView()));
}

void MasterView::goWelcomView()
{
    // 将welcomeView压入
    welcomeView = new welcomView(this);
    pushWidgetToStackView(welcomeView);

    connect(welcomeView, SIGNAL(goDepartmentView()), this, SLOT(goDepartmentView()));
    connect(welcomeView, SIGNAL(goDoctorView()), this, SLOT(goDoctorView()));
    connect(welcomeView, SIGNAL(goPatientView()), this, SLOT(goPatientView()));
}

void MasterView::goDoctorView()
{
    // 将doctorView压入
    doctorView = new DoctorView(this);
    pushWidgetToStackView(doctorView);
}

void MasterView::goDepartmentView()
{
    // 将departmentView压入
    departmentView = new DepartmentView(this);
    pushWidgetToStackView(departmentView);
}

void MasterView::goPatientView()
{
    // 将patientView压入
    patientView = new PatientView(this);
    pushWidgetToStackView(patientView);

    connect(patientView, SIGNAL(goPatientEditView()), this, SLOT(goPatientEditView()));
}

void MasterView::goPatientEditView()
{
    // 将patientEditView压入
    patientEditView = new PatientEditView(this);
    pushWidgetToStackView(patientEditView);
}

void MasterView::goPreviousView()
{
    int count = ui->stackedWidget->count();
    if (count > 1) {
        // 显示
        ui->stackedWidget->setCurrentIndex(count - 2);
        // 设置title
        ui->labelTitle->setText(ui->stackedWidget->currentWidget()->windowTitle());
        // 删除原来的
        QWidget *widget = ui->stackedWidget->widget(count - 1);
        ui->stackedWidget->removeWidget(widget);
        delete widget;
    }
}

void MasterView::pushWidgetToStackView(QWidget *widget)
{
    ui->stackedWidget->addWidget(widget);
    // 总是显示最新加入的view
    int count = ui->stackedWidget->count();
    ui->stackedWidget->setCurrentIndex(count - 1);
    // 设置title
    ui->labelTitle->setText(widget->windowTitle());
}

void MasterView::on_btBack_clicked()
{
    goPreviousView();
}

