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
	//QHostInfo�����ã���ȡ��������Ҳ����ͨ��������������IP��ַ������ͨ��IP��ַ�����������������
	QString localHostName = QHostInfo::localHostName();
	qDebug() << "LocalHostName:" << localHostName;

	//��ȡ��������ӿڵ��б�
	int i = 0;
	QStringList strList;
	foreach(auto netInterface, QNetworkInterface::allInterfaces())
	{
		//�豸��
		qDebug() << i << ">\t" << "Device:" << netInterface.name();
		//MAC��ַ
		qDebug() << "\tHardwareAddress:" << netInterface.hardwareAddress();
		strList.append(netInterface.hardwareAddress());
		auto entryList = netInterface.addressEntries();
		//����ÿһ��IP��ַ(ÿ������һ��IP��ַ��һ�����������һ���㲥��ַ)
		foreach(QNetworkAddressEntry entry, entryList)
		{
			//IP��ַ
			qDebug() << "\t\tIP Address:" << entry.ip().toString();
			//��������
			qDebug() << "\t\tNetmask:" << entry.netmask().toString();
			//�㲥��ַ
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
		QMessageBox::information(nullptr, QString::fromLocal8Bit("����"), QString::fromLocal8Bit("ֻ�ܴ�һ��Ӧ�ó���ʵ��"), 0);
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
