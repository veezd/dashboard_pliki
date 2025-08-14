import QtQuick 2.15


Item {
    id : root
    height: 100
    width:300
    Text {
        anchors.centerIn: parent
        text: clock.time
        font.pixelSize: 48
        font.bold : true
    }
}
