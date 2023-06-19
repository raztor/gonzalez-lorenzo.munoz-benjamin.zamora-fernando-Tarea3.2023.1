//
// Created by benjamin on 18-06-23.
//

#ifndef T3_POO_WINDOW_H
#define T3_POO_WINDOW_H

#include "magneticsensor.h"

class WindowView;

class Window
{
private:
    Window();
public:
    Window(MagneticSensor * sensor, WindowView * v);
    void changeState();
private:
    MagneticSensor * magneticSensor;
    WindowView * view;
    bool isClose;
};


#endif //T3_POO_WINDOW_H
