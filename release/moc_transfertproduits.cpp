/****************************************************************************
** Meta object code from reading C++ file 'transfertproduits.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../transfertproduits.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'transfertproduits.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TransfertProduits_t {
    QByteArrayData data[12];
    char stringdata[215];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_TransfertProduits_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_TransfertProduits_t qt_meta_stringdata_TransfertProduits = {
    {
QT_MOC_LITERAL(0, 0, 17),
QT_MOC_LITERAL(1, 18, 25),
QT_MOC_LITERAL(2, 44, 0),
QT_MOC_LITERAL(3, 45, 5),
QT_MOC_LITERAL(4, 51, 30),
QT_MOC_LITERAL(5, 82, 21),
QT_MOC_LITERAL(6, 104, 38),
QT_MOC_LITERAL(7, 143, 3),
QT_MOC_LITERAL(8, 147, 6),
QT_MOC_LITERAL(9, 154, 18),
QT_MOC_LITERAL(10, 173, 19),
QT_MOC_LITERAL(11, 193, 20)
    },
    "TransfertProduits\0on_du_currentIndexChanged\0"
    "\0index\0on_produit_currentIndexChanged\0"
    "on_pushButton_clicked\0"
    "on_table_liste_point_vente_cellClicked\0"
    "row\0column\0on_btn_del_clicked\0"
    "on_btn_edit_clicked\0on_btn_print_clicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TransfertProduits[] = {

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
       1,    1,   49,    2, 0x08,
       4,    1,   52,    2, 0x08,
       5,    0,   55,    2, 0x08,
       6,    2,   56,    2, 0x08,
       9,    0,   61,    2, 0x08,
      10,    0,   62,    2, 0x08,
      11,    0,   63,    2, 0x08,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    7,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TransfertProduits::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TransfertProduits *_t = static_cast<TransfertProduits *>(_o);
        switch (_id) {
        case 0: _t->on_du_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_produit_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_pushButton_clicked(); break;
        case 3: _t->on_table_liste_point_vente_cellClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->on_btn_del_clicked(); break;
        case 5: _t->on_btn_edit_clicked(); break;
        case 6: _t->on_btn_print_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject TransfertProduits::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_TransfertProduits.data,
      qt_meta_data_TransfertProduits,  qt_static_metacall, 0, 0}
};


const QMetaObject *TransfertProduits::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TransfertProduits::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TransfertProduits.stringdata))
        return static_cast<void*>(const_cast< TransfertProduits*>(this));
    return QDialog::qt_metacast(_clname);
}

int TransfertProduits::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
