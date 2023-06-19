QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/central.cpp \
    src/door.cpp \
    src/window.cpp \
    src/windowview.cpp \
    src/doorview.cpp \
    src/housewindow.cpp \
    src/magneticsensor.cpp \
    src/magneticsensorview.cpp \
    src/main.cpp \
    src/sensor.cpp

HEADERS += \
    src/central.h \
    src/door.h \
    src/doorview.h \
    src/window.h \
    src/windowview.h \
    src/housewindow.h \
    src/magneticsensor.h \
    src/magneticsensorview.h \
    src/sensor.h

FORMS += \
    src/housewindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    src/config.txt

