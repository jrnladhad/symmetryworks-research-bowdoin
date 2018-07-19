/****************************************************************************
** Meta object code from reading C++ file 'controllerthread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Sphere Skins/controllerthread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'controllerthread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Controller_t {
    QByteArrayData data[17];
    char stringdata0[230];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Controller_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Controller_t qt_meta_stringdata_Controller = {
    {
QT_MOC_LITERAL(0, 0, 10), // "Controller"
QT_MOC_LITERAL(1, 11, 12), // "workFinished"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 10), // "actionFlag"
QT_MOC_LITERAL(4, 36, 18), // "allThreadsFinished"
QT_MOC_LITERAL(5, 55, 15), // "progressChanged"
QT_MOC_LITERAL(6, 71, 8), // "progress"
QT_MOC_LITERAL(7, 80, 22), // "partialProgressChanged"
QT_MOC_LITERAL(8, 103, 17), // "newImageDataPoint"
QT_MOC_LITERAL(9, 121, 12), // "ComplexValue"
QT_MOC_LITERAL(10, 134, 4), // "data"
QT_MOC_LITERAL(11, 139, 24), // "handleRenderedImageParts"
QT_MOC_LITERAL(12, 164, 10), // "startPoint"
QT_MOC_LITERAL(13, 175, 8), // "Q2DArray"
QT_MOC_LITERAL(14, 184, 6), // "result"
QT_MOC_LITERAL(15, 191, 17), // "handleNewProgress"
QT_MOC_LITERAL(16, 209, 20) // "addNewImageDataPoint"

    },
    "Controller\0workFinished\0\0actionFlag\0"
    "allThreadsFinished\0progressChanged\0"
    "progress\0partialProgressChanged\0"
    "newImageDataPoint\0ComplexValue\0data\0"
    "handleRenderedImageParts\0startPoint\0"
    "Q2DArray\0result\0handleNewProgress\0"
    "addNewImageDataPoint"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Controller[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       4,    0,   57,    2, 0x06 /* Public */,
       5,    1,   58,    2, 0x06 /* Public */,
       7,    1,   61,    2, 0x06 /* Public */,
       8,    1,   64,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    2,   67,    2, 0x08 /* Private */,
      15,    1,   72,    2, 0x08 /* Private */,
      16,    1,   75,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Double,    6,
    QMetaType::Void, 0x80000000 | 9,   10,

 // slots: parameters
    QMetaType::Void, QMetaType::QPoint, 0x80000000 | 13,   12,   14,
    QMetaType::Void, QMetaType::Double,    6,
    QMetaType::Void, 0x80000000 | 9,   10,

       0        // eod
};

void Controller::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Controller *_t = static_cast<Controller *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->workFinished((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 1: _t->allThreadsFinished(); break;
        case 2: _t->progressChanged((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 3: _t->partialProgressChanged((*reinterpret_cast< const double(*)>(_a[1]))); break;
        case 4: _t->newImageDataPoint((*reinterpret_cast< const ComplexValue(*)>(_a[1]))); break;
        case 5: _t->handleRenderedImageParts((*reinterpret_cast< const QPoint(*)>(_a[1])),(*reinterpret_cast< const Q2DArray(*)>(_a[2]))); break;
        case 6: _t->handleNewProgress((*reinterpret_cast< const double(*)>(_a[1]))); break;
        case 7: _t->addNewImageDataPoint((*reinterpret_cast< const ComplexValue(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (Controller::*_t)(const int & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Controller::workFinished)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Controller::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Controller::allThreadsFinished)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Controller::*_t)(const int & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Controller::progressChanged)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Controller::*_t)(const double & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Controller::partialProgressChanged)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (Controller::*_t)(const ComplexValue & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Controller::newImageDataPoint)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Controller::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Controller.data,
      qt_meta_data_Controller,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Controller::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Controller::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Controller.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Controller::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void Controller::workFinished(const int & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Controller::allThreadsFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Controller::progressChanged(const int & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Controller::partialProgressChanged(const double & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Controller::newImageDataPoint(const ComplexValue & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
struct qt_meta_stringdata_ControllerThread_t {
    QByteArrayData data[5];
    char stringdata0[49];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ControllerThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ControllerThread_t qt_meta_stringdata_ControllerThread = {
    {
QT_MOC_LITERAL(0, 0, 16), // "ControllerThread"
QT_MOC_LITERAL(1, 17, 11), // "resultReady"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 10), // "actionFlag"
QT_MOC_LITERAL(4, 41, 7) // "newWork"

    },
    "ControllerThread\0resultReady\0\0actionFlag\0"
    "newWork"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ControllerThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,
       4,    0,   27,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,

       0        // eod
};

void ControllerThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ControllerThread *_t = static_cast<ControllerThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->resultReady((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 1: _t->newWork(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (ControllerThread::*_t)(const int & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ControllerThread::resultReady)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ControllerThread::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ControllerThread::newWork)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ControllerThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_ControllerThread.data,
      qt_meta_data_ControllerThread,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ControllerThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ControllerThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ControllerThread.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int ControllerThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void ControllerThread::resultReady(const int & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ControllerThread::newWork()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
