#ifndef GRIDLAYOUT_H
#define GRIDLAYOUT_H

#include <QMainWindow>
#include <QUdpSocket>
#include <QHostAddress>
#include "table.h"

namespace Ui {
class GridLayout;
}

class GridLayout : public QMainWindow
{
    Q_OBJECT

public:
    explicit GridLayout(QWidget *parent = 0);
    GridLayout(Table table_,QString nickName_,QWidget *parent = 0);
    ~GridLayout();

private:
    Ui::GridLayout *ui;
    QUdpSocket *udpSocket;
    QHostAddress groupAddress;
    QString nickName;
    int unique_num;
    Table table;
private slots:
    void processPendingDatagrams();
};

#endif // GRIDLAYOUT_H
