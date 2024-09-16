#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QPushButton;

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QPushButton *button1;
    QPushButton *button2;
    QPushButton *button3;
    QPushButton *button4;
    QPushButton *button5;
    QPushButton *button6;
    QPushButton *button7;
    QPushButton *button8;
    QPushButton *button9;

    QPushButton *resetButton;

    QString *turn = new QString("X");
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void reset();
    void takeTurn();
    void checkWin();
    void button1Clicked();
    void button2Clicked();
    void button3Clicked();
    void button4Clicked();
    void button5Clicked();
    void button6Clicked();
    void button7Clicked();
    void button8Clicked();
    void button9Clicked();
};
#endif // MAINWINDOW_H
