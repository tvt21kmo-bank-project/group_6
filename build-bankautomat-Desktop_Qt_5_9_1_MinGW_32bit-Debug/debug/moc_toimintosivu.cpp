/****************************************************************************
** Meta object code from reading C++ file 'toimintosivu.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../bankautomat/toimintosivu.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'toimintosivu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Toimintosivu_t {
    QByteArrayData data[11];
    char stringdata0[226];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Toimintosivu_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Toimintosivu_t qt_meta_stringdata_Toimintosivu = {
    {
QT_MOC_LITERAL(0, 0, 12), // "Toimintosivu"
QT_MOC_LITERAL(1, 13, 34), // "on_pushButtonKirjauduUlos2_cl..."
QT_MOC_LITERAL(2, 48, 0), // ""
QT_MOC_LITERAL(3, 49, 26), // "on_pushButtonSaldo_clicked"
QT_MOC_LITERAL(4, 76, 16), // "naytaAsiakasSlot"
QT_MOC_LITERAL(5, 93, 14), // "QNetworkReply*"
QT_MOC_LITERAL(6, 108, 6), // "reply2"
QT_MOC_LITERAL(7, 115, 26), // "on_pushButtonNosta_clicked"
QT_MOC_LITERAL(8, 142, 35), // "on_pushButtonTilitapahtumat_c..."
QT_MOC_LITERAL(9, 178, 25), // "on_pushButtonPane_clicked"
QT_MOC_LITERAL(10, 204, 21) // "toimintosivuTimerSlot"

    },
    "Toimintosivu\0on_pushButtonKirjauduUlos2_clicked\0"
    "\0on_pushButtonSaldo_clicked\0"
    "naytaAsiakasSlot\0QNetworkReply*\0reply2\0"
    "on_pushButtonNosta_clicked\0"
    "on_pushButtonTilitapahtumat_clicked\0"
    "on_pushButtonPane_clicked\0"
    "toimintosivuTimerSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Toimintosivu[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    1,   51,    2, 0x08 /* Private */,
       7,    0,   54,    2, 0x08 /* Private */,
       8,    0,   55,    2, 0x08 /* Private */,
       9,    0,   56,    2, 0x08 /* Private */,
      10,    0,   57,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Toimintosivu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Toimintosivu *_t = static_cast<Toimintosivu *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButtonKirjauduUlos2_clicked(); break;
        case 1: _t->on_pushButtonSaldo_clicked(); break;
        case 2: _t->naytaAsiakasSlot((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 3: _t->on_pushButtonNosta_clicked(); break;
        case 4: _t->on_pushButtonTilitapahtumat_clicked(); break;
        case 5: _t->on_pushButtonPane_clicked(); break;
        case 6: _t->toimintosivuTimerSlot(); break;
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

const QMetaObject Toimintosivu::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Toimintosivu.data,
      qt_meta_data_Toimintosivu,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Toimintosivu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Toimintosivu::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Toimintosivu.stringdata0))
        return static_cast<void*>(const_cast< Toimintosivu*>(this));
    return QDialog::qt_metacast(_clname);
}

int Toimintosivu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE