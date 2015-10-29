#ifndef CONNECTIONWINDOW_H
#define CONNECTIONWINDOW_H

#include <QMainWindow>
#include "networkoperationmanager.h"

namespace Ui {
class ConnectionWindow;
}

class ConnectionWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ConnectionWindow(QWidget *parent = 0);
    ~ConnectionWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ConnectionWindow *ui;
    NetworkOperationManager networkOperationManger;
};

#endif // CONNECTIONWINDOW_H
