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
    void disableHitFoldButton();
signals:
    void hitButtonPressed();
    void foldButtonPressed();

private slots:
    void on_hitButton_clicked();

    void on_foldButton_clicked();

private:
    Ui::PlayerDrawing *ui;
};

#endif // PLAYERDRAWING_H
