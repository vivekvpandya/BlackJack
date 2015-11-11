#include "gridlayout.h"
#include "ui_gridlayout.h"
#include "deck.h"
#include "card.h"
#include "carddrawing.h"
#include "table.h"
#include "playerdrawing.h"
#include "player.h"

GridLayout::GridLayout(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GridLayout)
{
    ui->setupUi(this);
    Deck newDeck = Deck();
    Card randomCard = newDeck.popRandomCard();

//    Card randomCard5 = newDeck.popRandomCard();
//    CardDrawing *cardDraw5 = new CardDrawing();
//    QPixmap pix5 = QPixmap(QString::fromStdString(randomCard5.convert()));
//    cardDraw2->drawWithPixmap(pix5);
//    ui->player1Layout->addWidget(cardDraw5);

    Table table = Table();
    table.setCapacity(3);
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


    int row = 0;
    for(int i = 0 ;i<table.getCapacity();i++ )
    {   std::list<Player>::iterator playerIt = table.playerListBegin();
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

GridLayout::~GridLayout()
{
    delete ui;
}
