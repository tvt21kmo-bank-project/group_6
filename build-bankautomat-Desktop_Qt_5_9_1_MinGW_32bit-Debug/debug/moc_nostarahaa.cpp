/****************************************************************************
** Meta object code from reading C++ file 'nostarahaa.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../bankautomat/nostarahaa.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'nostarahaa.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_NostaRahaa_t {
    QByteArrayData data[9];
    char stringdata0[155];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NostaRahaa_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NostaRahaa_t qt_meta_stringdata_NostaRahaa = {
    {
QT_MOC_LITERAL(0, 0, 10), // "NostaRahaa"
QT_MOC_LITERAL(1, 11, 24), // "on_pushButton_20_clicked"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 27), // "on_pushButton_Palaa_clicked"
QT_MOC_LITERAL(4, 65, 15), // "naytaSaldoSlot2"
QT_MOC_LITERAL(5, 81, 14), // "QNetworkReply*"
QT_MOC_LITERAL(6, 96, 6), // "reply3"
QT_MOC_LITERAL(7, 103, 19), // "nostaRahaaTimerSlot"
QT_MOC_LITERAL(8, 123, 31) // "on_pushButton_Muu_Summa_clicked"

    },
    "NostaRahaa\0on_pushButton_20_clicked\0"
    "\0on_pushButton_Palaa_clicked\0"
    "naytaSaldoSlot2\0QNetworkReply*\0reply3\0"
    "nostaRahaaTimerSlot\0on_pushButton_Muu_Summa_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NostaRahaa[] = {

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
       7,    0,   44,    2, 0x08 /* Private */,
       8,    0,   45,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void NostaRahaa::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NostaRahaa *_t = static_cast<NostaRahaa *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_20_clicked(); break;
        case 1: _t->on_pushButton_Palaa_clicked(); break;
        case 2: _t->naytaSaldoSlot2((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 3: _t->nostaRahaaTimerSlot(); break;
        case 4: _t->on_pushButton_Muu_Summa_clicked(); break;
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

const QMetaObject NostaRahaa::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_NostaRahaa.data,
      qt_meta_data_NostaRahaa,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *NostaRahaa::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NostaRahaa::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_NostaRahaa.stringdata0))
        return static_cast<void*>(const_cast< NostaRahaa*>(this));
    return QDialog::qt_metacast(_clname);
}

int NostaRahaa::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
