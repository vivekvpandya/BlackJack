#ifndef CARDDRAWING_H
#define CARDDRAWING_H

#include <QWidget>

namespace Ui {
class CardDrawing;
}

class CardDrawing : public QWidget
{
    Q_OBJECT

public:
    explicit CardDrawing(QWidget *parent = 0);
    ~CardDrawing();
    void drawWithPixmap(QPixmap pixmap);

private:
    Ui::CardDrawing *ui;
};

#endif // CARDDRAWING_H
