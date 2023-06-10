cmake_minimum_required(VERSION 3.22)
project(T3_POO)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

INCLUDE_DIRECTORIES("src")


# Paquetes necesarios para la compilación
find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        PrintSupport REQUIRED
        )

add_executable(T3_POO src/main.cpp src/magnetic_sensor.cpp src/door.cpp src/sensor.cpp)

target_link_libraries(T3_POO
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt::PrintSupport
        )



