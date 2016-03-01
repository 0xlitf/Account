/****************************************************************************
** Meta object code from reading C++ file 'billwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "stdafx.h"
#include "../../billwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'billwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_BillWidget_t {
    QByteArrayData data[9];
    char stringdata0[128];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BillWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BillWidget_t qt_meta_stringdata_BillWidget = {
    {
QT_MOC_LITERAL(0, 0, 10), // "BillWidget"
QT_MOC_LITERAL(1, 11, 14), // "signal_addData"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 13), // "showTableView"
QT_MOC_LITERAL(4, 41, 23), // "on_calculateBtn_clicked"
QT_MOC_LITERAL(5, 65, 20), // "on_importBtn_clicked"
QT_MOC_LITERAL(6, 86, 20), // "on_deleteBtn_clicked"
QT_MOC_LITERAL(7, 107, 15), // "updateTableView"
QT_MOC_LITERAL(8, 123, 4) // "date"

    },
    "BillWidget\0signal_addData\0\0showTableView\0"
    "on_calculateBtn_clicked\0on_importBtn_clicked\0"
    "on_deleteBtn_clicked\0updateTableView\0"
    "date"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BillWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   45,    2, 0x0a /* Public */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    1,   49,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QDate,    8,

       0        // eod
};

void BillWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BillWidget *_t = static_cast<BillWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_addData(); break;
        case 1: _t->showTableView(); break;
        case 2: _t->on_calculateBtn_clicked(); break;
        case 3: _t->on_importBtn_clicked(); break;
        case 4: _t->on_deleteBtn_clicked(); break;
        case 5: _t->updateTableView((*reinterpret_cast< const QDate(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (BillWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BillWidget::signal_addData)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject BillWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_BillWidget.data,
      qt_meta_data_BillWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *BillWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BillWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_BillWidget.stringdata0))
        return static_cast<void*>(const_cast< BillWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int BillWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void BillWidget::signal_addData()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
