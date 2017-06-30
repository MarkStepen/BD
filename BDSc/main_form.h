#if !defined (__MAIN_FORM_H__)
#define __MAIN_FORM_H__

#include "main_form_base.h"
#include <qsocketnotifier.h>
class TMainForm: public TMainFormBase {
	Q_OBJECT
public:
	TMainForm(QWidget * parent = 0, const char * name = 0, WFlags f = WType_TopLevel);
	virtual ~TMainForm();

private:
	int openSerialPort(char *devName,int baud);

public slots:
	void sendButtonClicked();
	void clearbutton();
        void autoButtonClicked();
        void comboboxClicked();
	void remoteDataIncoming();
	void remoteDataIncoming2();
	void remoteDataIncoming3();
	void remoteDataIncoming4();
	void beidou();
	void zigbee();
	void gprs();

private:
	int m_fd;
	int w_fd;
	int g_fd;
	int z_fd;
        int tm,rm,autoflag,flag;
	QSocketNotifier *m_notifier;
	QSocketNotifier *w_notifier;
	QSocketNotifier *g_notifier;
	QSocketNotifier *z_notifier;
        QTimer *testTimer;
	QTimer *zTimer;
	QTimer *gTimer;
};

#endif
