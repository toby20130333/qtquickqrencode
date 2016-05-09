import QtQuick 2.0

Item {
    property alias myaliasTxt: myTxt.text
    function setText(str){
        myaliasTxt = str;
    }
    Text {
        id: myTxt
        anchors.fill: parent
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }
}
