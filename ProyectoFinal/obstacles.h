#ifndef OBSTACLES_H
#define OBSTACLES_H
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QGraphicsRectItem>
#include <QDebug>
#include <QVector>
#include <QImage>
#include <QBrush>
#include <QPen>

class Obstacles
{
public:
    Obstacles( );
    void setPassengers(QGraphicsPixmapItem *);
    void setChairs(QGraphicsRectItem *);

    QVector <QGraphicsPixmapItem *> passengers;
    QVector <QGraphicsRectItem *> chairs;
};

#endif // OBSTACLES_H
