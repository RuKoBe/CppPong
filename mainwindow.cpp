#include "mainwindow.h"
#include <thread>
#include <ui_mainwindow.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_verticalScrollBar_valueChanged(int value)
{
    ui->pnlBounce->move(ui->pnlBounce->pos().x(), value);
}

void MainWindow::on_btnStart_clicked()
{
    ui->btnStart->setDisabled(true);
    gameTimer->setInterval(refreshrate);
    connect(gameTimer, SIGNAL(timeout()), this, SLOT(gameMethod()));
    gameTimer->start(refreshrate);
}

void MainWindow::addPoints(int points){
    MainWindow::points += points;
    ui->lblPoints->setText("Punkte: " + QString::number(MainWindow::points));
}

void MainWindow::reset(){
    points = 0;
    ui->pnlBall->move(10,10);
    ui->verticalScrollBar->setValue(0);
    ui->btnStart->setDisabled(false);
}

void MainWindow::gameMethod(){
    QWidget *ball = ui->pnlBall;
    QWidget *pnl = ui->pnlGame;
    int ballLocationY = ball->pos().y();
    int ballLocationX = ball->pos().x();

    if(ballLocationX + speed + 30 <= ui->pnlGame->width() && ballLocationX + speed > 0 && ballLocationY + gravity > 0 && ballLocationY + gravity + 30 < pnl->height()){
        if(inBounceArea()){
                    addPoints(speed);
                    if(points%4 == 0 && speed < 3) speed++;
                    speed *= -1;
          }
        ball->move(ballLocationX + speed, ballLocationY + gravity);
    }else{
        if(ballLocationX + speed + 30 > ui->pnlGame->width()){
            gameTimer->stop();
            showScore();
            reset();
        }else if(ballLocationX + speed <= 0){
            speed *= -1;
        }

        if(ballLocationY + gravity <= 0 || ballLocationY + gravity + 30 >= pnl->height()){
            gravity *= -1;
        }
    }
}

void MainWindow::showScore(){
    ui->lblPoints->setText("Deine Punktzahl war: " + QString::number(points));
}

bool MainWindow::inBounceArea(){
    int x = ui->pnlBall->pos().x() + speed + 30- ui->pnlBounce->pos().x();
    int y = ui->pnlBall->pos().y() + gravity + 30 - ui->pnlBounce->pos().y();
    return x>=0 && x<=46 && y >= 0 && y<=100;
}
