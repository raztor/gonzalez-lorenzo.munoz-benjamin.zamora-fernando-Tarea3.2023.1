#include "housewindow.h"
#include "ui_housewindow.h"

HouseWindow::HouseWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::HouseWindow)
{
    ui->setupUi(this);
    ui->houseRegion->setScene(&interiorScene);
    ui->alarmRegion->setScene(&alarmScene);
}
void HouseWindow::addHouseHollow(QGraphicsItemGroup * compoundItem){
    interiorScene.addItem(compoundItem);
}

void HouseWindow::addAlarmHollow(QGraphicsItem * compoundItem)
{
    alarmScene.addItem(compoundItem);
}

HouseWindow::~HouseWindow()
{
    delete ui;
}

