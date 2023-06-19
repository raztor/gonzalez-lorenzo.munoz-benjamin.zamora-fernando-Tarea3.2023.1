#include "door.h"
#include "doorview.h"

Door::Door()
{

}
Door::Door(MagneticSensor * sensor, DoorView * v){ // creo que va esto    : MagneticSensor(*sensor), DoorView(*v){
    view=v;
    magneticSensor=sensor;
    view->setDoorModel(this);
}
void Door::changeState() {
    if (magneticSensor->isClose()){
        magneticSensor->setSensorOpen();
        view->setOpen();
    }
    else{
        magneticSensor->setSensorClose();
        view->setClose();
    }

}

