#include "system.h"
#include <QQmlContext>

double decodeRawData(const deviceInfo* devInfo) {
    if (devInfo->specs.dataType == "uint") { return static_cast<uint>(devInfo->rawData) * devInfo->specs.factor + devInfo->specs.offset; } 
    if (devInfo->specs.dataType == "int") { return static_cast<int>(devInfo->rawData) * devInfo->specs.factor + devInfo->specs.offset; } 
    if (devInfo->specs.dataType == "char") { return static_cast<char>(devInfo->rawData) * devInfo->specs.factor + devInfo->specs.offset; } 
    if (devInfo->specs.dataType == "bool") { return static_cast<bool>(devInfo->rawData) * devInfo->specs.factor + devInfo->specs.offset; } // Zakladam ze tu factor itd nie bedzie potrzebny
    else {
        std::cout << "Nieznany typ sygnału" << std::endl;
        return 0.0;
    }
}

void passToSystem(deviceInfo *devInfo, System* system){
    switch (devInfo->id) {
    case 0x10: { // Battery
        system->battery.setValue(decodeRawData(devInfo));
        break;
    }
    case 0x01: { // Temperature
        system->temperature.setValue(decodeRawData(devInfo));
        break;
    }
    case 0x02: { // Mileage
        system->mileage.setValue(decodeRawData(devInfo));
        break;
    }
    case 0x03: { // Speedometer
        system->speedometer.setValue(decodeRawData(devInfo));
        break;
    }
    case 0x04: { // Drivemode (char)
        system->drivemode.setValue(decodeRawData(devInfo));
        break;
    }
    case 0x05: { // Engine power
        system->engine_power.setValue(decodeRawData(devInfo));
        break;
    }
    case 0x06: { // Low beam
        system->low_beam.setValue(decodeRawData(devInfo));
        break;
    }
    case 0x07: { // High beam
        system->high_beam.setValue(decodeRawData(devInfo));
        break;
    }
    case 0x08: { // Parking lights
        system->parking_lights.setValue(decodeRawData(devInfo));
        break;
    }
    case 0x09: { // Hazard lights
        system->hazard_lights.setValue(decodeRawData(devInfo));
        break;
    }
    case 0x0A: { // Right blinker
        system->blinkerRight.newState(decodeRawData(devInfo));
        break;
    }
    case 0x0B: { // Left blinker
        system->blinkerLeft.newState(decodeRawData(devInfo));
        break;
    }
    case 0x0C: { // High temperature warning
        system->high_temperature.setValue(decodeRawData(devInfo));
        break;
    }
    case 0x0D: { // Engine failure
        system->engine_failure.setValue(decodeRawData(devInfo));
        break;
    }
    case 0x0E: { // Power failure
        system->power_failure.setValue(decodeRawData(devInfo));
        break;
    }
    case 0x0F: { // Cruise control
        system->cruise_control.setValue(decodeRawData(devInfo));
        break;
    }
}
}

System::System(QQmlApplicationEngine* engine, const std::string &bus_name) :
    run_(false),
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


void System::start() {
    run_ = true;
    deviceInfo devInfo;
    while (run_) {
        devInfo = can.readFrame();
        if (devInfo.id != 0) { // Jesli odczytane id jest rozne od 0 to znaczy ze ramka byla poprawna
            passToSystem(&devInfo, this);
        }
    }
}
