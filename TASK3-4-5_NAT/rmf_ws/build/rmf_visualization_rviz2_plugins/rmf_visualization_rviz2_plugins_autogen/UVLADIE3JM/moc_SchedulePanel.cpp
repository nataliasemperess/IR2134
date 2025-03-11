/****************************************************************************
** Meta object code from reading C++ file 'SchedulePanel.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.13)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../src/rmf_visualization_rviz2_plugins/src/SchedulePanel.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SchedulePanel.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.13. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_rmf_visualization_rviz2_plugins__SchedulePanel_t {
    QByteArrayData data[19];
    char stringdata0[319];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_rmf_visualization_rviz2_plugins__SchedulePanel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_rmf_visualization_rviz2_plugins__SchedulePanel_t qt_meta_stringdata_rmf_visualization_rviz2_plugins__SchedulePanel = {
    {
QT_MOC_LITERAL(0, 0, 46), // "rmf_visualization_rviz2_plugi..."
QT_MOC_LITERAL(1, 47, 18), // "set_start_duration"
QT_MOC_LITERAL(2, 66, 0), // ""
QT_MOC_LITERAL(3, 67, 7), // "seconds"
QT_MOC_LITERAL(4, 75, 3), // "max"
QT_MOC_LITERAL(5, 79, 9), // "set_topic"
QT_MOC_LITERAL(6, 89, 5), // "topic"
QT_MOC_LITERAL(7, 95, 12), // "set_map_name"
QT_MOC_LITERAL(8, 108, 8), // "map_name"
QT_MOC_LITERAL(9, 117, 19), // "set_finish_duration"
QT_MOC_LITERAL(10, 137, 22), // "set_start_duration_max"
QT_MOC_LITERAL(11, 160, 10), // "send_param"
QT_MOC_LITERAL(12, 171, 12), // "update_topic"
QT_MOC_LITERAL(13, 184, 15), // "update_map_name"
QT_MOC_LITERAL(14, 200, 21), // "update_start_duration"
QT_MOC_LITERAL(15, 222, 22), // "update_finish_duration"
QT_MOC_LITERAL(16, 245, 25), // "update_start_duration_max"
QT_MOC_LITERAL(17, 271, 28), // "update_start_duration_editor"
QT_MOC_LITERAL(18, 300, 18) // "cancel_negotiation"

    },
    "rmf_visualization_rviz2_plugins::SchedulePanel\0"
    "set_start_duration\0\0seconds\0max\0"
    "set_topic\0topic\0set_map_name\0map_name\0"
    "set_finish_duration\0set_start_duration_max\0"
    "send_param\0update_topic\0update_map_name\0"
    "update_start_duration\0update_finish_duration\0"
    "update_start_duration_max\0"
    "update_start_duration_editor\0"
    "cancel_negotiation"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_rmf_visualization_rviz2_plugins__SchedulePanel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x0a /* Public */,
       1,    1,   87,    2, 0x0a /* Public */,
       5,    1,   90,    2, 0x0a /* Public */,
       7,    1,   93,    2, 0x0a /* Public */,
       9,    1,   96,    2, 0x0a /* Public */,
      10,    1,   99,    2, 0x0a /* Public */,
      11,    0,  102,    2, 0x09 /* Protected */,
      12,    0,  103,    2, 0x09 /* Protected */,
      13,    0,  104,    2, 0x09 /* Protected */,
      14,    0,  105,    2, 0x09 /* Protected */,
      15,    0,  106,    2, 0x09 /* Protected */,
      16,    0,  107,    2, 0x09 /* Protected */,
      17,    0,  108,    2, 0x09 /* Protected */,
      18,    0,  109,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,    4,
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

void rmf_visualization_rviz2_plugins::SchedulePanel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SchedulePanel *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->set_start_duration((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->set_start_duration((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->set_topic((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->set_map_name((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->set_finish_duration((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->set_start_duration_max((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->send_param(); break;
        case 7: _t->update_topic(); break;
        case 8: _t->update_map_name(); break;
        case 9: _t->update_start_duration(); break;
        case 10: _t->update_finish_duration(); break;
        case 11: _t->update_start_duration_max(); break;
        case 12: _t->update_start_duration_editor(); break;
        case 13: _t->cancel_negotiation(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject rmf_visualization_rviz2_plugins::SchedulePanel::staticMetaObject = { {
    QMetaObject::SuperData::link<rviz_common::Panel::staticMetaObject>(),
    qt_meta_stringdata_rmf_visualization_rviz2_plugins__SchedulePanel.data,
    qt_meta_data_rmf_visualization_rviz2_plugins__SchedulePanel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *rmf_visualization_rviz2_plugins::SchedulePanel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *rmf_visualization_rviz2_plugins::SchedulePanel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_rmf_visualization_rviz2_plugins__SchedulePanel.stringdata0))
        return static_cast<void*>(this);
    return rviz_common::Panel::qt_metacast(_clname);
}

int rmf_visualization_rviz2_plugins::SchedulePanel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = rviz_common::Panel::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
