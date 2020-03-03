#ifndef GAMELOOP_H
#define GAMELOOP_H

#include <QThread>
#include <mainwindow.h>


class GameLoop :public QThread
{
protected:
    void run();
};

void GameLoop::run(){
    MainWindow::setPoints(100);
}

#endif // GAMELOOP_H
