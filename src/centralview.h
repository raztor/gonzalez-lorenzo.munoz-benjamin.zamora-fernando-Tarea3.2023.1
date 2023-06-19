//
// Created by benjamin on 18-06-23.
//

#ifndef T3_POO_CENTRALVIEW_H
#define T3_POO_CENTRALVIEW_H

#include "central.h"
#include <QGraphicsItemGroup>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>

class CentralView : public QGraphicsItemGroup
{
public:
    CentralView();
    void setCentral(Central *c);
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *);

    ~CentralView();


private:
    Central *central;
    QGraphicsRectItem *arm;
    QGraphicsRectItem *disarm;
    QGraphicsTextItem* display;
    QGraphicsRectItem * BorderDisplay;

};




#endif //T3_POO_CENTRALVIEW_H
