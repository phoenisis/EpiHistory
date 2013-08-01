/****************************************************************************
** Meta object code from reading C++ file 'qbabel.h'
**
** Created: Tue Dec 11 20:47:33 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "/private/tmp/babel-2015-beydon_m/BabelClient/BabelClient/qbabel.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qbabel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QBabel[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x0a,
      22,    7,    7,    7, 0x0a,
      35,    7,    7,    7, 0x0a,
      47,    7,    7,    7, 0x0a,
      63,    7,    7,    7, 0x0a,
      77,    7,    7,    7, 0x0a,
      93,    7,    7,    7, 0x0a,
     100,    7,    7,    7, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QBabel[] = {
    "QBabel\0\0aboutQBabel()\0addContact()\0"
    "selection()\0settingScreen()\0saveOptions()\0"
    "cancelSetting()\0quit()\0creat()\0"
};

void QBabel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QBabel *_t = static_cast<QBabel *>(_o);
        switch (_id) {
        case 0: _t->aboutQBabel(); break;
        case 1: _t->addContact(); break;
        case 2: _t->selection(); break;
        case 3: _t->settingScreen(); break;
        case 4: _t->saveOptions(); break;
        case 5: _t->cancelSetting(); break;
        case 6: _t->quit(); break;
        case 7: _t->creat(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData QBabel::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QBabel::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_QBabel,
      qt_meta_data_QBabel, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QBabel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QBabel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QBabel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QBabel))
        return static_cast<void*>(const_cast< QBabel*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int QBabel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
