//
// Created by benjamin on 18-06-23.
//

#include "windowview.h"
#include "window.h"
#include <QBrush>

WindowView::WindowView(int x, int y, int angle, MagneticSensorView * mv) {
    makeWindowView();
    mv->setParentItem(this);
    installMagneticSensor(*mv);
    magnet = &(mv->getMagnetView());
    QTransform transform;
    transform.translate(x, y);
    transform.rotate(angle);
    setTransform(transform);
}

void WindowView::makeWindowView() {
    origenPillar = new QGraphicsRectItem(-10,8, 20, 20, this);
    switchPillar = new QGraphicsRectItem(280, 8, 20, 20, this);
    slidingGlass = new QGraphicsRectItem(140, 18, 140, 8, this);
    fixedGlass = new QGraphicsRectItem(10, 10, 140, 8, this);
    origenPillar->setBrush(Qt::blue);
    switchPillar->setBrush(Qt::yellow);
    slidingGlass->setBrush(Qt::magenta);
    fixedGlass->setBrush(Qt::green);
    addToGroup(origenPillar);
    addToGroup(switchPillar);
    addToGroup(slidingGlass);
    addToGroup(fixedGlass);
}
void WindowView::installMagneticSensor(MagneticSensorView & mv){
    mv.getMagnetView().setRect(slidingGlass->rect().right()-mv.getMagnetView().rect().width(),
                               slidingGlass->rect().bottom(),
                               mv.getMagnetView().rect().width(),
                               mv.getMagnetView().rect().height());
    mv.getSwitchView().setRect(switchPillar->rect().right()-2.5*mv.getMagnetView().rect().width(),
                               switchPillar->rect().bottom(),
                               mv.getSwitchView().rect().width(),
                               mv.getSwitchView().rect().height());
    mv.getMagnetView().setTransformOriginPoint(slidingGlass->rect().x() + slidingGlass->rect().height()- slidingGlass->rect().height(), slidingGlass->rect().y() + slidingGlass->rect().height());

    addToGroup(&mv.getMagnetView());
    addToGroup(&mv.getSwitchView());
}

void WindowView::setWindowModel(Window *m) {
    model = m;
}

void WindowView::setOpen(){
    slidingGlass->setPos(fixedGlass->rect().x() - fixedGlass->rect().width(), 0);
    magnet->setPos(fixedGlass->rect().x() - fixedGlass->rect().width(), 0);
}

void WindowView::setClose(){
    slidingGlass->setPos(0, 0);
    magnet->setPos(0, 0);
}
void WindowView::mousePressEvent(QGraphicsSceneMouseEvent * event){
    if (model!= NULL && event->button()==Qt::LeftButton)
        model->changeState();
}

WindowView::~WindowView() {
    delete slidingGlass;
    delete switchPillar;
    delete fixedGlass;
    delete origenPillar;
}
