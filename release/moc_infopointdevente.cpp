/****************************************************************************
** Meta object code from reading C++ file 'infopointdevente.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../infopointdevente.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'infopointdevente.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_InfoPointDeVente_t {
    QByteArrayData data[8];
    char stringdata[152];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_InfoPointDeVente_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_InfoPointDeVente_t qt_meta_stringdata_InfoPointDeVente = {
    {
QT_MOC_LITERAL(0, 0, 16),
QT_MOC_LITERAL(1, 17, 29),
QT_MOC_LITERAL(2, 47, 0),
QT_MOC_LITERAL(3, 48, 3),
QT_MOC_LITERAL(4, 52, 6),
QT_MOC_LITERAL(5, 59, 31),
QT_MOC_LITERAL(6, 91, 29),
QT_MOC_LITERAL(7, 121, 29)
    },
    "InfoPointDeVente\0on_table_produits_cellClicked\0"
    "\0row\0column\0on_table_produits_cellActivated\0"
    "on_table_produits_cellChanged\0"
    "on_btn_modifier_stock_clicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_InfoPointDeVente[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   34,    2, 0x08,
       5,    2,   39,    2, 0x08,
       6,    2,   44,    2, 0x08,
       7,    0,   49,    2, 0x08,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void,

       0        // eod
};

void InfoPointDeVente::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        InfoPointDeVente *_t = static_cast<InfoPointDeVente *>(_o);
        switch (_id) {
        case 0: _t->on_table_produits_cellClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->on_table_produits_cellActivated((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->on_table_produits_cellChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->on_btn_modifier_stock_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject InfoPointDeVente::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_InfoPointDeVente.data,
      qt_meta_data_InfoPointDeVente,  qt_static_metacall, 0, 0}
};


const QMetaObject *InfoPointDeVente::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *InfoPointDeVente::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_InfoPointDeVente.stringdata))
        return static_cast<void*>(const_cast< InfoPointDeVente*>(this));
    return QDialog::qt_metacast(_clname);
}

int InfoPointDeVente::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
