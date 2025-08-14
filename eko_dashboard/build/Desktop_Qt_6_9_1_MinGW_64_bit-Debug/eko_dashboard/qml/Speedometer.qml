import QtQuick 2.15

Item {
    id :root
    height : 490
    width : height


    Rectangle {
        id: speedmeter
        anchors.fill : parent
        color : "white"
        radius : parent.width/2



        Text {
                text: "Speed: " + Math.round(speedometer.value)
                anchors.top: parent.top
                anchors.horizontalCenter: parent.horizontalCenter
                font.pixelSize: 20

            }

        Image {
            id: needle
            x: 150
            y: 0

            source: "../images/needle.png"
            fillMode: Image.PreserveAspectFit

            transform : Rotation {
                origin.x : 150;
                origin.y : 300;
                angle: -120 + (240/150 * speedometer.value)
            }
        }


    }

}
