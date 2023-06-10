#include "door.h"
#include "doorview.h"

Door::Door()
{

}
Door::Door(MagneticSensor * sensor, DoorView * v): ?? { // creo que va esto    : MagneticSensor(*sensor)
    isClose=true;
    view->setDoorModel(this);
}
void Door::changeState() {
    if (magneticSensor->isClose())
        magneticSensor->setSensorOpen();
    else
        magneticSensor->setSensorClose();
}

