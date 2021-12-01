/****************************************************************************
** Meta object code from reading C++ file 'pano.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../bankautomat/pano.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pano.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Pano_t {
    QByteArrayData data[10];
    char stringdata0[227];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Pano_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Pano_t qt_meta_stringdata_Pano = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Pano"
QT_MOC_LITERAL(1, 5, 28), // "on_pushButton_pane20_clicked"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 27), // "on_pushButton_Palaa_clicked"
QT_MOC_LITERAL(4, 63, 29), // "on_pushButton_MuuPano_clicked"
QT_MOC_LITERAL(5, 93, 32), // "on_pushButtonKuuskymppia_clicked"
QT_MOC_LITERAL(6, 126, 13), // "PaneTimerSlot"
QT_MOC_LITERAL(7, 140, 27), // "on_pushButtonSatane_clicked"
QT_MOC_LITERAL(8, 168, 27), // "on_pushButtonNelkyt_clicked"
QT_MOC_LITERAL(9, 196, 30) // "on_pushButtonKaksSataa_clicked"

    },
    "Pano\0on_pushButton_pane20_clicked\0\0"
    "on_pushButton_Palaa_clicked\0"
    "on_pushButton_MuuPano_clicked\0"
    "on_pushButtonKuuskymppia_clicked\0"
    "PaneTimerSlot\0on_pushButtonSatane_clicked\0"
    "on_pushButtonNelkyt_clicked\0"
    "on_pushButtonKaksSataa_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Pano[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    0,   55,    2, 0x08 /* Private */,
       4,    0,   56,    2, 0x08 /* Private */,
       5,    0,   57,    2, 0x08 /* Private */,
       6,    0,   58,    2, 0x08 /* Private */,
       7,    0,   59,    2, 0x08 /* Private */,
       8,    0,   60,    2, 0x08 /* Private */,
       9,    0,   61,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Pano::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Pano *_t = static_cast<Pano *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_pane20_clicked(); break;
        case 1: _t->on_pushButton_Palaa_clicked(); break;
        case 2: _t->on_pushButton_MuuPano_clicked(); break;
        case 3: _t->on_pushButtonKuuskymppia_clicked(); break;
        case 4: _t->PaneTimerSlot(); break;
        case 5: _t->on_pushButtonSatane_clicked(); break;
        case 6: _t->on_pushButtonNelkyt_clicked(); break;
        case 7: _t->on_pushButtonKaksSataa_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Pano::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Pano.data,
      qt_meta_data_Pano,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Pano::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Pano::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Pano.stringdata0))
        return static_cast<void*>(const_cast< Pano*>(this));
    return QDialog::qt_metacast(_clname);
}

int Pano::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
