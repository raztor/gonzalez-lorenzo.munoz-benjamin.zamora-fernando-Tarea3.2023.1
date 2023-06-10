#ifndef WINDOW_H
#define WINDOW_H
#include "magnetic_sensor.h"
class Window
{
private:
    Window(); // a door creation without sensor is not allowed.
public:
    Window(int zone);
    void changeState();
private:
    MagneticSensor magneticSensor;
};

#endif // WINDOW_H
