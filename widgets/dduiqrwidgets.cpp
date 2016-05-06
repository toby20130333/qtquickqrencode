#include "dduiqrwidgets.h"

#define DDuiQRWidgets_WEBSITE "www.heilqt.com"

DDuiQRWidgets::DDuiQRWidgets(QWidget *parent):
    QWidget(parent)
{
    qrMargin =5;
    qrSize = QSize(128,128);
    qrForeground = QColor("#0E4963");
    qrBackground = QColor("white");
    qrCasesen = true;
    qrMode = MODE_8;
    qrLevel = LEVEL_Q;
    qrPercent = 0.23;
    qrLogo=DDuiQRWidgets_WEBSITE;
    qrData = DDuiQRWidgets_WEBSITE;
    qrFilePath = "";
    resize(qrSize);
}


DDuiQRWidgets::~DDuiQRWidgets()
{
}

void DDuiQRWidgets::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    QRcode *qrcode = QRcode_encodeString(qrData.toUtf8() , 7, (QRecLevel)qrLevel, (QRencodeMode)qrMode, qrCasesen ? 1 : 0);
    QRect rect(0,0,qrSize.width(),qrSize.height());
    if(0 != qrcode) {
        unsigned char *point = qrcode->data;
        painter.setPen(Qt::NoPen);
        painter.setBrush(this->qrBackground);
        painter.drawRect(rect);
        double scale = (rect.width () - 2.0 * qrMargin) / qrcode->width;
        painter.setBrush(this->qrForeground);
        for (int y = 0; y < qrcode->width; y ++) {
            for (int x = 0; x < qrcode->width; x ++) {
                if (*point & 1) {
                    QRectF r(qrMargin + x * scale, qrMargin + y * scale, scale, scale);
                    painter.drawRects(&r, 1);
                }
                point ++;
            }
        }
        point = NULL;
        QRcode_free(qrcode);
        //if qr_logo is empty return

        painter.setBrush(QColor("#00ffffff"));
        double icon_width = (rect.width () - 2.0 * qrMargin) * qrPercent;
        double icon_height = icon_width;
        double wrap_x = (rect.width () - icon_width) / 2.0;
        double wrap_y = (rect.width () - icon_height) / 2.0;
        QRectF wrap(wrap_x - 5, wrap_y - 5, icon_width + 10, icon_height + 10);
        painter.drawRoundRect(wrap, 50, 50);
        if(qrLogo.isEmpty() || qrLogo == DDuiQRWidgets_WEBSITE){
            painter.save();
            QPen pen;
            pen.setColor(Qt::red);
            painter.setFont(QFont("微软雅黑",14));
            painter.setPen(pen);
            painter.drawText(wrap,DDuiQRWidgets_WEBSITE);
            painter.restore();
        }else{
            if(qrLogo.startsWith("qrc")){
                qrLogo = qrLogo.replace("qrc","");
            }
            QPixmap image(qrLogo);
            QRectF target(wrap_x, wrap_y, icon_width, icon_height);
            QRectF source(0, 0, image.width (), image.height ());
            painter.drawPixmap (target, image, source);
        }
    }
}

void DDuiQRWidgets::resizeEvent(QResizeEvent *e)
{
    if(e->size().isValid()){
        int w = this->size().width();
        int h = this->size().height();
        if(w>h){
            setQrSize(QSize(h,h));
        }else{
            setQrSize(QSize(w,w));
        }
    }
}


QString DDuiQRWidgets::qrDDData()
{
    if(qrData==""){
        return DDuiQRWidgets_WEBSITE;
    }else{
        return qrData;
    }
}
///
/// \brief DDuiQRWidgets::qrDDLogo
/// \return set qrcode logo
///
QString DDuiQRWidgets::qrDDLogo()
{
    if(qrLogo==""){
        return "";
    }else{
        return qrLogo.replace("qrc","");
    }
}

QSize DDuiQRWidgets::qrDDSize()
{
    return qrSize;
}

DDuiQRWidgets::QR_MODE DDuiQRWidgets::qrDDMode()
{
    return qrMode;
}

DDuiQRWidgets::QR_LEVEL DDuiQRWidgets::qrDDLevel()
{
    return qrLevel;
}

bool DDuiQRWidgets::qrDDCasesen()
{
    return qrCasesen;
}

int DDuiQRWidgets::qrDDMargin()
{
    return qrMargin;
}

qreal DDuiQRWidgets::qrDDPercent()
{
    return qrPercent;
}

QColor DDuiQRWidgets::qrDDForeground()
{
    return qrForeground;
}

QColor DDuiQRWidgets::qrDDBackground()
{
    return qrBackground;
}

void DDuiQRWidgets::setQrData(const QString &data)
{
    if(qrData !=data){
        qrData = data;
        emit qrDataChanged(qrData);
        update();
    }
}

void DDuiQRWidgets::setQrLogo(const QString &logo)
{
    if(qrLogo != logo){
        qrLogo = logo;
        emit qrLogoChanged(qrLogo);
        update();
    }
}

void DDuiQRWidgets::setQrSize(QSize size)
{
    if(qrSize != size){
        qrSize = size;
        emit qrSizeChanged(qrSize);
        update();
    }
}

void DDuiQRWidgets::setQrMode(DDuiQRWidgets::QR_MODE mode)
{
    if(qrMode != mode){
        qrMode = mode;
        emit qrModeChanged(qrMode);
        update();
    }
}

void DDuiQRWidgets::setQrLevel(DDuiQRWidgets::QR_LEVEL level)
{
    if(qrLevel != level){
        qrLevel = level;
        emit qrLevelChanged(qrLevel);
        update();
    }
}

void DDuiQRWidgets::setQrCasesen(bool casesen)
{
    if(qrCasesen != casesen){
        qrCasesen = casesen;
        emit qrCasesenChanged(qrCasesen);
        update();
    }
}

void DDuiQRWidgets::setQrMargin(int margin)
{
    if(qrMargin != margin){
        qrMargin = margin;
        emit qrMarginChanged(qrMargin);
        update();
    }
}

void DDuiQRWidgets::setQrPercent(qreal percent)
{
    if(qrPercent != percent){
        qrPercent = percent;
        emit qrPercentChanged(qrPercent);
        update();
    }
}

void DDuiQRWidgets::setQrForeground(QColor forgb)
{
    if(qrForeground != forgb){
        qrForeground = forgb;
        emit qrForegroundChanged(qrForeground);
        update();
    }
}

void DDuiQRWidgets::setQrBackground(QColor backgb)
{
    if(qrBackground != backgb){
        qrBackground = backgb;
        emit qrBackgroundChanged(qrBackground);
        update();
    }
}

void DDuiQRWidgets::setQrSaveFile(const QString &filepath)
{
    qrFilePath = filepath;
    if(!qrFilePath.isEmpty()){
        saveCurViewToFile();
    }
}

void DDuiQRWidgets::saveCurViewToFile()
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
    QRect rect(0,0,qrSize.width(),qrSize.height());
    QPixmap pixmap(rect.size());
    this->render(&pixmap, QPoint(), QRegion(rect));
    pixmap.save(str);
}

void DDuiQRWidgets::saveItemToFile()
{
    //    if(m_grab == NULL){
    //        m_grab = new QuickItemGrabber(this);
    //        connect(m_grab,SIGNAL(grabbed()),this,SLOT(grabChanged()));
    //    }
    //    m_grab->clear();
    //    m_grab->grab(this,QSize(this->width(),this->height()));
}

void DDuiQRWidgets::grabChanged()
{
    //   if(m_grab->save(qrFilePath)){
    //       emit qrSaveFileChanged(QCoreApplication::applicationDirPath()+"/"+qrFilePath);
    //   }
}

