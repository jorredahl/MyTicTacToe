#include "mainwindow.h"

#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    QWidget *center = new QWidget();
    setCentralWidget(center);

    QVBoxLayout *mainLayout = new QVBoxLayout(center);

    QHBoxLayout *lineOne = new QHBoxLayout(center);
    QHBoxLayout *lineTwo = new QHBoxLayout(center);
    QHBoxLayout *lineThree = new QHBoxLayout(center);
    QHBoxLayout *resetLine = new QHBoxLayout(center);

    button1 = new QPushButton(" ");
    lineOne->addWidget(button1, 0, Qt::AlignCenter);
    connect(button1 , &QPushButton::clicked, this, &MainWindow::button1Clicked);

    button2 = new QPushButton(" ");
    lineOne->addWidget(button2, 0, Qt::AlignCenter);
    connect(button2 , &QPushButton::clicked, this, &MainWindow::button2Clicked);

    button3 = new QPushButton(" ");
    lineOne->addWidget(button3, 0, Qt::AlignCenter);
    connect(button3 , &QPushButton::clicked, this, &MainWindow::button3Clicked);

    button4 = new QPushButton(" ");
    lineTwo->addWidget(button4, 0, Qt::AlignCenter);
    connect(button4 , &QPushButton::clicked, this, &MainWindow::button4Clicked);

    button5 = new QPushButton(" ");
    lineTwo->addWidget(button5, 0, Qt::AlignCenter);
    connect(button5 , &QPushButton::clicked, this, &MainWindow::button5Clicked);

    button6 = new QPushButton(" ");
    lineTwo->addWidget(button6, 0, Qt::AlignCenter);
    connect(button6 , &QPushButton::clicked, this, &MainWindow::button6Clicked);

    button7 = new QPushButton(" ");
    lineThree->addWidget(button7, 0, Qt::AlignCenter);
    connect(button7 , &QPushButton::clicked, this, &MainWindow::button7Clicked);

    button8 = new QPushButton(" ");
    lineThree->addWidget(button8, 0, Qt::AlignCenter);
    connect(button8 , &QPushButton::clicked, this, &MainWindow::button8Clicked);

    button9 = new QPushButton(" ");
    lineThree->addWidget(button9, 0, Qt::AlignCenter);
    connect(button9 , &QPushButton::clicked, this, &MainWindow::button9Clicked);

    resetButton = new QPushButton("Reset");
    resetLine->addWidget(resetButton, 0, Qt::AlignCenter);
    connect(resetButton , &QPushButton::clicked, this, &MainWindow::reset);

    mainLayout->addLayout(lineOne);
    mainLayout->addLayout(lineTwo);
    mainLayout->addLayout(lineThree);
    mainLayout->addLayout(resetLine);
}

MainWindow::~MainWindow() {}

void MainWindow::reset(){
    button1->setEnabled(true);
    button1->setText(" ");
    button2->setEnabled(true);
    button2->setText(" ");
    button3->setEnabled(true);
    button3->setText(" ");
    button4->setEnabled(true);
    button4->setText(" ");
    button5->setEnabled(true);
    button5->setText(" ");
    button6->setEnabled(true);
    button6->setText(" ");
    button7->setEnabled(true);
    button7->setText(" ");
    button8->setEnabled(true);
    button8->setText(" ");
    button9->setEnabled(true);
    button9->setText(" ");
}

void MainWindow::takeTurn(){
    if (*turn == "X") {
        *turn = "O";
    } else {
        *turn = "X";
    }
}

void MainWindow::checkWin(){
    if (((button1->text() == "X") && (button2->text() == "X") && (button3->text() == "X")) ||
        ((button4->text() == "X") && (button5->text() == "X") && (button6->text() == "X")) ||
        ((button7->text() == "X") && (button8->text() == "X") && (button9->text() == "X")) ||
        ((button1->text() == "X") && (button4->text() == "X") && (button7->text() == "X")) ||
        ((button2->text() == "X") && (button5->text() == "X") && (button8->text() == "X")) ||
        ((button3->text() == "X") && (button6->text() == "X") && (button9->text() == "X")) ||
        ((button1->text() == "X") && (button5->text() == "X") && (button9->text() == "X")) ||
        ((button3->text() == "X") && (button5->text() == "X") && (button7->text() == "X"))) {
        QString msg; QTextStream out(&msg);

        out << "Team <b>X</b> Wins!<br/>";

        QTextEdit *edit = new QTextEdit();
        edit->setHtml(msg);
        edit->show();
        reset();
    } else if (((button1->text() == "O") && (button2->text() == "O") && (button3->text() == "O")) ||
               ((button4->text() == "O") && (button5->text() == "O") && (button6->text() == "O")) ||
               ((button7->text() == "O") && (button8->text() == "O") && (button9->text() == "O")) ||
               ((button1->text() == "O") && (button4->text() == "O") && (button7->text() == "O")) ||
               ((button2->text() == "O") && (button5->text() == "O") && (button8->text() == "O")) ||
               ((button3->text() == "O") && (button6->text() == "O") && (button9->text() == "O")) ||
               ((button1->text() == "O") && (button5->text() == "O") && (button9->text() == "O")) ||
               ((button3->text() == "O") && (button5->text() == "O") && (button7->text() == "O"))) {
        QString msg; QTextStream out(&msg);

        out << "Team <b>O</b> Wins!<br/>";

        QTextEdit *edit = new QTextEdit();
        edit->setHtml(msg);
        edit->show();
        reset();
    } else if ((button1->text() != " ") && (button2->text() != " ") && (button3->text() != " ") &&
               (button4->text() != " ") && (button5->text() != " ") && (button6->text() != " ") &&
               (button7->text() != " ") && (button8->text() != " ") && (button9->text() != " ")){
        QString msg; QTextStream out(&msg);

        out << "Tie Game! Try Again.<br/>";

        QTextEdit *edit = new QTextEdit();
        edit->setHtml(msg);
        edit->show();
        reset();
    }
}

void MainWindow::button1Clicked(){
    button1->setEnabled(false);
    button1->setText(*turn);
    takeTurn();
    checkWin();
}

void MainWindow::button2Clicked(){
    button2->setEnabled(false);
    button2->setText(*turn);
    takeTurn();
    checkWin();
}

void MainWindow::button3Clicked(){
    button3->setEnabled(false);
    button3->setText(*turn);
    takeTurn();
    checkWin();
}

void MainWindow::button4Clicked(){
    button4->setEnabled(false);
    button4->setText(*turn);
    takeTurn();
    checkWin();
}

void MainWindow::button5Clicked(){
    button5->setEnabled(false);
    button5->setText(*turn);
    takeTurn();
    checkWin();
}

void MainWindow::button6Clicked(){
    button6->setEnabled(false);
    button6->setText(*turn);
    takeTurn();
    checkWin();
}

void MainWindow::button7Clicked(){
    button7->setEnabled(false);
    button7->setText(*turn);
    takeTurn();
    checkWin();
}

void MainWindow::button8Clicked(){
    button8->setEnabled(false);
    button8->setText(*turn);
    takeTurn();
    checkWin();
}

void MainWindow::button9Clicked(){
    button9->setEnabled(false);
    button9->setText(*turn);
    takeTurn();
    checkWin();
}
