#include "playerdrawing.h"
#include "ui_playerdrawing.h"

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
