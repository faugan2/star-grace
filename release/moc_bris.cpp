/****************************************************************************
** Meta object code from reading C++ file 'bris.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../bris.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bris.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Bris_t {
    QByteArrayData data[8];
    char stringdata[118];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Bris_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Bris_t qt_meta_stringdata_Bris = {
    {
QT_MOC_LITERAL(0, 0, 4),
QT_MOC_LITERAL(1, 5, 21),
QT_MOC_LITERAL(2, 27, 0),
QT_MOC_LITERAL(3, 28, 38),
QT_MOC_LITERAL(4, 67, 3),
QT_MOC_LITERAL(5, 71, 6),
QT_MOC_LITERAL(6, 78, 19),
QT_MOC_LITERAL(7, 98, 18)
    },
    "Bris\0on_pushButton_clicked\0\0"
    "on_table_liste_point_vente_cellClicked\0"
    "row\0column\0on_btn_edit_clicked\0"
    "on_btn_del_clicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Bris[] = {

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
       1,    0,   34,    2, 0x08,
       3,    2,   35,    2, 0x08,
       6,    0,   40,    2, 0x08,
       7,    0,   41,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    4,    5,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Bris::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Bris *_t = static_cast<Bris *>(_o);
        switch (_id) {
        case 0: _t->on_pushButton_clicked(); break;
        case 1: _t->on_table_liste_point_vente_cellClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->on_btn_edit_clicked(); break;
        case 3: _t->on_btn_del_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject Bris::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Bris.data,
      qt_meta_data_Bris,  qt_static_metacall, 0, 0}
};


const QMetaObject *Bris::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Bris::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Bris.stringdata))
        return static_cast<void*>(const_cast< Bris*>(this));
    return QDialog::qt_metacast(_clname);
}

int Bris::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
