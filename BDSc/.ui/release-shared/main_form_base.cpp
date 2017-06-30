/****************************************************************************
** Form implementation generated from reading ui file 'main_form_base.ui'
**
** Created: Tue Apr 4 19:42:23 2017
**      by:  The User Interface Compiler (uic)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/
#include "main_form_base.h"

#include <qframe.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qmultilineedit.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qvariant.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

static const char* const image0_data[] = { 
"41 55 17 1",
"c c #000000",
"l c #0e0e0e",
"d c #1c1c1c",
"k c #2a2a2a",
"b c #3a3939",
"e c #474646",
"j c #555454",
"a c #636262",
"h c #6f6e6e",
"f c #7b7a7a",
"m c #888686",
"o c #939292",
"# c #9e9d9d",
"i c #a9a7a7",
"n c #b3b2b2",
"g c #c0bebe",
". c #cfcdcd",
".........................................",
".........................................",
".........................................",
".........................................",
".........................................",
".........................................",
".........................................",
".........................................",
".........................................",
".........................................",
".........................................",
".........................................",
".........................................",
".........................................",
".........................................",
".........................................",
".........................................",
"...............#abcccdefg................",
".............#bccccccccccag..............",
"............hcccccccccccccdi.............",
"...........jccccckjhhblccccli............",
"..........fccccbi......mlcccln...........",
".........iccccf.........gkcccb...........",
".........bccch...........gdccc#..........",
"........ncccb.............#ccce..........",
"........fccco..............bccc..........",
"........eccl...............fccc#.........",
"........bccb...............#ccc#.........",
"........bccb...............#ccc#.........",
"........bccb...............#ccc#.........",
"........eccc...............fccc#.........",
"........fccco..............bccc..........",
"........ncccb.............#ccce..........",
".........eccch...........gkccc#..........",
".........nccccm.........gkcccb...........",
"..........mccccen......mlccclg...........",
"...........jccccckhhhjdccccli............",
"............fcccccccccccccki.............",
".............ibccccccccclhg..............",
"...............iabcccdemg................",
".........................................",
".........................................",
".........................................",
".........................................",
".........................................",
".........................................",
".........................................",
".........................................",
".........................................",
".........................................",
".........................................",
".........................................",
".........................................",
".........................................",
"........................................."};


/* 
 *  Constructs a TMainFormBase which is a child of 'parent', with the 
 *  name 'name' and widget flags set to 'f' 
 */
TMainFormBase::TMainFormBase( QWidget* parent,  const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    QPixmap image0( ( const char** ) image0_data );
    if ( !name )
	setName( "TMainFormBase" );
    resize( 1108, 742 ); 
    setCaption( tr( "Form1" ) );

    Line4 = new QFrame( this, "Line4" );
    Line4->setGeometry( QRect( 840, 10, 20, 410 ) ); 
    Line4->setFrameStyle( QFrame::VLine | QFrame::Sunken );

    Line1 = new QFrame( this, "Line1" );
    Line1->setGeometry( QRect( 840, 520, 20, 210 ) ); 
    Line1->setFrameStyle( QFrame::VLine | QFrame::Sunken );

    Line7 = new QFrame( this, "Line7" );
    Line7->setGeometry( QRect( 840, 450, 21, 51 ) ); 
    Line7->setFrameStyle( QFrame::VLine | QFrame::Sunken );

    Line2_2 = new QFrame( this, "Line2_2" );
    Line2_2->setGeometry( QRect( 580, 500, 520, 21 ) ); 
    Line2_2->setFrameStyle( QFrame::HLine | QFrame::Sunken );

    Line2 = new QFrame( this, "Line2" );
    Line2->setGeometry( QRect( 580, 430, 520, 21 ) ); 
    Line2->setFrameStyle( QFrame::HLine | QFrame::Sunken );

    Gprs = new QPushButton( this, "Gprs" );
    Gprs->setGeometry( QRect( 620, 650, 170, 50 ) ); 
    Gprs->setText( tr( "send" ) );

    g4 = new QPushButton( this, "g4" );
    g4->setGeometry( QRect( 930, 650, 100, 50 ) ); 
    g4->setText( tr( "send" ) );

    g3 = new QPushButton( this, "g3" );
    g3->setGeometry( QRect( 190, 290, 210, 50 ) ); 
    g3->setText( tr( "Get T/H" ) );

    hu_2 = new QLineEdit( this, "hu_2" );
    hu_2->setGeometry( QRect( 410, 220, 70, 46 ) ); 

    TextLabel1_3_2_2_3 = new QLabel( this, "TextLabel1_3_2_2_3" );
    TextLabel1_3_2_2_3->setGeometry( QRect( 510, 230, 30, 31 ) ); 
    TextLabel1_3_2_2_3->setText( tr( "%" ) );

    TextLabel1_3_2_2 = new QLabel( this, "TextLabel1_3_2_2" );
    TextLabel1_3_2_2->setGeometry( QRect( 240, 230, 30, 31 ) ); 
    TextLabel1_3_2_2->setText( tr( "%" ) );

    hu = new QLineEdit( this, "hu" );
    hu->setGeometry( QRect( 140, 220, 70, 46 ) ); 

    tp = new QLineEdit( this, "tp" );
    tp->setGeometry( QRect( 140, 140, 70, 46 ) ); 

    TextLabel1_3_2_2_2 = new QLabel( this, "TextLabel1_3_2_2_2" );
    TextLabel1_3_2_2_2->setGeometry( QRect( 240, 150, 30, 30 ) ); 
    TextLabel1_3_2_2_2->setText( tr( "C" ) );

    Temp = new QLabel( this, "Temp" );
    Temp->setGeometry( QRect( 40, 150, 90, 31 ) ); 
    Temp->setText( tr( "Temp" ) );

    Hum_2 = new QLabel( this, "Hum_2" );
    Hum_2->setGeometry( QRect( 320, 230, 70, 31 ) ); 
    Hum_2->setText( tr( "Hum" ) );

    Hum = new QLabel( this, "Hum" );
    Hum->setGeometry( QRect( 50, 230, 70, 31 ) ); 
    Hum->setText( tr( "Hum" ) );

    PixmapLabel1_3 = new QLabel( this, "PixmapLabel1_3" );
    PixmapLabel1_3->setGeometry( QRect( 230, 140, 16, 20 ) ); 
    PixmapLabel1_3->setPixmap( image0 );
    PixmapLabel1_3->setScaledContents( TRUE );

    tp_2 = new QLineEdit( this, "tp_2" );
    tp_2->setGeometry( QRect( 410, 140, 70, 46 ) ); 

    jd1 = new QLabel( this, "jd1" );
    jd1->setGeometry( QRect( 150, 80, 30, 31 ) ); 
    jd1->setText( tr( "A" ) );

    Temp_2 = new QLabel( this, "Temp_2" );
    Temp_2->setGeometry( QRect( 310, 150, 90, 31 ) ); 
    Temp_2->setText( tr( "Temp" ) );

    Time = new QLabel( this, "Time" );
    Time->setGeometry( QRect( 50, 600, 70, 31 ) ); 
    Time->setText( tr( "Time" ) );

    TextLabel1_3_3_2_2 = new QLabel( this, "TextLabel1_3_3_2_2" );
    TextLabel1_3_3_2_2->setGeometry( QRect( 500, 440, 20, 30 ) ); 
    TextLabel1_3_3_2_2->setText( tr( "\"" ) );

    w3 = new QLineEdit( this, "w3" );
    w3->setGeometry( QRect( 420, 510, 70, 46 ) ); 

    TextLabel1_3_3_4 = new QLabel( this, "TextLabel1_3_3_4" );
    TextLabel1_3_3_4->setGeometry( QRect( 380, 440, 20, 31 ) ); 
    TextLabel1_3_3_4->setText( tr( "'" ) );

    j12 = new QLineEdit( this, "j12" );
    j12->setGeometry( QRect( 290, 430, 70, 46 ) ); 

    t1 = new QLineEdit( this, "t1" );
    t1->setGeometry( QRect( 160, 590, 70, 46 ) ); 

    J = new QLabel( this, "J" );
    J->setGeometry( QRect( 40, 440, 90, 31 ) ); 
    J->setText( tr( "Longti" ) );

    PixmapLabel1_3_2 = new QLabel( this, "PixmapLabel1_3_2" );
    PixmapLabel1_3_2->setGeometry( QRect( 240, 520, 16, 20 ) ); 
    PixmapLabel1_3_2->setPixmap( image0 );
    PixmapLabel1_3_2->setScaledContents( TRUE );

    j11 = new QLineEdit( this, "j11" );
    j11->setGeometry( QRect( 160, 430, 70, 46 ) ); 

    w2 = new QLineEdit( this, "w2" );
    w2->setGeometry( QRect( 290, 510, 70, 46 ) ); 

    PixmapLabel1_3_3 = new QLabel( this, "PixmapLabel1_3_3" );
    PixmapLabel1_3_3->setGeometry( QRect( 240, 440, 16, 20 ) ); 
    PixmapLabel1_3_3->setPixmap( image0 );
    PixmapLabel1_3_3->setScaledContents( TRUE );

    t3 = new QLineEdit( this, "t3" );
    t3->setGeometry( QRect( 420, 590, 70, 46 ) ); 

    W = new QLabel( this, "W" );
    W->setGeometry( QRect( 60, 520, 50, 31 ) ); 
    W->setText( tr( "Lati" ) );

    TextLabel1_3_3 = new QLabel( this, "TextLabel1_3_3" );
    TextLabel1_3_3->setGeometry( QRect( 380, 520, 20, 31 ) ); 
    TextLabel1_3_3->setText( tr( "'" ) );

    j13 = new QLineEdit( this, "j13" );
    j13->setGeometry( QRect( 420, 430, 70, 46 ) ); 

    w1 = new QLineEdit( this, "w1" );
    w1->setGeometry( QRect( 160, 510, 70, 46 ) ); 

    t2 = new QLineEdit( this, "t2" );
    t2->setGeometry( QRect( 290, 590, 70, 46 ) ); 

    m_receiveEdit = new QMultiLineEdit( this, "m_receiveEdit" );
    m_receiveEdit->setGeometry( QRect( 870, 10, 230, 360 ) ); 
    QFont m_receiveEdit_font(  m_receiveEdit->font() );
    m_receiveEdit_font.setFamily( "helvetica" );
    m_receiveEdit_font.setPointSize( 10 );
    m_receiveEdit->setFont( m_receiveEdit_font ); 
    m_receiveEdit->setFocusPolicy( QMultiLineEdit::StrongFocus );
    m_receiveEdit->setAcceptDrops( FALSE );
    m_receiveEdit->setFrameShape( QMultiLineEdit::WinPanel );
    m_receiveEdit->setHMargin( 3 );
    m_receiveEdit->setWordWrap( QMultiLineEdit::FixedColumnWidth );
    m_receiveEdit->setWrapColumnOrWidth( 32 );
    m_receiveEdit->setWrapPolicy( QMultiLineEdit::Anywhere );
    m_receiveEdit->setUndoEnabled( FALSE );

    Receive = new QLabel( this, "Receive" );
    Receive->setGeometry( QRect( 870, 390, 180, 30 ) ); 
    Receive->setText( tr( "receive area" ) );

    rx = new QLineEdit( this, "rx" );
    rx->setGeometry( QRect( 1050, 380, 51, 46 ) ); 

    Send = new QLabel( this, "Send" );
    Send->setGeometry( QRect( 610, 390, 160, 30 ) ); 
    Send->setText( tr( "send area" ) );

    g2 = new QPushButton( this, "g2" );
    g2->setGeometry( QRect( 200, 670, 210, 50 ) ); 
    g2->setText( tr( "Get pos" ) );

    Line6 = new QFrame( this, "Line6" );
    Line6->setGeometry( QRect( 10, 340, 541, 31 ) ); 
    Line6->setFrameStyle( QFrame::HLine | QFrame::Sunken );

    TextLabel1_3_2_2_2_2 = new QLabel( this, "TextLabel1_3_2_2_2_2" );
    TextLabel1_3_2_2_2_2->setGeometry( QRect( 510, 150, 30, 30 ) ); 
    TextLabel1_3_2_2_2_2->setText( tr( "C" ) );

    PixmapLabel1_3_4 = new QLabel( this, "PixmapLabel1_3_4" );
    PixmapLabel1_3_4->setGeometry( QRect( 500, 140, 16, 20 ) ); 
    PixmapLabel1_3_4->setPixmap( image0 );
    PixmapLabel1_3_4->setScaledContents( TRUE );

    m_sendEdit = new QMultiLineEdit( this, "m_sendEdit" );
    m_sendEdit->setGeometry( QRect( 590, 10, 240, 360 ) ); 
    QFont m_sendEdit_font(  m_sendEdit->font() );
    m_sendEdit_font.setFamily( "helvetica" );
    m_sendEdit_font.setPointSize( 10 );
    m_sendEdit->setFont( m_sendEdit_font ); 
    m_sendEdit->setFocusPolicy( QMultiLineEdit::StrongFocus );
    m_sendEdit->setAcceptDrops( FALSE );
    m_sendEdit->setFrameShape( QMultiLineEdit::WinPanel );
    m_sendEdit->setHMargin( 3 );
    m_sendEdit->setWordWrap( QMultiLineEdit::FixedColumnWidth );
    m_sendEdit->setWrapColumnOrWidth( 32 );
    m_sendEdit->setWrapPolicy( QMultiLineEdit::Anywhere );
    m_sendEdit->setUndoEnabled( FALSE );

    tx = new QLineEdit( this, "tx" );
    tx->setGeometry( QRect( 770, 380, 51, 46 ) ); 

    pos = new QLabel( this, "pos" );
    pos->setGeometry( QRect( 280, 380, 30, 31 ) ); 
    pos->setText( tr( "A" ) );

    TextLabel1_3 = new QLabel( this, "TextLabel1_3" );
    TextLabel1_3->setGeometry( QRect( 240, 600, 20, 31 ) ); 
    TextLabel1_3->setText( tr( ":" ) );

    TextLabel1_3_2 = new QLabel( this, "TextLabel1_3_2" );
    TextLabel1_3_2->setGeometry( QRect( 380, 600, 20, 31 ) ); 
    TextLabel1_3_2->setText( tr( ":" ) );

    Line5 = new QFrame( this, "Line5" );
    Line5->setGeometry( QRect( 550, 10, 31, 710 ) ); 
    Line5->setFrameStyle( QFrame::VLine | QFrame::Sunken );

    TextLabel1_3_3_2 = new QLabel( this, "TextLabel1_3_3_2" );
    TextLabel1_3_3_2->setGeometry( QRect( 500, 520, 20, 30 ) ); 
    TextLabel1_3_3_2->setText( tr( "\"" ) );

    Line9 = new QFrame( this, "Line9" );
    Line9->setGeometry( QRect( 280, 60, 21, 210 ) ); 
    Line9->setFrameStyle( QFrame::VLine | QFrame::Sunken );

    g5 = new QPushButton( this, "g5" );
    g5->setGeometry( QRect( 930, 450, 90, 50 ) ); 
    g5->setText( tr( "clear" ) );

    mode = new QLabel( this, "mode" );
    mode->setGeometry( QRect( 610, 460, 210, 31 ) ); 
    mode->setText( tr( "Mode Select" ) );

    BD = new QLabel( this, "BD" );
    BD->setGeometry( QRect( 910, 540, 140, 31 ) ); 
    BD->setText( tr( "BeidouID" ) );

    num = new QLabel( this, "num" );
    num->setGeometry( QRect( 620, 540, 170, 31 ) ); 
    num->setText( tr( "Phone Num" ) );

    zig = new QLabel( this, "zig" );
    zig->setGeometry( QRect( 280, 20, 30, 31 ) ); 
    zig->setText( tr( "A" ) );

    jd2 = new QLabel( this, "jd2" );
    jd2->setGeometry( QRect( 420, 80, 30, 31 ) ); 
    jd2->setText( tr( "A" ) );

    bdid = new QLineEdit( this, "bdid" );
    bdid->setGeometry( QRect( 920, 590, 120, 46 ) ); 
    bdid->setText( tr( "306355" ) );
    bdid->setEdited( TRUE );

    number = new QLineEdit( this, "number" );
    number->setGeometry( QRect( 600, 590, 210, 46 ) ); 
    number->setText( tr( "15061960053" ) );
    number->setEdited( TRUE );

    // signals and slots connections
    connect( g2, SIGNAL( clicked() ), this, SLOT( autoButtonClicked() ) );
    connect( Gprs, SIGNAL( clicked() ), this, SLOT( gprs() ) );
    connect( g4, SIGNAL( clicked() ), this, SLOT( sendButtonClicked() ) );
    connect( g5, SIGNAL( clicked() ), this, SLOT( clearbutton() ) );
    connect( g3, SIGNAL( clicked() ), this, SLOT( zigbee() ) );
}

/*  
 *  Destroys the object and frees any allocated resources
 */
TMainFormBase::~TMainFormBase()
{
    // no need to delete child widgets, Qt does it all for us
}

/*  
 *  Main event handler. Reimplemented to handle application
 *  font changes
 */
bool TMainFormBase::event( QEvent* ev )
{
    bool ret = QWidget::event( ev ); 
    if ( ev->type() == QEvent::ApplicationFontChange ) {
	QFont m_receiveEdit_font(  m_receiveEdit->font() );
	m_receiveEdit_font.setFamily( "helvetica" );
	m_receiveEdit_font.setPointSize( 10 );
	m_receiveEdit->setFont( m_receiveEdit_font ); 
	QFont m_sendEdit_font(  m_sendEdit->font() );
	m_sendEdit_font.setFamily( "helvetica" );
	m_sendEdit_font.setPointSize( 10 );
	m_sendEdit->setFont( m_sendEdit_font ); 
    }
    return ret;
}

void TMainFormBase::autoButtonClicked()
{
    qWarning( "TMainFormBase::autoButtonClicked(): Not implemented yet!" );
}

void TMainFormBase::beidou()
{
    qWarning( "TMainFormBase::beidou(): Not implemented yet!" );
}

void TMainFormBase::clearbutton()
{
    qWarning( "TMainFormBase::clearbutton(): Not implemented yet!" );
}

void TMainFormBase::comboboxClicked()
{
    qWarning( "TMainFormBase::comboboxClicked(): Not implemented yet!" );
}

void TMainFormBase::gprs()
{
    qWarning( "TMainFormBase::gprs(): Not implemented yet!" );
}

void TMainFormBase::sendButtonClicked()
{
    qWarning( "TMainFormBase::sendButtonClicked(): Not implemented yet!" );
}

void TMainFormBase::zigbee()
{
    qWarning( "TMainFormBase::zigbee(): Not implemented yet!" );
}

