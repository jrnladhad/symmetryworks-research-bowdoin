/****************************************************************************
** Meta object code from reading C++ file 'renderthread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Wallpaper Generation/renderthread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'renderthread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RenderThread_t {
    QByteArrayData data[11];
    char stringdata0[116];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RenderThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RenderThread_t qt_meta_stringdata_RenderThread = {
    {
QT_MOC_LITERAL(0, 0, 12), // "RenderThread"
QT_MOC_LITERAL(1, 13, 17), // "renderingFinished"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 10), // "startPoint"
QT_MOC_LITERAL(4, 43, 8), // "Q2DArray"
QT_MOC_LITERAL(5, 52, 6), // "result"
QT_MOC_LITERAL(6, 59, 11), // "newProgress"
QT_MOC_LITERAL(7, 71, 8), // "progress"
QT_MOC_LITERAL(8, 80, 17), // "newImageDataPoint"
QT_MOC_LITERAL(9, 98, 12), // "ComplexValue"
QT_MOC_LITERAL(10, 111, 4) // "data"

    },
    "RenderThread\0renderingFinished\0\0"
    "startPoint\0Q2DArray\0result\0newProgress\0"
    "progress\0newImageDataPoint\0ComplexValue\0"
    "data"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RenderThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   29,    2, 0x06 /* Public */,
       6,    1,   34,    2, 0x06 /* Public */,
       8,    1,   37,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QPoint, 0x80000000 | 4,    3,    5,
    QMetaType::Void, QMetaType::Double,    7,
    QMetaType::Void, 0x80000000 | 9,   10,

       0        // eod
};

void RenderThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RenderThread *_t = static_cast<RenderThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->renderingFinished((*reinterpret_cast< const QPoint(*)>(_a[1])),(*reinterpret_cast< const Q2DArray(*)>(_a[2]))); break;
        case 1: _t->newProgress((*reinterpret_cast< const double(*)>(_a[1]))); break;
        case 2: _t->newImageDataPoint((*reinterpret_cast< const ComplexValue(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (RenderThread::*_t)(const QPoint & , const Q2DArray & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RenderThread::renderingFinished)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (RenderThread::*_t)(const double & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RenderThread::newProgress)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (RenderThread::*_t)(const ComplexValue & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RenderThread::newImageDataPoint)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject RenderThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_RenderThread.data,
      qt_meta_data_RenderThread,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *RenderThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RenderThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RenderThread.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int RenderThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void RenderThread::renderingFinished(const QPoint & _t1, const Q2DArray & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void RenderThread::newProgress(const double & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void RenderThread::newImageDataPoint(const ComplexValue & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
