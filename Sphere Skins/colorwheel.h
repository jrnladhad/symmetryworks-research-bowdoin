#ifndef COLORWHEEL_H
#define COLORWHEEL_H

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <complex>
#include <time.h>

#include <QObject>
#include <QColor>
#include <QImage>
#include <QVector3D>

#include "geomath.h"

#define image_dim 3000

const unsigned int ICOS_FACES_SIZE = 20;
const unsigned int ZONE_VECT_SIZE = 32;

class ColorWheel : public QObject
{
    Q_OBJECT
    
public:
    // CONSTRUCTORS
    ColorWheel(QObject *parent = 0);
    
    // ACCESS FUNCTIONS
    QRgb operator() (std::complex<double> zin);
    void loadImage(QString filename);
    
    ColorWheel* clone();
    
    QColor getOverflowColor() { return overflowColor; }

    std::complex<double> getImagedataPoint() {return zDataPoint;}

    void setBeta(double x, double y) {beta.real(x); beta.imag(y);}

    int getCurrentSel() {return currentSel;}

    
private:
    
    // FUNCTIONAL VARIABLES
    int currentSel;
    QImage image;
    QColor overflowColor;
    int imageWidth;
    int imageHeight;
    std::complex<double> zDataPoint;
    std::complex<double> beta;
    
    // COLOR WHEEL FUNCTIONS
    QRgb ImageSquish(std::complex<double> zin);
    QRgb FromImageReverse(std::complex<double> zin);
    QRgb FromSphereImage(std::complex<double> zin);
    QRgb FromSphereImageT(std::complex<double> zin);
    QRgb FromSphereDMir(std::complex<double> zin);
    QRgb FromSphereHMir(std::complex<double> zin);
    QRgb FromSphereHNegMir(std::complex<double> zin);
    QRgb FromSphereRNegMir(std::complex<double> zin);
    QRgb DiskToSphere(std::complex<double> zin);
    QRgb FromImage(std::complex<double> zin);
    
    // COMPONENT VARIABLES
    QVector3D icosFaces[ICOS_FACES_SIZE] =
    {
        QVector3D(1.0/q3,1.0/q3,1.0/q3),
        QVector3D(gold/q3,(gold-1.0)/q3,0.0),
        QVector3D(0.0,gold/q3,(gold-1.0)/q3),
        QVector3D((gold-1.0)/q3,0.0,gold/q3),
        QVector3D(gold/q3,-(gold-1.0)/q3,0.0),
        QVector3D(0.0,gold/q3,-(gold-1.0)/q3),
        QVector3D(-(gold-1.0)/q3,0.0,gold/q3),
        QVector3D(1.0/q3,-1.0/q3,1.0/q3),
        QVector3D(1.0/q3,1.0/q3,-1.0/q3),
        QVector3D(-1.0/q3,1.0/q3,1.0/q3),
        QVector3D(-1.0/q3,1.0/q3,-1.0/q3),
        QVector3D(-1.0/q3,-1.0/q3,1.0/q3),
        QVector3D(1.0/q3,-1.0/q3,-1.0/q3),
        QVector3D(-gold/q3,(gold-1.0)/q3,0.0),
        QVector3D(0.0,-gold/q3,(gold-1.0)/q3),
        QVector3D((gold-1.0)/q3,0.0,-gold/q3),
        QVector3D(-gold/q3,-(gold-1.0)/q3,0.0),
        QVector3D(0.0,-gold/q3,-(gold-1.0)/q3),
        QVector3D(-(gold-1.0)/q3,0.0,-gold/q3),
        QVector3D(-1.0/q3,-1.0/q3,-1.0/q3)
    };
    
    QVector3D zoneVect[ZONE_VECT_SIZE];
    
    public slots:
    void setCurrent(int index);
    void changeOverflowColor(const QColor &color) { overflowColor = color; }
    
    
};

#endif // COLORWHEEL_H
