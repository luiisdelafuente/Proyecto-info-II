/****************************************************************************
** Meta object code from reading C++ file 'ventana3.h'
**
** Created: Sun 8. Nov 14:40:07 2020
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "ventana3.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ventana3.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Ventana3[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x0a,
      28,    9,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Ventana3[] = {
    "Ventana3\0\0mostrarVentana4()\0nopersiste()\0"
};

void Ventana3::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Ventana3 *_t = static_cast<Ventana3 *>(_o);
        switch (_id) {
        case 0: _t->mostrarVentana4(); break;
        case 1: _t->nopersiste(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData Ventana3::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Ventana3::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Ventana3,
      qt_meta_data_Ventana3, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Ventana3::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Ventana3::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Ventana3::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Ventana3))
        return static_cast<void*>(const_cast< Ventana3*>(this));
    return QWidget::qt_metacast(_clname);
}

int Ventana3::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
