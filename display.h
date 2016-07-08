#ifndef DISPLAY_H
#define DISPLAY_H

#include <QWidget>
#include <QImage>
#include <QColor>
#include <QPainter>
#include <QLabel>
#include <QPixmap>
#include <QDebug>
#include <QVector>

const double SCALE = 0.25;
const double MAX_PREVIEW_IMAGE_SIZE = 600;
const double MIN_PREVIEW_IMAGE_SIZE = 100;

class Display : public QWidget
{
    Q_OBJECT

public:
    explicit Display(int inputdim = 600, int imageDim = 200, QWidget *parent = 0);
    void setPixel(int i, int j, QRgb color);
    QSize sizeHint() const;
    int dim() const;
    QImage *getImage() { return &disp; }
    void shrink();
    void enlarge();
    int width() { return imageSize;}
    int height() { return imageSize;}
    void resetSize() {resize(imageSize, imageSize); update();}

protected:
    void paintEvent(QPaintEvent *event);
    // void resizeEvent(QPaintEvent *event) Q_DECL_OVERRIDE;


private:
    
    QImage disp;
    QVector<QVector<QRgb>> colorMap;
    int dimension;
    int imageSize;

    QPoint topLeft;
    QPoint bottomRight;
};



#endif // DISPLAY_H
