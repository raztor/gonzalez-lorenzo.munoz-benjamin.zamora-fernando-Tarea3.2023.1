#include "door.h"
#include "doorview.h"

Door::Door()
{

}
Door::Door(MagneticSensor * sensor, DoorView * v): ?? {
    isClose=true;
    view->setDoorModel(this);
}
void Door::changeState() {
    if (magneticSensor->isClose())
        magneticSensor->setSensorOpen();
    else
        magneticSensor->setSensorClose();
}

