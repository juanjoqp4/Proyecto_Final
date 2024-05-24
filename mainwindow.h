#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QKeyEvent>
#include <QTimer>
#include <QVector>

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
    void ActBars( );

private slots:
    void Travel( );
    void Board( );
    void TiredInt( );
    void on_eat_released( );

    void on_buysopa_released();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    Player *prot;
    Obstacles *walls;

    QVector <QString> stations;
    QTimer *traveltime, *travelstop;
    unsigned short int actStation = 0, direction = 1, day = 1;
    bool sell;
};
#endif // MAINWINDOW_H
