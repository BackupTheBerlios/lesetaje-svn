/****************************************************************************
** SkeletonCanvasView meta object code from reading C++ file 'skeletoncanvasview.hpp'
**
** Created: Sun Feb 26 18:04:50 2006
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.4   edited Jan 21 18:14 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../skeletoncanvasview.hpp"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *SkeletonCanvasView::className() const
{
    return "SkeletonCanvasView";
}

QMetaObject *SkeletonCanvasView::metaObj = 0;
static QMetaObjectCleanUp cleanUp_SkeletonCanvasView( "SkeletonCanvasView", &SkeletonCanvasView::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString SkeletonCanvasView::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "SkeletonCanvasView", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString SkeletonCanvasView::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "SkeletonCanvasView", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* SkeletonCanvasView::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QCanvasView::staticMetaObject();
    static const QUMethod slot_0 = {"timeout", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "timeout()", &slot_0, QMetaData::Protected }
    };
    metaObj = QMetaObject::new_metaobject(
	"SkeletonCanvasView", parentObject,
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_SkeletonCanvasView.setMetaObject( metaObj );
    return metaObj;
}

void* SkeletonCanvasView::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "SkeletonCanvasView" ) )
	return this;
    return QCanvasView::qt_cast( clname );
}

bool SkeletonCanvasView::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: timeout(); break;
    default:
	return QCanvasView::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool SkeletonCanvasView::qt_emit( int _id, QUObject* _o )
{
    return QCanvasView::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool SkeletonCanvasView::qt_property( int id, int f, QVariant* v)
{
    return QCanvasView::qt_property( id, f, v);
}

bool SkeletonCanvasView::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
