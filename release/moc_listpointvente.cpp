/****************************************************************************
** Meta object code from reading C++ file 'listpointvente.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../listpointvente.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'listpointvente.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_listpointvente_t {
    QByteArrayData data[13];
    char stringdata[194];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_listpointvente_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_listpointvente_t qt_meta_stringdata_listpointvente = {
    {
QT_MOC_LITERAL(0, 0, 14),
QT_MOC_LITERAL(1, 15, 21),
QT_MOC_LITERAL(2, 37, 0),
QT_MOC_LITERAL(3, 38, 9),
QT_MOC_LITERAL(4, 48, 4),
QT_MOC_LITERAL(5, 53, 38),
QT_MOC_LITERAL(6, 92, 3),
QT_MOC_LITERAL(7, 96, 6),
QT_MOC_LITERAL(8, 103, 19),
QT_MOC_LITERAL(9, 123, 18),
QT_MOC_LITERAL(10, 142, 21),
QT_MOC_LITERAL(11, 164, 4),
QT_MOC_LITERAL(12, 169, 23)
    },
    "listpointvente\0on_pushButton_clicked\0"
    "\0load_list\0init\0on_table_liste_point_vente_cellClicked\0"
    "row\0column\0on_btn_edit_clicked\0"
    "on_btn_del_clicked\0on_search_textChanged\0"
    "arg1\0on_pushButton_3_clicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_listpointvente[] = {

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
       1,    0,   54,    2, 0x08,
       3,    0,   55,    2, 0x08,
       4,    0,   56,    2, 0x08,
       5,    2,   57,    2, 0x08,
       8,    0,   62,    2, 0x08,
       9,    0,   63,    2, 0x08,
      10,    1,   64,    2, 0x08,
      12,    0,   67,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void,

       0        // eod
};

void listpointvente::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        listpointvente *_t = static_cast<listpointvente *>(_o);
        switch (_id) {
        case 0: _t->on_pushButton_clicked(); break;
        case 1: _t->load_list(); break;
        case 2: _t->init(); break;
        case 3: _t->on_table_liste_point_vente_cellClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->on_btn_edit_clicked(); break;
        case 5: _t->on_btn_del_clicked(); break;
        case 6: _t->on_search_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->on_pushButton_3_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject listpointvente::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_listpointvente.data,
      qt_meta_data_listpointvente,  qt_static_metacall, 0, 0}
};


const QMetaObject *listpointvente::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *listpointvente::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_listpointvente.stringdata))
        return static_cast<void*>(const_cast< listpointvente*>(this));
    return QDialog::qt_metacast(_clname);
}

int listpointvente::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_END_MOC_NAMESPACE
