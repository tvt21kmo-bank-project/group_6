/****************************************************************************
** Meta object code from reading C++ file 'tilitapahtumat.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../bankautomat/tilitapahtumat.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tilitapahtumat.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Tilitapahtumat_t {
    QByteArrayData data[9];
    char stringdata0[182];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Tilitapahtumat_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Tilitapahtumat_t qt_meta_stringdata_Tilitapahtumat = {
    {
QT_MOC_LITERAL(0, 0, 14), // "Tilitapahtumat"
QT_MOC_LITERAL(1, 15, 23), // "naytaTilitapahtumatSlot"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 14), // "QNetworkReply*"
QT_MOC_LITERAL(4, 55, 6), // "reply3"
QT_MOC_LITERAL(5, 62, 34), // "on_pushButton_KirjauduUlos_cl..."
QT_MOC_LITERAL(6, 97, 27), // "on_pushButton_Palaa_clicked"
QT_MOC_LITERAL(7, 125, 32), // "on_pushButton_NaytaLisaa_clicked"
QT_MOC_LITERAL(8, 158, 23) // "TilitapahtumatTimerSlot"

    },
    "Tilitapahtumat\0naytaTilitapahtumatSlot\0"
    "\0QNetworkReply*\0reply3\0"
    "on_pushButton_KirjauduUlos_clicked\0"
    "on_pushButton_Palaa_clicked\0"
    "on_pushButton_NaytaLisaa_clicked\0"
    "TilitapahtumatTimerSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Tilitapahtumat[] = {

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
       1,    1,   39,    2, 0x08 /* Private */,
       5,    0,   42,    2, 0x08 /* Private */,
       6,    0,   43,    2, 0x08 /* Private */,
       7,    0,   44,    2, 0x08 /* Private */,
       8,    0,   45,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Tilitapahtumat::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Tilitapahtumat *_t = static_cast<Tilitapahtumat *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->naytaTilitapahtumatSlot((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 1: _t->on_pushButton_KirjauduUlos_clicked(); break;
        case 2: _t->on_pushButton_Palaa_clicked(); break;
        case 3: _t->on_pushButton_NaytaLisaa_clicked(); break;
        case 4: _t->TilitapahtumatTimerSlot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    }
}

const QMetaObject Tilitapahtumat::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Tilitapahtumat.data,
      qt_meta_data_Tilitapahtumat,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Tilitapahtumat::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Tilitapahtumat::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Tilitapahtumat.stringdata0))
        return static_cast<void*>(const_cast< Tilitapahtumat*>(this));
    return QDialog::qt_metacast(_clname);
}

int Tilitapahtumat::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
