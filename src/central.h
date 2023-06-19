#ifndef CENTRAL_H
#define CENTRAL_H
#include <QObject>
#include <vector>
#include <QTimer>
#include <QElapsedTimer>
#include "sensor.h"
#include "sirenview.h"
using namespace std; //needed by vector<>

class Central : public QObject
{
Q_OBJECT
public:
    explicit Central(QObject *parent);
    void addNewSensor(Sensor * ps);
    void desactivarAlarma();
    void activarAlarma();
    int getEstadoAlarma();
    bool armable();
    int getZonaAbierta();
    void setSirenView(SirenView * sirenview);
    void setDisplay(QGraphicsTextItem * display);
    void sonandoUpdateDisplay();
    void preAlarmaUpdateDisplay();
    ~Central();
signals:
private slots:
    int checkZones();
    bool AlarmaSonando();
    //void startBlinking();
    //
private:
    vector<Sensor *> zones;  // keep references to all sensors already installed in doors and windows.
    QTimer * timer;
    QElapsedTimer * timer2;
    int tipo_Alarma; // 0: desactivada, 1: perimetral
    SirenView * sirenview;
    QGraphicsTextItem * display;




};

#endif // CENTRAL_H
