#include "connectionwindow.h"
#include "ui_connectionwindow.h"

ConnectionWindow::ConnectionWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ConnectionWindow)
{
    ui->setupUi(this);
}

ConnectionWindow::~ConnectionWindow()
{
    delete ui;
}
