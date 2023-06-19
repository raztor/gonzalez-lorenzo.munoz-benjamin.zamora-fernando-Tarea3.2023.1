#include "central.h"
#include <iostream>


Central::Central(QObject *parent)
        : QObject(parent), timer(new QTimer(this)) {

    timer ->start(200);
    tipo_Alarma = 0;
}
void Central::addNewSensor(Sensor * ps){
    zones.push_back(ps);
}
int cont =0;
int Central::checkZones() {
    // Arreglo con las zonas y si estan abiertas o no
    int openZones[zones.size()];

    for (uint i=0; i< zones.size(); i++) {
        for(uint i=0; i< zones.size(); i++){
            if(!zones[i]->isClose()){
                if(tipo_Alarma==1){
                    if(cont==0) {
                        cont++;
                        connect(timer, SIGNAL(timeout()), this, SLOT(AlarmaSonando()));
                        sonandoUpdateDisplay();
                        sirenview->startBlinking();

                    }return 3;
                }
                int zone = zones[i]->getZone();
                cout << "Zone " << zone << " is open" << endl;
                if (openZones[zone] != 1){
                    openZones[zone] = 1;
                }
            }
        }
    }
    if(openZones[0] == 1 || openZones[1] == 1){
        cout << "Zona abierta" << endl;
        return 1;
    }return 0;
}

void Central::setSirenView(SirenView * sirenview){
    this->sirenview = sirenview;
}

bool Central::armable() {
    if (checkZones()==0) {
        return true;
    }
    preAlarmaUpdateDisplay();
    return false;
}

void Central::desactivarAlarma(){
    tipo_Alarma = 0;
    disconnect(timer, SIGNAL(timeout()), this, SLOT(checkZones()));
    disconnect(timer, SIGNAL(timeout()), this, SLOT(AlarmaSonando()));
    sirenview->stopBlinking();
    cont=0;
}
void Central::activarAlarma() {
    if (checkZones()==1) {
        cout << "Zona abierta, alarma no activada" << endl;
        return;
    } else {
        cout << "Alarma activada" << endl;
        tipo_Alarma = 1;
        connect(timer, SIGNAL(timeout()), this, SLOT(checkZones()));
    }
}

bool Central::AlarmaSonando() {
    cout << "Alarma sonando" << endl;
    disconnect(timer, SIGNAL(timeout()), this, SLOT(checkZones()));
    sonandoUpdateDisplay();
    return true;
}


int Central::getEstadoAlarma() {
    return tipo_Alarma;
}

Central::~Central(){
    delete timer;
}


int Central::getZonaAbierta() {
    int openZones[zones.size()];
    for (uint i=0; i< zones.size(); i++) {
        if(!zones[i]->isClose()){
            int zone = zones[i]->getZone();
            if (openZones[zone] != 1){
                openZones[zone] = 1;

            }
        }
    }
    if(openZones[0] == 1 && openZones[1] == 1) {
        return 2;
    }if(openZones[0] == 1){
        return 0;
    }else if(openZones[1] == 1){
        return 1;
    } return 999;
}

void Central::setDisplay(QGraphicsTextItem *display) {
    this->display = display;
}

void Central::sonandoUpdateDisplay() {
    // obtiene el numero de zona abierta
    int zona = getZonaAbierta();
    if(zona == 2){
        display->setPlainText("Alarma zona 0 y 1)");
    }else if(zona == 0||zona==1){
        QString texto = "Alarma zona:" + QString::number(zona);
        display->setPlainText(texto);
    }
}
void Central::preAlarmaUpdateDisplay() {
    //obtiene todas las zonas abiertas y las muestra en el display
    int zona = getZonaAbierta();
    if(zona == 2){
        display->setPlainText("Error: zona: 0 y 1");
    }else if(zona == 0||zona==1) {
        QString texto = "Error: zona:  " + QString::number(zona);
        display->setPlainText(texto);
    } else{
        display->setPlainText("Alarma armada");
    }
}


