/****************************************************************************
** SkeletonWidget meta object code from reading C++ file 'skeletonwidget.hpp'
**
** Created: Thu Mar 9 12:07:06 2006
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.4   edited Jan 21 18:14 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../skeletonwidget.hpp"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *SkeletonWidget::className() const
{
    return "SkeletonWidget";
}

QMetaObject *SkeletonWidget::metaObj = 0;
static QMetaObjectCleanUp cleanUp_SkeletonWidget( "SkeletonWidget", &SkeletonWidget::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString SkeletonWidget::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "SkeletonWidget", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString SkeletonWidget::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "SkeletonWidget", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* SkeletonWidget::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUMethod slot_0 = {"Pruefen", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "Pruefen()", &slot_0, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"SkeletonWidget", parentObject,
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_SkeletonWidget.setMetaObject( metaObj );
    return metaObj;
}

void* SkeletonWidget::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "SkeletonWidget" ) )
	return this;
    return QWidget::qt_cast( clname );
}

bool SkeletonWidget::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: Pruefen(); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool SkeletonWidget::qt_emit( int _id, QUObject* _o )
{
    return QWidget::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool SkeletonWidget::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool SkeletonWidget::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
