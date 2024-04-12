import QtQuick

Rectangle {
    id: landingPage
    color:"#333333"

    Rectangle {
        id: heroSection
        width: 524
        height: 202
        color: "#333333"
        anchors.centerIn: parent


        Text {
            id: displayText

            anchors {
                top: heroSection.top
                horizontalCenter: heroSection.horizontalCenter
            }

            font {
                pixelSize: 45
                family: "Montserrat"
                bold: true
            }

            color: "#FFFFFF"
            text: "Fantasy Movie"
        }

        Text {
            id: description

            anchors {
                top: displayText.bottom
                horizontalCenter: heroSection.horizontalCenter
                topMargin: 16
            }

            font {
                pixelSize: 22
                family: "Montserrat"
            }

            color: "#FFFFFF"
            text: "Enter a number to get a random movie recommendation"
        }


        Rectangle {
            id: startButton
            color: "#333333"
            width: 140
            height: 48
            radius: 8

            anchors {
                top: description.bottom
                topMargin: 16
                horizontalCenter: heroSection.horizontalCenter
            }

            border {
                width: 1
                color: "#FFFFFF"
            }

            Text {
                anchors.centerIn: startButton

                font {
                    pixelSize: 16
                    family: "Montserrat"
                }

                color: "#FFFFFF"
                text: "Start"
            }
        }
    }
}
