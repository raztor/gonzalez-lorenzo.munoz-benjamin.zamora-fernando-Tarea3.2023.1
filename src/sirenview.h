//
// Created by benjamin on 18-06-23.
//

#ifndef T3_POO_SIRENVIEW_H
#define T3_POO_SIRENVIEW_H

#include <QObject>
#include <QGraphicsItemGroup>
#include <QGraphicsPolygonItem>
#include <QTimer>

class SirenView : public QObject, public QGraphicsItemGroup
{
Q_OBJECT

public:
    SirenView();
    void startBlinking();
    void stopBlinking();
    ~SirenView();

private:
    QGraphicsPolygonItem* siren;
    QTimer* timer;

private slots:
    void changeColor();
};



#endif //T3_POO_SIRENVIEW_H
