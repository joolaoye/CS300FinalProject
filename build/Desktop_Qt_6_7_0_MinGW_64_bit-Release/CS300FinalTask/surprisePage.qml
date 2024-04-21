import QtQuick


// The page to view the random movie
Rectangle {
    id: surprisePage
    color: "#333333"


    // Back button navigates to the previous page
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

        // Click interaction
        MouseArea {
            anchors.fill: parent
            onClicked: activityStack.pop() // Pop current screen from the stackview
        }
    }

    Rectangle {
        id: heroSection
        width: 300
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

        // Output container
        Rectangle {
            id: outputBorder
            color: "#333333"
            width: 300
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

            // Edit text for output
            TextInput {
                id: output
                width: contentWidth
                height: 40
                readOnly: true

                anchors {
                    top: outputBorder.top
                    topMargin: 8
                    left: outputBorder.left
                    leftMargin: 8
                }

                font {
                    pixelSize: 16
                    family: "Montserrat"
                }

                color: "#FFFFFF"
                focus: true

                // Text label for output
                Text {
                        text: logicClass.output;

                        font {
                            pixelSize: 14
                            family: "Montserrat"
                        }

                        color: "#FFFFFF"
                        visible: true
                    }
            }
        }
    }
}
