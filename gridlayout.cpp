#include "gridlayout.h"
#include "ui_gridlayout.h"

GridLayout::GridLayout(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GridLayout)
{
    ui->setupUi(this);
}

GridLayout::~GridLayout()
{
    delete ui;
}
