/****************************************************************************
** Meta object code from reading C++ file 'LiftPanel.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.13)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../src/rmf_visualization_rviz2_plugins/src/LiftPanel.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'LiftPanel.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.13. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_rmf_visualization_rviz2_plugins__LiftPanel_t {
    QByteArrayData data[5];
    char stringdata0[112];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_rmf_visualization_rviz2_plugins__LiftPanel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_rmf_visualization_rviz2_plugins__LiftPanel_t qt_meta_stringdata_rmf_visualization_rviz2_plugins__LiftPanel = {
    {
QT_MOC_LITERAL(0, 0, 42), // "rmf_visualization_rviz2_plugi..."
QT_MOC_LITERAL(1, 43, 17), // "send_lift_request"
QT_MOC_LITERAL(2, 61, 0), // ""
QT_MOC_LITERAL(3, 62, 25), // "update_lift_name_selector"
QT_MOC_LITERAL(4, 88, 23) // "update_state_visualizer"

    },
    "rmf_visualization_rviz2_plugins::LiftPanel\0"
    "send_lift_request\0\0update_lift_name_selector\0"
    "update_state_visualizer"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_rmf_visualization_rviz2_plugins__LiftPanel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x09 /* Protected */,
       3,    0,   30,    2, 0x09 /* Protected */,
       4,    0,   31,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void rmf_visualization_rviz2_plugins::LiftPanel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<LiftPanel *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->send_lift_request(); break;
        case 1: _t->update_lift_name_selector(); break;
        case 2: _t->update_state_visualizer(); break;
        default: ;
        }
    }
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject rmf_visualization_rviz2_plugins::LiftPanel::staticMetaObject = { {
    QMetaObject::SuperData::link<rviz_common::Panel::staticMetaObject>(),
    qt_meta_stringdata_rmf_visualization_rviz2_plugins__LiftPanel.data,
    qt_meta_data_rmf_visualization_rviz2_plugins__LiftPanel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *rmf_visualization_rviz2_plugins::LiftPanel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *rmf_visualization_rviz2_plugins::LiftPanel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_rmf_visualization_rviz2_plugins__LiftPanel.stringdata0))
        return static_cast<void*>(this);
    return rviz_common::Panel::qt_metacast(_clname);
}

int rmf_visualization_rviz2_plugins::LiftPanel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = rviz_common::Panel::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
