import QtQuick 2.15

Item {
    id:root
    width: 300
    height: 100
    Rectangle{
        color: "white"
        anchors.fill : parent

        Text {
            id: temperature_string
            text: qsTr(temperature.value + "℃")
            anchors.centerIn: parent
        }
    }
}
