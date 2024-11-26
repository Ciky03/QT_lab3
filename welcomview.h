#ifndef WELCOMVIEW_H
#define WELCOMVIEW_H

#include <QWidget>

namespace Ui {
class welcomView;
}

class welcomView : public QWidget
{
    Q_OBJECT

public:
    explicit welcomView(QWidget *parent = nullptr);
    ~welcomView();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::welcomView *ui;
};

#endif // WELCOMVIEW_H
