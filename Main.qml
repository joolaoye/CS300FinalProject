import QtQuick
import QtQuick.Controls

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Fantasy Movie")

    // Keeps track of multiple screens
    StackView {
        id: activityStack
        anchors.fill: parent
        initialItem: "landingPage.qml"
    }
}
