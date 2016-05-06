## [2016-05-05 update]QRCode Powered Support QWidgets And QML(qml1 and qml2) Module
Designing cool, interactive interfaces. DuoDuoZhijiao came up with a much better answer for QtQuick1QREncode: `QWidgets QML`, 
a Widget And a declarative language perfect for designing UIs (and much more). 
Here's a sample of how QtQuick1QREncode Plugin For QML looks like:

![Add Logo](http://7qn7mv.com1.z0.glb.clouddn.com/_ddui111.png)

![No Logo](http://7qn7mv.com1.z0.glb.clouddn.com/_ddui22.png)

```
//QML2 code
import QtQuick 2.3
import com.duoduo.component 1.0
    QtQuick1QREncode{
        id:qr
        width: 128
        height: 128
        qrSize: Qt.size(width,width)
        anchors.centerIn: parent
        qrData:"duoduozhijiao" //encode contents
        qrForeground: "#29aee1" //encode color
        qrBackground: "white"
        qrMargin: 2
        qrMode: QtQuick1QREncode.MODE_8    //encode model
		qrLevel: QtQuick1QREncode.LEVEL_Q // encode level
        qrLogo: "qrc:/256.png" //or local path or qrc path but not network url
        onQrSaveFileChanged: {
            console.log("We get save file path is :"+qrfilepath)
        }
    }
```

```
//qml1 Code:
import QtQuick 1.0 //notice here
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
```

```
//this is a widgets Code
#include <QApplication>
#include "dduiqrwidgets.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    DDuiQRWidgets w;
    w.resize(400,100);
    w.show();
    w.setQrSaveFile("xxx.png");
    return app.exec();
}
```

This project aims at bringing the power of QtQuick1QREncode to qml designer UI and widgets.


# Summary
* [How to build](#how-to-build)
* [How to use with QtQuick1QREncode](#how-to-use-with-qml-plugins)
* [How to extend](#how-to-extend)
* [Todo](#todo)

## How to Build
#### Add the source code  to your local machine on Mac Windows Linux.
#### Make Sure Setting your env for Qt SDK
#### Use Command
Git clone it.
Build it

```
make clean(mingw32-make clean)
qmake
make （mingw32-make mingw) | nmake(vc)
sudo make install (*unix)
```
## Use QtCreator
You may use qtcreator to build it.


## How to use with QtQuick1QREncode
Note that for the following, you need to have `Qt SDK` for Qt5.x or later installed.

#### QtQuick1QREncode
You can use QtQuick1QREncode to encode your QtQuick1QREncode UI.

```
import QtQuick 2.3
import com.duoduo.component 1.0
    QtQuick1QREncode{
        id:qr
        width: 128
        height: 128
        qrSize: Qt.size(width,width)
        anchors.centerIn: parent
        qrData:"duoduozhijiao" //encode contents
        qrForeground: "#29aee1" //encode color
        qrBackground: "white"
        qrMargin: 2
        qrMode: QtQuick1QREncode.MODE_8    //encode model
		qrLevel: QtQuick1QREncode.LEVEL_Q // encode level
        qrLogo: "qrc:/256.png" //or local path or qrc path but not network url
        onQrSaveFileChanged: {
            console.log("We get save file path is :"+qrfilepath)
        }
    }	
	//use this function also can save current item to file
	 function savetofile(obj,filename){
        obj.grabToImage(function(result) {
      result.saveToFile(filename);
    });
    }
```

#### Implemented  QML Extension USE C++ (QQmlExtensionPlugin)(Qt5.x or later)
Implemented a QML Extension module that:
- Refer to [http://doc.qt.io/qt-5/qqmlextensionplugin.html](http://doc.qt.io/qt-5/qqmlextensionplugin.html).

#### Implemented properties
- qrData           (QtQuick1QREncode data show)
- qrLogo     (QtQuick1QREncode middle logo)
- qrSize (QtQuick1QREncode size)
- qrMode    (mode )
- qrLevel (level )
- qrCasesen        (casesen upper)
- qrMargin   (margin)
- qrPercent   (percent)
- qrForeground   (qrForeground)
- qrBackground   (qrBackground)

#### Implemented signals
- Above all signals

#### Implemented slots and functions
- all Above slots
- setQrSaveFile(const QString& filePath) //can sava current QtQuick1QREncode to file


#### Implemented  QWidget Extension USE C++ (Qt5.x or later)
Implemented a QWidget Extension module that:
- Refer to how to build share libary

#### Implemented properties
- qrData           (QtQuick1QREncode data show)
- qrLogo     (QtQuick1QREncode middle logo)
- qrSize (QtQuick1QREncode size)
- qrMode    (mode )
- qrLevel (level )
- qrCasesen        (casesen upper)
- qrMargin   (margin)
- qrPercent   (percent)
- qrForeground   (qrForeground)
- qrBackground   (qrBackground)

#### Implemented signals
- Above all signals

#### Implemented slots and functions
- all Above slots
- setQrSaveFile(const QString& filePath) //can sava current QtQuick1QREncode to file


## FeedBack

Contact information

- Email(373955953#qq.com, Change#to@)
- QQ: 39559539234
- QQ Group:312125701
- github: [寒山-居士](https://github.com/toby20130333)


## Thanks

[https://github.com/penk/terrarium-app](https://github.com/penk/terrarium-app)

## About Author

```
  var duoduozhijiao = {
    nickName  : "寒山-居士",
    site : "http://www.heilqt.com",
    blog : "http://blog.heilqt.com"
  }
  ```
