#ifndef DDUIQRENCODE_H
#define DDUIQRENCODE_H

#include <QDeclarativeItem>
#include <QResizeEvent>
#include "qrencode/3rd/qrencode.h"
#include <QPainter>
#include <QCoreApplication>

class DDuiQREncode : public QDeclarativeItem
{
    Q_OBJECT
    Q_DISABLE_COPY(DDuiQREncode)
    Q_ENUMS(QR_MODE)
    Q_ENUMS(QR_LEVEL)

    Q_PROPERTY(QString qrData READ qrDDData WRITE setQrData NOTIFY qrDataChanged)
    Q_PROPERTY(QString qrLogo READ qrDDLogo WRITE setQrLogo NOTIFY qrLogoChanged)
    Q_PROPERTY(QSize qrSize READ qrDDSize WRITE setQrSize NOTIFY qrSizeChanged)
    Q_PROPERTY(QR_MODE qrMode READ qrDDMode WRITE setQrMode NOTIFY qrModeChanged)
    Q_PROPERTY(QR_LEVEL qrLevel READ qrDDLevel WRITE setQrLevel NOTIFY qrLevelChanged)
    Q_PROPERTY(bool qrCasesen READ qrDDCasesen WRITE setQrCasesen NOTIFY qrCasesenChanged)
    Q_PROPERTY(int qrMargin READ qrDDMargin WRITE setQrMargin NOTIFY qrMarginChanged)
    Q_PROPERTY(qreal qrPercent READ qrDDPercent WRITE setQrPercent NOTIFY qrPercentChanged)
    Q_PROPERTY(QColor qrForeground READ qrDDForeground WRITE setQrForeground NOTIFY qrForegroundChanged)
    Q_PROPERTY(QColor qrBackground READ qrDDBackground WRITE setQrBackground NOTIFY qrBackgroundChanged)
public:
    DDuiQREncode(QDeclarativeItem *parent = 0);
    ~DDuiQREncode();

    enum QR_MODE {
        MODE_NUL = QR_MODE_NUL,
        MODE_NUM = QR_MODE_NUM,
        MODE_AN = QR_MODE_AN,
        MODE_8 = QR_MODE_8,
        MODE_KANJI = QR_MODE_KANJI,
        MODE_STRUCTURE = QR_MODE_STRUCTURE,
        MODE_ECI = QR_MODE_ECI,
        MODE_FNC1FIRST = QR_MODE_FNC1FIRST,
        MODE_FNC1SECOND = QR_MODE_FNC1SECOND
    };
    enum QR_LEVEL {
        LEVEL_L = QR_ECLEVEL_L,
        LEVEL_M = QR_ECLEVEL_M,
        LEVEL_Q = QR_ECLEVEL_Q,
        LEVEL_H = QR_ECLEVEL_H
    };

    QString qrDDData();
    QString qrDDLogo();
    QSize    qrDDSize();
    QR_MODE qrDDMode();
    QR_LEVEL qrDDLevel();
    bool      qrDDCasesen();
    int        qrDDMargin();
    qreal    qrDDPercent();
    QColor qrDDForeground();
    QColor qrDDBackground();

    Q_INVOKABLE void setQrData(const QString& data);
    Q_INVOKABLE void setQrLogo(const QString& logo);
    Q_INVOKABLE void setQrSize(QSize mode);
    Q_INVOKABLE void setQrMode(QR_MODE mode);
    Q_INVOKABLE void setQrLevel(QR_LEVEL level);
    Q_INVOKABLE void setQrCasesen(bool casesen);
    Q_INVOKABLE void setQrMargin(int margin);
    Q_INVOKABLE void setQrPercent(qreal percent);
    Q_INVOKABLE void setQrForeground(QColor forgb);
    Q_INVOKABLE void setQrBackground(QColor backgb);
    Q_INVOKABLE void setQrSaveFile(const QString& filepath);

signals:
    void qrDataChanged(const QString& qrdata);
    void qrLogoChanged(const QString& qrlogo);
    void qrSizeChanged(const QSize& qrsize);
    void qrModeChanged(QR_MODE qrmodel);
    void qrLevelChanged(QR_LEVEL qrlevel);
    void qrCasesenChanged(bool qrcasesen);
    void qrMarginChanged(int qrmargin);
    void qrPercentChanged(qreal qrpercent);
    void qrForegroundChanged(const QColor& qrfg);
    void qrBackgroundChanged(const QColor& qrbg);
    void qrSaveFileChanged(const QString& qrfilepath);

private:
    QString qrData;
    QString qrLogo;
    QSize qrSize;
    QR_MODE qrMode;
    QR_LEVEL qrLevel;
    bool qrCasesen;
    int qrMargin;
    qreal qrPercent;
    QColor qrForeground;
    QColor qrBackground;
    QString qrFilePath;

//    QuickItemGrabber* m_grab;
    QString icon;
    QByteArray text;
    void saveCurViewToFile();
    void saveItemToFile();
private slots:
    void grabChanged();
protected:
    void paint(QPainter *, const QStyleOptionGraphicsItem *, QWidget *);
};

QML_DECLARE_TYPE(DDuiQREncode)

#endif // DDUIQRENCODE_H
