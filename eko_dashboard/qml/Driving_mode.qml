import QtQuick 2.15

Item {
    id : root
    width: 300
    height: 100
    Rectangle{
        color: "#ecec94"
        anchors.fill : parent

        Text{
            anchors.centerIn: parent
            text: drivemode.value
        }
    }
}
