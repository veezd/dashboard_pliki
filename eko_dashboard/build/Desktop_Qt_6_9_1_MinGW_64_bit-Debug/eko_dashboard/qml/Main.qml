import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15


Window {
    width: 1600
    height: 600
    visible: true
    title: qsTr("Ekran kierowcy")
    Column {
        anchors.centerIn: parent
        spacing: 20

        Dashboard{
            Row{
                BatteryLevel {
                    width: 250
                    height: 600
                }

                Column{
                    Row {
                        spacing : 100
                        Blinker {
                            width: 100
                            height: 100
                            mirrored : true
                            opacity : blinkerLeft.blinkState
                        }

                        Blinker {
                            width: 100
                            height: 100
                            opacity : blinkerRight.blinkState
                        }
                    }

                    Mileage {
                        width: 300
                        height: 100
                    }

                    Driving_mode {
                        width:300
                        height: 100
                    }

                    Clock{
                        width: 300
                        height: 100
                    }

                    Temperature {
                        id: outsideTemp
                        width: 300
                        height: 100
                    }

                    Engine_power{
                        id: engine
                        width: 300
                        height: 100
                    }

                }

                Speedometer{
                    width: 600
                    height: 600
                }

                Column{
                    Lights{
                        width:450
                        height:100
                    }

                    Warnings{
                        width:450
                        height:100
                    }
                }
            }
        }

        Slider {
            id:slider_battery
            from: 0
            stepSize: 1
            to: 100
            value: battery.value

            onValueChanged: {
                   battery.value = value
               }
        }

        Slider {
            id:slider_temp
            from: -80
            stepSize: 1
            to: 80
            value: temperature.value

            onValueChanged: {
                   temperature.value = value
               }
        }

        Button {
            id: mileage_button
            onClicked : mileage.setValue(mileage.value + 1)
            width: 100
            text: "+1 mileage"
        }

        Slider {
                id: speedSlider
                from: 0
                to: 150
                onMoved: speedometer.value = value
                value: speedometer.value  // tylko do aktualizacji wizualnej





        }




    }
}
