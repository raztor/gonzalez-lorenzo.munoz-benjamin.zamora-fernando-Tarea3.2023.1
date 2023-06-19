//
// Created by benjamin on 18-06-23.
//

#include "centralview.h"
#include <QDebug>
#include <QGraphicsTextItem>
#include <QPen>

CentralView::CentralView()

{
    //Crea un timer
    arm = new QGraphicsRectItem(-20, 170, 40, 40, this);
    arm->setBrush(Qt::lightGray);


    QGraphicsTextItem *label1 = new QGraphicsTextItem("   P", this);
    label1->setPos(-20, 180);


    disarm = new QGraphicsRectItem(60, 170, 40, 40, this);
    disarm->setBrush(Qt::lightGray);


    QGraphicsTextItem *label2 = new QGraphicsTextItem("   D", this);
    label2->setPos(60, 180);


    BorderDisplay = new QGraphicsRectItem(-14, 120, 130, 30, this);

    QPen pen(Qt::black);
    pen.setWidth(2);
    BorderDisplay->setPen(pen);


    display = new QGraphicsTextItem(this);
    display->setPos(-10, 120);
    display->setDefaultTextColor(Qt::black);
    display->setPlainText("Desarmado");

}

void CentralView::setCentral(Central *c)
{
    central = c;
    central->setDisplay(display);
}
void CentralView::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        if (arm->contains(event->pos())) {
            if(!central->getEstadoAlarma()) {
                if (central->armable()) {
                    central->activarAlarma();
                    central->preAlarmaUpdateDisplay();
                } else {
                    // establece el texto de la zona abierta
                    central->preAlarmaUpdateDisplay();
                    central->desactivarAlarma();
                }
            }
        }
        else if (disarm->contains(event->pos())) {
            central->desactivarAlarma();
            display->setPlainText("Desarmado");
        }
    }

    QGraphicsItemGroup::mousePressEvent(event);
}





CentralView::~CentralView()
{
    delete arm;
    delete disarm;
}

