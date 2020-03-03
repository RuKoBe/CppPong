#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QTimer *gameTimer = new QTimer(this);

private slots:
    void on_verticalScrollBar_valueChanged(int value);

    void on_btnStart_clicked();

    void addPoints(int points);

    void reset();

    void gameMethod();

    void showScore();

private:
    Ui::MainWindow *ui;
    int points = 0;
    int speed = 1;
    int gravity = 1;
    int refreshrate = 5;
    bool inBounceArea();

};

#endif // MAINWINDOW_H
