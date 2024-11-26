#ifndef PATIENTVIEW_H
#define PATIENTVIEW_H

#include <QWidget>

namespace Ui {
class patientView;
}

class patientView : public QWidget
{
    Q_OBJECT

public:
    explicit patientView(QWidget *parent = nullptr);
    ~patientView();

private:
    Ui::patientView *ui;
};

#endif // PATIENTVIEW_H
