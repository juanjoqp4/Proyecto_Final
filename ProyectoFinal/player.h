#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QKeyEvent>
#include <QDebug>

class Player
{
public:
    Player( );
    void keyPressEvent(QKeyEvent *event, int);
    void Impact( );

    QGraphicsPixmapItem *jugador;
};

#endif // PLAYER_H
