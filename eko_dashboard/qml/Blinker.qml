import QtQuick 2.15

Item {
    property bool mirrored : false

    id: root
    width : 100
    height : width
    Image {
        source : "../images/greenArrow.png"
        anchors.fill : parent

        mirror : parent.mirrored
    }
}
