#include "colorwheel.h"

ColorWheel::ColorWheel(QObject *parent) :
QObject(parent)
{
    currentSel = 0;
    image = QImage(image_dim, image_dim, QImage::Format_RGB32);
    image.fill(MAX_RGB);
    
    //initialize zoneVect
    zoneVect[0] = tilt(QVector3D(0.0,0.0,1.0));
    zoneVect[1] = tilt(QVector3D(0.0,0.0,-1.0));
    
    int m = 6;
    
    for(int i = 1; i < m; i++)
    {
        for(int j = 0; j < m; j++)
        {
            zoneVect[2+j+6*(i-1)] = tilt(QVector3D(cos(2.0*pi*float(j)/6.0)*sin(pi*i/m),sin(2.0*pi*j/6.0)*sin(pi*i/m),cos(pi*i/m)));
        }
    }
}

ColorWheel* ColorWheel::clone()
{
    
    ColorWheel *c = new ColorWheel();
    qDebug()<<currentSel<<"\n";
    c->setCurrent(this->currentSel);
    c->changeOverflowColor(this->getOverflowColor());
    
    if (!(this->image.isNull())) {
        c->image = this->image.copy();
    }
    return c;
}

QRgb ColorWheel::operator() (std::complex<double> zin)
{
    QRgb col;
    
    switch(currentSel)
    {
        case 0:
            col=ImageSquish(zin);
            break;
        case 1:
            col=FromSphereImage(zin);
            break;
        case 2:
            col=FromSphereImageT(zin);
            break;
        case 3:
            col=FromSphereDMir(zin);
            break;
        case 4:
            col=FromSphereRNegMir(zin);
            break;
        case 5:
            col=FromSphereHMir(zin);
            break;
        case 6:
            col=FromSphereHNegMir(zin);
            break;
        case 7:
            col=FromImageReverse(zin);
            break;
        case 8:
            col=DiskToSphere(zin);
            break;
        case 9:
            col=FromImage(zin);
            break;
    }
    
    return col;
}

void ColorWheel::loadImage(QString filename)
{
    QImage raw(filename);
    imageWidth = raw.width();
    imageHeight = raw.height();
    image = raw.scaled(imageWidth, imageHeight, Qt::IgnoreAspectRatio, Qt::FastTransformation);
}

QRgb ColorWheel::ImageSquish(std::complex<double> zin)
{
    double x = zin.real();
    double y = zin.imag();
    double denom = sqrt(1.0+0.5*x*x+0.5*y*y);
    x/=denom;
    y/=denom;
    double r = x*x+y*y;
    QColor color;

    if(x >= -2.0 && x < 2.0 && y >= -2.0 && y < 2.0)      //our image is defined within the Cartesian coordinates
    {                                                       // -2 <= x <= 2  and -2 <= y <= 2
        /*
         * My idea for getting the theta and phi values from the complex 2-D plane:
         *  1. Convert the cartesian coordinates to 3-D coordinates using the stereographic projection formula given on page 177 of Creating Symmetry.
         *  2. Use the X and Y coordiantes to obtain the theta value and having a local variable called rho for finding phi.
        */

        double X = (2*x)/(r*r+1);
        double Y = (2*y)/(r*r+1);
        double Z = (r*r-1)/(r*r+1);
        double rho = sqrt(X*X+Y*Y+Z*Z);
        double theta = qAtan2(y,x) + pi;
        double phi = qAcos(Z/rho);

        //This is a complex<double> type variable that stores the point and is used in renderthread to plot the points for the image data points.
        zDataPoint = theta + Eye*phi;

        int translated_x = (int) ((x + 2.0) * ((imageWidth - 1) / 4.0));
        int translated_y = (int) (imageHeight - 1) - ((y + 2.0) * ((imageHeight-1) / 4.0));

        color = image.pixel(translated_x, translated_y);
    }
    else{
        zDataPoint = 1000.0 + Eye*1000.0;
        color = overflowColor;
    }
    return color.rgb();
}

QRgb ColorWheel::FromSphereImage(std::complex<double> zin)
{
    double x = zin.real();
    double y = zin.imag();
    double r2=x*x+y*y;
    double r=qSqrt(r2);
    double theta=qAtan2(y,x)+pi;
    double phi=qAtan2(2.0*r ,r2-1);
    int translated_x;
    int translated_y;
    QRgb color;

    //This is a complex<double> type variable that stores the point and is used in renderthread to plot the points for the image data points.
    zDataPoint = theta + Eye*phi;

    translated_x = (int) ((imageWidth - 1)*(theta / (2.0*pi)));
    translated_y = (int) ((imageHeight - 1)*(phi/ pi));

    color = image.pixel(translated_x, translated_y);

    return color;
}

QRgb ColorWheel::FromSphereImageT(std::complex<double> zin)
{
    std::complex<double> zt = (zin - beta)/(beta*zin + 1.0);
    //std::complex<double> zt=(1.8*zin-1.0)/(zin+1.8);//1.38 would give 72 degrees;
    double x = zt.real();//zt is z-turned 60 degrees about y-axis on sphere
    double y = zt.imag();
    double r2=x*x+y*y;
    double r=qSqrt(r2);
    double theta=qAtan2(y,x)+pi;
    double phi=qAtan2(2.0*r ,r2-1);
    QRgb color;

    //This is a complex<double> type variable that stores the point and is used in renderthread to plot the points for the image data points.
   zDataPoint = theta + Eye*phi;

    int translated_x = (int) ((theta / (2.0*pi)) * (imageWidth - 1));
    int translated_y = (int) ((phi/ pi) * (imageHeight - 1));

    color = image.pixel(translated_x, translated_y);

    return color;
}

QRgb ColorWheel::FromSphereDMir(std::complex<double> zin)
{
    double x = zin.real();
    double y = zin.imag();
    double r2=x*x+y*y;
    double r=qSqrt(r2);
    double theta=qAtan2(y,x)+pi;
    double phi=qAtan2(2.0*r ,r2-1);
    if(theta<pi/2.0){theta=pi-theta;};
    if(theta>3*pi/2.0){theta=3*pi-theta;};
    QRgb color;

    //This is a complex<double> type variable that stores the point and is used in renderthread to plot the points for the image data points.
    zDataPoint = theta + Eye*phi;

    int translated_x = (int) ((imageWidth - 1)*(theta / (2.0*pi)));
    int translated_y = (int) ((imageHeight - 1)*(phi/ pi));

    color = image.pixel(translated_x, translated_y);

    return color;
}

QRgb ColorWheel::FromSphereRNegMir(std::complex<double> zin)
{
    double x = zin.real();
    double y = zin.imag();
    double r2=x*x+y*y;
    double r=qSqrt(r2);
    double theta=qAtan2(y,x)+pi;
    double phi=qAtan2(2.0*r ,r2-1);
    QRgb color;
    QRgb colorInv;
    int re,g,b;
    if(qAbs(theta-pi)<0.01){color = qRgb(210,231,255);}//cordon off values near pi/2 OR 3pi/2
    else{
    if(theta>pi){
        theta=theta-pi;//put highest half back to 1st half and negate

        //This is a complex<double> type variable that stores the point and is used in renderthread to plot the points for the image data points.
        zDataPoint = theta + Eye*phi;

        int translated_x = (int) ((imageWidth - 1)*(theta / (2.0*pi)));
        int translated_y = (int) ((imageHeight - 1)*(phi/ pi));
        colorInv = image.pixel(translated_x, translated_y);
        re=255-QColor(colorInv).red();
        g=255-QColor(colorInv).green();
        b=255-QColor(colorInv).blue();
        color = qRgb(re,g,b);
    }
    else{

        //This is a complex<double> type variable that stores the point and is used in renderthread to plot the points for the image data points.
        zDataPoint = theta + Eye*phi;

        int translated_x = (int) ((imageWidth - 1)*(theta / (2.0*pi)));
        int translated_y = (int) ((imageHeight - 1)*(phi/ pi));
       color = image.pixel(translated_x, translated_y);}
    }
    return color;
}

QRgb ColorWheel::FromSphereHMir(std::complex<double> zin)
{
    double x = zin.real();
    double y = zin.imag();
    double r2=x*x+y*y;
    double r=qSqrt(r2);
    double theta=qAtan2(y,x)+pi;
    double phi=qAtan2(2.0*r ,r2-1);
    QRgb color;
    if(theta>pi){theta=2.0*pi-theta;}//reflect high values into lower range and use pixels

    //This is a complex<double> type variable that stores the point and is used in renderthread to plot the points for the image data points.
    zDataPoint = theta + Eye*phi;

    int translated_x = (int) ((imageWidth - 1)*(theta / (2.0*pi)));
    int translated_y = (int) ((imageHeight - 1)*(phi/ pi));
    color = image.pixel(translated_x, translated_y);

    return color;
}

QRgb ColorWheel::FromSphereHNegMir(std::complex<double> zin)
{
    double x = zin.real();
    double y = zin.imag();
    double r2=x*x+y*y;
    double r=qSqrt(r2);
    double theta=qAtan2(y,x)+pi;
    double phi=qAtan2(2.0*r ,r2-1);
    QRgb color;
    QRgb colorInv;
    int re,g,b;
    if(qAbs(theta-pi)<0.08){color = qRgb(0,0,0);}
    else{

        if(theta>pi){
            theta=2*pi-theta;//reflect values above pi to values below pi and use positive colors

            //This is a complex<double> type variable that stores the point and is used in renderthread to plot the points for the image data points.
            zDataPoint = theta + Eye*phi;

            int translated_x = (int) ((imageWidth - 1)*(theta / (2.0*pi)));
            int translated_y = (int) ((imageHeight - 1))*(phi/ pi);
            color = image.pixel(translated_x, translated_y);
        }//Otherwise, use negative colors
        else{

            //This is a complex<double> type variable that stores the point and is used in renderthread to plot the points for the image data points.
            zDataPoint = theta + Eye*phi;

            int translated_x = (int) ((imageWidth - 1)*(theta / (2.0*pi)));
            int translated_y = (int) ((imageHeight - 1)*(phi/ pi)  );
            colorInv = image.pixel(translated_x, translated_y);
            re=255-QColor(colorInv).red();
            g=255-QColor(colorInv).green();
            b=255-QColor(colorInv).blue();
            color=qRgb(re,g,b);
          }
    }

    return color;
}

QRgb ColorWheel::FromImageReverse(std::complex<double> zin)
{
    double x = zin.real();
    double y = zin.imag();
    double r2=x*x+y*y;
    QRgb color;
    QRgb colorInv;
    int r,g,b;

    /*
     * My idea for getting the theta and phi values from the complex 2-D plane:
     *  1. Convert the cartesian coordinates to 3-D coordinates using the stereographic projection formula given on page 177 of Creating Symmetry.
     *  2. Use the X and Y coordiantes to obtain the theta value and having a local variable called rho for finding phi.
    */

    if(r2<1)      //do the usual routine for complex numbers inside unit circle
    {
        double X = (2*x)/(r2*r2+1);
        double Y = (2*y)/(r2*r2+1);
        double Z = (r2*r2-1)/(r2*r2+1);
        double rho = sqrt(X*X+Y*Y+Z*Z);
        double theta = qAtan2(y,x) + pi;
        double phi = qAcos(Z/rho);

        //This is a complex<double> type variable that stores the point and is used in renderthread to plot the points for the image data points.
        zDataPoint = theta +Eye*phi;

        int translated_x = (int) ((x + 1.0) * ((imageWidth - 1) / 2.0));
        int translated_y = (int) (imageHeight - 1) - ((y + 1.0) * ((imageHeight - 1) / 2.0));

        color = image.pixel(translated_x, translated_y);
    }
    else{
        std::complex<double> zinv=pow(zin,-1.0);
        x=zinv.real();
        y=zinv.imag();
        double X = (2*x)/(r2*r2+1);
        double Y = (2*y)/(r2*r2+1);
        double Z = (r2*r2-1)/(r2*r2+1);
        double rho = sqrt(X*X+Y*Y+Z*Z);
        double theta = qAtan2(y,x) + pi;
        double phi = qAcos(Z/rho);

        //This is a complex<double> type variable that stores the point and is used in renderthread to plot the points for the image data points.
        zDataPoint = theta +Eye*phi;

        int translated_x = (int) ((x + 1.0) * ((imageWidth - 1) / 2.0));
        int translated_y = (int) (imageHeight - 1) - ((y + 1.0) * ((imageHeight - 1) / 2.0));
        colorInv = image.pixel(translated_x, translated_y);
         r=255-QColor(colorInv).red();
         g=255-QColor(colorInv).green();
         b=255-QColor(colorInv).blue();
        color=qRgb(r,g,b);}

    return color;
}

QRgb ColorWheel::DiskToSphere(std::complex<double> zin)
{
    double x = zin.real();
    double y = zin.imag();
    double r2=x*x+y*y;
    QRgb color;

    /*
     * My idea for getting the theta and phi values from the complex 2-D plane:
     *  1. Convert the cartesian coordinates to 3-D coordinates using the stereographic projection formula given on page 177 of Creating Symmetry.
     *  2. Use the X and Y coordiantes to obtain the theta value and having a local variable called rho for finding phi.
    */

    if(r2<1)      //do the usual routine for complex numbers inside unit circle
    {
        double X = (2*x)/(r2*r2+1);
        double Y = (2*y)/(r2*r2+1);
        double Z = (r2*r2-1)/(r2*r2+1);
        double rho = sqrt(X*X+Y*Y+Z*Z);
        double theta = qAtan2(y,x) + pi;
        double phi = qAcos(Z/rho);

        //This is a complex<double> type variable that stores the point and is used in renderthread to plot the points for the image data points.
        zDataPoint = theta +Eye*phi;

        int translated_x = (int) ((x + 1.0) * ((imageWidth - 1) / 2.0));
        int translated_y = (int) (imageHeight - 1) - ((y + 1.0) * ((imageHeight - 1) / 2.0));
        color = image.pixel(translated_x, translated_y);
    }
    else{//do circle inversion for points outside, to make it conts
        std::complex<double> zinv=pow(zin,-1.0);
        double x1 = zinv.real();
        double y1 = 0.0-zinv.imag();
        double X = (2*x)/(r2*r2+1);
        double Y = (2*y)/(r2*r2+1);
        double Z = (r2*r2-1)/(r2*r2+1);
        double rho = sqrt(X*X+Y*Y+Z*Z);
        double theta = qAtan2(y,x) + pi;
        double phi = qAcos(Z/rho);


        //This is a complex<double> type variable that stores the point and is used in renderthread to plot the points for the image data points.
        zDataPoint = theta +Eye*phi;

        int translated_x = (int) ((x1 + 1.0) * ((imageWidth - 1) / 2.0));
        int translated_y = (int) (imageHeight - 1) - ((y1 + 1.0) * ((imageHeight - 1) / 2.0));
        color = image.pixel(translated_x, translated_y);
        };

    return color;
}

QRgb ColorWheel::FromImage(std::complex<double> zin)
{
    double x = zin.real();
    double y = zin.imag();
    QColor color;

    /*
     * My idea for getting the theta and phi values from the complex 2-D plane:
     *  1. Convert the cartesian coordinates to 3-D coordinates using the stereographic projection formula given on page 177 of Creating Symmetry.
     *  2. Use the X and Y coordiantes to obtain the theta value and having a local variable called rho for finding phi.
    */

    if(x >= -2.0 && x < 2.0 && y >= -2.0 && y < 2.0)      //our image is defined within the Cartesian coordinates
    {                                                       // -2 <= x <= 2  and -2 <= y <= 2
        double r2=x*x+y*y;
        double X = (2*x)/(r2*r2+1);
        double Y = (2*y)/(r2*r2+1);
        double Z = (r2*r2-1)/(r2*r2+1);
        double rho = sqrt(X*X+Y*Y+Z*Z);
        double theta = qAtan2(y,x) + pi;
        double phi = qAcos(Z/rho);

        //This is a complex<double> type variable that stores the point and is used in renderthread to plot the points for the image data points.
        zDataPoint = theta +Eye*phi;

        int translated_x = (int) ((x + 2.0) * ((imageWidth - 1) / 4.0));
        int translated_y = (int) (imageHeight - 1) - ((y + 2.0) * ((imageHeight - 1) / 4.0));
        color = image.pixel(translated_x, translated_y);
    }
    else {
        zDataPoint = 1000.0 + Eye*1000.0;
        color = overflowColor;
    }
    return color.rgb();
}

void ColorWheel::setCurrent(int index)
{
    if(index >= 0 && index <= 9)
        currentSel = index;
}

