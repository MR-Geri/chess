/****************************************************************************
** Meta object code from reading C++ file 'tst_engine.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../tests/tst_engine.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tst_engine.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TestsEngine_t {
    QByteArrayData data[9];
    char stringdata0[169];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TestsEngine_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TestsEngine_t qt_meta_stringdata_TestsEngine = {
    {
QT_MOC_LITERAL(0, 0, 11), // "TestsEngine"
QT_MOC_LITERAL(1, 12, 25), // "test_quantityPossibleMove"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 21), // "test_enemyUnderAttack"
QT_MOC_LITERAL(4, 61, 28), // "test_calculateAdvantageWhite"
QT_MOC_LITERAL(5, 90, 27), // "test_setStartingArrangement"
QT_MOC_LITERAL(6, 118, 21), // "test_setFigureOnBoard"
QT_MOC_LITERAL(7, 140, 15), // "test_clearBoard"
QT_MOC_LITERAL(8, 156, 12) // "test_getData"

    },
    "TestsEngine\0test_quantityPossibleMove\0"
    "\0test_enemyUnderAttack\0"
    "test_calculateAdvantageWhite\0"
    "test_setStartingArrangement\0"
    "test_setFigureOnBoard\0test_clearBoard\0"
    "test_getData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TestsEngine[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    0,   54,    2, 0x08 /* Private */,
       8,    0,   55,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TestsEngine::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TestsEngine *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->test_quantityPossibleMove(); break;
        case 1: _t->test_enemyUnderAttack(); break;
        case 2: _t->test_calculateAdvantageWhite(); break;
        case 3: _t->test_setStartingArrangement(); break;
        case 4: _t->test_setFigureOnBoard(); break;
        case 5: _t->test_clearBoard(); break;
        case 6: _t->test_getData(); break;
        default: ;
        }
    }
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject TestsEngine::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_TestsEngine.data,
    qt_meta_data_TestsEngine,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TestsEngine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TestsEngine::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TestsEngine.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int TestsEngine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
