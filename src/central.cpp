#include "central.h"
#include <iostream>

Central::Central(QObject *parent)
    : QObject(parent), timer(new QTimer(this)) {
    connect(timer, SIGNAL(timeout()), this, SLOT(checkZones()));
    timer ->start(200);
}
void Central::addNewSensor(Sensor * ps){
    zones.push_back(ps);
}
void Central::checkZones() {
    bool closeZones[zones.size()];
    checkCloseZones(closeZones);
    bool zoneOpen = false;
    for (uint i=0; i< zones.size(); i++) {
        if (!closeZones[i]) {
            zoneOpen = true;
            break;
        }
    }
    if (zoneOpen) {
        std::cout << "Alguna zona esta abierta." << std::endl;
    }
}

void Central::checkCloseZones(bool closeZones[]) {
    for (uint i = 0; i < zones.size(); i++) {
        closeZones[i] = zones[i]->isClose();
    }
}

Central::~Central(){
    delete timer;
}
