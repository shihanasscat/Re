/****************************************************************************
** Meta object code from reading C++ file 'form_task.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../client/form_task.h"
#include <QtNetwork/QSslPreSharedKeyAuthenticator>
#include <QtNetwork/QSslError>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'form_task.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Form_task_t {
    const uint offsetsAndSize[24];
    char stringdata0[174];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Form_task_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Form_task_t qt_meta_stringdata_Form_task = {
    {
QT_MOC_LITERAL(0, 9), // "Form_task"
QT_MOC_LITERAL(10, 12), // "solved_now_1"
QT_MOC_LITERAL(23, 0), // ""
QT_MOC_LITERAL(24, 12), // "solved_now_2"
QT_MOC_LITERAL(37, 12), // "solved_now_3"
QT_MOC_LITERAL(50, 12), // "solved_now_4"
QT_MOC_LITERAL(63, 16), // "not_solved_now_1"
QT_MOC_LITERAL(80, 16), // "not_solved_now_2"
QT_MOC_LITERAL(97, 16), // "not_solved_now_3"
QT_MOC_LITERAL(114, 16), // "not_solved_now_4"
QT_MOC_LITERAL(131, 24), // "on_pushButton_ok_clicked"
QT_MOC_LITERAL(156, 17) // "on_secret_clicked"

    },
    "Form_task\0solved_now_1\0\0solved_now_2\0"
    "solved_now_3\0solved_now_4\0not_solved_now_1\0"
    "not_solved_now_2\0not_solved_now_3\0"
    "not_solved_now_4\0on_pushButton_ok_clicked\0"
    "on_secret_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Form_task[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   74,    2, 0x06,    1 /* Public */,
       3,    0,   75,    2, 0x06,    2 /* Public */,
       4,    0,   76,    2, 0x06,    3 /* Public */,
       5,    0,   77,    2, 0x06,    4 /* Public */,
       6,    0,   78,    2, 0x06,    5 /* Public */,
       7,    0,   79,    2, 0x06,    6 /* Public */,
       8,    0,   80,    2, 0x06,    7 /* Public */,
       9,    0,   81,    2, 0x06,    8 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      10,    0,   82,    2, 0x08,    9 /* Private */,
      11,    0,   83,    2, 0x08,   10 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Form_task::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Form_task *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->solved_now_1(); break;
        case 1: _t->solved_now_2(); break;
        case 2: _t->solved_now_3(); break;
        case 3: _t->solved_now_4(); break;
        case 4: _t->not_solved_now_1(); break;
        case 5: _t->not_solved_now_2(); break;
        case 6: _t->not_solved_now_3(); break;
        case 7: _t->not_solved_now_4(); break;
        case 8: _t->on_pushButton_ok_clicked(); break;
        case 9: _t->on_secret_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Form_task::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Form_task::solved_now_1)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Form_task::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Form_task::solved_now_2)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Form_task::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Form_task::solved_now_3)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Form_task::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Form_task::solved_now_4)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Form_task::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Form_task::not_solved_now_1)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Form_task::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Form_task::not_solved_now_2)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (Form_task::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Form_task::not_solved_now_3)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (Form_task::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Form_task::not_solved_now_4)) {
                *result = 7;
                return;
            }
        }
    }
    (void)_a;
}

const QMetaObject Form_task::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Form_task.offsetsAndSize,
    qt_meta_data_Form_task,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Form_task_t
, QtPrivate::TypeAndForceComplete<Form_task, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *Form_task::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Form_task::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Form_task.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Form_task::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void Form_task::solved_now_1()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Form_task::solved_now_2()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Form_task::solved_now_3()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Form_task::solved_now_4()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Form_task::not_solved_now_1()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void Form_task::not_solved_now_2()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void Form_task::not_solved_now_3()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void Form_task::not_solved_now_4()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
