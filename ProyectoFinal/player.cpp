#include "player.h"

Player :: Player( )
{
    jugador = new QGraphicsPixmapItem( );
    QPixmap pp("C:/Users/juanj/Desktop/Proyecto Final/Images/goku1.png");
    jugador->setPixmap(pp);
    jugador->setPos(465, 500);
    jugador->setScale(0.30);
}

void Player :: keyPressEvent(QKeyEvent *event, int type){
    short int mult = (15)*(type);
    //qDebug( ) << mult;
    if (event->key( ) == Qt::Key_W) {
        jugador->moveBy(0, (-1)*(mult));
    }

    else if (event->key( ) == Qt::Key_S) {
        jugador->moveBy(0, mult);
    }

    else if (event->key( ) == Qt::Key_A) {
        jugador->moveBy((-1)*(mult), 0);
    }

    else if (event->key( ) == Qt::Key_D) {
        jugador->moveBy(mult, 0);
    }
    if(type == 1)qDebug( ) << "X : " << jugador->pos( ).x( ) << " // Y : " << jugador->pos( ).y( ) << " // ";
}

