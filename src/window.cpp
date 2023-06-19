//
// Created by benjamin on 18-06-23.
//

#include "window.h"
#include "windowview.h"

Window::Window()
{

}
Window::Window(MagneticSensor * sensor, WindowView * v): magneticSensor(sensor), view(v) {
    isClose=true;
    view->setWindowModel(this);
}
void Window::changeState() {
    if (isClose) {
       isClose = false;
       magneticSensor->setSensorClose();
       view ->setClose();

    } else {
       isClose = true;
       magneticSensor->setSensorOpen();
       view ->setOpen();

    }
}
