/****************************************************************************
** Meta object code from reading C++ file 'polarplane.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "polarplane.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'polarplane.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PolarPlaneView_t {
    QByteArrayData data[3];
    char stringdata0[30];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PolarPlaneView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PolarPlaneView_t qt_meta_stringdata_PolarPlaneView = {
    {
QT_MOC_LITERAL(0, 0, 14), // "PolarPlaneView"
QT_MOC_LITERAL(1, 15, 13), // "newCoordinate"
QT_MOC_LITERAL(2, 29, 0) // ""

    },
    "PolarPlaneView\0newCoordinate\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PolarPlaneView[] = {

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

void PolarPlaneView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PolarPlaneView *_t = static_cast<PolarPlaneView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newCoordinate(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (PolarPlaneView::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PolarPlaneView::newCoordinate)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject PolarPlaneView::staticMetaObject = {
    { &QChartView::staticMetaObject, qt_meta_stringdata_PolarPlaneView.data,
      qt_meta_data_PolarPlaneView,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *PolarPlaneView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PolarPlaneView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PolarPlaneView.stringdata0))
        return static_cast<void*>(this);
    return QChartView::qt_metacast(_clname);
}

int PolarPlaneView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void PolarPlaneView::newCoordinate()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
struct qt_meta_stringdata_PolarPlane_t {
    QByteArrayData data[14];
    char stringdata0[193];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PolarPlane_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PolarPlane_t qt_meta_stringdata_PolarPlane = {
    {
QT_MOC_LITERAL(0, 0, 10), // "PolarPlane"
QT_MOC_LITERAL(1, 11, 19), // "setPolarCoordinates"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 9), // "coeffFlag"
QT_MOC_LITERAL(4, 42, 6), // "radius"
QT_MOC_LITERAL(5, 49, 5), // "angle"
QT_MOC_LITERAL(6, 55, 14), // "showPlanePopUp"
QT_MOC_LITERAL(7, 70, 4), // "flag"
QT_MOC_LITERAL(8, 75, 31), // "updatePolarCoordinatesWithIndex"
QT_MOC_LITERAL(9, 107, 5), // "index"
QT_MOC_LITERAL(10, 113, 22), // "updatePolarCoordinates"
QT_MOC_LITERAL(11, 136, 16), // "polarPlaneZoomIn"
QT_MOC_LITERAL(12, 153, 17), // "polarPlaneZoomOut"
QT_MOC_LITERAL(13, 171, 21) // "resetPolarCoordinates"

    },
    "PolarPlane\0setPolarCoordinates\0\0"
    "coeffFlag\0radius\0angle\0showPlanePopUp\0"
    "flag\0updatePolarCoordinatesWithIndex\0"
    "index\0updatePolarCoordinates\0"
    "polarPlaneZoomIn\0polarPlaneZoomOut\0"
    "resetPolarCoordinates"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PolarPlane[] = {

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
       1,    3,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   61,    2, 0x08 /* Private */,
       8,    1,   64,    2, 0x08 /* Private */,
      10,    0,   67,    2, 0x08 /* Private */,
      11,    0,   68,    2, 0x08 /* Private */,
      12,    0,   69,    2, 0x08 /* Private */,
       1,    0,   70,    2, 0x08 /* Private */,
      13,    0,   71,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QString,    3,    4,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void PolarPlane::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PolarPlane *_t = static_cast<PolarPlane *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setPolarCoordinates((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 1: _t->showPlanePopUp((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->updatePolarCoordinatesWithIndex((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 3: _t->updatePolarCoordinates(); break;
        case 4: _t->polarPlaneZoomIn(); break;
        case 5: _t->polarPlaneZoomOut(); break;
        case 6: _t->setPolarCoordinates(); break;
        case 7: _t->resetPolarCoordinates(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (PolarPlane::*_t)(int , const QString & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PolarPlane::setPolarCoordinates)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject PolarPlane::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_PolarPlane.data,
      qt_meta_data_PolarPlane,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *PolarPlane::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PolarPlane::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PolarPlane.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int PolarPlane::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void PolarPlane::setPolarCoordinates(int _t1, const QString & _t2, const QString & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
