Compile system: Fedora14
Running environment: Qtopia2.2
Development board: itop4412
Interface design: Qtdesigner
Open VMware10.0 and start Fedora14.0, under the /opt/ new folder QT, respectively, the source file main.cpp; main_form.cpp; main_form.h; buildarm.sh; BDS.ui; BDS.pro; Makefile.target; in the directory
Compile the project: open the system terminal in Fedora14.0, enter CD /opt/QT, enter the project folder, enter the./buildarm.sh compiler, and then generate the target file under /opt/QT: BDR.
Subsequently, BDR is copied into the /opt/Qtopia/bin of the development board, and PC is connected to the development board through serial port 0. After opening the SecureCRT connection, enter the instruction "CP /opt/Qtopia/bin".
Restart the development board, you can open the use of this software
