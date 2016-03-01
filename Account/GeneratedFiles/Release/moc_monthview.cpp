/****************************************************************************
** Meta object code from reading C++ file 'monthview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "stdafx.h"
#include "../../monthview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'monthview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MonthView_t {
    QByteArrayData data[10];
    char stringdata0[147];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MonthView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MonthView_t qt_meta_stringdata_MonthView = {
    {
QT_MOC_LITERAL(0, 0, 9), // "MonthView"
QT_MOC_LITERAL(1, 10, 13), // "showTableView"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 15), // "updateTableView"
QT_MOC_LITERAL(4, 41, 4), // "date"
QT_MOC_LITERAL(5, 46, 20), // "slot_ComboBoxChanged"
QT_MOC_LITERAL(6, 67, 24), // "slot_comboBoxTextChanged"
QT_MOC_LITERAL(7, 92, 14), // "updateComboBox"
QT_MOC_LITERAL(8, 107, 20), // "on_deleteBtn_clicked"
QT_MOC_LITERAL(9, 128, 18) // "on_viewBtn_clicked"

    },
    "MonthView\0showTableView\0\0updateTableView\0"
    "date\0slot_ComboBoxChanged\0"
    "slot_comboBoxTextChanged\0updateComboBox\0"
    "on_deleteBtn_clicked\0on_viewBtn_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MonthView[] = {

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
       1,    0,   49,    2, 0x0a /* Public */,
       3,    1,   50,    2, 0x0a /* Public */,
       5,    0,   53,    2, 0x0a /* Public */,
       6,    1,   54,    2, 0x0a /* Public */,
       7,    0,   57,    2, 0x0a /* Public */,
       8,    0,   58,    2, 0x08 /* Private */,
       9,    0,   59,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QDate,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MonthView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MonthView *_t = static_cast<MonthView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->showTableView(); break;
        case 1: _t->updateTableView((*reinterpret_cast< const QDate(*)>(_a[1]))); break;
        case 2: _t->slot_ComboBoxChanged(); break;
        case 3: _t->slot_comboBoxTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->updateComboBox(); break;
        case 5: _t->on_deleteBtn_clicked(); break;
        case 6: _t->on_viewBtn_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject MonthView::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MonthView.data,
      qt_meta_data_MonthView,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MonthView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MonthView::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MonthView.stringdata0))
        return static_cast<void*>(const_cast< MonthView*>(this));
    return QWidget::qt_metacast(_clname);
}

int MonthView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
