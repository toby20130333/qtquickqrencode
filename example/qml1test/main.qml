import QtQuick 1.0
import com.ddui.qmlcomponents 1.0

Item {
    width: 256
    height: width
    visible: true
    QtQuick1QREncode{
           id:qr
           anchors.fill: parent
           qrSize: Qt.size(width,width)
           qrData:"www.heilqt.com" //encode contents
           qrForeground: "#29aee1" //encode color
           qrBackground: "white"
           qrMargin: 4
           qrMode: QtQuick1QREncode.MODE_8    //encode model
           qrLevel: QtQuick1QREncode.LEVEL_Q // encode level
           qrLogo: "qrc:/Apple.png" //or local path or qrc path but not network url
           onQrSaveFileChanged: {
               console.log("We get save file path is :"+qrfilepath)
           }
           onQrSizeChanged:{
               console.log("Size get save file path is :"+qrsize.width)
           }
       }
    onWidthChanged: {
        if(width>height){
            qr.setQrSize(Qt.size(height,height))
        }else{
            qr.setQrSize(Qt.size(width,width))
        }
    }
}
