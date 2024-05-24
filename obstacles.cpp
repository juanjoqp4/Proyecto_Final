#include "obstacles.h"

Obstacles::Obstacles( )
{
    short int ancho = 96, largo = 64;
    QPen lapiz(Qt :: blue, 5, Qt :: DashDotLine, Qt :: RoundCap, Qt :: RoundJoin);
    QGraphicsRectItem *silla = new QGraphicsRectItem( );
    silla->setRect(0,0,ancho,largo);
    silla->setPos(687,255);
    silla->setPen(lapiz);

    QGraphicsRectItem *silla2 = new QGraphicsRectItem( );
    silla2->setRect(0,0,ancho,largo);
    silla2->setPos(687,335);
    silla2->setPen(lapiz);

    QGraphicsRectItem *silla3 = new QGraphicsRectItem( );
    silla3->setRect(0,0,ancho,largo);
    silla3->setPos(687,415);
    silla3->setPen(lapiz);

    //Sillas parte inferior derecha

    QGraphicsRectItem *silla4 = new QGraphicsRectItem( );
    silla4->setRect(0,0,ancho,largo);
    silla4->setPos(687,660);
    silla4->setPen(lapiz);

    QGraphicsRectItem *silla5 = new QGraphicsRectItem( );
    silla5->setRect(0,0,ancho,largo);
    silla5->setPos(687,740);
    silla5->setPen(lapiz);

    QGraphicsRectItem *silla6 = new QGraphicsRectItem( );
    silla6->setRect(0,0,ancho,largo);
    silla6->setPos(687,830);
    silla6->setPen(lapiz);

    //Sillas parte superior izquierda
    QGraphicsRectItem *silla7 = new QGraphicsRectItem( );
    silla7->setRect(0,0,ancho,largo);
    silla7->setPos(237,255);
    silla7->setPen(lapiz);

    QGraphicsRectItem *silla8 = new QGraphicsRectItem( );
    silla8->setRect(0,0,ancho,largo);
    silla8->setPos(237,335);
    silla8->setPen(lapiz);

    QGraphicsRectItem *silla9 = new QGraphicsRectItem( );
    silla9->setRect(0,0,ancho,largo);
    silla9->setPos(237,415);
    silla9->setPen(lapiz);

    //Sillas parte inferior izquierda

    QGraphicsRectItem *silla10 = new QGraphicsRectItem( );
    silla10->setRect(0,0,ancho,largo);
    silla10->setPos(237,660);
    silla10->setPen(lapiz);

    QGraphicsRectItem *silla11 = new QGraphicsRectItem( );
    silla11->setRect(0,0,ancho,largo);
    silla11->setPos(237,740);
    silla11->setPen(lapiz);

    QGraphicsRectItem *silla12 = new QGraphicsRectItem( );
    silla12->setRect(0,0,ancho,largo);
    silla12->setPos(237,830);
    silla12->setPen(lapiz);

    chairs.append(silla);
    chairs.append(silla2);
    chairs.append(silla3);
    chairs.append(silla4);
    chairs.append(silla5);
    chairs.append(silla6);
    chairs.append(silla7);
    chairs.append(silla8);
    chairs.append(silla9);
    chairs.append(silla10);
    chairs.append(silla11);
    chairs.append(silla12);
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
