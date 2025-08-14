import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
//import "./qml/BatteryLevel.qml"

Window {
    width: 300
    height: 300
    visible: true
    title: qsTr("Poziom baterii")
    Column {
            anchors.centerIn: parent
            spacing: 20

            Battery {

            }

        }
}
