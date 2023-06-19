//
// Created by benjamin on 18-06-23.
//

#include <QBrush>
#include "sirenview.h"

SirenView::SirenView()
{
    siren = new QGraphicsPolygonItem(this);
    QPolygonF sirendraw;
    sirendraw.append(QPointF(0, 30));
    sirendraw.append(QPointF(0, 50));
    sirendraw.append(QPointF(40, 80));
    sirendraw.append(QPointF(40, 0));
    siren->setPolygon(sirendraw);
    siren->setBrush(Qt::green);
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &SirenView::changeColor);

}
void SirenView :: startBlinking(){
    timer-> start(100);
    //&SirenView::changeColor;
}
void SirenView :: stopBlinking(){
    timer -> stop();

}
SirenView::~SirenView()
{
    timer->stop();
    delete timer;
    delete siren;
}

void SirenView::changeColor()
{
    if (siren->brush() == Qt::green) {
        siren->setBrush(Qt::red);
    } else {
        siren->setBrush(Qt::green);
    }
}
