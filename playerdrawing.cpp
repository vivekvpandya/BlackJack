#include "playerdrawing.h"
#include "ui_playerdrawing.h"
#include "carddrawing.h"
#include "card.h"

PlayerDrawing::PlayerDrawing(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlayerDrawing)
{
    ui->setupUi(this);
}

PlayerDrawing::~PlayerDrawing()
{
    delete ui;
}

void PlayerDrawing::setPlayerName(QString name)
{

    ui->playerName->setText(name);
}

void PlayerDrawing::addCardtoStack(Card card)
{
    CardDrawing *drawCard = new CardDrawing();
    QPixmap pixmap = QPixmap(QString::fromStdString(card.convert()));
    drawCard->drawWithPixmap(pixmap);
    ui->horizontalLayout->addWidget(drawCard);

}

void PlayerDrawing::enableHitFoldButton()
{
    ui->foldButton->setEnabled(true);
    ui->hitButton->setEnabled(true);
}

void PlayerDrawing::disableHitFoldButton()
{
    ui->foldButton->setEnabled(false);
    ui->hitButton->setEnabled(false);
}

void PlayerDrawing::on_hitButton_clicked()
{
    emit hitButtonPressed();
}

void PlayerDrawing::on_foldButton_clicked()
{
    emit foldButtonPressed();
}
