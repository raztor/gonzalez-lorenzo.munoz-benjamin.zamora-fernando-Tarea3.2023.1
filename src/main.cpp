#include "housewindow.h"
#include <QApplication>
#include <iostream>
#include <fstream>
#include <vector>
#include "door.h"
#include "doorview.h"
#include "window.h"
#include "windowview.h"
#include "central.h"
#include "centralview.h"
#include "sirenview.h"
using namespace std;
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HouseWindow gui;  // gui: Graphical User Interface
    Central central(nullptr);
    SirenView * sirenView = new SirenView();
    CentralView * centralView = new CentralView();
    centralView->setCentral(&central);
    central.setSirenView(sirenView);
    ifstream fin;
    int nDoors, nWindows;
    if (argc != 2) {
        cout << "Usage: "<<argv[0]<<" <configuration_file>" << endl;
        return -1;
    }
    fin.open(argv[1]);
    if (!fin){
        cout << "Could not read file" << endl;
        return -2;
    }
    cout << "Argument:" << argv[1] << endl;
    fin >> nDoors;
    fin >> nWindows;
    cout << "nDoors:" << nDoors << " nWindows: " << nWindows << endl;

    for( int i=0; i<nDoors; i++) {
        int x, y, angle, zone;
        fin >> x >> y >> angle >> zone;
        printf("Door %d: x=%d y=%d angle=%d zone=%d\n", i, x, y, angle, zone);
        MagneticSensor * sensor = new MagneticSensor(zone);
        DoorView * doorView = new DoorView(x,y,angle, sensor->getView());
        new Door(sensor, doorView);
        central.addNewSensor(sensor);
        gui.addHouseHollow(doorView);
    }
    for( int i=0; i<nWindows; i++) {
        int x, y, angle, zone;
        fin >> x >> y >> angle >> zone;
        printf("Window %d: x=%d y=%d angle=%d zone=%d\n", i, x, y, angle, zone);
        MagneticSensor * sensor = new MagneticSensor(zone);
        WindowView * windowView = new WindowView(x,y,angle, sensor->getView());
        new Window(sensor, windowView);
        central.addNewSensor(sensor);
        gui.addHouseHollow(windowView);
    }
    gui.addAlarmHollow(sirenView);
    gui.addAlarmHollow(centralView);
    gui.show();
    return a.exec();
}
