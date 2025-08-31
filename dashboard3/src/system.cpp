#include "system.h"

System::System(QQmlApplicationEngine* engine, const std::string &bus_name) :
    can(bus_name), 
    battery(QVariant::fromValue<int>(0)), 
    temperature(QVariant::fromValue<int>(0)),
    mileage(QVariant::fromValue<uint>(0)),
    speedometer(QVariant::fromValue<uint>(0)),
    drivemode(QVariant::fromValue<QString>("P")),
    engine_power(QVariant::fromValue<int>(0)),
    low_beam(QVariant::fromValue<bool>(false)),
    high_beam(QVariant::fromValue<bool>(false)),
    parking_lights(QVariant::fromValue<bool>(false)),
    hazard_lights(QVariant::fromValue<bool>(false)),
    high_temperature(QVariant::fromValue<bool>(false)),
    engine_failure(QVariant::fromValue<bool>(false)),
    power_failure(QVariant::fromValue<bool>(false)),
    cruise_control(QVariant::fromValue<bool>(false))
    //open_door(QVariant::fromValue<bool>(false)) Narazie nie uzywamy
    //blinker i clock maja konstruktory domyslne
{
    engine->rootContext()->setContextProperty("clock", &clock);
    engine->rootContext()->setContextProperty("battery", &battery);
    engine->rootContext()->setContextProperty("temperature", &temperature);
    engine->rootContext()->setContextProperty("mileage", &mileage);
    engine->rootContext()->setContextProperty("speedometer", &speedometer);
    engine->rootContext()->setContextProperty("drivemode", &drivemode);
    engine->rootContext()->setContextProperty("engine_power", &engine_power);
    engine->rootContext()->setContextProperty("low_beam", &low_beam);
    engine->rootContext()->setContextProperty("high_beam", &high_beam);
    engine->rootContext()->setContextProperty("parking_lights", &parking_lights);
    engine->rootContext()->setContextProperty("hazard_lights", &hazard_lights);
    engine->rootContext()->setContextProperty("blinkerRight", &blinkerRight);
    engine->rootContext()->setContextProperty("blinkerLeft", &blinkerLeft);
    engine->rootContext()->setContextProperty("high_temperature", &high_temperature);
    engine->rootContext()->setContextProperty("engine_failure", &engine_failure);
    engine->rootContext()->setContextProperty("power_failure", &power_failure);
    engine->rootContext()->setContextProperty("cruise_control", &cruise_control);
    //engine.rootContext()->setContextProperty("open_door", &open_door_cpp);
}
