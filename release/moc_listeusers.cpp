/****************************************************************************
** Meta object code from reading C++ file 'listeusers.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../listeusers.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'listeusers.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ListeUsers_t {
    QByteArrayData data[11];
    char stringdata[166];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ListeUsers_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_ListeUsers_t qt_meta_stringdata_ListeUsers = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 21),
QT_MOC_LITERAL(2, 33, 0),
QT_MOC_LITERAL(3, 34, 32),
QT_MOC_LITERAL(4, 67, 3),
QT_MOC_LITERAL(5, 71, 6),
QT_MOC_LITERAL(6, 78, 18),
QT_MOC_LITERAL(7, 97, 19),
QT_MOC_LITERAL(8, 117, 21),
QT_MOC_LITERAL(9, 139, 4),
QT_MOC_LITERAL(10, 144, 20)
    },
    "ListeUsers\0on_pushButton_clicked\0\0"
    "on_table_liste_users_cellClicked\0row\0"
    "column\0on_btn_del_clicked\0on_btn_edit_clicked\0"
    "on_search_textChanged\0arg1\0"
    "on_btn_droit_clicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ListeUsers[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08,
       3,    2,   45,    2, 0x08,
       6,    0,   50,    2, 0x08,
       7,    0,   51,    2, 0x08,
       8,    1,   52,    2, 0x08,
      10,    0,   55,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void,

       0        // eod
};

void ListeUsers::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ListeUsers *_t = static_cast<ListeUsers *>(_o);
        switch (_id) {
        case 0: _t->on_pushButton_clicked(); break;
        case 1: _t->on_table_liste_users_cellClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->on_btn_del_clicked(); break;
        case 3: _t->on_btn_edit_clicked(); break;
        case 4: _t->on_search_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->on_btn_droit_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject ListeUsers::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ListeUsers.data,
      qt_meta_data_ListeUsers,  qt_static_metacall, 0, 0}
};


const QMetaObject *ListeUsers::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ListeUsers::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ListeUsers.stringdata))
        return static_cast<void*>(const_cast< ListeUsers*>(this));
    return QDialog::qt_metacast(_clname);
}

int ListeUsers::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
