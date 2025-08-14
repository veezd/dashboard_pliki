import QtQuick 2.15

Item {
    id: root
    width: 300
    height: 100
    Rectangle{
        color: "#efa4a4"
        anchors.fill : parent


        Text{
            text: qsTr(mileage.value + " km")
            topPadding: 0
            anchors.centerIn: parent
        }
    }
}
