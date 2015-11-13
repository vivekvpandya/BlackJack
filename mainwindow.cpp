#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "card.h"
#include "carddrawing.h"
#include "deck.h"
#include "player.h"
#include "table.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Testing code for card drwaing
//
    Deck newDeck = Deck();
    Card randomCard = newDeck.popRandomCard();

//    Card randomCard5 = newDeck.popRandomCard();
//    CardDrawing *cardDraw5 = new CardDrawing();
//    QPixmap pix5 = QPixmap(QString::fromStdString(randomCard5.convert()));
//    cardDraw2->drawWithPixmap(pix5);
//    ui->player1Layout->addWidget(cardDraw5);

    Table table = Table();
    table.setCapacity(2);
    table.setTableName("Royal Casino");
    table.setPortNo(12000);

    Player player = Player("Vivek");
    player.setUnique_num(1);
    player.addCardToHand(newDeck.popRandomCard());
    player.addCardToHand(newDeck.popRandomCard());
    player.addCardToHand(newDeck.popRandomCard());

    Player player2 = Player("Dipesh");
    player2.setUnique_num(2);
    player2.addCardToHand(newDeck.popRandomCard());
    player2.addCardToHand(newDeck.popRandomCard());
    player2.addCardToHand(newDeck.popRandomCard());

    Player player3 = Player("Satya");
    player3.setUnique_num(3);
    player3.addCardToHand(newDeck.popRandomCard());
    player3.addCardToHand(newDeck.popRandomCard());
    player3.addCardToHand(newDeck.popRandomCard());

    table.addPlayerToTable(player);
    table.addPlayerToTable(player2);
    table.addPlayerToTable(player3);
    gameDecider(&table);


    std::vector<Card>  playerHand = player.getCardHand();
    for(int itereator = 0; itereator!= playerHand.size(); itereator++){
        Card card = playerHand.at(itereator);
        qDebug()<<card.getValue()<<"\n";
        CardDrawing *cardDrawing = new CardDrawing();
        QPixmap pixmap = QPixmap(QString::fromStdString(card.convert()));
        cardDrawing->drawWithPixmap(pixmap);
        ui->player1Layout->addWidget(cardDrawing);
    }

    std::vector<Card>  player2Hand = player2.getCardHand();
    for(int itereator = 0; itereator!= player2Hand.size(); itereator++){
        Card card = player2Hand.at(itereator);
        qDebug()<<card.getValue()<<"\n";
        CardDrawing *cardDrawing = new CardDrawing();
        QPixmap pixmap = QPixmap(QString::fromStdString(card.convert()));
        cardDrawing->drawWithPixmap(pixmap);
        ui->player2Layout->addWidget(cardDrawing);
    }

    std::vector<Card>  player3Hand = player3.getCardHand();
    for(int itereator = 0; itereator!= player3Hand.size(); itereator++){
        Card card = player3Hand.at(itereator);
        qDebug()<<card.getValue()<<"\n";
        CardDrawing *cardDrawing = new CardDrawing();
        QPixmap pixmap = QPixmap(QString::fromStdString(card.convert()));
        cardDrawing->drawWithPixmap(pixmap);
        ui->player3Layout->addWidget(cardDrawing);
    }

    // To hide remaining player name
   // ui->player2Name->hide();
    //ui->player3Name->hide();
    ui->player4Name->hide();
    ui->player5Name->hide();
    ui->player1Name->setText(player.getName());
    ui->player2Name->setText(player2.getName());
    ui->player3Name->setText(player3.getName());



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::gameDecider(Table *table){
    vector<Card> temp;
    vector<int> values;
    for(std::list< Player >::iterator it=table->playerListBegin();it!=table->playerListEnd();it++){
        temp = ((*it).getCardHand());
        int value=0;
        for(std::vector<Card>::iterator itcard=temp.begin();itcard!=temp.end();itcard++){
            value+=(*itcard).getValue();
        }
           values.push_back(value);
    }
     int ans=0,index=0;
    for(int i=0;i<values.size();i++){
        if(values[i]<=21 && values[i]>ans){
            ans=values[i];
            index=i;
        }
    }
    qDebug()<<"player "<< index << " won the game.";
}
