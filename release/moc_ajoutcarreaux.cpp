/****************************************************************************
** Meta object code from reading C++ file 'ajoutcarreaux.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ajoutcarreaux.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ajoutcarreaux.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AjoutCarreaux_t {
    QByteArrayData data[20];
    char stringdata[397];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_AjoutCarreaux_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_AjoutCarreaux_t qt_meta_stringdata_AjoutCarreaux = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 21),
QT_MOC_LITERAL(2, 36, 0),
QT_MOC_LITERAL(3, 37, 9),
QT_MOC_LITERAL(4, 47, 4),
QT_MOC_LITERAL(5, 52, 21),
QT_MOC_LITERAL(6, 74, 4),
QT_MOC_LITERAL(7, 79, 19),
QT_MOC_LITERAL(8, 99, 18),
QT_MOC_LITERAL(9, 118, 38),
QT_MOC_LITERAL(10, 157, 3),
QT_MOC_LITERAL(11, 161, 6),
QT_MOC_LITERAL(12, 168, 12),
QT_MOC_LITERAL(13, 181, 29),
QT_MOC_LITERAL(14, 211, 28),
QT_MOC_LITERAL(15, 240, 38),
QT_MOC_LITERAL(16, 279, 38),
QT_MOC_LITERAL(17, 318, 36),
QT_MOC_LITERAL(18, 355, 5),
QT_MOC_LITERAL(19, 361, 34)
    },
    "AjoutCarreaux\0on_pushButton_clicked\0"
    "\0load_list\0init\0on_search_textChanged\0"
    "arg1\0on_btn_edit_clicked\0on_btn_del_clicked\0"
    "on_table_liste_point_vente_cellClicked\0"
    "row\0column\0load_formats\0"
    "on_btn_modifier_stock_clicked\0"
    "on_format_currentTextChanged\0"
    "on_table_liste_point_vente_cellChanged\0"
    "on_table_liste_point_vente_cellEntered\0"
    "on_table_liste_point_vente_activated\0"
    "index\0on_table_liste_point_vente_entered\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AjoutCarreaux[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x08,
       3,    0,   85,    2, 0x08,
       4,    0,   86,    2, 0x08,
       5,    1,   87,    2, 0x08,
       7,    0,   90,    2, 0x08,
       8,    0,   91,    2, 0x08,
       9,    2,   92,    2, 0x08,
      12,    0,   97,    2, 0x08,
      13,    0,   98,    2, 0x08,
      14,    1,   99,    2, 0x08,
      15,    2,  102,    2, 0x08,
      16,    2,  107,    2, 0x08,
      17,    1,  112,    2, 0x08,
      19,    1,  115,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   10,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   10,   11,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   10,   11,
    QMetaType::Void, QMetaType::QModelIndex,   18,
    QMetaType::Void, QMetaType::QModelIndex,   18,

       0        // eod
};

void AjoutCarreaux::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AjoutCarreaux *_t = static_cast<AjoutCarreaux *>(_o);
        switch (_id) {
        case 0: _t->on_pushButton_clicked(); break;
        case 1: _t->load_list(); break;
        case 2: _t->init(); break;
        case 3: _t->on_search_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->on_btn_edit_clicked(); break;
        case 5: _t->on_btn_del_clicked(); break;
        case 6: _t->on_table_liste_point_vente_cellClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->load_formats(); break;
        case 8: _t->on_btn_modifier_stock_clicked(); break;
        case 9: _t->on_format_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->on_table_liste_point_vente_cellChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 11: _t->on_table_liste_point_vente_cellEntered((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 12: _t->on_table_liste_point_vente_activated((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 13: _t->on_table_liste_point_vente_entered((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject AjoutCarreaux::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_AjoutCarreaux.data,
      qt_meta_data_AjoutCarreaux,  qt_static_metacall, 0, 0}
};


const QMetaObject *AjoutCarreaux::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AjoutCarreaux::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AjoutCarreaux.stringdata))
        return static_cast<void*>(const_cast< AjoutCarreaux*>(this));
    return QDialog::qt_metacast(_clname);
}

int AjoutCarreaux::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
