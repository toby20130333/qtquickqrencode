import QtQuick 2.3
import QtQuick.Window 2.2
import com.duoduo.components 1.0

Window {
    visible: true
    QtQuick2QREncode{
        id:qr
        width: 128
        height: 128
        qrSize: Qt.size(width,width)
        anchors.centerIn: parent
        qrData:"duoduozhijiao" //encode contents
        qrForeground: "#29aee1" //encode color
        qrBackground: "white"
        qrMargin: 2
        qrMode: QtQuick2QREncode.MODE_8    //encode model
        qrLevel: QtQuick2QREncode.LEVEL_Q // encode level
        qrLogo: "qrc:/256.png" //or local path or qrc path but not network url
        onQrSaveFileChanged: {
            console.log("We get save file path is :"+qrfilepath)
        }
    }
}
