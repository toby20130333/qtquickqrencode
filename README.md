## QRCode Powered QML Module
Designing cool, interactive interfaces. DuoDuoZhijiao came up with a much better answer for QRencode: `QML`, a declarative language perfect for designing UIs (and much more). Here's a sample of how QREncode Plugin For QML looks like:

![Add Logo](http://7qn7mv.com1.z0.glb.clouddn.com/_dduiencode.png)
![No Logo](http://7qn7mv.com1.z0.glb.clouddn.com/_dduiencode2.png)

```QML
import QtQuick 2.3
import com.duoduo.component 1.0
    QREnCode{
        id:qr
        width: 128
        height: 128
        qrSize: Qt.size(width,width)
        anchors.centerIn: parent
        qrData:"duoduozhijiao" //encode contents
        qrForeground: "#29aee1" //encode color
        qrBackground: "white"
        qrMargin: 2
        qrMode: QREnCode.MODE_8    //encode model
		qrLevel: QREnCode.LEVEL_Q // encode level
        qrLogo: "qrc:/256.png" //or local path or qrc path but not network url
        onQrSaveFileChanged: {
            console.log("We get save file path is :"+qrfilepath)
        }
    }
```

This project aims at bringing the power of qrencode to qml designer UI.


# Summary
* [How to build](#how-to-build)
* [How to use with QREnCode](#how-to-use-with-qml-plugins)
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


## How to use with QREnCode
Note that for the following, you need to have `Qt SDK` for Qt5.x or later installed.

#### QREnCode
You can use QREnCode to encode your qrencode UI.

```QML
import QtQuick 2.3
import com.duoduo.component 1.0
    QREnCode{
        id:qr
        width: 128
        height: 128
        qrSize: Qt.size(width,width)
        anchors.centerIn: parent
        qrData:"duoduozhijiao" //encode contents
        qrForeground: "#29aee1" //encode color
        qrBackground: "white"
        qrMargin: 2
        qrMode: QREnCode.MODE_8    //encode model
		qrLevel: QREnCode.LEVEL_Q // encode level
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

#### Implemented  QML Extension USE C++ (QQmlExtensionPlugin)
Implemented a QML Extension module that:
- Refer to [http://doc.qt.io/qt-5/qqmlextensionplugin.html](http://doc.qt.io/qt-5/qqmlextensionplugin.html).

#### Implemented properties
- qrData           (qrencode data show)
- qrLogo     (qrencode middle logo)
- qrSize (qrencode size)
- qrMode    (mode )
- qrLevel (level )
- qrCasesen        (casesen upper)
- qrMargin   (margin)
- qrPercent   (percent)
- qrForeground   (qrForeground)
- qrBackground   (qrBackground)

#### Implemented signals
Above all signals

#### Implemented slots and functions
- all Above slots
- setQrSaveFile(const QString& filePath) //can sava current qrencode to file


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
