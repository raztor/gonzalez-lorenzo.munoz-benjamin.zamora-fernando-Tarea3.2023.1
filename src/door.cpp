#include "door.h"

Door::Door()
{

}
Door::Door(int zone): magneticSensor(zone) {
}
void Door::changeState() {
        if (magneticSensor.isClose())
        magneticSensor.setSensorOpen();
        else
        magneticSensor.setSensorClose();
}

int Door::getZone() {
    return magneticSensor.getZone();
}
bool Door::isClosed() {
    return magneticSensor.isClose();
}



