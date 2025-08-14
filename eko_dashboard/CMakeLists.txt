cmake_minimum_required(VERSION 3.16)

project(eko_dashboard VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.8)

qt_add_executable(appeko_dashboard

)

qt_add_qml_module(appeko_dashboard
    URI eko_dashboard
    VERSION 1.0
    QML_FILES
        qml/Main.qml
        qml/BatteryLevel.qml
        qml/Dashboard.qml
        qml/Current_gear.qml
        qml/Mileage.qml
        qml/Driving_mode.qml

    SOURCES


        QML_FILES qml/Clock.qml
        QML_FILES qml/Speedometer.qml
        SOURCES src/clock.cpp
        SOURCES inc/clock.h
        SOURCES
        QML_FILES qml/Temperature.qml
        SOURCES
        SOURCES
        SOURCES
        SOURCES
        SOURCES
        SOURCES
        RESOURCES
        SOURCES
        SOURCES
        SOURCES inc/blinker.h
        SOURCES src/blinker.cpp
        QML_FILES qml/Blinker.qml
        SOURCES
        SOURCES
        QML_FILES qml/Engine_power.qml
        SOURCES inc/valueinfo.h
        SOURCES src/valueinfo.cpp
        SOURCES
        QML_FILES qml/Lights.qml
        SOURCES src/main.cpp
        QML_FILES qml/Warnings.qml

)


include_directories(
    ./inc
)
# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appeko_dashboard PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appeko_dashboard
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appeko_dashboard
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appeko_dashboard
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
