/****************************************************************************
** Meta object code from reading C++ file 'Ringboard.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Ringboard.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Ringboard.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Ringboard_t {
    QByteArrayData data[31];
    char stringdata0[416];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Ringboard_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Ringboard_t qt_meta_stringdata_Ringboard = {
    {
QT_MOC_LITERAL(0, 0, 9), // "Ringboard"
QT_MOC_LITERAL(1, 10, 17), // "startAngleChanged"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 10), // "startAngle"
QT_MOC_LITERAL(4, 40, 16), // "spanAngleChanged"
QT_MOC_LITERAL(5, 57, 9), // "spanAngle"
QT_MOC_LITERAL(6, 67, 18), // "radiusInnerChanged"
QT_MOC_LITERAL(7, 86, 11), // "radiusInner"
QT_MOC_LITERAL(8, 98, 18), // "radiusOuterChanged"
QT_MOC_LITERAL(9, 117, 11), // "radiusOuter"
QT_MOC_LITERAL(10, 129, 17), // "roundConerChanged"
QT_MOC_LITERAL(11, 147, 10), // "roundConer"
QT_MOC_LITERAL(12, 158, 15), // "gradientChanged"
QT_MOC_LITERAL(13, 174, 8), // "Gradient"
QT_MOC_LITERAL(14, 183, 8), // "gradient"
QT_MOC_LITERAL(15, 192, 18), // "siglanguageChanged"
QT_MOC_LITERAL(16, 211, 11), // "timeoutSlot"
QT_MOC_LITERAL(17, 223, 13), // "setStartAngle"
QT_MOC_LITERAL(18, 237, 12), // "setSpanAngle"
QT_MOC_LITERAL(19, 250, 14), // "setRadiusInner"
QT_MOC_LITERAL(20, 265, 14), // "setRadiusOuter"
QT_MOC_LITERAL(21, 280, 13), // "setRoundConer"
QT_MOC_LITERAL(22, 294, 11), // "setGradient"
QT_MOC_LITERAL(23, 306, 11), // "setlanguage"
QT_MOC_LITERAL(24, 318, 8), // "language"
QT_MOC_LITERAL(25, 327, 11), // "emptystring"
QT_MOC_LITERAL(26, 339, 10), // "NoGradient"
QT_MOC_LITERAL(27, 350, 14), // "RadialGradiant"
QT_MOC_LITERAL(28, 365, 15), // "ConicalGradiant"
QT_MOC_LITERAL(29, 381, 14), // "LinearGradient"
QT_MOC_LITERAL(30, 396, 19) // "LinearGradientlight"

    },
    "Ringboard\0startAngleChanged\0\0startAngle\0"
    "spanAngleChanged\0spanAngle\0"
    "radiusInnerChanged\0radiusInner\0"
    "radiusOuterChanged\0radiusOuter\0"
    "roundConerChanged\0roundConer\0"
    "gradientChanged\0Gradient\0gradient\0"
    "siglanguageChanged\0timeoutSlot\0"
    "setStartAngle\0setSpanAngle\0setRadiusInner\0"
    "setRadiusOuter\0setRoundConer\0setGradient\0"
    "setlanguage\0language\0emptystring\0"
    "NoGradient\0RadialGradiant\0ConicalGradiant\0"
    "LinearGradient\0LinearGradientlight"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Ringboard[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       7,  130, // properties
       1,  158, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x06 /* Public */,
       4,    1,   92,    2, 0x06 /* Public */,
       6,    1,   95,    2, 0x06 /* Public */,
       8,    1,   98,    2, 0x06 /* Public */,
      10,    1,  101,    2, 0x06 /* Public */,
      12,    1,  104,    2, 0x06 /* Public */,
      15,    0,  107,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      16,    0,  108,    2, 0x0a /* Public */,
      17,    1,  109,    2, 0x0a /* Public */,
      18,    1,  112,    2, 0x0a /* Public */,
      19,    1,  115,    2, 0x0a /* Public */,
      20,    1,  118,    2, 0x0a /* Public */,
      21,    1,  121,    2, 0x0a /* Public */,
      22,    1,  124,    2, 0x0a /* Public */,
      23,    1,  127,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QReal,    3,
    QMetaType::Void, QMetaType::QReal,    5,
    QMetaType::Void, QMetaType::QReal,    7,
    QMetaType::Void, QMetaType::QReal,    9,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QReal,    3,
    QMetaType::Void, QMetaType::QReal,    5,
    QMetaType::Void, QMetaType::QReal,    7,
    QMetaType::Void, QMetaType::QReal,    9,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, QMetaType::Int,   24,

 // properties: name, type, flags
       3, QMetaType::QReal, 0x00495103,
       5, QMetaType::QReal, 0x00495103,
       7, QMetaType::QReal, 0x00495103,
       9, QMetaType::QReal, 0x00495103,
      11, QMetaType::Bool, 0x00495103,
      14, 0x80000000 | 13, 0x0049510b,
      25, QMetaType::QString, 0x00495001,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,
       4,
       5,
       6,

 // enums: name, flags, count, data
      13, 0x0,    5,  162,

 // enum data: key, value
      26, uint(Ringboard::NoGradient),
      27, uint(Ringboard::RadialGradiant),
      28, uint(Ringboard::ConicalGradiant),
      29, uint(Ringboard::LinearGradient),
      30, uint(Ringboard::LinearGradientlight),

       0        // eod
};

void Ringboard::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Ringboard *_t = static_cast<Ringboard *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->startAngleChanged((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 1: _t->spanAngleChanged((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 2: _t->radiusInnerChanged((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 3: _t->radiusOuterChanged((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 4: _t->roundConerChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->gradientChanged((*reinterpret_cast< Gradient(*)>(_a[1]))); break;
        case 6: _t->siglanguageChanged(); break;
        case 7: _t->timeoutSlot(); break;
        case 8: _t->setStartAngle((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 9: _t->setSpanAngle((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 10: _t->setRadiusInner((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 11: _t->setRadiusOuter((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 12: _t->setRoundConer((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->setGradient((*reinterpret_cast< Gradient(*)>(_a[1]))); break;
        case 14: _t->setlanguage((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Ringboard::*_t)(qreal );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Ringboard::startAngleChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Ringboard::*_t)(qreal );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Ringboard::spanAngleChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Ringboard::*_t)(qreal );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Ringboard::radiusInnerChanged)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Ringboard::*_t)(qreal );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Ringboard::radiusOuterChanged)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (Ringboard::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Ringboard::roundConerChanged)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (Ringboard::*_t)(Gradient );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Ringboard::gradientChanged)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (Ringboard::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Ringboard::siglanguageChanged)) {
                *result = 6;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        Ringboard *_t = static_cast<Ringboard *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< qreal*>(_v) = _t->startAngle(); break;
        case 1: *reinterpret_cast< qreal*>(_v) = _t->spanAngle(); break;
        case 2: *reinterpret_cast< qreal*>(_v) = _t->radiusInner(); break;
        case 3: *reinterpret_cast< qreal*>(_v) = _t->radiusOuter(); break;
        case 4: *reinterpret_cast< bool*>(_v) = _t->roundConer(); break;
        case 5: *reinterpret_cast< Gradient*>(_v) = _t->gradient(); break;
        case 6: *reinterpret_cast< QString*>(_v) = _t->emptystring(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        Ringboard *_t = static_cast<Ringboard *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setStartAngle(*reinterpret_cast< qreal*>(_v)); break;
        case 1: _t->setSpanAngle(*reinterpret_cast< qreal*>(_v)); break;
        case 2: _t->setRadiusInner(*reinterpret_cast< qreal*>(_v)); break;
        case 3: _t->setRadiusOuter(*reinterpret_cast< qreal*>(_v)); break;
        case 4: _t->setRoundConer(*reinterpret_cast< bool*>(_v)); break;
        case 5: _t->setGradient(*reinterpret_cast< Gradient*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject Ringboard::staticMetaObject = {
    { &QQuickPaintedItem::staticMetaObject, qt_meta_stringdata_Ringboard.data,
      qt_meta_data_Ringboard,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Ringboard::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Ringboard::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Ringboard.stringdata0))
        return static_cast<void*>(const_cast< Ringboard*>(this));
    return QQuickPaintedItem::qt_metacast(_clname);
}

int Ringboard::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QQuickPaintedItem::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 7;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Ringboard::startAngleChanged(qreal _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Ringboard::spanAngleChanged(qreal _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Ringboard::radiusInnerChanged(qreal _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Ringboard::radiusOuterChanged(qreal _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Ringboard::roundConerChanged(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Ringboard::gradientChanged(Gradient _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Ringboard::siglanguageChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
