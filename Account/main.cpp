#include "stdafx.h"
#include "account.h"
#include <QtWidgets/QApplication>
#include <QtNetwork/QNetworkInterface>
#include <stdlib.h>  
#include <QHostInfo>
#include <QList>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	QFile f(":qdarkstyle/style.qss");
	if (!f.exists()) {
		printf("Unable to set stylesheet, file not found\n");
	}
	else {
		f.open(QFile::ReadOnly | QFile::Text);
		QTextStream ts(&f);
		qApp->setStyleSheet(ts.readAll());
	}

	QString name = qgetenv("USERNAME");
	qDebug() << "User Name:" << name;
	//QHostInfo类作用，获取主机名，也可以通过主机名来查找IP地址，或者通过IP地址来反向查找主机名。
	QString localHostName = QHostInfo::localHostName();
	qDebug() << "LocalHostName:" << localHostName;

	//获取所有网络接口的列表
	int i = 0;
	QStringList strList;
	foreach(auto netInterface, QNetworkInterface::allInterfaces())
	{
		//设备名
		qDebug() << i << ">\t" << "Device:" << netInterface.name();
		//MAC地址
		qDebug() << "\tHardwareAddress:" << netInterface.hardwareAddress();
		strList.append(netInterface.hardwareAddress());
		auto entryList = netInterface.addressEntries();
		//遍历每一个IP地址(每个包含一个IP地址，一个子网掩码和一个广播地址)
		foreach(QNetworkAddressEntry entry, entryList)
		{
			//IP地址
			qDebug() << "\t\tIP Address:" << entry.ip().toString();
			//子网掩码
			qDebug() << "\t\tNetmask:" << entry.netmask().toString();
			//广播地址
			qDebug() << "\t\tBroadcast:" << entry.broadcast().toString();
		}
		++i;
	}

	QStringList destinationStr;
	destinationStr << "00:1C:42:44:DE:3C" << "EC:B1:D7:59:69:91" ;
	bool accessFlag = false;
	for (auto j = 0; j < destinationStr.count(); ++j)   {
		if (strList.contains(destinationStr[j]))
		{
			accessFlag = true;
		}
	}
	if (!accessFlag)
	{
	//	return 0;
	}
	QSharedMemory shared_memory;
	shared_memory.setKey(QString("account"));

	if (shared_memory.attach()) {
		QMessageBox::information(nullptr, QString::fromLocal8Bit("警告"), QString::fromLocal8Bit("只能打开一个应用程序实例"), 0);
		return 0;
	}

	if (shared_memory.create(1)) {
		Account w;
		w.show();
		w.showMaximized();
		return a.exec();
	}

	return a.exec();
}
