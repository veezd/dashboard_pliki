import QtQuick 2.15

Item {
    id:root
    Row{
        spacing : 30
        anchors.centerIn: parent
        Rectangle{
            id:lowBattery
            height: 50
            width: height
            radius: width
            color: "pink"
            opacity: battery.value <= 10 ? 1.0 : 0.0 // Sprawdza obiekt battery_cpp
        }
        Rectangle{
            id:highTemp
            height: 50
            width: height
            radius: width
            color: "gray"
            opacity: high_temperature.value // Tu tez niejawna konwersja 0(false) -> 0.0
        }
        Rectangle{
            id:openDoor
            height: 50
            width: height
            radius: width
            color: "black"
            opacity: open_door.value
        }
        Rectangle{
            id:engFailure
            height: 50
            width: height
            radius: width
            color: "white"
            opacity: engine_failure.value
        }
        Rectangle{
            id:pwrFailure
            height: 50
            width: height
            radius: width
            color: "cyan"
            opacity: power_failure.value
        }
    }
}
