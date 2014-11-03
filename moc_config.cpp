/****************************************************************************
** Meta object code from reading C++ file 'config.h'
**
** Created: Sat Jun 21 18:31:05 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "config.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'config.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Config[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x05,

 // slots: signature, parameters, type, tag, flags
      24,    7,    7,    7, 0x0a,
      34,    7,    7,    7, 0x0a,
      44,    7,    7,    7, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Config[] = {
    "Config\0\0config_change()\0openDir()\0"
    "openSdk()\0on_save_accepted()\0"
};

const QMetaObject Config::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Config,
      qt_meta_data_Config, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Config::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Config::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Config::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Config))
        return static_cast<void*>(const_cast< Config*>(this));
    return QWidget::qt_metacast(_clname);
}

int Config::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: config_change(); break;
        case 1: openDir(); break;
        case 2: openSdk(); break;
        case 3: on_save_accepted(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void Config::config_change()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
