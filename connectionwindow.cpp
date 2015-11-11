#include "connectionwindow.h"
#include "ui_connectionwindow.h"
#include "networkoperationmanager.h"
#include <QMessageBox>

ConnectionWindow::ConnectionWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ConnectionWindow)
{
    ui->setupUi(this);
    connect(&networkOperationManger,SIGNAL(tableDetailsAvailable(std::vector<Table>)),this,SLOT(updateAvailableTableList(std::vector<Table>)));
}

ConnectionWindow::~ConnectionWindow()
{
    delete ui;
}

void ConnectionWindow::on_pushButton_clicked()
{
    QString hostAddress = ui->ipAddr->text();
    QString portNumber = ui->portNo->text();
    qint64 portNum = portNumber.toLongLong();
    QString nickNameStr = ui->nickName->text();
    if (nickNameStr.isEmpty() == true){
        QMessageBox nickerror;
        nickerror.setText("Nick Name is compulsory");
        nickerror.exec();
        return;
    }

    networkOperationManger.connectToHost(QHostAddress(hostAddress),portNum);
    if(networkOperationManger.isConnected()){
        networkOperationManger.requestTableList();
    }
    else{
        QMessageBox networkError;
        networkError.setText("Connection Failed with error: "+networkOperationManger.networkConnectionError());
        networkError.exec();
        return;
    }

    }

void ConnectionWindow::updateAvailableTableList(std::vector<Table> tableDetails)
{   qDebug() << "HEre";
    for(Table table:tableDetails)
    {   qDebug() << table.getTableName();
        ui->tableListWidget->addItem(table.getTableName());
    }

}


