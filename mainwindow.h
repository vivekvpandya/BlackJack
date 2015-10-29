#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class Table;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void gameDecider(Table *table);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
