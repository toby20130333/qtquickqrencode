import QtQuick 2.3
import QtQuick.Window 2.2
import com.duoduo.components 1.0

Window {
    visible: true
    width: 228
    height: 228
    QtQuick2QREncode{
        id:qr
        anchors.fill: parent
        qrSize: Qt.size(width,width)
        anchors.centerIn: parent
        qrData:"www.heilqt.com" //encode contents
        qrForeground: "#29aee1" //encode color
        qrBackground: "#dddddd"
        qrMargin: 10
        qrMode: QtQuick2QREncode.MODE_8    //encode model
        qrLevel: QtQuick2QREncode.LEVEL_Q // encode level
        qrLogo: "qrc:/256.png" //or local path or qrc path but not network url
        onQrSaveFileChanged: {
            console.log("We get save file path is :"+qrfilepath)
        }
        onHeightChanged: {
            getSize();
        }
        onWidthChanged: {
           getSize();
        }
    }
    function getSize(){
        var w = Math.min(width,height);
        console.log("---------------w"+w);
        qr.qrSize = Qt.size(w,w);
    }

    //以下是测试text别名的使用
    Component.onCompleted: {
        tt.setText("欢迎二维码生成器....");
    }
    AliasText{
        id:tt
        anchors.centerIn: parent
        width: parent.width
        height: 30
    }
    MouseArea{
        id:saveMa
        anchors.fill: parent
        onClicked: {
            qr.setQrSaveFile("xxx.png");
        }
    }
}
