#include "colorwheel.h"

ColorWheel::ColorWheel(QObject *parent) :
QObject(parent)
{
    currentSel = 0;
    image = QImage(image_dim, image_dim, QImage::Format_ARGB32_Premultiplied);
    image.fill(MAX_RGB);
    
    //initialize zoneVect
    zoneVect[0] = tilt(QVector3D(0.0,0.0,1.0));
    zoneVect[1] = tilt(QVector3D(0.0,0.0,-1.0));
    
    int m = 6;
    
    for(int i = 1; i < m; i++)
    {
        for(int j = 0; j < m; j++)
            zoneVect[2+j+6*(i-1)] = tilt(QVector3D(cos(2.0*pi*float(j)/6.0)*sin(pi*i/m),sin(2.0*pi*j/6.0)*sin(pi*i/m),cos(pi*i/m)));
    }
}

//The function returns a pointer of type class ColorWheel.
ColorWheel* ColorWheel::clone()
{
    
    ColorWheel *c = new ColorWheel();
    
    c->setCurrent(this->currentSel);
    c->changeOverflowColor(this->getOverflowColor());
    
    if (!(this->image.isNull())) {
        c->image = this->image.copy();
    } else {
        
    }
    
    return c;
}

QRgb ColorWheel::operator() (std::complex<double> zin)
{
    QRgb col;
    
    switch(currentSel)
    {
        case 0:
            col=IcosColor(zin);
            break;
        case 1:
            col=IcosColorC(zin);
            break;
        case 2:
            col=StCol(zin);
            break;
        case 3:
            col=StColC(zin);
            break;
        case 4:
            col=StCol35(zin);
            break;
        case 5:
            col=ZoneCol(zin);
            break;
        case 6:
            col=SectCol(zin);
            break;
        case 7:
            col=Sect6Col(zin);
            break;
        case 8:
            col=WinCol(zin);
            break;
        case 9:
            col=FromSphereImage(zin);
            break;
        case 10:
            col=FromSphereImageT(zin);
            break;
        case 11:
            col=FromSphereDMir(zin);
            break;
        case 12:
            col=FromSphereHMir(zin);
            break;
        case 13:
            col=FromSphereRNegMir(zin);
            break;
        case 14:
            col=DiskToSphere(zin);
            break;
        case 15:
            col=FromImageReverse(zin);
            break;
        case 16:
            col=ImageSquish(zin);
            break;
        case 17:
            col=FromSphereHNegMir(zin);
            break;
        case 18:
            col=FromImage(zin);
            break;
    }
    
    return col;
}



void ColorWheel::loadImage(QString filename)
{
    QImage raw(filename);
    image = raw.scaled(raw.width(), raw.height(), Qt::IgnoreAspectRatio, Qt::FastTransformation);
}

QRgb ColorWheel::IcosColor(std::complex<double> zin)
{
    QVector3D V;
    int Tag;
    double test,compare;
    
    
    V = tilt(stereo(zin));
    test = 0.0;
    for(unsigned int n = 0; n < ICOS_FACES_SIZE; n++)
    {
        compare = dotProduct(V, icosFaces[n]);
        if(compare > test)
        {
            Tag = n;
            test = compare;
        }
    }
    
    return RgbFromVec3(icosFaces[Tag]);
}

QRgb ColorWheel::IcosColorC(std::complex<double> zin)
{
    QVector3D V;
    int Tag;
    double test,compare;
    
    V = tilt(stereo(zin));
    test = 0.0;
    for(unsigned int n = 0; n < ICOS_FACES_SIZE; n++)
    {
        compare = dotProduct(V, icosFaces[n]);
        if(compare > test)
        {
            Tag = n;
            test = compare;
        }
    }
    
    return RgbFromVec3(cubeRootVec(icosFaces[Tag]));
}

QRgb ColorWheel::StCol(std::complex<double> zin)
{
    QVector3D V;
    V = tilt(stereo(zin));
    
    return RgbFromVec3(V);
    
}

QRgb ColorWheel::StColC(std::complex<double> zin)
{
    QVector3D V;
    V = cubeRootVec(tilt(stereo(zin)));
    
    return RgbFromVec3(V);
}

QRgb ColorWheel::StCol35(std::complex<double> zin)
{
    QVector3D V;
    V = pow35Vec(tilt(stereo(zin)));
    
    return RgbFromVec3(V);
}

QRgb ColorWheel::ZoneCol(std::complex<double> zin)
{
    QVector3D V;
    int Tag;
    double test,compare;
    
    V = tilt(stereo(zin));
    test = 0.0;
    Tag = 0;
    
    for(unsigned int n = 0; n < ZONE_VECT_SIZE; n++)
    {
        compare = dotProduct(V, zoneVect[n]);
        if(compare > test)
        {
            Tag = n;
            test = compare;
        }
    }
    
    return RgbFromVec3(cubeRootVec(zoneVect[Tag]));;
}

QRgb ColorWheel::SectCol(std::complex<double> zin)
{
    
    int S1,r,g,b;
    double ra;
    double x = zin.real();
    double y = -zin.imag();
    
    ra = qSqrt(x*x+y*y);
    
    int extremeValue = int(MAX_RGB - (MAX_RGB * ra)/2.0);
    
    if(ra < 0.25)
    {
        r = MAX_RGB;
        g = MAX_RGB;
        b = MAX_RGB;
    }
    else
    {
        if(ra > 2.0)
        {
            r = MIN_RGB;
            g = MIN_RGB;
            b = MIN_RGB;
        }
        else
        {
            if(y > 0.0)
            {
                if (y < 0.72654 * x)
                {
                    S1 = 1;
                }
                else
                {
                    if(y < -3.077 * x)
                    {
                        S1 = 3;
                    }
                    else
                    {
                        S1 = 2;
                    }
                }
            }
            else
            {
                if(y > -0.72654 * x)
                {
                    S1 = 1;
                }
                else
                {
                    if(y > 3.077 * x)
                    {
                        S1 = 4;
                    }
                    else
                    {
                        S1 = 5;
                    }
                }
            }
            switch(S1)
            {
                case 1:
                    r = extremeValue;
                    g = MIN_RGB;
                    b = MIN_RGB;
                    break;
                case 2:
                    r = extremeValue;
                    g = extremeValue;
                    b = MIN_RGB;
                    break;
                case 3:
                    r = MIN_RGB;
                    g = extremeValue;
                    b = MIN_RGB;
                    break;
                case 4:
                    r = MIN_RGB;
                    g = MIN_RGB;
                    b = extremeValue;
                    break;
                case 5:
                    r = extremeValue;
                    g = MIN_RGB;
                    b = extremeValue;
                    break;
            }
        }
    }
    
    return QColor(r, g, b).rgb();
}

QRgb ColorWheel::Sect6Col(std::complex<double> zin)
{
    int S1,S2,r,g,b;
    
    double x = zin.real();
    double y = zin.imag();
    
    double ra = qSqrt(x * x + y * y);
    
    int specialValue1 = int(MAX_RGB * (1.5 - 2 * ra));
    int specialValue2 = int(MAX_RGB - (MAX_RGB * ra)/2.0);
    
    if(ra < 0.25)
    {
        r = MAX_RGB;
        g = MAX_RGB;
        b = MAX_RGB;
    }
    else
    {
        if(ra > 2.0)
        {
            r = MIN_RGB;
            g = MIN_RGB;
            b = MIN_RGB;
        }
        else
        {
            if (x > 0.0)
            {
                if(y < -x/1.732)
                {
                    S1 = 6;
                }
                else
                {
                    if(y > x/1.732)
                    {
                        S1 = 2;
                    }
                    else
                    {
                        S1 = 1;
                    }
                }
            }
            else
            {
                if(y < x/1.732)
                {
                    S1 = 5;
                }
                else
                {
                    if(y > -x/1.732)
                    {
                        S1 = 3;
                    }
                    else
                    {
                        S1 = 4;
                    }
                }
            }
            if(ra < 0.75)
            {
                S2 = 1;
            }
            else
            {
                if(ra < 1.25)
                {
                    S2 = 2;
                }
                else
                {
                    S2 = 3;
                }
            }
            switch(S2)
            {
                case 1:
                    switch(S1)
                {
                    case 1:
                        r = int(MAX_RGB);
                        g = specialValue1;
                        b = specialValue1;
                        break;
                    case 2:
                        r = int(MAX_RGB);
                        g = int(MAX_RGB);
                        b = specialValue1;
                        break;
                    case 3:
                        r = specialValue1;
                        g = MAX_RGB;
                        b = specialValue1;
                        break;
                    case 4:
                        r = specialValue1;
                        g = int(MAX_RGB);
                        b = int(MAX_RGB);
                        break;
                    case 5:
                        r = specialValue1;
                        g = specialValue1;
                        b = int(MAX_RGB);
                        break;
                    case 6:
                        r = int(MAX_RGB);
                        g = specialValue1;
                        b = int(MAX_RGB);
                        break;
                }
                    break;
                case 2:
                    switch(S1)
                {
                    case 1:
                        r = int(MAX_RGB);
                        g = int(0);
                        b = int(0);
                        break;
                    case 2:
                        r = int(MAX_RGB);
                        g = int(MAX_RGB);
                        b = 0;
                        break;
                    case 3:
                        r = 0;
                        g = MAX_RGB;
                        b = 0;
                        break;
                    case 4:
                        r = 0;
                        g = MAX_RGB;
                        b = MAX_RGB;
                        break;
                    case 5:
                        r = 0;
                        g = 0;
                        b = MAX_RGB;
                        break;
                    case 6:
                        r = MAX_RGB;
                        g = 0;
                        b = MAX_RGB;
                        break;
                }
                    break;
                case 3:
                    switch(S1)
                {
                    case 1:
                        r = specialValue2;
                        g = 0;
                        b = 0;
                        break;
                    case 2:
                        r = specialValue2;
                        g = specialValue2;
                        b = 0;
                        break;
                    case 3:
                        r = 0;
                        g = specialValue2;
                        b = 0;
                        break;
                    case 4:
                        r = 0;
                        g = specialValue2;
                        b = specialValue2;
                        break;
                    case 5:
                        r = 0;
                        g = 0;
                        b = specialValue2;
                        break;
                    case 6:
                        r = specialValue2;
                        g = 0;
                        b = specialValue2;
                        break;
                }
                    break;
            }
        }
    }
    
    return QColor(r, g, b).rgb();
}

QRgb ColorWheel::WinCol(std::complex<double> zin)
{
    double X,Y,Z,xa,ya,xtm,ytm,ztm,Xf,Yf,Zf;
    vect5 E1, E2, E3, B1, B2;
    int r, g, b;
    
    E1 = initVect5(1.0/ma,c2/ma,c4/ma,c6/ma,c8/ma);
    E2 = initVect5(0.0,s2/ma,s4/ma,s6/ma,s8/ma);
    E3 = initVect5(1.0/qSqrt(5.0),1.0/qSqrt(5.0),1.0/qSqrt(5.0),1.0/qSqrt(5.0),1.0/qSqrt(5.0));
    
    xa = zin.real();
    ya = zin.imag();
    
    //1st do stereographic proj
    xtm = 2.0*xa/(1.0+xa*xa+ya*ya);
    ytm = 2.0*ya/(1.0+xa*xa+ya*ya);
    ztm = 2.0/(1.0+xa*xa+ya*ya) -1.0;
    
    //put sphere up in R5
    B1 = Bvect5(xtm,ytm,ztm);
    
    //take cube roots
    B2 = initVect5(cubeRoot(B1.xv),cubeRoot(B1.yv),cubeRoot(B1.zv),cubeRoot(B1.uv),cubeRoot(B1.vv));
    Xf = B2.xv * E1.xv + B2.yv * E1.yv + B2.zv * E1.zv + B2.uv * E1.uv + B2.vv * E1.vv;
    Yf = B2.xv * E2.xv + B2.yv * E2.yv + B2.zv * E2.zv + B2.uv * E2.uv + B2.vv * E2.vv;
    Zf = B2.xv * E3.xv + B2.yv * E3.yv + B2.zv * E3.zv + B2.uv * E3.uv + B2.vv * E3.vv;
    
    //following accomplishes "tilt," but it was already written out, so fine.
    X = (Xf*q2+Zf)/q3;
    Z = 0.0 - Xf/q2/q3-Yf/q2+Zf/q3;
    Y = 0.0 - Xf/q2/q3+Yf/q2+Zf/q3;
    r = int(double(MAX_RGB) * (1.0 + X)/2.0);
    g = int(double(MAX_RGB) * (1.0 + Z)/2.0);
    b = int(double(MAX_RGB) * (1.0 + Y)/2.0);
    if(r > MAX_RGB){ r = MAX_RGB; }
    if(g > MAX_RGB){ g = MAX_RGB; }
    if(b > MAX_RGB){ b = MAX_RGB; }
    if(r < MIN_RGB){ r = MIN_RGB; }
    if(g < MIN_RGB){ g = MIN_RGB; }
    if(b < MIN_RGB){ b = MIN_RGB; }
    
    return QColor(r, g, b).rgb();
    
    
}

QRgb ColorWheel::ImageSquish(std::complex<double> zin)
{
    double x = zin.real();
    double y = zin.imag();
    double denom = sqrt(1.0+0.5*x*x+0.5*y*y);
    x=x/denom;
    y=y/denom;
    QRgb color;

    if(x >= -2.0 && x < 2.0 && y >= -2.0 && y < 2.0)      //our image is defined within the Cartesian coordinates
    {                                                       // -2 <= x <= 2  and -2 <= y <= 2
        int translated_x = (int) ((x + 2.0) * (image_dim / 4.0));
        int translated_y = (int) image_dim - ((y + 2.0) * (image_dim / 4.0));

        color = image.pixel(translated_x, translated_y);
    }
    else
        color = qRgb(0,0,0);
    return color;
}

QRgb ColorWheel::FromSphereImage(std::complex<double> zin)
{
    double x = zin.real();
    double y = zin.imag();
    double r2=x*x+y*y;
    double r=qSqrt(r2);
    double theta=qAtan2(y,x)+pi;
    double phi=qAtan2(2.0*r ,r2-1);
    QRgb color;

        int translated_x = (int) ((image_dim)*(theta / (2.0*pi))  );
        int translated_y = (int) ((image_dim )*(phi/ pi)  );

        color = image.pixel(translated_x, translated_y);

    return color;
}

QRgb ColorWheel::FromSphereImageT(std::complex<double> zin)
{
    std::complex<double> zt=(1.8*zin-1.0)/(zin+1.8);//1.38 would give 72 degrees;
    double x = zt.real();//zt is z-turned 60 degrees about y-axis on sphere
    double y = zt.imag();
    double r2=x*x+y*y;
    double r=qSqrt(r2);
    double theta=qAtan2(y,x)+pi;
    double phi=qAtan2(2.0*r ,r2-1);
    QRgb color;


        int translated_x = (int) ((theta / (2.0*pi)) * (image_dim));
        int translated_y = (int) ((phi/ pi) * (image_dim ));

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

        int translated_x = (int) ((image_dim)*(theta / (2.0*pi))  );
        int translated_y = (int) ((image_dim )*(phi/ pi)  );

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
    if(theta>pi){theta=theta-pi;//put highest half back to 1st half and negate
        int translated_x = (int) ((image_dim)*(theta / (2.0*pi))  );
        int translated_y = (int) ((image_dim )*(phi/ pi)  );
        colorInv = image.pixel(translated_x, translated_y);
         re=255-QColor(colorInv).red();
         g=255-QColor(colorInv).green();
         b=255-QColor(colorInv).blue();
        color=qRgb(re,g,b);}
    else{ int translated_x = (int) ((image_dim)*(theta / (2.0*pi))  );
            int translated_y = (int) ((image_dim )*(phi/ pi)  );

            color = image.pixel(translated_x, translated_y);};}
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

        int translated_x = (int) ((image_dim)*(theta / (2.0*pi))  );
        int translated_y = (int) ((image_dim )*(phi/ pi)  );
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
    if(theta>pi){theta=2*pi-theta;//reflect values above pi to values below pi and use positive colors
        int translated_x = (int) ((image_dim)*(theta / (2.0*pi))  );
        int translated_y = (int) ((image_dim )*(phi/ pi)  );
        color = image.pixel(translated_x, translated_y);}//Otherwise, use negative colors
    else{
        int translated_x = (int) ((image_dim)*(theta / (2.0*pi))  );
        int translated_y = (int) ((image_dim )*(phi/ pi)  );
        colorInv = image.pixel(translated_x, translated_y);
         re=255-QColor(colorInv).red();
         g=255-QColor(colorInv).green();
         b=255-QColor(colorInv).blue();

        color=qRgb(re,g,b);
          };};


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

    if(r2<1)      //do the usual routine for complex numbers inside unit circle
    {
        int translated_x = (int) ((x + 1.0) * (image_dim / 2.0));
        int translated_y = (int) image_dim - ((y + 1.0) * (image_dim / 2.0));

        color = image.pixel(translated_x, translated_y);
    }
    else{
        std::complex<double> zinv=pow(zin,-1.0);
        x=zinv.real();y=zinv.imag();
        int translated_x = (int) ((x + 1.0) * (image_dim / 2.0));
        int translated_y = (int) image_dim - ((y + 1.0) * (image_dim / 2.0));
        colorInv = image.pixel(translated_x, translated_y);
         r=255-QColor(colorInv).red();
         g=255-QColor(colorInv).green();
         b=255-QColor(colorInv).blue();

        color=qRgb(r,g,b);};

    return color;
}


QRgb ColorWheel::DiskToSphere(std::complex<double> zin)
{
    double x = zin.real();
    double y = zin.imag();
    double r2=x*x+y*y;
    QRgb color;

    if(r2<1)      //do the usual routine for complex numbers inside unit circle
    {
        int translated_x = (int) ((x + 1.0) * (image_dim / 2.0));
        int translated_y = (int) image_dim - ((y + 1.0) * (image_dim / 2.0));
        color = image.pixel(translated_x, translated_y);
    }
    else{//do circle inversion for points outside, to make it conts
        std::complex<double> zinv=pow(zin,-1.0);
        double x1 = zinv.real();
        double y1 = 0.0-zinv.imag();
        int translated_x = (int) ((x1 + 1.0) * (image_dim / 2.0));
        int translated_y = (int) image_dim - ((y1 + 1.0) * (image_dim / 2.0));
        color = image.pixel(translated_x, translated_y);
        };

    return color;
}

QRgb ColorWheel::FromImage(std::complex<double> zin)
{
    double x = zin.real();
    double y = zin.imag();
    QColor color;
    
    if(x >= -2.0 && x < 2.0 && y >= -2.0 && y < 2.0)      //our image is defined within the Cartesian coordinates
    {                                                       // -2 <= x <= 2  and -2 <= y <= 2
        int translated_x = (int) ((x + 2.0) * (image_dim / 4.0));
        int translated_y = (int) image_dim - ((y + 2.0) * (image_dim / 4.0));
        color = image.pixel(translated_x, translated_y);
    }
    else {
        color = overflowColor;
    }
    return color.rgb();
}

void ColorWheel::setCurrent(int index)
{
    if(index >= 0 && index <= 9)
        currentSel = index;
}

