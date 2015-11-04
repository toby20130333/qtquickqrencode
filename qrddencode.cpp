#include "qrddencode.h"
#define QRENCODE_WEBSITE "www.heilqt.com"

QREnCode::QREnCode(QQuickItem *parent):
    QQuickPaintedItem(parent),m_grab(NULL)
{
    qrMargin =5;
    qrSize = QSize(128,128);
    qrForeground = QColor("#0E4963");
    qrBackground = QColor("white");
    qrCasesen = true;
    qrMode = MODE_8;
    qrLevel = LEVEL_Q;
    qrPercent = 0.23;
    qrLogo=QRENCODE_WEBSITE;
    qrData = QRENCODE_WEBSITE;
    qrFilePath = "";
    setSize(qrSize);
}

void QREnCode::paint(QPainter *painter)
{
    QRcode *qrcode = QRcode_encodeString(qrData.toUtf8() , 7, (QRecLevel)qrLevel, (QRencodeMode)qrMode, qrCasesen ? 1 : 0);
    QRect rect(0,0,qrSize.width(),qrSize.height());
    if(0 != qrcode) {
        unsigned char *point = qrcode->data;
        painter->setPen(Qt::NoPen);
        painter->setBrush(this->qrBackground);
        painter->drawRect(rect);
        double scale = (rect.width () - 2.0 * qrMargin) / qrcode->width;
        painter->setBrush(this->qrForeground);
        for (int y = 0; y < qrcode->width; y ++) {
            for (int x = 0; x < qrcode->width; x ++) {
                if (*point & 1) {
                    QRectF r(qrMargin + x * scale, qrMargin + y * scale, scale, scale);
                    painter->drawRects(&r, 1);
                }
                point ++;
            }
        }
        point = NULL;
        QRcode_free(qrcode);
        //if qr_logo is empty return

        painter->setBrush(QColor("#00ffffff"));
        double icon_width = (rect.width () - 2.0 * qrMargin) * qrPercent;
        double icon_height = icon_width;
        double wrap_x = (rect.width () - icon_width) / 2.0;
        double wrap_y = (rect.width () - icon_height) / 2.0;
        QRectF wrap(wrap_x - 5, wrap_y - 5, icon_width + 10, icon_height + 10);
        painter->drawRoundRect(wrap, 50, 50);
        if(qrLogo.isEmpty() || qrLogo == QRENCODE_WEBSITE){
            painter->drawText(wrap,QRENCODE_WEBSITE);
        }else{
            QPixmap image(qrLogo);
            QRectF target(wrap_x, wrap_y, icon_width, icon_height);
            QRectF source(0, 0, image.width (), image.height ());
            painter->drawPixmap (target, image, source);
        }
    }
}

QREnCode::~QREnCode()
{
}
QString QREnCode::qrDDData()
{
    if(qrData==""){
        return QRENCODE_WEBSITE;
    }else{
        return qrData;
    }
}
///
/// \brief QREnCode::qrDDLogo
/// \return set qrcode logo
///
QString QREnCode::qrDDLogo()
{
    if(qrLogo==""){
        return "";
    }else{
        return qrLogo.replace("qrc","");
    }
}

QSize QREnCode::qrDDSize()
{
    return qrSize;
}

QREnCode::QR_MODE QREnCode::qrDDMode()
{
    return qrMode;
}

QREnCode::QR_LEVEL QREnCode::qrDDLevel()
{
    return qrLevel;
}

bool QREnCode::qrDDCasesen()
{
    return qrCasesen;
}

int QREnCode::qrDDMargin()
{
    return qrMargin;
}

qreal QREnCode::qrDDPercent()
{
    return qrPercent;
}

QColor QREnCode::qrDDForeground()
{
    return qrForeground;
}

QColor QREnCode::qrDDBackground()
{
    return qrBackground;
}

void QREnCode::setQrData(const QString &data)
{
    if(qrData !=data){
        qrData = data;
        emit qrDataChanged(qrData);
    }
}

void QREnCode::setQrLogo(const QString &logo)
{
    if(qrLogo != logo){
        qrLogo = logo;
        emit qrLogoChanged(qrLogo);
    }
}

void QREnCode::setQrSize(QSize size)
{
    if(qrSize != size){
        qrSize = size;
        emit qrSizeChanged(qrSize);
    }
}

void QREnCode::setQrMode(QREnCode::QR_MODE mode)
{
    if(qrMode != mode){
        qrMode = mode;
        emit qrModeChanged(qrMode);
    }
}

void QREnCode::setQrLevel(QREnCode::QR_LEVEL level)
{
    if(qrLevel != level){
        qrLevel = level;
        emit qrLevelChanged(qrLevel);
    }
}

void QREnCode::setQrCasesen(bool casesen)
{
    if(qrCasesen != casesen){
        qrCasesen = casesen;
        emit qrCasesenChanged(qrCasesen);
    }
}

void QREnCode::setQrMargin(int margin)
{
    if(qrMargin != margin){
        qrMargin = margin;
        emit qrMarginChanged(qrMargin);
    }
}

void QREnCode::setQrPercent(qreal percent)
{
    if(qrPercent != percent){
        qrPercent = percent;
        emit qrPercentChanged(qrPercent);
    }
}

void QREnCode::setQrForeground(QColor forgb)
{
    if(qrForeground != forgb){
        qrForeground = forgb;
        emit qrForegroundChanged(qrForeground);
    }
}

void QREnCode::setQrBackground(QColor backgb)
{
    if(qrBackground != backgb){
        qrBackground = backgb;
        emit qrBackgroundChanged(qrBackground);
    }
}

void QREnCode::setQrSaveFile(const QString &filepath)
{
    qrFilePath = filepath;
    if(!qrFilePath.isEmpty()){
        saveItemToFile();
    }
}

void QREnCode::saveCurViewToFile()
{
    //创建文件
    QString str = qrFilePath;
    if(!str.endsWith(".png")){
        str.append(".png");
    }
    QFile file(str);
    if (!file.open(QIODevice::WriteOnly)){
        file.close();
        return;
    }
    //流方式写入文件
    QQuickWindow *window = this->window();
    if(window){
        QImage img = window->grabWindow();
        QByteArray ba;
        QBuffer buffer(&ba);
        buffer.open(QIODevice::WriteOnly);
        img.save(&buffer, "png");
        file.write(ba);
    }
}

void QREnCode::saveItemToFile()
{
    if(m_grab == NULL){
        m_grab = new QuickItemGrabber(this);
        connect(m_grab,SIGNAL(grabbed()),this,SLOT(grabChanged()));
    }
    m_grab->clear();
    m_grab->grab(this,QSize(this->width(),this->height()));
}

void QREnCode::grabChanged()
{
   if(m_grab->save(qrFilePath)){
       emit qrSaveFileChanged(QCoreApplication::applicationDirPath()+"/"+qrFilePath);
   }
}

