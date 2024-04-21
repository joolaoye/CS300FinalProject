import QtQuick

Rectangle {
    id: enterNumberPage
    color: "#333333"


    Rectangle {
        id: heroSection
        width: 211
        height: 111
        color: "#333333"
        anchors {
            centerIn: parent
        }

        Text {
            id: prompt

            anchors {
                top: heroSection.top
                left: parent.left
            }

            font {
                pixelSize: 28
                family: "Montserrat"
            }

            color: "#FFFFFF"
            text: "Enter a number"
        }

        Rectangle {
            id: inputBorder
            color: "#333333"
            width: 140
            height: 48
            radius: 8

            property bool isInputValid: false // Track if input is valid

            border {
                width: 1
                color: "#FFFFFF"
            }

            anchors {
                top: prompt.bottom
                topMargin: 16
                left: parent.left
            }

            TextInput {
                id: userInput
                width: 132
                height: 40

                anchors {
                    top: inputBorder.top
                    topMargin: 8
                    left: inputBorder.left
                    leftMargin: 8
                }

                property string placeholderText: "Type here"

                font {
                    pixelSize: 16
                    family: "Montserrat"
                }

                color: "#FFFFFF"
                focus: true

                onTextChanged: {
                    // Update the property to reflect whether there is input
                    inputBorder.isInputValid = userInput.text.trim() !== ""
                }

                Text {
                    text: userInput.placeholderText

                    font {
                        pixelSize: 16
                        family: "Montserrat"
                    }

                    color: "#FFFFFF"
                    visible: !userInput.text && !userInput.activeFocus
                }
            }
        }

        Rectangle {
            id: checkButton
            width: 48
            height: 48
            radius: 8
            color: (inputBorder.isInputValid && logicClass.isNumber(userInput.text)) ? "#1B7E25" : "#666666" // Change color based on input validity
            opacity:(inputBorder.isInputValid && logicClass.isNumber(userInput.text)) ? 1 : 0.5 // Change opacity based on input validity
            anchors {
                top: prompt.bottom
                topMargin: 16
                right: parent.right
            }

            Image {
                width: 24
                height: 24
                anchors {
                    horizontalCenter: checkButton.horizontalCenter
                    verticalCenter: checkButton.verticalCenter
                }
                source: "ui/assets/check-mark-24.png"
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    if ((inputBorder.isInputValid && logicClass.isNumber(userInput.text))) {
                        logicClass.setOutput("Yes")
                        activityStack.push("surprisePage.qml")
                    }

                }
            }
        }

    }
}
