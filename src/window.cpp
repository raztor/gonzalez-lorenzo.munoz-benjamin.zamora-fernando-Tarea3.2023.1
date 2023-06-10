#include "window.h"

Window::Window()
{

}
Window::Window(int zone): magneticSensor(zone) {
}
void Window::changeState() {
        if (magneticSensor.isClose())
        magneticSensor.setSensorOpen();
        else
        magneticSensor.setSensorClose();
}

int Window::getZone() {
    return magneticSensor.getZone();
}
bool Window::isClosed() {
    return magneticSensor.isClose();
}


