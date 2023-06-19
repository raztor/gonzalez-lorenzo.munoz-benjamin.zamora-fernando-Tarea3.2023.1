//
// Created by benjamin on 18-06-23.
//

#ifndef T3_POO_WINDOWVIEW_H
#define T3_POO_WINDOWVIEW_H

#include <QGraphicsItemGroup>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include "window.h"
#include "magneticsensorview.h"

class Window;

class WindowView : public QGraphicsItemGroup
{
public:
    explicit WindowView(int x, int y, int angle, MagneticSensorView * mv);
    void setWindowModel(Window * model);
    void setOpen();
    void setClose();
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void installMagneticSensor(MagneticSensorView & mv);
    ~WindowView();
private:
    void makeWindowView();
    Window * model;
    QGraphicsRectItem * slidingGlass;
    QGraphicsRectItem * fixedGlass;
    QGraphicsRectItem * switchPillar;
    QGraphicsRectItem * origenPillar;
    QGraphicsRectItem * magnet;
};



#endif //T3_POO_WINDOWVIEW_H
