import QtQuick 2.15

Item {
    id: root
    property int level: 0

    Rectangle{
        id:battery_space //ten rectangle jest uzywany tylko w testach (do usuniecia)
        color:"#ed9f9f"
        width: 250
        height:600

        Rectangle {
            id: batteryOutline
            width: 50
            height: 200
            anchors.centerIn: parent
            color: "transparent"
            border.color: "black"
            border.width: 2
            radius: 5

            Rectangle {
                id: batteryFill
                x: 0
                y: batteryOutline.height - batteryFill.height
                width: parent.width
                height: battery.value *  batteryOutline.height / 100
                radius: 5
                border.color: "black"
                border.width: 2

                gradient: Gradient {
                    GradientStop{
                        position: 0.0
                        color: "#a8de99"
                    }
                    GradientStop{
                        position: 1.0
                        color: "#abdbdb"
                    }
                }
            }

            Text {
                anchors.centerIn: parent
                text: battery.value + "%"
                font.bold: true
            }
        }
    }
}
