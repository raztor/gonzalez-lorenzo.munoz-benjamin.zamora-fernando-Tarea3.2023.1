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


