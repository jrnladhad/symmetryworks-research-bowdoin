/****************************************************************************
** Meta object code from reading C++ file 'tiltplane.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Sphere Skins/tiltplane.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tiltplane.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TiltPlaneView_t {
    QByteArrayData data[3];
    char stringdata0[29];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TiltPlaneView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TiltPlaneView_t qt_meta_stringdata_TiltPlaneView = {
    {
QT_MOC_LITERAL(0, 0, 13), // "TiltPlaneView"
QT_MOC_LITERAL(1, 14, 13), // "newCoordinate"
QT_MOC_LITERAL(2, 28, 0) // ""

    },
    "TiltPlaneView\0newCoordinate\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TiltPlaneView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,

       0        // eod
};

void TiltPlaneView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TiltPlaneView *_t = static_cast<TiltPlaneView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newCoordinate(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (TiltPlaneView::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TiltPlaneView::newCoordinate)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject TiltPlaneView::staticMetaObject = {
    { &QChartView::staticMetaObject, qt_meta_stringdata_TiltPlaneView.data,
      qt_meta_data_TiltPlaneView,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *TiltPlaneView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TiltPlaneView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TiltPlaneView.stringdata0))
        return static_cast<void*>(this);
    return QChartView::qt_metacast(_clname);
}

int TiltPlaneView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QChartView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void TiltPlaneView::newCoordinate()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
struct qt_meta_stringdata_TiltPlane_t {
    QByteArrayData data[12];
    char stringdata0[162];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TiltPlane_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TiltPlane_t qt_meta_stringdata_TiltPlane = {
    {
QT_MOC_LITERAL(0, 0, 9), // "TiltPlane"
QT_MOC_LITERAL(1, 10, 18), // "setTiltCoordinates"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 1), // "x"
QT_MOC_LITERAL(4, 32, 1), // "y"
QT_MOC_LITERAL(5, 34, 14), // "showPlanePopUp"
QT_MOC_LITERAL(6, 49, 30), // "updateTiltCoordinatesWithIndex"
QT_MOC_LITERAL(7, 80, 5), // "index"
QT_MOC_LITERAL(8, 86, 21), // "updateTiltCoordinates"
QT_MOC_LITERAL(9, 108, 15), // "tiltPlaneZoomIn"
QT_MOC_LITERAL(10, 124, 16), // "tiltPlaneZoomOut"
QT_MOC_LITERAL(11, 141, 20) // "resetTiltCoordinates"

    },
    "TiltPlane\0setTiltCoordinates\0\0x\0y\0"
    "showPlanePopUp\0updateTiltCoordinatesWithIndex\0"
    "index\0updateTiltCoordinates\0tiltPlaneZoomIn\0"
    "tiltPlaneZoomOut\0resetTiltCoordinates"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TiltPlane[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   59,    2, 0x08 /* Private */,
       6,    1,   60,    2, 0x08 /* Private */,
       8,    0,   63,    2, 0x08 /* Private */,
       9,    0,   64,    2, 0x08 /* Private */,
      10,    0,   65,    2, 0x08 /* Private */,
       1,    0,   66,    2, 0x08 /* Private */,
      11,    0,   67,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TiltPlane::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TiltPlane *_t = static_cast<TiltPlane *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setTiltCoordinates((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: _t->showPlanePopUp(); break;
        case 2: _t->updateTiltCoordinatesWithIndex((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 3: _t->updateTiltCoordinates(); break;
        case 4: _t->tiltPlaneZoomIn(); break;
        case 5: _t->tiltPlaneZoomOut(); break;
        case 6: _t->setTiltCoordinates(); break;
        case 7: _t->resetTiltCoordinates(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (TiltPlane::*_t)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TiltPlane::setTiltCoordinates)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject TiltPlane::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_TiltPlane.data,
      qt_meta_data_TiltPlane,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *TiltPlane::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TiltPlane::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TiltPlane.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int TiltPlane::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void TiltPlane::setTiltCoordinates(const QString & _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
