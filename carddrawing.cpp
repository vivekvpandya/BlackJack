#include "carddrawing.h"
#include "ui_carddrawing.h"

CardDrawing::CardDrawing(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CardDrawing)
{
    ui->setupUi(this);
}

CardDrawing::~CardDrawing()
{
    delete ui;
}

void CardDrawing::drawWithPixmap(QPixmap pixmap)
{
    ui->drawing->setPixmap(pixmap);
    ui->drawing->setScaledContents(true);
}
