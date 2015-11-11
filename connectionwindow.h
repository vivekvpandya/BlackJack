#ifndef CONNECTIONWINDOW_H
#define CONNECTIONWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QHash>
#include "table.h"

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
   // void updateAvailableTableList(std::vector<Table> tableDetails);
    void connected();
    void disconnected();
    void readyRead();
    void displayError(QAbstractSocket::SocketError socketError);

private:
    Ui::ConnectionWindow *ui;
    QTcpSocket *socket;
    QString nickNameStr;
    QHash<QString, Table> tables;
};

#endif // CONNECTIONWINDOW_H
