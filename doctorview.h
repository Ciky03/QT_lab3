#ifndef DOCTORVIEW_H
#define DOCTORVIEW_H

#include <QWidget>

namespace Ui {
class doctorView;
}

class doctorView : public QWidget
{
    Q_OBJECT

public:
    explicit doctorView(QWidget *parent = nullptr);
    ~doctorView();

private:
    Ui::doctorView *ui;
};

#endif // DOCTORVIEW_H
