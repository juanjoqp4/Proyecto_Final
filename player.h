#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QKeyEvent>
#include <QTimer>
#include <QDebug>

class Player
{
public slots:
    void Tired( );
public:
    Player( );
    void keyPressEvent(QKeyEvent *event, int);
    void Impact( );
    void Eat( );

    QGraphicsPixmapItem *jugador;
    short int energia = 100, hambre = 0, civismo = 100, estres = 0, dinero = 25, sopa = 3;

    QTimer *energCons;
};

#endif // PLAYER_H
