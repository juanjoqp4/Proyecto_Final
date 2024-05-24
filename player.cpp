#include "player.h"

Player :: Player( )
{
    jugador = new QGraphicsPixmapItem( );
    QPixmap pp("C:/Users/juanj/Desktop/Proyecto Final/Images/goku1.png");
    jugador->setPixmap(pp);
    jugador->setPos(465, 500);
    jugador->setScale(0.30);
    sell = true;
    energCons = new QTimer( );
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
    //if(type == 1)qDebug( ) << "X : " << jugador->pos( ).x( ) << " // Y : " << jugador->pos( ).y( ) << " // ";

    if((energia > 0) && (event->key( ) == Qt::Key_W) || (event->key( ) == Qt::Key_A) || (event->key( ) == Qt::Key_S) || (event->key( ) == Qt::Key_D)) energia--;
}

void Player::Eat( )
{
    energia += 20;
    sopa--;
    hambre -= 20;
    civismo -= 10;
}

void Player::Buy()
{
    civismo -= 10;
    sopa++;
    dinero -= 5;
}

void Player::Tired( ){
    hambre += 2;
    estres += 1;
    energia -= 1;
    if(estres > 60){
        QPixmap pp("C:/Users/juanj/Desktop/Proyecto Final/Images/goku4.png");           //CONFIGURAR PARA QUE INTERCAMBIE ASPECTOS ENTRE EL ESTRES
        jugador->setPixmap(pp);
    }
}
