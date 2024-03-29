#ifndef HOUSEWINDOW_H
#define HOUSEWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItemGroup>

QT_BEGIN_NAMESPACE
namespace Ui { class HouseWindow; }
QT_END_NAMESPACE

class HouseWindow : public QMainWindow
{
Q_OBJECT

public:
    HouseWindow(QWidget *parent = nullptr);
    void addHouseHollow(QGraphicsItemGroup * ); // doors and windows
    void addAlarmHollow(QGraphicsItem * compoundItem);
    ~HouseWindow();

private:
    Ui::HouseWindow *ui;
    QGraphicsScene interiorScene;
    QGraphicsScene alarmScene;
};

#endif // HOUSEWINDOW_H
