/****************************************************************************
** TMainFormBase meta object code from reading C++ file 'main_form_base.h'
**
** Created: Tue Apr 4 19:42:24 2017
**      by: The Qt MOC ($Id: qt/src/moc/moc.y   2.3.12   edited 2005-10-27 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 9
#elif Q_MOC_OUTPUT_REVISION != 9
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "../../.ui/release-shared/main_form_base.h"
#include <qmetaobject.h>
#include <qapplication.h>
#ifdef QWS
#include <qobjectdict.h>
#endif



const char *TMainFormBase::className() const
{
    return "TMainFormBase";
}

QMetaObject *TMainFormBase::metaObj = 0;

#ifdef QWS
static class TMainFormBase_metaObj_Unloader {
public:
    ~TMainFormBase_metaObj_Unloader()
    {
         if ( objectDict )
             objectDict->remove( "TMainFormBase" );
    }
} TMainFormBase_metaObj_unloader;
#endif

void TMainFormBase::initMetaObject()
{
    if ( metaObj )
	return;
    if ( qstrcmp(QWidget::className(), "QWidget") != 0 )
	badSuperclassWarning("TMainFormBase","QWidget");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION

QString TMainFormBase::tr(const char* s)
{
    return qApp->translate( "TMainFormBase", s, 0 );
}

QString TMainFormBase::tr(const char* s, const char * c)
{
    return qApp->translate( "TMainFormBase", s, c );
}

#endif // QT_NO_TRANSLATION

QMetaObject* TMainFormBase::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QWidget::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    typedef void (TMainFormBase::*m1_t0)();
    typedef void (QObject::*om1_t0)();
    typedef void (TMainFormBase::*m1_t1)();
    typedef void (QObject::*om1_t1)();
    typedef void (TMainFormBase::*m1_t2)();
    typedef void (QObject::*om1_t2)();
    typedef void (TMainFormBase::*m1_t3)();
    typedef void (QObject::*om1_t3)();
    typedef void (TMainFormBase::*m1_t4)();
    typedef void (QObject::*om1_t4)();
    typedef void (TMainFormBase::*m1_t5)();
    typedef void (QObject::*om1_t5)();
    typedef void (TMainFormBase::*m1_t6)();
    typedef void (QObject::*om1_t6)();
    m1_t0 v1_0 = &TMainFormBase::autoButtonClicked;
    om1_t0 ov1_0 = (om1_t0)v1_0;
    m1_t1 v1_1 = &TMainFormBase::beidou;
    om1_t1 ov1_1 = (om1_t1)v1_1;
    m1_t2 v1_2 = &TMainFormBase::clearbutton;
    om1_t2 ov1_2 = (om1_t2)v1_2;
    m1_t3 v1_3 = &TMainFormBase::comboboxClicked;
    om1_t3 ov1_3 = (om1_t3)v1_3;
    m1_t4 v1_4 = &TMainFormBase::gprs;
    om1_t4 ov1_4 = (om1_t4)v1_4;
    m1_t5 v1_5 = &TMainFormBase::sendButtonClicked;
    om1_t5 ov1_5 = (om1_t5)v1_5;
    m1_t6 v1_6 = &TMainFormBase::zigbee;
    om1_t6 ov1_6 = (om1_t6)v1_6;
    QMetaData *slot_tbl = QMetaObject::new_metadata(7);
    QMetaData::Access *slot_tbl_access = QMetaObject::new_metaaccess(7);
    slot_tbl[0].name = "autoButtonClicked()";
    slot_tbl[0].ptr = (QMember)ov1_0;
    slot_tbl_access[0] = QMetaData::Public;
    slot_tbl[1].name = "beidou()";
    slot_tbl[1].ptr = (QMember)ov1_1;
    slot_tbl_access[1] = QMetaData::Public;
    slot_tbl[2].name = "clearbutton()";
    slot_tbl[2].ptr = (QMember)ov1_2;
    slot_tbl_access[2] = QMetaData::Public;
    slot_tbl[3].name = "comboboxClicked()";
    slot_tbl[3].ptr = (QMember)ov1_3;
    slot_tbl_access[3] = QMetaData::Public;
    slot_tbl[4].name = "gprs()";
    slot_tbl[4].ptr = (QMember)ov1_4;
    slot_tbl_access[4] = QMetaData::Public;
    slot_tbl[5].name = "sendButtonClicked()";
    slot_tbl[5].ptr = (QMember)ov1_5;
    slot_tbl_access[5] = QMetaData::Public;
    slot_tbl[6].name = "zigbee()";
    slot_tbl[6].ptr = (QMember)ov1_6;
    slot_tbl_access[6] = QMetaData::Public;
    metaObj = QMetaObject::new_metaobject(
	"TMainFormBase", "QWidget",
	slot_tbl, 7,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    metaObj->set_slot_access( slot_tbl_access );
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    return metaObj;
}
