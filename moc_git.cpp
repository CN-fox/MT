/****************************************************************************
** Meta object code from reading C++ file 'git.h'
**
** Created: Sat Jun 21 18:31:05 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "git.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'git.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Git[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       5,    4,    4,    4, 0x0a,
      21,    4,    4,    4, 0x08,
      38,    4,    4,    4, 0x08,
      61,    4,    4,    4, 0x08,
      79,    4,    4,    4, 0x08,
     101,    4,    4,    4, 0x08,
     122,    4,    4,    4, 0x08,
     144,    4,    4,    4, 0x08,
     162,    4,    4,    4, 0x08,
     191,    4,    4,    4, 0x08,
     211,    4,    4,    4, 0x08,
     218,    4,    4,    4, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Git[] = {
    "Git\0\0config_change()\0on_run_clicked()\0"
    "on_push_code_clicked()\0on_make_clicked()\0"
    "on_push_rom_clicked()\0on_tcpdump_clicked()\0"
    "on_push_apk_clicked()\0on_diff_clicked()\0"
    "on_select_activated(QString)\0"
    "on_search_clicked()\0read()\0finished(int)\0"
};

const QMetaObject Git::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Git,
      qt_meta_data_Git, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Git::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Git::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Git::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Git))
        return static_cast<void*>(const_cast< Git*>(this));
    return QWidget::qt_metacast(_clname);
}

int Git::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: config_change(); break;
        case 1: on_run_clicked(); break;
        case 2: on_push_code_clicked(); break;
        case 3: on_make_clicked(); break;
        case 4: on_push_rom_clicked(); break;
        case 5: on_tcpdump_clicked(); break;
        case 6: on_push_apk_clicked(); break;
        case 7: on_diff_clicked(); break;
        case 8: on_select_activated((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: on_search_clicked(); break;
        case 10: read(); break;
        case 11: finished((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
