/****************************************************************************
** Meta object code from reading C++ file 'calculatorfx.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Calculator/calculatorfx.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'calculatorfx.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CalculatorFX_t {
    QByteArrayData data[15];
    char stringdata0[203];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CalculatorFX_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CalculatorFX_t qt_meta_stringdata_CalculatorFX = {
    {
QT_MOC_LITERAL(0, 0, 12), // "CalculatorFX"
QT_MOC_LITERAL(1, 13, 11), // "eventFilter"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 7), // "watched"
QT_MOC_LITERAL(4, 34, 7), // "QEvent*"
QT_MOC_LITERAL(5, 42, 5), // "event"
QT_MOC_LITERAL(6, 48, 24), // "opNormal_restart_clicked"
QT_MOC_LITERAL(7, 73, 25), // "opNormal_continue_clicked"
QT_MOC_LITERAL(8, 99, 18), // "opFunction_clicked"
QT_MOC_LITERAL(9, 118, 13), // "equal_clicked"
QT_MOC_LITERAL(10, 132, 11), // "Ans_clicked"
QT_MOC_LITERAL(11, 144, 11), // "DEL_clicked"
QT_MOC_LITERAL(12, 156, 10), // "AC_clicked"
QT_MOC_LITERAL(13, 167, 17), // "optionCal_toggled"
QT_MOC_LITERAL(14, 185, 17) // "optionTri_toggled"

    },
    "CalculatorFX\0eventFilter\0\0watched\0"
    "QEvent*\0event\0opNormal_restart_clicked\0"
    "opNormal_continue_clicked\0opFunction_clicked\0"
    "equal_clicked\0Ans_clicked\0DEL_clicked\0"
    "AC_clicked\0optionCal_toggled\0"
    "optionTri_toggled"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CalculatorFX[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   64,    2, 0x0a /* Public */,
       6,    0,   69,    2, 0x08 /* Private */,
       7,    0,   70,    2, 0x08 /* Private */,
       8,    0,   71,    2, 0x08 /* Private */,
       9,    0,   72,    2, 0x08 /* Private */,
      10,    0,   73,    2, 0x08 /* Private */,
      11,    0,   74,    2, 0x08 /* Private */,
      12,    0,   75,    2, 0x08 /* Private */,
      13,    0,   76,    2, 0x08 /* Private */,
      14,    0,   77,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Bool, QMetaType::QObjectStar, 0x80000000 | 4,    3,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CalculatorFX::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CalculatorFX *_t = static_cast<CalculatorFX *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { bool _r = _t->eventFilter((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< QEvent*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 1: _t->opNormal_restart_clicked(); break;
        case 2: _t->opNormal_continue_clicked(); break;
        case 3: _t->opFunction_clicked(); break;
        case 4: _t->equal_clicked(); break;
        case 5: _t->Ans_clicked(); break;
        case 6: _t->DEL_clicked(); break;
        case 7: _t->AC_clicked(); break;
        case 8: _t->optionCal_toggled(); break;
        case 9: _t->optionTri_toggled(); break;
        default: ;
        }
    }
}

const QMetaObject CalculatorFX::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_CalculatorFX.data,
      qt_meta_data_CalculatorFX,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CalculatorFX::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CalculatorFX::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CalculatorFX.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int CalculatorFX::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
