#include "door.h"
#include "doorview.h"

Door::Door()
{

}
Door::Door(MagneticSensor * sensor, DoorView * v): magneticSensor(sensor), view(v) { // creo que va esto    : MagneticSensor(*sensor), DoorView(*v){
    view=v;
    magneticSensor=sensor;
    isClose=true;
    view->setDoorModel(this);
}
void Door::changeState() {
    if (magneticSensor->isClose()){
        isClose = false;
       magneticSensor->setSensorOpen();
       view->setOpen();
    }
    else{
       isClose = true;
       magneticSensor->setSensorClose();
       view->setClose();
    }

}

