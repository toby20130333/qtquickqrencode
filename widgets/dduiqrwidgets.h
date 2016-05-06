#ifndef DDUIQRWIDGETS_H
#define DDUIQRWIDGETS_H

#include "widgets_global.h"
#include <QResizeEvent>
#include "qrencode/3rd/qrencode.h"
#include <QPainter>
#include <QSize>
#include <QWidget>
#include <QPaintEvent>


class WIDGETSSHARED_EXPORT DDuiQRWidgets :
        public QWidget
{
    Q_OBJECT
    Q_DISABLE_COPY(DDuiQRWidgets)
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
    DDuiQRWidgets(QWidget *parent = 0);
    ~DDuiQRWidgets();

    ///
    /// \brief The QR_MODE enum
    /// 设置二维码的编码模式
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
    ///
    /// \brief The QR_LEVEL enum
    /// 设置二维码编码的识别质量的级别
    ///
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

    //设置需要编码的数据
    Q_INVOKABLE void setQrData(const QString& data);
    // 设置二维码的logo
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
    QString icon;
    QByteArray text;
    void saveCurViewToFile();
    void saveItemToFile();
private slots:
    void grabChanged();
protected:
    void paintEvent(QPaintEvent *e);
    void resizeEvent(QResizeEvent *e);
};

#endif // DDUIQRWIDGETS_H
