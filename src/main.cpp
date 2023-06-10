#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "door.h"
#include "window.h"
using namespace std;

// recibe un vecto de puertas y uno de ventanas y comprueba si la zona a la que pertenecen esta abierta o cerrada
void checkZones(vector<Door *> doors, vector<Window *> windows) {
    vector<int> openZones;
    for (unsigned int i=0; i<doors.size(); i++) {
        if (!doors[i]->isClosed()) {
            // Revisa si la zona no esta en la lista de zonas abiertas
            // Si no esta, la agrega
            if(!(find(openZones.begin(), openZones.end(), doors[i]->getZone()) != openZones.end()))
                openZones.push_back(doors[i]->getZone());
        }
    }
    for (unsigned int i=0; i<windows.size(); i++) {
        if (!windows[i]->isClosed()) {
            // Revisa si la zona no esta en la lista de zonas abiertas
            // Si no esta, la agrega
            if(!(find(openZones.begin(), openZones.end(), windows[i]->getZone()) != openZones.end()))
                openZones.push_back(windows[i]->getZone());
        }
    }
    // Si no hay zonas abiertas printea "Zonas Cerradas", de lo contrario printea "Alguna zona esta aberta"
    // Podríamos mencionar exactamente que zona se encuentra abierta pero debido a las instrucciones del ejercicio solo lo haremos de este modo
    if (openZones.size() == 0)
        cout << "Zonas Cerradas" << endl;
    else
        cout << "Alguna zona esta abierta" << endl;
    
}



int main(int argc, char * argv[]) {
    ifstream fin;
    int nDoors, nWindows;
    vector<Door *> doors;
    vector<Window *> windows;
    if (argc != 2) {
        cout << "Usage: "<<argv[0]<<" <configuration_file>" << endl;
        return -1;
    }
    fin.open(argv[1]);
    if (fin.fail()){
        cout << "Could not read file" << endl;
        return -2;
    }
    cout << "Argument:" << argv[1] << endl;
    fin >> nDoors;
    fin >> nWindows;
    cout << "nDoors:" << nDoors << " nWindows: " << nWindows << endl;
    for( int i=0; i<nDoors; i++) {
        int zone;
        float x,y,angle;
        fin >> x >> y >> angle >> zone;
        doors.push_back(new Door(zone));
    }
    for (unsigned int i=0; i<doors.size(); i++) { //uint : unsigned int
        printf("Door %d\n", i);
        doors[i]->changeState();
        doors[i]->changeState();
    }
    for( int i=0; i<nWindows; i++) {
        int zone;
        float x,y,angle;
        fin >> x >> y >> angle >> zone;
        windows.push_back(new Window(zone));
    }
    for (unsigned int i=0; i<windows.size(); i++) {
        printf("Window %d\n", i);
        windows[i]->changeState();
        windows[i]->changeState();
    }
    checkZones(doors, windows);

    // Abre la/s puerta/s principal/es (la/s que pertenece/n a la zona 0)
    for (unsigned int i=0; i<doors.size(); i++) {
        if (doors[i]->getZone() == 0) {
            doors[i]->changeState();
            break;
        }
    }
    checkZones(doors, windows);
}
