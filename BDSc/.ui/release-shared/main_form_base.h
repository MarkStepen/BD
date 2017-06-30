/****************************************************************************
** Form interface generated from reading ui file 'main_form_base.ui'
**
** Created: Tue Apr 4 19:42:22 2017
**      by:  The User Interface Compiler (uic)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/
#ifndef TMAINFORMBASE_H
#define TMAINFORMBASE_H

#include <qvariant.h>
#include <qwidget.h>
class QVBoxLayout; 
class QHBoxLayout; 
class QGridLayout; 
class QFrame;
class QLabel;
class QLineEdit;
class QMultiLineEdit;
class QPushButton;

class TMainFormBase : public QWidget
{ 
    Q_OBJECT

public:
    TMainFormBase( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~TMainFormBase();

    QFrame* Line4;
    QFrame* Line1;
    QFrame* Line7;
    QFrame* Line2_2;
    QFrame* Line2;
    QPushButton* Gprs;
    QPushButton* g4;
    QPushButton* g3;
    QLineEdit* hu_2;
    QLabel* TextLabel1_3_2_2_3;
    QLabel* TextLabel1_3_2_2;
    QLineEdit* hu;
    QLineEdit* tp;
    QLabel* TextLabel1_3_2_2_2;
    QLabel* Temp;
    QLabel* Hum_2;
    QLabel* Hum;
    QLabel* PixmapLabel1_3;
    QLineEdit* tp_2;
    QLabel* jd1;
    QLabel* Temp_2;
    QLabel* Time;
    QLabel* TextLabel1_3_3_2_2;
    QLineEdit* w3;
    QLabel* TextLabel1_3_3_4;
    QLineEdit* j12;
    QLineEdit* t1;
    QLabel* J;
    QLabel* PixmapLabel1_3_2;
    QLineEdit* j11;
    QLineEdit* w2;
    QLabel* PixmapLabel1_3_3;
    QLineEdit* t3;
    QLabel* W;
    QLabel* TextLabel1_3_3;
    QLineEdit* j13;
    QLineEdit* w1;
    QLineEdit* t2;
    QMultiLineEdit* m_receiveEdit;
    QLabel* Receive;
    QLineEdit* rx;
    QLabel* Send;
    QPushButton* g2;
    QFrame* Line6;
    QLabel* TextLabel1_3_2_2_2_2;
    QLabel* PixmapLabel1_3_4;
    QMultiLineEdit* m_sendEdit;
    QLineEdit* tx;
    QLabel* pos;
    QLabel* TextLabel1_3;
    QLabel* TextLabel1_3_2;
    QFrame* Line5;
    QLabel* TextLabel1_3_3_2;
    QFrame* Line9;
    QPushButton* g5;
    QLabel* mode;
    QLabel* BD;
    QLabel* num;
    QLabel* zig;
    QLabel* jd2;
    QLineEdit* bdid;
    QLineEdit* number;

public slots:
    virtual void autoButtonClicked();
    virtual void beidou();
    virtual void clearbutton();
    virtual void comboboxClicked();
    virtual void gprs();
    virtual void sendButtonClicked();
    virtual void zigbee();

protected:
    bool event( QEvent* );
};

#endif // TMAINFORMBASE_H
