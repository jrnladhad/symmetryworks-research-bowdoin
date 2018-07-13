/****************************************************************************
** Meta object code from reading C++ file 'interface.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "interface.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'interface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CustomLineEdit_t {
    QByteArrayData data[1];
    char stringdata0[15];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CustomLineEdit_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CustomLineEdit_t qt_meta_stringdata_CustomLineEdit = {
    {
QT_MOC_LITERAL(0, 0, 14) // "CustomLineEdit"

    },
    "CustomLineEdit"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CustomLineEdit[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void CustomLineEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject CustomLineEdit::staticMetaObject = {
    { &QLineEdit::staticMetaObject, qt_meta_stringdata_CustomLineEdit.data,
      qt_meta_data_CustomLineEdit,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CustomLineEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CustomLineEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CustomLineEdit.stringdata0))
        return static_cast<void*>(this);
    return QLineEdit::qt_metacast(_clname);
}

int CustomLineEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLineEdit::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_CustomSpinBox_t {
    QByteArrayData data[1];
    char stringdata0[14];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CustomSpinBox_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CustomSpinBox_t qt_meta_stringdata_CustomSpinBox = {
    {
QT_MOC_LITERAL(0, 0, 13) // "CustomSpinBox"

    },
    "CustomSpinBox"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CustomSpinBox[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void CustomSpinBox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject CustomSpinBox::staticMetaObject = {
    { &QSpinBox::staticMetaObject, qt_meta_stringdata_CustomSpinBox.data,
      qt_meta_data_CustomSpinBox,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CustomSpinBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CustomSpinBox::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CustomSpinBox.stringdata0))
        return static_cast<void*>(this);
    return QSpinBox::qt_metacast(_clname);
}

int CustomSpinBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSpinBox::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_ClickableLabel_t {
    QByteArrayData data[4];
    char stringdata0[46];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ClickableLabel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ClickableLabel_t qt_meta_stringdata_ClickableLabel = {
    {
QT_MOC_LITERAL(0, 0, 14), // "ClickableLabel"
QT_MOC_LITERAL(1, 15, 23), // "doubleClickFunctionIcon"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 5) // "index"

    },
    "ClickableLabel\0doubleClickFunctionIcon\0"
    "\0index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ClickableLabel[] = {

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
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

       0        // eod
};

void ClickableLabel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ClickableLabel *_t = static_cast<ClickableLabel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->doubleClickFunctionIcon((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (ClickableLabel::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ClickableLabel::doubleClickFunctionIcon)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ClickableLabel::staticMetaObject = {
    { &QLabel::staticMetaObject, qt_meta_stringdata_ClickableLabel.data,
      qt_meta_data_ClickableLabel,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ClickableLabel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ClickableLabel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ClickableLabel.stringdata0))
        return static_cast<void*>(this);
    return QLabel::qt_metacast(_clname);
}

int ClickableLabel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
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
void ClickableLabel::doubleClickFunctionIcon(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_QDoubleSlider_t {
    QByteArrayData data[9];
    char stringdata0[94];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QDoubleSlider_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QDoubleSlider_t qt_meta_stringdata_QDoubleSlider = {
    {
QT_MOC_LITERAL(0, 0, 13), // "QDoubleSlider"
QT_MOC_LITERAL(1, 14, 18), // "doubleValueChanged"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 5), // "value"
QT_MOC_LITERAL(4, 40, 15), // "newSliderAction"
QT_MOC_LITERAL(5, 56, 4), // "item"
QT_MOC_LITERAL(6, 61, 6), // "oldVal"
QT_MOC_LITERAL(7, 68, 6), // "newVal"
QT_MOC_LITERAL(8, 75, 18) // "notifyValueChanged"

    },
    "QDoubleSlider\0doubleValueChanged\0\0"
    "value\0newSliderAction\0item\0oldVal\0"
    "newVal\0notifyValueChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QDoubleSlider[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       4,    3,   32,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   39,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::QObjectStar, QMetaType::Double, QMetaType::Double,    5,    6,    7,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,

       0        // eod
};

void QDoubleSlider::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QDoubleSlider *_t = static_cast<QDoubleSlider *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->doubleValueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->newSliderAction((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 2: _t->notifyValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (QDoubleSlider::*_t)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QDoubleSlider::doubleValueChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (QDoubleSlider::*_t)(QObject * , double , double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QDoubleSlider::newSliderAction)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QDoubleSlider::staticMetaObject = {
    { &QSlider::staticMetaObject, qt_meta_stringdata_QDoubleSlider.data,
      qt_meta_data_QDoubleSlider,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QDoubleSlider::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QDoubleSlider::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QDoubleSlider.stringdata0))
        return static_cast<void*>(this);
    return QSlider::qt_metacast(_clname);
}

int QDoubleSlider::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSlider::qt_metacall(_c, _id, _a);
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
void QDoubleSlider::doubleValueChanged(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QDoubleSlider::newSliderAction(QObject * _t1, double _t2, double _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
struct qt_meta_stringdata_ProgressBar_t {
    QByteArrayData data[5];
    char stringdata0[51];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ProgressBar_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ProgressBar_t qt_meta_stringdata_ProgressBar = {
    {
QT_MOC_LITERAL(0, 0, 11), // "ProgressBar"
QT_MOC_LITERAL(1, 12, 14), // "renderFinished"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 13), // "partialUpdate"
QT_MOC_LITERAL(4, 42, 8) // "progress"

    },
    "ProgressBar\0renderFinished\0\0partialUpdate\0"
    "progress"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ProgressBar[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   25,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Double,    4,

       0        // eod
};

void ProgressBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ProgressBar *_t = static_cast<ProgressBar *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->renderFinished(); break;
        case 1: _t->partialUpdate((*reinterpret_cast< const double(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (ProgressBar::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ProgressBar::renderFinished)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ProgressBar::staticMetaObject = {
    { &QProgressBar::staticMetaObject, qt_meta_stringdata_ProgressBar.data,
      qt_meta_data_ProgressBar,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ProgressBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ProgressBar::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ProgressBar.stringdata0))
        return static_cast<void*>(this);
    return QProgressBar::qt_metacast(_clname);
}

int ProgressBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QProgressBar::qt_metacall(_c, _id, _a);
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
void ProgressBar::renderFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
struct qt_meta_stringdata_Interface_t {
    QByteArrayData data[80];
    char stringdata0[1093];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Interface_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Interface_t qt_meta_stringdata_Interface = {
    {
QT_MOC_LITERAL(0, 0, 9), // "Interface"
QT_MOC_LITERAL(1, 10, 17), // "imageActionStatus"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 6), // "status"
QT_MOC_LITERAL(4, 36, 14), // "updateCurrTerm"
QT_MOC_LITERAL(5, 51, 1), // "i"
QT_MOC_LITERAL(6, 53, 14), // "changeNumTerms"
QT_MOC_LITERAL(7, 68, 17), // "colorWheelChanged"
QT_MOC_LITERAL(8, 86, 5), // "index"
QT_MOC_LITERAL(9, 92, 14), // "setImagePushed"
QT_MOC_LITERAL(10, 107, 16), // "selectColorWheel"
QT_MOC_LITERAL(11, 124, 11), // "selectImage"
QT_MOC_LITERAL(12, 136, 14), // "changeFunction"
QT_MOC_LITERAL(13, 151, 17), // "aspectRatioLocked"
QT_MOC_LITERAL(14, 169, 7), // "checked"
QT_MOC_LITERAL(15, 177, 25), // "changingSliderWorldHeight"
QT_MOC_LITERAL(16, 203, 3), // "val"
QT_MOC_LITERAL(17, 207, 24), // "changingSliderWorldWidth"
QT_MOC_LITERAL(18, 232, 22), // "changingBoxWorldHeight"
QT_MOC_LITERAL(19, 255, 21), // "changingBoxWorldWidth"
QT_MOC_LITERAL(20, 277, 16), // "changeWorldWidth"
QT_MOC_LITERAL(21, 294, 17), // "changeWorldHeight"
QT_MOC_LITERAL(22, 312, 13), // "changeXCorner"
QT_MOC_LITERAL(23, 326, 13), // "changeYCorner"
QT_MOC_LITERAL(24, 340, 12), // "changeOWidth"
QT_MOC_LITERAL(25, 353, 13), // "changeOHeight"
QT_MOC_LITERAL(26, 367, 7), // "changeN"
QT_MOC_LITERAL(27, 375, 7), // "changeM"
QT_MOC_LITERAL(28, 383, 7), // "changeR"
QT_MOC_LITERAL(29, 391, 7), // "changeA"
QT_MOC_LITERAL(30, 399, 12), // "changeScaleA"
QT_MOC_LITERAL(31, 412, 12), // "changeScaleR"
QT_MOC_LITERAL(32, 425, 19), // "changeOverflowColor"
QT_MOC_LITERAL(33, 445, 5), // "color"
QT_MOC_LITERAL(34, 451, 19), // "exportImageFunction"
QT_MOC_LITERAL(35, 471, 17), // "cancelImageExport"
QT_MOC_LITERAL(36, 489, 16), // "startImageExport"
QT_MOC_LITERAL(37, 506, 13), // "resetFunction"
QT_MOC_LITERAL(38, 520, 16), // "loadFromSettings"
QT_MOC_LITERAL(39, 537, 17), // "saveCurrWorkspace"
QT_MOC_LITERAL(40, 555, 19), // "saveCurrWorkspaceAs"
QT_MOC_LITERAL(41, 575, 23), // "previewDisplayResetSize"
QT_MOC_LITERAL(42, 599, 16), // "snapshotFunction"
QT_MOC_LITERAL(43, 616, 13), // "termViewPopUp"
QT_MOC_LITERAL(44, 630, 7), // "addTerm"
QT_MOC_LITERAL(45, 638, 15), // "updateTermTable"
QT_MOC_LITERAL(46, 654, 4), // "cell"
QT_MOC_LITERAL(47, 659, 12), // "addTermTable"
QT_MOC_LITERAL(48, 672, 19), // "termViewCellClicked"
QT_MOC_LITERAL(49, 692, 3), // "row"
QT_MOC_LITERAL(50, 696, 3), // "col"
QT_MOC_LITERAL(51, 700, 16), // "resetTableButton"
QT_MOC_LITERAL(52, 717, 19), // "setPolarCoordinates"
QT_MOC_LITERAL(53, 737, 9), // "coeffFlag"
QT_MOC_LITERAL(54, 747, 6), // "radius"
QT_MOC_LITERAL(55, 754, 5), // "angle"
QT_MOC_LITERAL(56, 760, 12), // "loadSettings"
QT_MOC_LITERAL(57, 773, 8), // "fileName"
QT_MOC_LITERAL(58, 782, 24), // "popUpImageExportFinished"
QT_MOC_LITERAL(59, 807, 8), // "filePath"
QT_MOC_LITERAL(60, 816, 21), // "resetMainWindowButton"
QT_MOC_LITERAL(61, 838, 17), // "showFunctionIcons"
QT_MOC_LITERAL(62, 856, 22), // "showOverflowColorPopUp"
QT_MOC_LITERAL(63, 879, 20), // "addNewImageDataPoint"
QT_MOC_LITERAL(64, 900, 12), // "ComplexValue"
QT_MOC_LITERAL(65, 913, 4), // "data"
QT_MOC_LITERAL(66, 918, 18), // "showImageDataGraph"
QT_MOC_LITERAL(67, 937, 20), // "updateImageDataGraph"
QT_MOC_LITERAL(68, 958, 13), // "startShifting"
QT_MOC_LITERAL(69, 972, 5), // "point"
QT_MOC_LITERAL(70, 978, 14), // "updateShifting"
QT_MOC_LITERAL(71, 993, 14), // "finishShifting"
QT_MOC_LITERAL(72, 1008, 17), // "changeAspectRatio"
QT_MOC_LITERAL(73, 1026, 10), // "handleUndo"
QT_MOC_LITERAL(74, 1037, 10), // "handleRedo"
QT_MOC_LITERAL(75, 1048, 16), // "createUndoAction"
QT_MOC_LITERAL(76, 1065, 4), // "item"
QT_MOC_LITERAL(77, 1070, 6), // "oldVal"
QT_MOC_LITERAL(78, 1077, 6), // "newVal"
QT_MOC_LITERAL(79, 1084, 8) // "showInfo"

    },
    "Interface\0imageActionStatus\0\0status\0"
    "updateCurrTerm\0i\0changeNumTerms\0"
    "colorWheelChanged\0index\0setImagePushed\0"
    "selectColorWheel\0selectImage\0"
    "changeFunction\0aspectRatioLocked\0"
    "checked\0changingSliderWorldHeight\0val\0"
    "changingSliderWorldWidth\0"
    "changingBoxWorldHeight\0changingBoxWorldWidth\0"
    "changeWorldWidth\0changeWorldHeight\0"
    "changeXCorner\0changeYCorner\0changeOWidth\0"
    "changeOHeight\0changeN\0changeM\0changeR\0"
    "changeA\0changeScaleA\0changeScaleR\0"
    "changeOverflowColor\0color\0exportImageFunction\0"
    "cancelImageExport\0startImageExport\0"
    "resetFunction\0loadFromSettings\0"
    "saveCurrWorkspace\0saveCurrWorkspaceAs\0"
    "previewDisplayResetSize\0snapshotFunction\0"
    "termViewPopUp\0addTerm\0updateTermTable\0"
    "cell\0addTermTable\0termViewCellClicked\0"
    "row\0col\0resetTableButton\0setPolarCoordinates\0"
    "coeffFlag\0radius\0angle\0loadSettings\0"
    "fileName\0popUpImageExportFinished\0"
    "filePath\0resetMainWindowButton\0"
    "showFunctionIcons\0showOverflowColorPopUp\0"
    "addNewImageDataPoint\0ComplexValue\0"
    "data\0showImageDataGraph\0updateImageDataGraph\0"
    "startShifting\0point\0updateShifting\0"
    "finishShifting\0changeAspectRatio\0"
    "handleUndo\0handleRedo\0createUndoAction\0"
    "item\0oldVal\0newVal\0showInfo"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Interface[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      64,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  334,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,  337,    2, 0x08 /* Private */,
       6,    1,  340,    2, 0x08 /* Private */,
       7,    1,  343,    2, 0x08 /* Private */,
       9,    0,  346,    2, 0x08 /* Private */,
      10,    0,  347,    2, 0x08 /* Private */,
      11,    0,  348,    2, 0x08 /* Private */,
      12,    1,  349,    2, 0x08 /* Private */,
      13,    1,  352,    2, 0x08 /* Private */,
      15,    1,  355,    2, 0x08 /* Private */,
      17,    1,  358,    2, 0x08 /* Private */,
      18,    1,  361,    2, 0x08 /* Private */,
      19,    1,  364,    2, 0x08 /* Private */,
      20,    1,  367,    2, 0x08 /* Private */,
      20,    0,  370,    2, 0x08 /* Private */,
      21,    1,  371,    2, 0x08 /* Private */,
      21,    0,  374,    2, 0x08 /* Private */,
      22,    1,  375,    2, 0x08 /* Private */,
      22,    0,  378,    2, 0x08 /* Private */,
      23,    1,  379,    2, 0x08 /* Private */,
      23,    0,  382,    2, 0x08 /* Private */,
      24,    0,  383,    2, 0x08 /* Private */,
      25,    0,  384,    2, 0x08 /* Private */,
      26,    1,  385,    2, 0x08 /* Private */,
      27,    1,  388,    2, 0x08 /* Private */,
      28,    1,  391,    2, 0x08 /* Private */,
      29,    1,  394,    2, 0x08 /* Private */,
      30,    0,  397,    2, 0x08 /* Private */,
      30,    1,  398,    2, 0x08 /* Private */,
      31,    0,  401,    2, 0x08 /* Private */,
      31,    1,  402,    2, 0x08 /* Private */,
      32,    1,  405,    2, 0x08 /* Private */,
      34,    0,  408,    2, 0x08 /* Private */,
      35,    0,  409,    2, 0x08 /* Private */,
      36,    0,  410,    2, 0x08 /* Private */,
      37,    0,  411,    2, 0x08 /* Private */,
      38,    0,  412,    2, 0x08 /* Private */,
      39,    0,  413,    2, 0x08 /* Private */,
      40,    0,  414,    2, 0x08 /* Private */,
      41,    0,  415,    2, 0x08 /* Private */,
      42,    0,  416,    2, 0x08 /* Private */,
      43,    0,  417,    2, 0x08 /* Private */,
      44,    0,  418,    2, 0x08 /* Private */,
      45,    1,  419,    2, 0x08 /* Private */,
      47,    0,  422,    2, 0x08 /* Private */,
      48,    2,  423,    2, 0x08 /* Private */,
      51,    0,  428,    2, 0x08 /* Private */,
      52,    3,  429,    2, 0x08 /* Private */,
      56,    1,  436,    2, 0x08 /* Private */,
      58,    1,  439,    2, 0x08 /* Private */,
      60,    1,  442,    2, 0x08 /* Private */,
      61,    0,  445,    2, 0x08 /* Private */,
      62,    0,  446,    2, 0x08 /* Private */,
      63,    1,  447,    2, 0x08 /* Private */,
      66,    0,  450,    2, 0x08 /* Private */,
      67,    0,  451,    2, 0x08 /* Private */,
      68,    1,  452,    2, 0x08 /* Private */,
      70,    1,  455,    2, 0x08 /* Private */,
      71,    1,  458,    2, 0x08 /* Private */,
      72,    0,  461,    2, 0x08 /* Private */,
      73,    0,  462,    2, 0x08 /* Private */,
      74,    0,  463,    2, 0x08 /* Private */,
      75,    3,  464,    2, 0x08 /* Private */,
      79,    0,  471,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Bool,   14,
    QMetaType::Void, QMetaType::Double,   16,
    QMetaType::Void, QMetaType::Double,   16,
    QMetaType::Void, QMetaType::Double,   16,
    QMetaType::Void, QMetaType::Double,   16,
    QMetaType::Void, QMetaType::Double,   16,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   16,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   16,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Double,   16,
    QMetaType::Void, QMetaType::Double,   16,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   16,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   16,
    QMetaType::Void, QMetaType::QColor,   33,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QObjectStar,   46,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   49,   50,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QString,   53,   54,   55,
    QMetaType::QString, QMetaType::QString,   57,
    QMetaType::Void, QMetaType::QString,   59,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 64,   65,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,   69,
    QMetaType::Void, QMetaType::QPoint,   69,
    QMetaType::Void, QMetaType::QPoint,   69,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QObjectStar, QMetaType::Double, QMetaType::Double,   76,   77,   78,
    QMetaType::Void,

       0        // eod
};

void Interface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Interface *_t = static_cast<Interface *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->imageActionStatus((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->updateCurrTerm((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->changeNumTerms((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->colorWheelChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->setImagePushed(); break;
        case 5: _t->selectColorWheel(); break;
        case 6: _t->selectImage(); break;
        case 7: _t->changeFunction((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->aspectRatioLocked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->changingSliderWorldHeight((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 10: _t->changingSliderWorldWidth((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 11: _t->changingBoxWorldHeight((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 12: _t->changingBoxWorldWidth((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 13: _t->changeWorldWidth((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 14: _t->changeWorldWidth(); break;
        case 15: _t->changeWorldHeight((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 16: _t->changeWorldHeight(); break;
        case 17: _t->changeXCorner((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 18: _t->changeXCorner(); break;
        case 19: _t->changeYCorner((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 20: _t->changeYCorner(); break;
        case 21: _t->changeOWidth(); break;
        case 22: _t->changeOHeight(); break;
        case 23: _t->changeN((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 24: _t->changeM((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 25: _t->changeR((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 26: _t->changeA((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 27: _t->changeScaleA(); break;
        case 28: _t->changeScaleA((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 29: _t->changeScaleR(); break;
        case 30: _t->changeScaleR((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 31: _t->changeOverflowColor((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 32: _t->exportImageFunction(); break;
        case 33: _t->cancelImageExport(); break;
        case 34: _t->startImageExport(); break;
        case 35: _t->resetFunction(); break;
        case 36: _t->loadFromSettings(); break;
        case 37: _t->saveCurrWorkspace(); break;
        case 38: _t->saveCurrWorkspaceAs(); break;
        case 39: _t->previewDisplayResetSize(); break;
        case 40: _t->snapshotFunction(); break;
        case 41: _t->termViewPopUp(); break;
        case 42: _t->addTerm(); break;
        case 43: _t->updateTermTable((*reinterpret_cast< QObject*(*)>(_a[1]))); break;
        case 44: _t->addTermTable(); break;
        case 45: _t->termViewCellClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 46: _t->resetTableButton(); break;
        case 47: _t->setPolarCoordinates((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 48: { QString _r = _t->loadSettings((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 49: _t->popUpImageExportFinished((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 50: _t->resetMainWindowButton((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 51: _t->showFunctionIcons(); break;
        case 52: _t->showOverflowColorPopUp(); break;
        case 53: _t->addNewImageDataPoint((*reinterpret_cast< const ComplexValue(*)>(_a[1]))); break;
        case 54: _t->showImageDataGraph(); break;
        case 55: _t->updateImageDataGraph(); break;
        case 56: _t->startShifting((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 57: _t->updateShifting((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 58: _t->finishShifting((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 59: _t->changeAspectRatio(); break;
        case 60: _t->handleUndo(); break;
        case 61: _t->handleRedo(); break;
        case 62: _t->createUndoAction((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 63: _t->showInfo(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (Interface::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Interface::imageActionStatus)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Interface::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Interface.data,
      qt_meta_data_Interface,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Interface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Interface::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Interface.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Interface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 64)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 64;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 64)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 64;
    }
    return _id;
}

// SIGNAL 0
void Interface::imageActionStatus(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
