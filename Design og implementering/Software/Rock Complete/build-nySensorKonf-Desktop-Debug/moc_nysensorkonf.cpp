/****************************************************************************
** Meta object code from reading C++ file 'nysensorkonf.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../nySensorKonf/nysensorkonf.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'nysensorkonf.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_NySensorKonf_t {
    QByteArrayData data[6];
    char stringdata[92];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_NySensorKonf_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_NySensorKonf_t qt_meta_stringdata_NySensorKonf = {
    {
QT_MOC_LITERAL(0, 0, 12),
QT_MOC_LITERAL(1, 13, 21),
QT_MOC_LITERAL(2, 35, 0),
QT_MOC_LITERAL(3, 36, 27),
QT_MOC_LITERAL(4, 64, 4),
QT_MOC_LITERAL(5, 69, 21)
    },
    "NySensorKonf\0on_backButton_clicked\0\0"
    "on_Sensordropdown_activated\0arg1\0"
    "on_saveButton_clicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NySensorKonf[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x08,
       3,    1,   30,    2, 0x08,
       5,    0,   33,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,

       0        // eod
};

void NySensorKonf::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NySensorKonf *_t = static_cast<NySensorKonf *>(_o);
        switch (_id) {
        case 0: _t->on_backButton_clicked(); break;
        //case 1: _t->on_Sensordropdown_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->on_saveButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject NySensorKonf::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_NySensorKonf.data,
      qt_meta_data_NySensorKonf,  qt_static_metacall, 0, 0}
};


const QMetaObject *NySensorKonf::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NySensorKonf::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NySensorKonf.stringdata))
        return static_cast<void*>(const_cast< NySensorKonf*>(this));
    return QWidget::qt_metacast(_clname);
}

int NySensorKonf::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
