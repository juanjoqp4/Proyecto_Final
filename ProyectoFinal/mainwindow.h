#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QKeyEvent>

#include "player.h"
#include "obstacles.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void keyPressEvent(QKeyEvent *event);
    void BackGround( );
    void Passengers( );
    bool Impact(QGraphicsPixmapItem *);

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    Player *prot;
    Obstacles *walls;
};
#endif // MAINWINDOW_H
