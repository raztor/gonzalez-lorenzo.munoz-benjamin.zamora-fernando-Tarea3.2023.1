#include "magneticsensor.h"

MagneticSensor::MagneticSensor(int z): Sensor(z) {
    view = new MagneticSensorView();
}
void MagneticSensor::setSensorOpen() {
    setClose(false);
}
void MagneticSensor::setSensorClose() {
    setClose(true);
}
MagneticSensorView * MagneticSensor::getView() {
    return view;
}
MagneticSensor::~MagneticSensor(){
    delete view;
}
