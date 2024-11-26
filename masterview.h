#ifndef MASTERVIEW_H
#define MASTERVIEW_H

#include <QWidget>

#include "patienteditview.h"
#include "patientview.h"
#include "welcomview.h"
#include "departmentview.h"
#include "loginview.h"
#include "doctorview.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MasterView;
}
QT_END_NAMESPACE

class MasterView : public QWidget
{
    Q_OBJECT

public:
    MasterView(QWidget *parent = nullptr);
    ~MasterView();

public slots:
    void goLoginView();
    void goWelcomView();
    void goDoctorView();
    void goDepartmentView();
    void goPatientView();
    void goPatientEditView();
    void goPreviousView();

private slots:
    void on_btBack_clicked();

private:
    void pushWidgetToStackView(QWidget *widget);

    Ui::MasterView *ui;

    welcomView *welcomeView;
    PatientView *patientView;
    DepartmentView *departmentView;
    PatientEditView *patientEditView;
    LoginView *loginview;
    DoctorView *doctorView;
};
#endif // MASTERVIEW_H
