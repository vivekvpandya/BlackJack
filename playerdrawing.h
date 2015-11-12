#ifndef PLAYERDRAWING_H
#define PLAYERDRAWING_H

#include <QWidget>

class Card;

namespace Ui {
class PlayerDrawing;
}

class PlayerDrawing : public QWidget
{
    Q_OBJECT

public:
    explicit PlayerDrawing(QWidget *parent = 0);
    ~PlayerDrawing();
    void setPlayerName(QString name);
    void addCardtoStack(Card card);
    void enableHitFoldButton();
private:
    Ui::PlayerDrawing *ui;
};

#endif // PLAYERDRAWING_H
