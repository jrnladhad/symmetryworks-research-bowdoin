#include "tiltplane.h"


// CONSTRUCTOR sets up layout for plane pop-up window
TiltPlane::TiltPlane(QWidget *parent) : QWidget(parent)
{
    // INPUT VALIDATORS (NUMERICAL)
    doubleValidateX = new QDoubleValidator(-9999999.0, 9999999.0, 5, this);
    doubleValidateY = new QDoubleValidator(-9999999.0, 9999999.0, 5, this);

    //SET UP COEFFICIENT PLANE
    tiltPlanePopUp = new QWidget(parent, Qt::Window);

    tiltPlanePopUpLayout = new QHBoxLayout();
    tiltPlaneWithZoomLayout = new QVBoxLayout();
    tiltCoordinatesBox = new QGroupBox(tr("Tilt Coordinates"), tiltPlanePopUp);
    tiltCoordinatesLayout = new QVBoxLayout(tiltCoordinatesBox);
    actionButtonLayout = new QHBoxLayout();
    zoomButtonLayout = new QHBoxLayout();

    // GRAPH ELEMENTS
    graph = new QChart();

    axisX = new QValueAxis();
    axisY = new QValueAxis();

    series = new QSplineSeries();
    series2 = new QSplineSeries();
    xSeries = new QLineSeries();
    ySeries = new QLineSeries();
    coordinateSeries = new QScatterSeries();

    xLabel = new QLabel(tr("X: "), tiltCoordinatesBox);
    yLabel = new QLabel(tr("Y: "), tiltCoordinatesBox);

    xEdit = new QLineEdit();
    yEdit = new QLineEdit();

    // UI ELEMENTS
    resetButton = new QPushButton(tr("Reset"));
    zoomInButton = new QPushButton(QIcon(":/Images/Icons/zoomin.png"), "Zoom In");
    zoomInButton->setStyleSheet("QPushButton { text-align:center; padding:5px}");
    zoomOutButton = new QPushButton(QIcon(":/Images/Icons/zoomout.png"), "Zoom Out");
    zoomOutButton->setStyleSheet("QPushButton { text-align:center; padding:5px}");

    planeSpacer1 = new QSpacerItem(15,15);
    planeSpacer2 = new QSpacerItem(5,5);

    *series << QPointF(10, 0) << QPointF(2,0) << QPointF(-2,0) << QPointF(-10,0);
    *series2 << QPointF(0, 10) << QPointF(0,2) << QPointF(0,-2) << QPointF(0, -10);
    *xSeries << QPointF(0,0) << QPointF(1,0);
    *ySeries << QPointF(0,0) << QPointF(1,0);
    *coordinateSeries << QPointF(1.00, 0.00);

    xEdit->setValidator(doubleValidateX);
    xEdit->setText("1.00");
    yEdit->setValidator(doubleValidateY);
   yEdit->setText("0.00");

    //adjust axis size
    QPen axisPen(Qt::black);
    axisPen.setWidth(2);
    series->setPen(axisPen);
    series2->setPen(axisPen);

    //adjust line series size & color
    QPen linePen(Qt::gray);
    linePen.setWidth(2);
    xSeries->setPen(linePen);
    ySeries->setPen(linePen);

    //adjust data points size & color
    QPen pointPen(Qt::black);
    QBrush pointBrush(Qt::black);
    coordinateSeries->setPen(pointPen);
    coordinateSeries->setBrush(pointBrush);
    coordinateSeries->setMarkerSize(10.0);

    axisX->setTickCount(9);
    axisX->setRange(-2.5, 2.5);
    axisY->setTickCount(8);
    axisY->setRange(-2.5, 2.5);

    graph->addSeries(series);
    graph->addSeries(series2);
    graph->addSeries(xSeries);
    graph->addSeries(ySeries);
    graph->addSeries(coordinateSeries);

    axisX->setGridLineVisible(false);
    axisY->setGridLineVisible(false);

    graph->addAxis(axisX, Qt::AlignBottom);
    graph->addAxis(axisY, Qt::AlignLeft);

    series->attachAxis(axisX);
    series->attachAxis(axisY);
    series2->attachAxis(axisX);
    series2->attachAxis(axisY);
    xSeries->attachAxis(axisX);
    xSeries->attachAxis(axisY);
    ySeries->attachAxis(axisX);
    ySeries->attachAxis(axisY);
    coordinateSeries->attachAxis(axisX);
    coordinateSeries->attachAxis(axisY);

    graphDisplay = new TiltPlaneView(graph, coordinateSeries);
    graphDisplay->setRenderHint(QPainter::Antialiasing);

    graph->legend()->hide();

    xLabel->setFixedWidth(200);
    xEdit->setFixedWidth(200);
    yLabel->setFixedWidth(200);
    yEdit->setFixedWidth(200);

    actionButtonLayout->addWidget(resetButton);

    tiltCoordinatesLayout->addWidget(xLabel);
    tiltCoordinatesLayout->addWidget(xEdit);
    tiltCoordinatesLayout->addWidget(yLabel);
    tiltCoordinatesLayout->addWidget(yEdit);
    tiltCoordinatesLayout->addItem(planeSpacer1);
    tiltCoordinatesLayout->addLayout(actionButtonLayout);
    tiltCoordinatesLayout->addStretch(0);
    tiltCoordinatesLayout->setSizeConstraint(QLayout::SetFixedSize);

    zoomButtonLayout->addWidget(zoomInButton);
    zoomButtonLayout->addWidget(zoomOutButton);

    tiltPlaneWithZoomLayout->addWidget(graphDisplay);
    tiltPlaneWithZoomLayout->addLayout(zoomButtonLayout);

    tiltPlanePopUpLayout->addLayout(tiltPlaneWithZoomLayout);
    tiltPlanePopUpLayout->addWidget(tiltCoordinatesBox);

    tiltPlanePopUp->setLayout(tiltPlanePopUpLayout);
    tiltPlanePopUp->setFixedSize(720, 400);

    // CONNECT ALL SIGNALS
    connect(xEdit, SIGNAL(returnPressed()), this, SLOT(updateTiltCoordinates()));
    connect(yEdit, SIGNAL(returnPressed()), this, SLOT(updateTiltCoordinates()));
    connect(coordinateSeries, SIGNAL(pointReplaced(int)), this, SLOT(updateTiltCoordinatesWithIndex(int)));
    connect(resetButton, SIGNAL(clicked()), this, SLOT(resetTiltCoordinates()));
    connect(zoomInButton, SIGNAL(clicked()), this, SLOT(tiltPlaneZoomIn()));
    connect(zoomOutButton, SIGNAL(clicked()), this, SLOT(tiltPlaneZoomOut()));
    connect(graphDisplay, SIGNAL(newCoordinate()), this, SLOT(setTiltCoordinates()));

}


// show plane in new window
void TiltPlane::showPlanePopUp()
{
    tiltPlanePopUp->setWindowTitle((tr("Tilt Coordinates")));

    showActionFlag = true;

    double tempX = 0.0, tempY = 0.0;

    QPointF point(tempX, tempY);

    coordinateSeries->replace(0, point);
    tiltPlanePopUp->show();

    showActionFlag = false;
    startingX = tempX;
    startingY = tempY;

}


void TiltPlane::updateTiltCoordinatesWithIndex(const int &index)
{
    QPointF point = coordinateSeries->at(index);
    updateTiltCoordinates(point);
}

void TiltPlane::updateTiltCoordinates()
{
    double tempX = xEdit->text().toDouble();
    double tempY = yEdit->text().toDouble();

    coordinateSeries->replace(0, QPointF(tempX, tempY));
}

void TiltPlane::updateTiltCoordinates(QPointF point)
{
    QVector<QPointF> list1;
    list1 << QPointF(0,0) << point;
    QVector<QPointF> list2;
    list2 << QPointF(point.x(), 0) << point;

    xSeries->replace(list1);
    ySeries->replace(list2);

    xEdit->blockSignals(true);
    yEdit->blockSignals(true);
    xEdit->setText(QString::number(point.x(), 'f', 2));
    yEdit->setText(QString::number(qAtan2(point.y(), point.x()), 'f', 2));
    xEdit->blockSignals(false);
    yEdit->blockSignals(false);

    if (!showActionFlag) {
        setTiltCoordinates();
    }
}

void TiltPlane::setTiltCoordinates()
{
    qDebug() << "emit new signal";
    emit setTiltCoordinates(xEdit->text(), yEdit->text());
}

void TiltPlane::resetTiltCoordinates()
{
    coordinateSeries->replace(0, QPointF(startingX, startingY));
}

void TiltPlane::tiltPlaneZoomOut()
{
    series->insert(0, QPointF(series->at(0).x() * 2, series->at(0).y() * 2));
    series->append(QPointF(series->at(series->count() - 1).x() * 2, series->at(series->count() - 1).y() * 2));

    series2->insert(0, QPointF(series2->at(0).x() * 2, series2->at(0).y() * 2));
    series2->append(QPointF(series2->at(series2->count() - 1).x() * 2, series2->at(series2->count() - 1).y() * 2));

    graph->zoomOut();
}

void TiltPlane::tiltPlaneZoomIn()
{
    series->replace(0, QPointF(series->at(0).x() / 2, series->at(0).y() / 2));
    series->replace(series->count() - 1, QPointF(series->at(series->count() - 1).x() / 2, series->at(series->count() - 1).y() / 2));

    series2->replace(0, QPointF(series2->at(0).x() / 2, series2->at(0).y() / 2));
    series2->replace(series->count() - 1, QPointF(series2->at(series2->count() - 1).x() / 2, series2->at(series2->count() - 1).y() / 2));

    graph->zoomIn();
}


