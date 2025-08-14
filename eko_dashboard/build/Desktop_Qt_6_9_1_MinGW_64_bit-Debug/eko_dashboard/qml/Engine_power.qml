import QtQuick 2.15

Item {
    id : root
    Rectangle{
        width: 300
        height: 100
        color : "yellow"

        Text {
            anchors.centerIn: parent
            text: "Moc silnika " + engine_power.value
        }
    }
}
