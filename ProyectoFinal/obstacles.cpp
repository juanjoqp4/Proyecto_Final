#include "obstacles.h"

Obstacles::Obstacles( )
{
    short int ancho = 170, largo = 290;
    QGraphicsRectItem *silla = new QGraphicsRectItem( );
    silla->setRect(0,0,ancho,largo);
    silla->setPos(687,210);

    QGraphicsRectItem *silla2 = new QGraphicsRectItem( );
    silla2->setRect(0,0,ancho,largo);
    silla2->setPos(687,615);

    QGraphicsRectItem *silla3 = new QGraphicsRectItem( );
    silla3->setRect(0,0,ancho,largo);
    silla3->setPos(150,210);

    QGraphicsRectItem *silla4 = new QGraphicsRectItem( );
    silla4->setRect(0,0,ancho,largo);
    silla4->setPos(150,615);

    chairs.append(silla);
    chairs.append(silla2);
    chairs.append(silla3);
    chairs.append(silla4);
}

void Obstacles::setPassengers(QGraphicsPixmapItem *pass)
{
    passengers.append(pass);
}
/*
void Obstacles::setChairs(QGraphicsRectItem *silla)
{
    chairs.append(silla);
}
*/
