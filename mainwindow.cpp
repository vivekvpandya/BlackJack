#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "card.h"
#include "carddrawing.h"
#include "deck.h"
#include "player.h"
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

    Player player = Player("Vivek");
    player.setUnique_num(1);
    for(int i =0; i<43 ;i++)
        newDeck.popRandomCard();
    player.addCardToHand(newDeck.popRandomCard());
    player.addCardToHand(newDeck.popRandomCard());
    player.addCardToHand(newDeck.popRandomCard());
    player.addCardToHand(newDeck.popRandomCard());



    std::vector<Card> * playerHand = player.getCardHand();
    for(int itereator = 0; itereator!= playerHand->size(); itereator++){
        Card card = playerHand->at(itereator);
        qDebug()<<card.getValue()<<"\n";
        CardDrawing *cardDrawing = new CardDrawing();
        QPixmap pixmap = QPixmap(QString::fromStdString(card.convert()));
        cardDrawing->drawWithPixmap(pixmap);
        ui->player1Layout->addWidget(cardDrawing);
    }

    // To hide remaining player name
    ui->player2Name->hide();
    ui->player3Name->hide();
    ui->player4Name->hide();
    ui->player5Name->hide();
    ui->player1Name->setText(player.getName());


}

MainWindow::~MainWindow()
{
    delete ui;
}
