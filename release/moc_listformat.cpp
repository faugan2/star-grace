/****************************************************************************
** Meta object code from reading C++ file 'listformat.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../listformat.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'listformat.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Listformat_t {
    QByteArrayData data[14];
    char stringdata[207];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Listformat_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Listformat_t qt_meta_stringdata_Listformat = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 21),
QT_MOC_LITERAL(2, 33, 0),
QT_MOC_LITERAL(3, 34, 9),
QT_MOC_LITERAL(4, 44, 4),
QT_MOC_LITERAL(5, 49, 18),
QT_MOC_LITERAL(6, 68, 34),
QT_MOC_LITERAL(7, 103, 5),
QT_MOC_LITERAL(8, 109, 38),
QT_MOC_LITERAL(9, 148, 3),
QT_MOC_LITERAL(10, 152, 6),
QT_MOC_LITERAL(11, 159, 21),
QT_MOC_LITERAL(12, 181, 4),
QT_MOC_LITERAL(13, 186, 19)
    },
    "Listformat\0on_pushButton_clicked\0\0"
    "load_list\0init\0on_btn_del_clicked\0"
    "on_table_liste_point_vente_clicked\0"
    "index\0on_table_liste_point_vente_cellClicked\0"
    "row\0column\0on_search_textChanged\0arg1\0"
    "on_btn_edit_clicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Listformat[] = {

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
       5,    0,   57,    2, 0x08,
       6,    1,   58,    2, 0x08,
       8,    2,   61,    2, 0x08,
      11,    1,   66,    2, 0x08,
      13,    0,   69,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    7,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    9,   10,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void,

       0        // eod
};

void Listformat::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Listformat *_t = static_cast<Listformat *>(_o);
        switch (_id) {
        case 0: _t->on_pushButton_clicked(); break;
        case 1: _t->load_list(); break;
        case 2: _t->init(); break;
        case 3: _t->on_btn_del_clicked(); break;
        case 4: _t->on_table_liste_point_vente_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 5: _t->on_table_liste_point_vente_cellClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->on_search_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->on_btn_edit_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject Listformat::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Listformat.data,
      qt_meta_data_Listformat,  qt_static_metacall, 0, 0}
};


const QMetaObject *Listformat::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Listformat::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Listformat.stringdata))
        return static_cast<void*>(const_cast< Listformat*>(this));
    return QDialog::qt_metacast(_clname);
}

int Listformat::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
