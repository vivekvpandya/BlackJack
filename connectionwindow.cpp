#include "connectionwindow.h"
#include "ui_connectionwindow.h"
#include "message.h"
#include "table.h"
#include "gridlayout.h"
#include <QMessageBox>

ConnectionWindow::ConnectionWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ConnectionWindow)
{
    ui->setupUi(this);
  //  connect(&networkOperationManger,SIGNAL(tableDetailsAvailable(std::vector<Table>)),this,SLOT(updateAvailableTableList(std::vector<Table>)));
    socket = new QTcpSocket(this);

    connect(socket, SIGNAL(connected()), this, SLOT(connected()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    connect(socket, SIGNAL(error(QAbstractSocket::SocketError)),this, SLOT(displayError(QAbstractSocket::SocketError)));
    //connect(socket,SIGNAL(bytesWritten(qint64)), this, SLOT(bytesWritten(qint64)));
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
    ConnectionWindow::nickNameStr = nickNameStr;
    if (nickNameStr.isEmpty() == true){
        QMessageBox nickerror;
        nickerror.setText("Nick Name is compulsory");
        nickerror.exec();
        return;
    }

    if(socket->isValid() == true){
        Message message = Message(MessageType::GetTableDetails);
                 QByteArray block;
                QDataStream out(&block, QIODevice::ReadWrite);
                out.setVersion(QDataStream::Qt_5_5);
            //! [4] //! [6]
                out << (quint16)0;
                //out << s;
                //out << peer;
                out << message;
                out.device()->seek(0);

                out << (quint16)(block.size() - sizeof(quint16));
            //! [6] //! [7]
               qDebug()<<QString(block);
               socket->write(block);
               socket->flush();

               socket->waitForBytesWritten(3000);
               qDebug()<<"getTableDetails : sent!";

    }else{
    qDebug() << nickNameStr;
    Message message = Message(MessageType::GetTableDetails);
    socket->connectToHost(hostAddress,portNum);
    socket->waitForConnected();

             QByteArray block;
            QDataStream out(&block, QIODevice::ReadWrite);
            out.setVersion(QDataStream::Qt_5_5);
        //! [4] //! [6]
            out << (quint16)0;
            //out << s;
            //out << peer;
            out << message;
            out.device()->seek(0);

            out << (quint16)(block.size() - sizeof(quint16));
        //! [6] //! [7]
           qDebug()<<QString(block);
           socket->write(block);
           socket->flush();

           socket->waitForBytesWritten(3000);
           qDebug()<<"getTabelDetails : sent!";
   /* QString responseString="getRoomDetails: ";

    QByteArray tempByteArray = responseString.toUtf8();
    const char *tempChar = tempByteArray.data();
    socket->write(tempChar);

    socket->flush();
*/
  }
           //socket->waitForBytesWritten(3000);
}



void ConnectionWindow::connected(){

    qDebug() << "Connected !";

}

void ConnectionWindow::disconnected(){

    qDebug() << "Disconnected !";
}

/* This is a slot responsible to handle readyRead signal sent by connected TCP socket.
 * It will update client data structures based on message type received,
 * for example in response to GetRoomDetails client will receive RoomDetails message.
 * */
void ConnectionWindow::readyRead(){

    qDebug() << "Reading ... " <<'\n';

    quint16 blockSize=0;
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_5_5);

    if (blockSize == 0) {
        if (socket->bytesAvailable() < (int)sizeof(quint16))
            return;
//! [8]

//! [10]
        in >> blockSize;
    }

    if (socket->bytesAvailable() < blockSize)
        return;
//! [10] //! [11]

   // Sample sample;
   // in >> sample;
   // qDebug() << sample.message+"Message Recieved";
   // qDebug()<<sample.sender+"From Sender ";
   // Peer peer;
    //in >> peer;

    //qDebug() << peer.getNickName();
    //qDebug() << peer.getpeerAddress();
    Message message ;
    in >> message;
    qDebug() << blockSize;
    MessageType mtype = message.getMessageType();
    if(mtype == MessageType::TableDetails){
        ui->tableListWidget->clear();
        qDebug() << "TableDetails";
        std::vector<Table> tableVector = message.getTableDetails();
        for(Table table: tableVector){
                    ConnectionWindow::tables.insert(table.getTableName(),table);
                    ui->tableListWidget->addItem(table.getTableName());
        }
    }
    else if (mtype == MessageType::GetTableDetails){
        qDebug() <<"GetRoomDetails";
        // Drop this message
    }
    else if(mtype == MessageType::AddedToTable)
    {
        std::vector<QString> cmd = message.getDataStrings();
        qDebug() << nickNameStr << " has been added to " << cmd[0];
        GridLayout *gird = new GridLayout(tables[cmd[0]],nickNameStr);
        gird->show();



        //this->hide(); This will be used to hide the connection window. But it requires a signal from GridLayout when it is closed.


    }
    else if(mtype == MessageType::TableOverFolw)
    {   std::vector<QString> cmd = message.getDataStrings();
        QMessageBox::information(this, tr("Black Jack"),
                                 tr(": %1 table is full, please select some other table !")
                                 .arg(cmd[0]));
    }

    std::vector<QString> strings = message.getDataStrings();
    for(QString str : strings){
        qDebug() << str;
    }


// Old string logic
//    QString dataString =  QString::fromLatin1(socket->readAll());
//    qDebug() << dataString;
//    QStringList roomsList = dataString.split(":",QString::SkipEmptyParts);
//    for (QStringList::iterator it = roomsList.begin();
//             it != roomsList.end(); ++it) {

//      int distance =  it - roomsList.begin();
//      if(distance % 2 == 0){
//        ui->roomList->addItem(*it);
//        qDebug() << *it;
//        rooms.insert(*it,(*(it+1)).toInt());
//      }
//        }
}


//void ConnectionWindow::updateAvailableTableList(std::vector<Table> tableDetails)
//{   qDebug() << "HEre";
//    for(Table table:tableDetails)
//    {   qDebug() << table.getTableName();
//        ui->tableListWidget->addItem(table.getTableName());
//    }

//}

void ConnectionWindow::displayError(QAbstractSocket::SocketError socketError)
{
    switch (socketError) {
    case QAbstractSocket::RemoteHostClosedError:
        break;
    case QAbstractSocket::HostNotFoundError:
        QMessageBox::information(this, tr("Black Jack"),
                                 tr("The host was not found. Please check the "
                                    "host name and port settings."));
        break;
    case QAbstractSocket::ConnectionRefusedError:
        QMessageBox::information(this, tr("Black Jack"),
                                 tr("The connection was refused by the peer. "
                                    "Make sure the Room Manager is running, "
                                    "and check that the host name and port "
                                    "settings are correct."));
        break;
    default:
        QMessageBox::information(this, tr("Black Jack"),
                                 tr("The following error occurred: %1.")
                                 .arg(socket->errorString()));
    }


}


void ConnectionWindow::on_tableListWidget_doubleClicked(const QModelIndex &index)
{
    QString tableName = ui->tableListWidget->currentItem()->text();
    Message message = Message(MessageType::JoinTable);
    message.insertDataString(nickNameStr);
    message.insertDataString(tableName);
    QByteArray block;
    QDataStream out(&block, QIODevice::ReadWrite);
    out.setVersion(QDataStream::Qt_5_5);
    out << (quint16)0;
    out << message;
    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));
    qDebug()<<QString(block);
    socket->write(block);
    socket->flush();
    socket->waitForBytesWritten(3000);
    qDebug()<<"JoinTable : sent!";
    ui->statusInfo->setText("Request to join table " + tableName +" sent!");
}
