import QtQuick

Rectangle {
    id: surprisePage
    color: "#333333"


    Rectangle {
        id: backButton
        width: 48
        height: 48
        color: "#333333"
        anchors {
            top: parent.top
            left: parent.left
            topMargin: 16
            leftMargin: 16
        }

        Image {
            width: 24
            height: 24
            anchors {
                horizontalCenter: backButton.horizontalCenter
                verticalCenter: backButton.verticalCenter
            }
            source: "ui/assets/arrow-121-24.png"
        }
    }

    Rectangle {
        id: heroSection
        width: 200
        height: 111
        color: "#333333"
        anchors {
            centerIn: parent
        }

        Text {
            id: surprise

            anchors {
                top: heroSection.top
                horizontalCenter: parent.horizontalCenter
            }

            font {
                pixelSize: 28
                family: "Montserrat"
            }

            color: "#FFFFFF"
            text: "Surprise!!"
        }

        Rectangle {
            id: outputBorder
            color: "#333333"
            width: 200
            height: 48
            radius: 8

            border {
                width: 1
                color: "#FFFFFF"
            }

            anchors {
                top: surprise.bottom
                topMargin: 16
                left: parent.left
            }

            TextInput {
                id: output
                width: 200
                height: 40

                anchors {
                    top: outputBorder.top
                    topMargin: 8
                    left: outputBorder.left
                    leftMargin: 8
                }

                property string placeholderText: "Jupiter Ascending"

                font {
                    pixelSize: 16
                    family: "Montserrat"
                }

                color: "#FFFFFF"
                focus: true

                Text {
                        text: output.placeholderText

                        font {
                            pixelSize: 16
                            family: "Montserrat"
                        }

                        color: "#FFFFFF"
                        visible: !output.text && !output.activeFocus
                    }
            }
        }

    }
}
