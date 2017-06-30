#include "main_form.h"
#include <qmultilineedit.h>
#include <qtimer.h>
#include <qapplication.h>
#include <qmessagebox.h>
#include <qpushbutton.h>
#include <qlineedit.h>
#include <qcombobox.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <linux/fs.h>
#include <errno.h>
#include <string.h>
#include <termio.h>
#include <qtextcodec.h>
#include <qlabel.h>
QTextCodec * codec = QTextCodec::codecForName("UTF-8");
const int flag =0;
int cell =0;
int cout =0;
int count =0;
int count1 =0;
int BUFFSIZE = 50;
int zigbee=1;
int m=6;
int p=0;
char beidoubuff[100];
int beidoucount=0;
char zigbeebuff[6];
int zigbeecount=0;
char gprsbuff[100];
int gprscount=0;
char buff1[5];
char buff2[15];
char t[22] ={0x03,0x00,0x06,0x03,0x05,0x05};
char r =0x00;
/*================================================================================================
FUNCTION: TMainForm
DESCRIPTION: 
    This is the constructor function of the class TMainForm which is inherited from 
    the class TMainFormBase
ARGUMENTS PASSED:
    parent: The parent of this widget
    name:   The name of this widget
    f:      The flags parameter of this widget
RETURN VALUE:
    None
IMPORTANT NOTES:  
==================================================================================================*/
TMainForm::TMainForm(QWidget * parent, const char * name, WFlags f):TMainFormBase(parent, name, f), m_notifier(0),g_notifier(0), w_notifier(0), z_notifier(0)
{
       autoflag=0;
    /***=========== Open the seiral port "dev/ttySAC1234" ===========***/
       char *devName1="dev/ttySAC3";  //con2
       char *devName2="dev/ttySAC0";  //con5
       char *devName3="dev/ttySAC2";  //con3
       char *devName4="dev/ttySAC1";  //con4

       m_fd = openSerialPort(devName1,3);  //bdou 115200 con2
       g_fd = openSerialPort(devName2,1);  //gprs 9600 con5
       w_fd = openSerialPort(devName3,3);  //wifi 115200 con3
       z_fd = openSerialPort(devName4,3);  //zigbee 115200 con4

	if ((m_fd < 0)||(g_fd < 0)||(w_fd<0)||(z_fd<0))
          {
		QMessageBox::warning(this, tr("Error"), tr("Fail to open serial port!"));
		//	return ;
	  }
    /***============== Set the socketNotifier ===================***/
	m_notifier = new QSocketNotifier(m_fd, QSocketNotifier::Read, this);
	connect (m_notifier, SIGNAL(activated(int)), this, SLOT(remoteDataIncoming()));

       	g_notifier = new QSocketNotifier(g_fd, QSocketNotifier::Read, this);
	connect (g_notifier, SIGNAL(activated(int)), this, SLOT(remoteDataIncoming2()));

	w_notifier = new QSocketNotifier(w_fd, QSocketNotifier::Read, this);
	connect (w_notifier, SIGNAL(activated(int)), this, SLOT(remoteDataIncoming3()));

      	z_notifier = new QSocketNotifier(z_fd, QSocketNotifier::Read, this);
      	connect (z_notifier, SIGNAL(activated(int)), this, SLOT(remoteDataIncoming4()));
    /***================== Initialize the timer =================***/
       testTimer = new QTimer(this);
       connect(testTimer,SIGNAL(timeout()),this,SLOT(beidou()));
       zTimer = new QTimer(this);
       connect(zTimer,SIGNAL(timeout()),this,SLOT(zigbee()));
       gTimer = new QTimer(this);
       connect(gTimer,SIGNAL(timeout()),this,SLOT(gprs()));
    /***======== Initialize the appearance of the widget ==========***/
       Temp->setText(codec->toUnicode("温度"));
       Hum->setText(codec->toUnicode("湿度"));
       Temp_2->setText(codec->toUnicode("温度"));
       Hum_2->setText(codec->toUnicode("湿度"));
       Gprs->setText(codec->toUnicode("发送短信"));
       num->setText(codec->toUnicode("通讯号码："));
       mode->setText(codec->toUnicode("发送模式选择"));
       J->setText(codec->toUnicode("经度"));
       W->setText(codec->toUnicode("纬度"));
       Time->setText(codec->toUnicode("时间"));
       g2->setText(codec->toUnicode("查寻定位信息"));
       g3->setText(codec->toUnicode("查看温度/湿度"));
       g4->setText(codec->toUnicode("发送短报文"));
       g5->setText(codec->toUnicode("清空"));
       BD->setText(codec->toUnicode("目标北斗ID："));
       zig->setText(codec->toUnicode("温湿度节点信息"));
       pos->setText(codec->toUnicode("北斗卫星定位信息"));
       Send->setText(codec->toUnicode("已发送"));
       Receive->setText(codec->toUnicode("已接收"));
       jd1->setText(codec->toUnicode("监测节点A"));
       jd2->setText(codec->toUnicode("监测节点B"));
       	t1->setText("7");//t[10]
	t2->setText("52");
	t3->setText("28");
	j11->setText("120");
	j12->setText("19");
	j13->setText("48.6"); 	
	w1->setText("31");
	w2->setText("28");
	w3->setText("57.0");
       //m_sendEdit->setText(codec->toUnicode("北斗应急通讯终端"));
}
/*================================================================================================
FUNCTION: ~TMainForm
DESCRIPTION: 
    This is the destructor function of the class TMainForm which is inherited from the 
    class TMainFormBase
ARGUMENTS PASSED:
    None
RETURN VALUE:
    None
IMPORTANT NOTES: 
    Both the constructor and destructor are very unusual types of functions: they have 
    no return value. This is distinctly different from a void return value, in which the 
    function returns nothing but you still have the option to make it something else. 
    Constructors and destructors return nothing and you don’t have an option. 
==================================================================================================*/
TMainForm::~TMainForm()
{
  if (m_notifier) 
   {
     delete m_notifier;
   }
   if (m_fd >= 0) 
   {
     ::close(m_fd);
     m_fd = -1;
   }
   if (g_fd >= 0) 
   {
     ::close(g_fd);
     g_fd = -1;
   }
     if (w_fd >= 0) 
   {
     ::close(w_fd);
     w_fd = -1;
   }

   if (g_notifier) 
   {
     delete g_notifier;
     g_notifier = 0;
   }
  if (g_fd >= 0) 
   {
     ::close(g_fd);
     g_fd = -1;
   }
 
   if (w_notifier) 
   {
     delete w_notifier;
     w_notifier = 0;
   }
  if (w_fd >= 0) 
   {
     ::close(w_fd);
     w_fd = -1;
   }

   if (z_notifier) 
   {
     delete z_notifier;
     z_notifier = 0;
   }
  if (z_fd >= 0) 
   {
     ::close(z_fd);
     z_fd = -1;
   }
 
}
/*================================================================================================
FUNCTION: sendButtonClicked
DESCRIPTION: 
    This is the slot function of the event sendButtonClicked
ARGUMENTS PASSED:
    None
RETURN VALUE:
    None
IMPORTANT NOTES:  
==================================================================================================*/

void TMainForm::sendButtonClicked()
{
  char l=0x12; //length init is 18
  int ll;
  char lla,llb;
  int i;
  char te[100] = {0x24,0x54,0x58,0x53,0x51,0x00,l,0x00,0x00,0x00,0x46,0x04,0xAC,0xB4,lla,llb,0x00,0xA4}; 
  char * c1[18];
  char * c2[18];
  char * end;
  char * len;
  char * lenn;
  char * len2;
  char * aa;
  char k=0;
  char * x;
  end =(char*)(&r);
  QString text(m_sendEdit->text());
  QString text1(bdid->text());

  tm=tm+text.length();
  tx->setText(QString::number(tm));     //number of words

    l = 18+text.length()+23+1;//l为总长度*8 lla，18是前面固定的报头，23是发送的协议内容，1是校验位 
    len = (char*)(&l);
    l = *len;

    ll = 8*(text.length()+24);
    lla = ll>>8;                  //lla llb是长度的高低8位
    llb = ll;
    lenn = (char*)(&lla);
    len2 = (char*)(&llb);
    lla = *lenn;
    llb = *len2;

    const char* ch = text.latin1();
    for(i=18;i<40;i++)
      te[i] = t[i-18];
    for(i=0;i<text.length();i++)
      te[i+40] = ch[i];

    te[6] = l;
    te[14]=lla;
    te[15]=llb;

    for(i=0;i<40+text.length();i++)
      k^=te[i];

      k^=r;
      x =(char*)(&k);

    if(text.isEmpty())   
       return;

      for( i=0;i<6;i++)        //te[0-5]
      {
	c1[i] = (char*)(&te[i]);
	::write(m_fd,c1[i],1);
      }
   
      ::write(m_fd,len,1);       //te[6]

      for( i=7;i<14;i++)        //te[7-14]
      {
	c1[i] = (char*)(&te[i]);
	::write(m_fd,c1[i],1);
      }

      ::write(m_fd,lenn,1);       //14
      ::write(m_fd,len2,1);       //te[15]
      
      for( i=16;i<18;i++)        //te[16-17]
      {
	c1[i] = (char*)(&te[i]);
	::write(m_fd,c1[i],1);
      }
      
      ::write(m_fd,text1.latin1(),text1.length());//发送北斗ID
      for(i=6;i<22;i++)         //t[22]
      {
	c2[i] = (char*)(&t[i]);
       ::write(m_fd,c2[i],1);
      }

       ::write(m_fd,text.latin1(),text.length());
       ::write(m_fd,end,1);       //check number
       ::write(m_fd,x,1);
        m_receiveEdit->insert(codec->toUnicode("短报文已发送。\r\n"));
}

/*================================================================================================
FUNCTION: openSerialPort
DESCRIPTION: 
    This function is used to open the selected serial port with a certain baud
ARGUMENTS PASSED:
    devName: The string pointer which indicates the device's name
    baud:    The integer used to choose the baud
RETURN VALUE:
    The file descriptor of the opened serial port. When the serial port is failed to open,
    a -1 will be returned   
IMPORTANT NOTES:  
==================================================================================================*/
int TMainForm::openSerialPort(char *devName,int baud)
{

  int fd = -1;
  fd=::open(devName,O_RDWR|O_NONBLOCK);
  if(fd<0)
    return -1;
  termios serialAttr;
  memset(&serialAttr,0,sizeof serialAttr);
  serialAttr.c_iflag=IGNPAR;
  switch(baud)
    {
    case 1:
       serialAttr.c_cflag=B9600|HUPCL|CS8|CREAD|CLOCAL;break;
    case 2:
       serialAttr.c_cflag=B38400|HUPCL|CS8|CREAD|CLOCAL;break;
    case 3:
       serialAttr.c_cflag=B115200|HUPCL|CS8|CREAD|CLOCAL;break;
    defult: break;
    }
  serialAttr.c_cc[VMIN]=1;
       if(tcsetattr(fd,TCSANOW,&serialAttr)!=0)
	 return -1;
       return fd;
}

/*================================================================================================
FUNCTION: clearbutton
DESCRIPTION: 
    This is the slot function of the event clearbuttonClicked
ARGUMENTS PASSED:
None
RETURN VALUE:
    None
IMPORTANT NOTES:  
==================================================================================================*/
void TMainForm::clearbutton()
{
  m_receiveEdit->setText("");       //Clear m_receiveEdit
  m_sendEdit->setText("");          //Clear m_sendEdit
/***=========== Clear the send and receive count ========***/
  tx->setText("0");                 
  rx->setText("0");
  tm=0;
  rm=0;
}
/*================================================================================================
FUNCTION:GPRS
==================================================================================================*/
void TMainForm::comboboxClicked()
{
  char c;
  char a = 0x1A;
  char *b;
  b =(char*)(&a);
  char d = 0x22;
  char *e;
  e =(char*)(&d);

  QString text(m_sendEdit->text()); 
  QString text1("AT+CSCS=");
  QString text11("GSM");	
  QString text12("\r\n");
  QString text2("AT+CMGF=1\r\n");
  QString text3("AT+CMGS=");
  QString text4(number->text());
  QString text5("\r\n");	
  QString text6("AT+CMGD=1");

  ::write(g_fd,text1.latin1(),text1.length());
  ::write(g_fd,e,1);
  ::write(g_fd,text11.latin1(),text11.length());
  ::write(g_fd,e,1);
  ::write(g_fd,text12.latin1(),text12.length());
  
  sleep(2); //delay
  
  ::write(g_fd,text2.latin1(),text2.length());

  sleep(2); //delay

  ::write(g_fd,text3.latin1(),text3.length());
  ::write(g_fd,e,1);
  ::write(g_fd,text4.latin1(),text4.length());
  ::write(g_fd,e,1);
  ::write(g_fd,text5.latin1(),text5.length());

  sleep(3); //delay  //delay

  ::write(g_fd,text.latin1(),text.length());   
  ::write(g_fd,b,1);
  ::write(g_fd,text5.latin1(),text5.length());

   m_receiveEdit->insert(codec->toUnicode("短信已发送。\r\n"));
}

/*================================================================================================
FUNCTION: remoteDataIncoming
DESCRIPTION: 
    This the slot function of the event m_notifierActivated(int)
ARGUMENT PASSED:
    None
RETURN VALUE:
    None
    IMPORTANT NOTES: 
==================================================================================================*/
void TMainForm::remoteDataIncoming()
{
  char c; 
  int timems=20;

    if(read(m_fd,&c,sizeof c)!=1) 
       return;
       beidoubuff[beidoucount]=c;  
       beidoucount++;
       rm=rm+(sizeof c);
       rx->setText(QString::number(rm));
       testTimer->start(timems);               	
}
//==========================================================//
void TMainForm::autoButtonClicked()
{
  int i = 0;
  char loc[]={0x24,0x44,0x57,0x53,0x51,0x00,0x16,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x27};
 char * l[22];
 
 for(int i=0;i<22;i++)
   {
	l[i] = (char*)(&loc[i]);
	::write(m_fd,l[i],1);
      }
}
//=====================GPRS=============================//
void TMainForm::remoteDataIncoming2()
{
    int timems=200;
    char c;
    if(read(g_fd,&c,sizeof c)!=1) 
       return;
       gprsbuff[gprscount]=c;  
       gprscount++;
       gTimer->start(timems);      
}
//===================wifi===============================//
void TMainForm::remoteDataIncoming3()
{
    char c;
    if(read(w_fd,&c,sizeof c)!=1) 
    return;
    m_sendEdit->insert(QString(QChar(c)));
    if(c=='o')
    TMainForm::sendButtonClicked();
}
//=====================zigbee===========================//
void TMainForm::remoteDataIncoming4()
{
    int timems=20;
    char c;
    if(read(z_fd,&c,sizeof c)!=1) 
       return;
       zigbeebuff[zigbeecount]=c;  
       zigbeecount++;
       zTimer->start(timems);       
}
//=====================beidou===========================//
void TMainForm::beidou()
{
  int i;
  int y;
  char * c[100];

  if(beidoucount==0)
    return;
  testTimer->stop();
 if((beidoubuff[0]=='$')&&(beidoubuff[1]=='D')&&(beidoubuff[2]=='W')&&(beidoubuff[3]=='X')&&(beidoubuff[10]==0X08))
      {
	for(i=0;i<12;i++)
	  {
	    t[i+10]=beidoubuff[i+14];
	   }
	
	t1->setText(QString::number(t[10]));//t[10]
	t2->setText(QString::number(t[11]));
	t3->setText(QString::number(t[12]));
	j11->setText(QString::number(t[14]));
	j12->setText(QString::number(t[15]));
	j13->setText(QString::number(t[16]+0.1*t[17])); 	
	w1->setText(QString::number(t[18]));
	w2->setText(QString::number(t[19]));
	w3->setText(QString::number(t[20]+0.1*t[21]));

	for(i=0;i<8;i++)           //检测经纬度中的1A，如果有，加一，r左移
	  {
	    if(t[i+14]==0X1A)
	      {
		t[i+14]=0X1B;
		r|=1<<(7-i);
	      }
	  }
      }

   else if((beidoubuff[0]=='$')&&(beidoubuff[1]=='T')&&(beidoubuff[2]=='X')&&(beidoubuff[3]=='X')&&(beidoubuff[10]==0x60))
      {
	 m_receiveEdit->insert(codec->toUnicode("来源：北斗\r\n"));
	y =  (int)beidoubuff[6]-21;
	for(i=0;i<y;i++)
	  {	       
	    	m_receiveEdit->insert(QString(QChar(beidoubuff[i+19])));
		c[i] = (char*)(&beidoubuff[i+19]);
		::write(w_fd,c[i],1);
	  }
      }
  beidoucount=0;
}

//=====================zigbee===========================//
void TMainForm::zigbee()
{
  int i;

  if(zigbeecount==0)
    return;
  zTimer->stop();

  if(zigbeebuff[2]=='A')
      {
        t[8]=zigbeebuff[0]; //shi 10
	t[9]=zigbeebuff[1];//shi 1
	t[6]=zigbeebuff[3];//wen 10
	t[7]=zigbeebuff[4];//wen 1

       	hu->setText(QString::number(10*(t[8]-(t[8]/16)*16)+(t[9]-(t[9]/16)*16)));
	tp->setText(QString::number(10*(t[6]-(t[6]/16)*16)+(t[7]-(t[7]/16)*16)));
	
       	t[8]=(t[8]-(t[8]/16)*16);
	t[9]=(t[9]-(t[9]/16)*16);
	t[6]=(t[6]-(t[6]/16)*16);
	t[7]=(t[7]-(t[7]/16 )*16);
      }
    else if(zigbeebuff[2]=='B')
    {
        t[8]=zigbeebuff[0]; //shi 10
	t[9]=zigbeebuff[1];//shi 1
	t[6]=zigbeebuff[3];//wen 10
	t[7]=zigbeebuff[4];//wen 1

       	hu_2->setText(QString::number(10*(t[8]-(t[8]/16)*16)+(t[9]-(t[9]/16)*16)));
	tp_2->setText(QString::number(10*(t[6]-(t[6]/16)*16)+(t[7]-(t[7]/16)*16)));
	
	t[8]=(t[8]-(t[8]/16)*16);
	t[9]=(t[9]-(t[9]/16)*16);
	t[6]=(t[6]-(t[6]/16)*16);
	t[7]=(t[7]-(t[7]/16)*16);
    }
  zigbeecount=0;
}
//=====================gprs===========================//
void TMainForm::gprs()
{
  QString text5("\r\n");
  QString text("AT+CMGR=1");
  QString text6("AT+CMGD=1");
  int i;
  if(gprscount==0)
    return;
  gTimer->stop();

   if((gprsbuff[14]=='C')&&(gprsbuff[15]=='M')&&(gprsbuff[16]=='G')&&(gprsbuff[17]=='R'))
     {
      m_receiveEdit->insert(codec->toUnicode("来源："));

      for(i=2;i<16;i++ )
	{
	  m_receiveEdit->insert(QString(QChar(gprsbuff[32+i])));//提取手机号码
	}
      m_receiveEdit->insert(QString("\n"));

      m_receiveEdit->insert(codec->toUnicode("时间："));

      for(i=2;i<19;i++)
	{
	  m_receiveEdit->insert(QString(QChar(gprsbuff[52+i])));//提取时间
	}
      m_receiveEdit->insert(QString("\n"));

      m_receiveEdit->insert(codec->toUnicode("内容："));

      for(i=77;i<gprscount-4;i++ )
	{
        m_receiveEdit->insert(QString(QChar(gprsbuff[i])));//信息内容
	}
      m_receiveEdit->insert(QString("\r\n"));
      ::write(g_fd,text6.latin1(),text6.length());
      ::write(g_fd,text5.latin1(),text5.length());
     }

      if((gprsbuff[3]=='C')&&(gprsbuff[4]=='M')&&(gprsbuff[5]=='T')&&(gprsbuff[6]=='I'))
	{
	  m_receiveEdit->insert(codec->toUnicode("您有新的短信息!\r\n"));

         ::write(g_fd,text.latin1(),text.length()); 
         ::write(g_fd,text5.latin1(),text5.length());
	}

   gprscount=0;
}

