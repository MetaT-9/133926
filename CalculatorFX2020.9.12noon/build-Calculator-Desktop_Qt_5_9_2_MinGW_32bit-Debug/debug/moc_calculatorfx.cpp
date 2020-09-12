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
    QByteArrayData data[11];
    char stringdata0[169];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CalculatorFX_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CalculatorFX_t qt_meta_stringdata_CalculatorFX = {
    {
QT_MOC_LITERAL(0, 0, 12), // "CalculatorFX"
QT_MOC_LITERAL(1, 13, 24), // "opNormal_restart_clicked"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 25), // "opNormal_continue_clicked"
QT_MOC_LITERAL(4, 65, 18), // "opFunction_clicked"
QT_MOC_LITERAL(5, 84, 13), // "equal_clicked"
QT_MOC_LITERAL(6, 98, 11), // "Ans_clicked"
QT_MOC_LITERAL(7, 110, 11), // "DEL_clicked"
QT_MOC_LITERAL(8, 122, 10), // "AC_clicked"
QT_MOC_LITERAL(9, 133, 17), // "optionCal_toggled"
QT_MOC_LITERAL(10, 151, 17) // "optionTri_toggled"

    },
    "CalculatorFX\0opNormal_restart_clicked\0"
    "\0opNormal_continue_clicked\0"
    "opFunction_clicked\0equal_clicked\0"
    "Ans_clicked\0DEL_clicked\0AC_clicked\0"
    "optionCal_toggled\0optionTri_toggled"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CalculatorFX[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    0,   60,    2, 0x08 /* Private */,
       4,    0,   61,    2, 0x08 /* Private */,
       5,    0,   62,    2, 0x08 /* Private */,
       6,    0,   63,    2, 0x08 /* Private */,
       7,    0,   64,    2, 0x08 /* Private */,
       8,    0,   65,    2, 0x08 /* Private */,
       9,    0,   66,    2, 0x08 /* Private */,
      10,    0,   67,    2, 0x08 /* Private */,

 // slots: parameters
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
        case 0: _t->opNormal_restart_clicked(); break;
        case 1: _t->opNormal_continue_clicked(); break;
        case 2: _t->opFunction_clicked(); break;
        case 3: _t->equal_clicked(); break;
        case 4: _t->Ans_clicked(); break;
        case 5: _t->DEL_clicked(); break;
        case 6: _t->AC_clicked(); break;
        case 7: _t->optionCal_toggled(); break;
        case 8: _t->optionTri_toggled(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
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
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
