import QtQuick 2.15

Item {
    id: root

    Row{
        spacing: 20
        anchors.centerIn: parent
        Rectangle{
            id: highBeam
            height : 50
            width: height
            radius: width/2
            color : "red"
            opacity : high_beam.value // Tu wystepuję niejawna konwersja z bool 0-1 do double 0.0 - 1.0
        }

        Rectangle{
            id: lowBeam
            height : 50
            width: height
            radius: width/2
            color : "yellow"
            opacity : low_beam.value
        }

        Rectangle{
            id: parkingLights
            height : 50
            width: height
            radius: width/2
            color : "green"
            opacity : parking_lights.value
        }

        Rectangle{
            id: hazardLights
            height : 50
            width: height
            radius: width/2
            color : "blue"
            opacity : hazard_lights.value
        }

    }
}
