/****************************************************************************
** Meta object code from reading C++ file 'paasivu.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../bankautomat/paasivu.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'paasivu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_paaSivu_t {
    QByteArrayData data[9];
    char stringdata0[122];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_paaSivu_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_paaSivu_t qt_meta_stringdata_paaSivu = {
    {
QT_MOC_LITERAL(0, 0, 7), // "paaSivu"
QT_MOC_LITERAL(1, 8, 24), // "on_kirjauduNappi_clicked"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 24), // "on_takaisinNappi_clicked"
QT_MOC_LITERAL(4, 59, 14), // "kirjauduSisaan"
QT_MOC_LITERAL(5, 74, 14), // "QNetworkReply*"
QT_MOC_LITERAL(6, 89, 5), // "reply"
QT_MOC_LITERAL(7, 95, 11), // "myTimerSlot"
QT_MOC_LITERAL(8, 107, 14) // "myPinTimerSlot"

    },
    "paaSivu\0on_kirjauduNappi_clicked\0\0"
    "on_takaisinNappi_clicked\0kirjauduSisaan\0"
    "QNetworkReply*\0reply\0myTimerSlot\0"
    "myPinTimerSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_paaSivu[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    1,   41,    2, 0x08 /* Private */,
       7,    0,   44,    2, 0x0a /* Public */,
       8,    0,   45,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void paaSivu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        paaSivu *_t = static_cast<paaSivu *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_kirjauduNappi_clicked(); break;
        case 1: _t->on_takaisinNappi_clicked(); break;
        case 2: _t->kirjauduSisaan((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 3: _t->myTimerSlot(); break;
        case 4: _t->myPinTimerSlot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    }
}

const QMetaObject paaSivu::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_paaSivu.data,
      qt_meta_data_paaSivu,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *paaSivu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *paaSivu::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_paaSivu.stringdata0))
        return static_cast<void*>(const_cast< paaSivu*>(this));
    return QDialog::qt_metacast(_clname);
}

int paaSivu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
