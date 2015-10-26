#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "card.h"
#include "carddrawing.h"
#include "deck.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Testing code for card drwaing
//
    Deck newDeck = Deck();
    Card randomCard = newDeck.popRandomCard();

    CardDrawing *cardDraw = new CardDrawing();
    QPixmap pix = QPixmap(QString::fromStdString(randomCard.convert()));
    cardDraw->drawWithPixmap(pix);
    ui->player1Layout->addWidget(cardDraw);
    Card randomCard2 = newDeck.popRandomCard();

    CardDrawing *cardDraw2 = new CardDrawing();
    QPixmap pix2 = QPixmap(QString::fromStdString(randomCard2.convert()));
    cardDraw2->drawWithPixmap(pix2);
    ui->player1Layout->addWidget(cardDraw2);


    Card randomCard3 = newDeck.popRandomCard();
    CardDrawing *cardDraw3 = new CardDrawing();
    QPixmap pix3 = QPixmap(QString::fromStdString(randomCard3.convert()));
    cardDraw3->drawWithPixmap(pix3);
    ui->player1Layout->addWidget(cardDraw3);

    Card randomCard4 = newDeck.popRandomCard();
    CardDrawing *cardDraw4 = new CardDrawing();
    QPixmap pix4 = QPixmap(QString::fromStdString(randomCard4.convert()));
    cardDraw4->drawWithPixmap(pix4);
    ui->player1Layout->addWidget(cardDraw4);

//    Card randomCard5 = newDeck.popRandomCard();
//    CardDrawing *cardDraw5 = new CardDrawing();
//    QPixmap pix5 = QPixmap(QString::fromStdString(randomCard5.convert()));
//    cardDraw2->drawWithPixmap(pix5);
//    ui->player1Layout->addWidget(cardDraw5);


}

MainWindow::~MainWindow()
{
    delete ui;
}
