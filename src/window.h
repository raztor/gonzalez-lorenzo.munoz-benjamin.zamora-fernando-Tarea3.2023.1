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
    int getZone();
    bool isClosed();
private:
    MagneticSensor magneticSensor;
};

#endif // WINDOW_H
