#include "gridlayout.h"
#include "ui_gridlayout.h"
#include "deck.h"
#include "card.h"
#include "carddrawing.h"
#include "table.h"
#include "playerdrawing.h"
#include "player.h"
#include "message.h"

GridLayout::GridLayout(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GridLayout)
{
    ui->setupUi(this);

//    Deck newDeck = Deck();
//    Card randomCard = newDeck.popRandomCard();

//    Card randomCard5 = newDeck.popRandomCard();
//    CardDrawing *cardDraw5 = new CardDrawing();
//    QPixmap pix5 = QPixmap(QString::fromStdString(randomCard5.convert()));
//    cardDraw2->drawWithPixmap(pix5);
//    ui->player1Layout->addWidget(cardDraw5);

//    Table table = Table();
//    table.setCapacity(3);
//    table.setTableName("Royal Casino");
//    table.setPortNo(12000);

//    Player player = Player("Vivek");
//    player.setUnique_num(1);
//    player.addCardToHand(newDeck.popRandomCard());
//    player.addCardToHand(newDeck.popRandomCard());
//    player.addCardToHand(newDeck.popRandomCard());

//    Player player2 = Player("Dipesh");
//    player2.setUnique_num(2);
//    player2.addCardToHand(newDeck.popRandomCard());
//    player2.addCardToHand(newDeck.popRandomCard());
//    player2.addCardToHand(newDeck.popRandomCard());

//    Player player3 = Player("Satya");
//    player3.setUnique_num(3);
//    player3.addCardToHand(newDeck.popRandomCard());
//    player3.addCardToHand(newDeck.popRandomCard());
//    player3.addCardToHand(newDeck.popRandomCard());

//    table.addPlayerToTable(player);
//    table.addPlayerToTable(player2);
//    table.addPlayerToTable(player3);


//    int row = 0;
//    for(int i = 0 ;i<table.getCapacity();i++ )
//    {   std::list<Player>::iterator playerIt = table.playerListBegin();
//        std::advance(playerIt,i);
//        Player player = *playerIt;
//        PlayerDrawing *playerDrwaing = new PlayerDrawing();
//        playerDrwaing->setPlayerName(player.getName());
//        std::vector<Card> *playerHand = player.getCardHand();
//        for(std::vector<Card>::iterator cardIt = playerHand->begin(); cardIt != playerHand->end() ; cardIt++ )
//        {
//            playerDrwaing->addCardtoStack(*cardIt);
//        }
//        if(i%2 == 0) {
//            ui->gridLayout->addWidget(playerDrwaing,row,0);

//        }
//        else{
//            ui->gridLayout->addWidget(playerDrwaing,row,1);
//        row++;
//        }
//    }





}

GridLayout::GridLayout(Table table_, QString nickName_, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GridLayout)
{   ui->setupUi(this);
    table = table_;
    nickName == nickName_;
    groupAddress = QHostAddress("239.255.43.21");
    udpSocket = new QUdpSocket();
    udpSocket->bind(QHostAddress::AnyIPv4,table.getPortNo(), QUdpSocket::ShareAddress);
    udpSocket->joinMulticastGroup(groupAddress);
    connect(udpSocket,SIGNAL(readyRead()),this,SLOT(processPendingDatagrams()));
    qDebug() << "GridLayout is created";
    qDebug() << table.getPortNo() ;
    Message message = Message(MessageType::GetTableDetails); // A joinRoom Message
    QByteArray datagram;
    QDataStream out(&datagram, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_5);
    out << message;
    udpSocket->writeDatagram(datagram, groupAddress, table.getPortNo());
}


void GridLayout::processPendingDatagrams()
{   Message message;
    while (udpSocket->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(udpSocket->pendingDatagramSize());
        udpSocket->readDatagram(datagram.data(), datagram.size());
        //statusLabel->setText(tr("Received datagram: \"%1\"").arg(datagram.data()));
        qDebug()<<"got here121";

           QDataStream in(&datagram, QIODevice::ReadOnly);
           in.setVersion(QDataStream::Qt_5_5);
           in >> message;
           MessageType mtype = message.getMessageType();
           if(mtype == MessageType::GameDetails){
               // This will be one time message sent by Dealer when game begins
               for(Player player : message.getPlayers()){
                   table.addPlayerToTable(player);
               }
               int row = 0;
               for(int i = 0 ;i<table.getCapacity();i++ )
                   {  qDebug() << "Looping over the player";
                       std::list<Player>::iterator playerIt = table.playerListBegin();
                       std::advance(playerIt,i);
                       Player player = *playerIt;
                       PlayerDrawing *playerDrwaing = new PlayerDrawing();
                       playerDrwaing->setPlayerName(player.getName());
                       std::vector<Card> *playerHand = player.getCardHand();
                       for(std::vector<Card>::iterator cardIt = playerHand->begin(); cardIt != playerHand->end() ; cardIt++ )
                       {
                           playerDrwaing->addCardtoStack(*cardIt);
                       }
                       if(i%2 == 0) {
                           ui->gridLayout->addWidget(playerDrwaing,row,0);
                       }
                       else{
                           ui->gridLayout->addWidget(playerDrwaing,row,1);
                       row++;
                       }
                   }
           }
           else if(mtype == MessageType::GetTableDetails)
           {
               qDebug() << "dropping GetTableDetails message";
           }
    }
}


GridLayout::~GridLayout()
{
    delete ui;
}
