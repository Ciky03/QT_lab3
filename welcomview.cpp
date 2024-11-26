#include "welcomview.h"
#include "ui_welcomview.h"

welcomView::welcomView(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::welcomView)
{
    ui->setupUi(this);
}

welcomView::~welcomView()
{
    delete ui;
}
