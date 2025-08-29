#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "clock.h"
#include "valueinfo.h"
#include "blinker.h"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    Clock clock_cpp;
    engine.rootContext()->setContextProperty("clock", &clock_cpp);

    ValueInfo battery_cpp(QVariant::fromValue<int>(0));
    battery_cpp.setValue(91);
    engine.rootContext()->setContextProperty("battery", &battery_cpp);

    ValueInfo temperature_cpp(QVariant::fromValue<int>(0));
    temperature_cpp.setValue(21);
    engine.rootContext()->setContextProperty("temperature", &temperature_cpp);

    ValueInfo mileage_cpp(QVariant::fromValue<uint>(0));
    mileage_cpp.setValue(131131231);
    engine.rootContext()->setContextProperty("mileage", &mileage_cpp);

    ValueInfo speedometer_cpp(QVariant::fromValue<uint>(0));
    speedometer_cpp.setValue(139);
    engine.rootContext()->setContextProperty("speedometer", &speedometer_cpp);

    ValueInfo drivemode_cpp(QVariant::fromValue<QString>("P"));
    drivemode_cpp.setValue("D");
    engine.rootContext()->setContextProperty("drivemode", &drivemode_cpp);

    ValueInfo engine_power_cpp(QVariant::fromValue<int>(0));
    engine_power_cpp.setValue(12);
    engine.rootContext()->setContextProperty("engine_power", &engine_power_cpp);

    // Światła / Lights #################################################################

    ValueInfo low_beam_cpp(QVariant::fromValue<bool>(false));
    ValueInfo high_beam_cpp(QVariant::fromValue<bool>(false));
    ValueInfo parking_lights_cpp(QVariant::fromValue<bool>(false));
    ValueInfo hazard_lights_cpp(QVariant::fromValue<bool>(false));

    Blinker blinkerRight_cpp;
    Blinker blinkerLeft_cpp;

    blinkerRight_cpp.newState(true);
    low_beam_cpp.setValue(true);



    engine.rootContext()->setContextProperty("low_beam", &low_beam_cpp);
    engine.rootContext()->setContextProperty("high_beam", &high_beam_cpp);
    engine.rootContext()->setContextProperty("parking_lights", &parking_lights_cpp);
    engine.rootContext()->setContextProperty("hazard_lights", &hazard_lights_cpp);
    engine.rootContext()->setContextProperty("blinkerRight", &blinkerRight_cpp);
    engine.rootContext()->setContextProperty("blinkerLeft", &blinkerLeft_cpp);

    // Ostrzeżenia / Warnings ###########################################################

    ValueInfo high_temperature_cpp(QVariant::fromValue<bool>(false));
    //ValueInfo open_door_cpp(QVariant::fromValue<bool>(false)); Narazie nie uzywamy
    ValueInfo engine_failure_cpp(QVariant::fromValue<bool>(false));
    ValueInfo power_failure_cpp(QVariant::fromValue<bool>(false));
    ValueInfo cruise_control_cpp(QVariant::fromValue<bool>(false));

    high_temperature_cpp.setValue(true);
    cruise_control_cpp.setValue(true);

    engine.rootContext()->setContextProperty("high_temperature", &high_temperature_cpp);
    //engine.rootContext()->setContextProperty("open_door", &open_door_cpp);
    engine.rootContext()->setContextProperty("engine_failure", &engine_failure_cpp);
    engine.rootContext()->setContextProperty("power_failure", &power_failure_cpp);
    engine.rootContext()->setContextProperty("cruise_control", &cruise_control_cpp);


    engine.load(QUrl("qrc:/qml/Main.qml"));

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
