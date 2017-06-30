编译系统：Fedora14
运行环境：Qtopia2.2  
开发板：itop4412
界面设计：Qtdesigner

打开VMware10.0并启动Fedora14.0，在/opt/下新建文件夹QT，分别将源文件main.cpp;main_form.cpp;main_form.h;BDS.ui;BDS.pro;Makefile.target;buildarm.sh放在该目录下

编译工程：
在Fedora14.0中打开系统终端，输入cd /opt/QT进入工程文件夹，输入./buildarm.sh编译，此时在/opt/QT下生成目标文件：BDR。如图3所示。
随后将BDR拷入Smart210的/opt/Qtopia/bin中，PC通过串口0连接到开发板，打开SecureCRT连接上之后输入指令cp /opt/Qtopia/bin。
重启开发板，即可打开使用本软件

