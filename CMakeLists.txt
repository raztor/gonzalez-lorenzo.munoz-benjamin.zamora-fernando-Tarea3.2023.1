cmake_minimum_required(VERSION 3.22)
project(T3_POO)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


# Incluye la carpeta src
INCLUDE_DIRECTORIES("src")

#copia el config.txt a la carpeta de compilación
#configure_file(config.txt config.txt COPYONLY)


# Busca las librerías de Qt5
find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        PrintSupport REQUIRED
        )

add_executable(T3_POO
        src/central.cpp
        src/door.cpp
        src/house.cpp
        src/doorview.cpp
        src/housewindow.cpp
        src/magneticsensor.cpp
        src/magneticsensorview.cpp
        src/main.cpp
        src/sensor.cpp
        src/windowview.cpp
        src/windowview.h
        src/windowview.cpp
        src/windowview.h src/window.cpp
        src/window.h src/centralview.cpp src/centralview.h src/sirenview.cpp src/sirenview.h)

# Agrega las librerías previamente encontradas
target_link_libraries(T3_POO
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt::PrintSupport
        )



