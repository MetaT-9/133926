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
    QByteArrayData data[17];
    char stringdata0[235];
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
QT_MOC_LITERAL(10, 151, 17), // "optionTri_toggled"
QT_MOC_LITERAL(11, 169, 13), // "sysConversion"
QT_MOC_LITERAL(12, 183, 11), // "sys_current"
QT_MOC_LITERAL(13, 195, 10), // "sys_target"
QT_MOC_LITERAL(14, 206, 3), // "num"
QT_MOC_LITERAL(15, 210, 13), // "triConversion"
QT_MOC_LITERAL(16, 224, 10) // "tri_target"

    },
    "CalculatorFX\0opNormal_restart_clicked\0"
    "\0opNormal_continue_clicked\0"
    "opFunction_clicked\0equal_clicked\0"
    "Ans_clicked\0DEL_clicked\0AC_clicked\0"
    "optionCal_toggled\0optionTri_toggled\0"
    "sysConversion\0sys_current\0sys_target\0"
    "num\0triConversion\0tri_target"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CalculatorFX[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    0,   70,    2, 0x08 /* Private */,
       4,    0,   71,    2, 0x08 /* Private */,
       5,    0,   72,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       7,    0,   74,    2, 0x08 /* Private */,
       8,    0,   75,    2, 0x08 /* Private */,
       9,    0,   76,    2, 0x08 /* Private */,
      10,    0,   77,    2, 0x08 /* Private */,
      11,    3,   78,    2, 0x08 /* Private */,
      15,    2,   85,    2, 0x08 /* Private */,

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
    QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   12,   13,   14,
    QMetaType::QString, QMetaType::QString, QMetaType::QString,   16,   14,

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
        case 9: { QString _r = _t->sysConversion((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 10: { QString _r = _t->triConversion((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
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
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
