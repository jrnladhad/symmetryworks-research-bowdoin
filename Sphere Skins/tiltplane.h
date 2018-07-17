#ifndef TILTPLANE_H
#define TILTPLANE_H


#include <QWidget>
#include <QChart>
#include <QChartView>
#include <QValueAxis>
#include <QSplineSeries>
#include <QLineSeries>
#include <QScatterSeries>
#include <QMouseEvent>
#include <QLabel>
#include <QGroupBox>
#include <QLineEdit>
#include <QSlider>
#include <QKeyEvent>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSignalMapper>
#include <QValidator>

#include "shared.h"
#include "geomath.h"
#include "functions.h"

using namespace QtCharts;

// object for creating a plane pop-up view for function constants
class TiltPlaneView : public QChartView {

    Q_OBJECT

public:

    TiltPlaneView(QChart *chart, QScatterSeries *coordinateSeries) : QChartView(chart) { this->chart = chart; this->coordinateSeries = coordinateSeries; setMouseTracking(false);}

signals:
    void newCoordinate();

protected:
    // MOUSE EVENTS

    void mouseReleaseEvent(QMouseEvent *event)
    {
        if(event->button() == Qt::LeftButton)
        {
            // qDebug() << "Clicked on: " << event->pos();
            coordinateSeries->replace(0, chart->mapToValue(event->pos(), coordinateSeries));
            mouseMoving = false;
        }
    };

    void mousePressEvent(QMouseEvent *event)
    {
        if(event->button() == Qt::LeftButton)
        {
            mouseMoving = true;
        }
        QChartView::mousePressEvent(event);
    }

    void mouseMoveEvent(QMouseEvent *event)
    {
        if(mouseMoving)
        {
            coordinateSeries->replace(0, chart->mapToValue(event->pos(), coordinateSeries));
            emit newCoordinate();
        }
    };

private:
    QScatterSeries* coordinateSeries;
    QChart *chart;
    bool mouseMoving;
};



class TiltPlane : public QWidget
{
    Q_OBJECT
public:
    //TiltPlane(QWidget *parent = 0) : QWidget(parent) { }
    TiltPlane(QWidget *parent = 0);
    ~TiltPlane() { }

    void hideTiltPlane() { qDebug() << "hello"; tiltPlanePopUp->close(); }

signals:
    void setTiltCoordinates(const QString &x, const QString &y);

private:
    // organizational elements
    QWidget *tiltPlanePopUp;
    QGroupBox *tiltCoordinatesBox;
    QHBoxLayout *tiltPlanePopUpLayout;
    QVBoxLayout *tiltCoordinatesLayout;
    QHBoxLayout *actionButtonLayout;
    QHBoxLayout *zoomButtonLayout;
    QVBoxLayout *tiltPlaneWithZoomLayout;
    TiltPlaneView *graphDisplay;
    QChart *graph;
    QValueAxis *axisX;
    QValueAxis *axisY;
    QLabel *xLabel;
    QLabel *yLabel;
    QLineEdit *xEdit;
    QLineEdit *yEdit;
    //sQPushButton *confirmButton;
    QPushButton *resetButton;
    QPushButton *cancelButton;
    QPushButton *zoomInButton;
    QPushButton *zoomOutButton;
    QSpacerItem *planeSpacer1;
    QSpacerItem *planeSpacer2;
    QLineSeries *series;
    QLineSeries *series2;
    QScatterSeries *coordinateSeries;
    QLineSeries *xSeries;
    QLineSeries *ySeries;

    //int coeffFlag; // stores type of function constant pair
    bool showActionFlag; //stores if the user trigger the "show" action
    double startingX; //stores the radius when first shown
    double startingY;  //stores the angle when first shown

    QDoubleValidator *doubleValidateX;
    QDoubleValidator *doubleValidateY;

    std::complex<double> oldBetaValues;

protected:

    void updateTiltCoordinates(QPointF point);

private slots:

    void showPlanePopUp();
    void updateTiltCoordinatesWithIndex(const int &index);
    void updateTiltCoordinates();
    void tiltPlaneZoomIn();
    void tiltPlaneZoomOut();

    void setTiltCoordinates();
    void resetTiltCoordinates();


};
#endif // TILTPLANE_H
