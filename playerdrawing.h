#ifndef PLAYERDRAWING_H
#define PLAYERDRAWING_H

#include <QWidget>

namespace Ui {
class PlayerDrawing;
}

class PlayerDrawing : public QWidget
{
    Q_OBJECT

public:
    explicit PlayerDrawing(QWidget *parent = 0);
    ~PlayerDrawing();

private:
    Ui::PlayerDrawing *ui;
};

#endif // PLAYERDRAWING_H
