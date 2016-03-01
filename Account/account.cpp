#include "stdafx.h"
#include "account.h"
#include <QLabel>
#include <QPixmap>
#include "billwidget.h"
#include "dayview.h"
#include "monthview.h"


// const QString pushColor = "background-color: rgb(200, 200, 200);";
// const QString unpushColor = "background-color: rgb(255, 255, 255);";
Account::Account(QWidget *parent)
: QWidget(parent)
{
	ui.setupUi(this);
	//下面一行引起qss不起作用
	//this->setBackgroundRole(QPalette::Dark);

	//this->setMinimumSize(1400, 1000);
	//	this->showMaximized();
	this->setWindowIcon(QIcon(":/Account/Resources/Entypo_2712(0)_64.png"));
	this->setWindowTitle(QString("Account"));
	//this->setWindowFlags(Qt::FramelessWindowHint);

	//右上角功能键
	// 	labelMini = new QLabel(this);
	// 	labelClose = new QLabel(this);
	// 	labelMini->setPixmap(QPixmap(":/Account/Resources/Entypo_2d(0)_32.png"));
	// 	labelClose->setPixmap(QPixmap(":/Account/Resources/Entypo_2715(1)_32.png"));
	// 
	// 	labelMini->move(this->rect().width() - 64, 0);
	// 	labelMini->installEventFilter(this);
	// 	qDebug() << this->rect().width() - 64;
	// 	labelClose->move(this->rect().width() - 32, 0);
	// 	labelClose->installEventFilter(this);

	sWgt = new QStackedWidget();
	createButtons();
	createStackedWidget();

	QHBoxLayout* hLayout = new QHBoxLayout;

	QSpacerItem *vSpacer = new QSpacerItem(10000, 10000, QSizePolicy::Maximum, QSizePolicy::Maximum);

	hLayout->addWidget(pBtn1);
	hLayout->addWidget(pBtn2);
	hLayout->addWidget(pBtn3);
	hLayout->addStretch(1);
	hLayout->addWidget(pBtn4);
	// 	hLayout->addWidget(pBtn5);
//	hLayout->addSpacerItem(vSpacer);
	hLayout->addSpacing(30);
	QHBoxLayout* sLayout = new QHBoxLayout;
	sLayout->addWidget(sWgt);

	ui.verticalLayout->addLayout(hLayout);
	ui.verticalLayout->addLayout(sLayout);

	connect(pBtn1, SIGNAL(clicked()), this, SLOT(on_pBtn1_clicked()));
	connect(pBtn2, SIGNAL(clicked()), this, SLOT(on_pBtn2_clicked()));
	connect(pBtn3, SIGNAL(clicked()), this, SLOT(on_pBtn3_clicked()));
	connect(pBtn4, SIGNAL(clicked()), this, SLOT(on_pBtn4_clicked()));
	connect(pBtn5, SIGNAL(clicked()), this, SLOT(on_pBtn5_clicked()));
}

void Account::paintEvent(QPaintEvent *)
{

}

void Account::createButtons()
{
	pBtn1 = new QToolButton();
	pBtn1->setText(QString::fromLocal8Bit("单笔录入"));
	QPixmap pixmap1(":/Account/Resources/Entypo_229e(6)_64.png");
	pBtn1->setIcon(pixmap1);
	pBtn1->setIconSize(pixmap1.size());

	pBtn2 = new QToolButton();
	pBtn2->setText(QString::fromLocal8Bit("日视图"));
	QPixmap pixmap2(":/Account/Resources/Entypo_e731(4)_64.png");
	pBtn2->setIcon(pixmap2);
	pBtn2->setIconSize(pixmap2.size());


	pBtn3 = new QToolButton();
	pBtn3->setText(QString::fromLocal8Bit("月视图"));
	QPixmap pixmap3(":/Account/Resources/Entypo_f601(3)_64.png");
	pBtn3->setIcon(pixmap3);
	pBtn3->setIconSize(pixmap3.size());

	pBtn4 = new QToolButton();
	pBtn4->setText(QString::fromLocal8Bit("切换主题"));
	QPixmap pixmap4(":/Account/Resources/Entypo_25d1(5)_64.png");
	pBtn4->setIcon(pixmap4);
	pBtn4->setIconSize(pixmap4.size());

	pBtn5 = new QToolButton();
	pBtn5->setText(QString::fromLocal8Bit("备用"));
	QPixmap pixmap5(":/Account/Resources/Entypo_e736(1)_64.png");
	pBtn5->setIcon(pixmap5);
	pBtn5->setIconSize(pixmap5.size());

	QList<QToolButton*> btnList;
	btnList << pBtn1 << pBtn2 << pBtn3 << pBtn4 << pBtn5;

	QButtonGroup* btnGroup = new QButtonGroup;
	for (auto btn : btnList) {
		btn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
		btn->setCheckable(true);
		btn->setAutoExclusive(true);
		btnGroup->addButton(btn);
	}

}

void Account::createStackedWidget()
{
	billWidget = new BillWidget(this);
	dayView = new DayView(this);
	monthView = new MonthView(this);

	connect(billWidget, SIGNAL(signal_addData()),
			monthView, SLOT(slot_ComboBoxChanged()));
	sWgt->addWidget(billWidget);
	sWgt->addWidget(dayView);
	sWgt->addWidget(monthView);

}

Account::~Account()
{

}


void Account::on_pBtn1_clicked(){
	pBtn1->setChecked(true);
	pBtn1->setFocus(Qt::PopupFocusReason);
	sWgt->setCurrentIndex(0);
	billWidget->showTableView();
}

void Account::on_pBtn2_clicked(){
	pBtn2->setChecked(true);
	pBtn2->setFocus(Qt::PopupFocusReason);
	sWgt->setCurrentIndex(1);
	dayView->showTableView();
}

void Account::on_pBtn3_clicked(){

	pBtn3->setChecked(true);
	pBtn3->setFocus(Qt::PopupFocusReason);
	sWgt->setCurrentIndex(2);
	monthView->showTableView();
}

void Account::on_pBtn4_clicked(){
// 	pBtn4->setChecked(true);
// 	pBtn4->setFocus(Qt::NoFocusReason);
	sWgt->setCurrentIndex(3);
	QFile f(":qdarkstyle/style.qss");
	if (!f.exists())
	{
		printf("Unable to set stylesheet, file not found\n");
	}
	else
	{
		f.open(QFile::ReadOnly | QFile::Text);
		QTextStream ts(&f);
		static bool styleSheetFlag = false;
		if (styleSheetFlag)
		{
			styleSheetFlag = false;
			qApp->setStyleSheet(ts.readAll());
		}
		else
		{
			styleSheetFlag = true;
			qApp->setStyleSheet(NULL);
		}
	}
}

void Account::on_pBtn5_clicked(){

	sWgt->setCurrentIndex(4);
}


void Account::mousePressEvent(QMouseEvent *event)
{
	//只能是鼠标左键移动和改变大小
	if (event->button() == Qt::LeftButton) {
		m_mousePress = true;
	}
	//窗口移动距离
	m_movePoint = event->globalPos() - pos();
}

void Account::mouseReleaseEvent(QMouseEvent *)
{
	m_mousePress = false;
}

void Account::mouseMoveEvent(QMouseEvent *event)
{
	//移动窗口
	if (m_mousePress) {
		QPoint movePpos = event->globalPos();
		move(movePpos - m_movePoint);
	}
}

void Account::on_closeLabel_clicked(){
	qApp->exit();
	qDebug() << "labelClose";
}

bool Account::eventFilter(QObject *obj, QEvent *event)
{
	if (obj == labelClose) {
		if (event->type() == QEvent::MouseButtonPress) {
			//QMessageBox::information(NULL, QString::fromLocal8Bit("单击"), QString::fromLocal8Bit("单击确定"), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
			qApp->exit();
			return true;
		}
		else {
			return false;
		}
	}
	if (obj == labelMini) {
		if (event->type() == QEvent::MouseButtonPress) {
			//QMessageBox::information(NULL, QString::fromLocal8Bit("单击"), QString::fromLocal8Bit("单击确定"), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
			//qApp->exit();
			this->showMinimized();
			return true;
		}
		else {
			return false;
		}
	}
	return QWidget::eventFilter(obj, event);
}



/*
Microsoft Windows [版本 10.0.10586]
(c) 2015 Microsoft Corporation。保留所有权利。

C:\Users\Administrator>ipconfig /all

Windows IP 配置

主机名  . . . . . . . . . . . . . : XT1-20141108UJK
主 DNS 后缀 . . . . . . . . . . . :
节点类型  . . . . . . . . . . . . : 混合
IP 路由已启用 . . . . . . . . . . : 否
WINS 代理已启用 . . . . . . . . . : 否

以太网适配器 本地连接 2:

媒体状态  . . . . . . . . . . . . : 媒体已断开连接
连接特定的 DNS 后缀 . . . . . . . :
描述. . . . . . . . . . . . . . . : Realtek PCIe GBE Family Controller
物理地址. . . . . . . . . . . . . : 08-9E-01-E3-24-4B
DHCP 已启用 . . . . . . . . . . . : 是
自动配置已启用. . . . . . . . . . : 是

无线局域网适配器 本地连接* 2:

媒体状态  . . . . . . . . . . . . : 媒体已断开连接
连接特定的 DNS 后缀 . . . . . . . :
描述. . . . . . . . . . . . . . . : Microsoft Wi-Fi Direct Virtual Adapter
物理地址. . . . . . . . . . . . . : 0C-8B-FD-50-9E-58
DHCP 已启用 . . . . . . . . . . . : 是
自动配置已启用. . . . . . . . . . : 是

无线局域网适配器 本地连接* 3:

媒体状态  . . . . . . . . . . . . : 媒体已断开连接
连接特定的 DNS 后缀 . . . . . . . :
描述. . . . . . . . . . . . . . . : Microsoft Hosted Network Virtual Adapter
物理地址. . . . . . . . . . . . . : 0E-8B-FD-50-9E-57
DHCP 已启用 . . . . . . . . . . . : 是
自动配置已启用. . . . . . . . . . : 是

无线局域网适配器 无线网络连接:

连接特定的 DNS 后缀 . . . . . . . :
描述. . . . . . . . . . . . . . . : Intel(R) Wireless-N 7260
物理地址. . . . . . . . . . . . . : 0C-8B-FD-50-9E-57
DHCP 已启用 . . . . . . . . . . . : 是
自动配置已启用. . . . . . . . . . : 是
本地链接 IPv6 地址. . . . . . . . : fe80::9d08:7bec:27e0:84af%5(首选)
IPv4 地址 . . . . . . . . . . . . : 192.168.0.107(首选)
子网掩码  . . . . . . . . . . . . : 255.255.255.0
获得租约的时间  . . . . . . . . . : 2016年2月27日 星期六 09:12:57
租约过期的时间  . . . . . . . . . : 2016年3月1日 星期二 20:03:54
默认网关. . . . . . . . . . . . . : 192.168.0.1
DHCP 服务器 . . . . . . . . . . . : 192.168.0.1
DHCPv6 IAID . . . . . . . . . . . : 286034941
DHCPv6 客户端 DUID  . . . . . . . : 00-01-00-01-1B-EF-C7-B5-08-9E-01-E3-24-4B
DNS 服务器  . . . . . . . . . . . : 192.168.0.1
8.8.8.8
TCPIP 上的 NetBIOS  . . . . . . . : 已启用

以太网适配器 Bluetooth 网络连接:

媒体状态  . . . . . . . . . . . . : 媒体已断开连接
连接特定的 DNS 后缀 . . . . . . . :
描述. . . . . . . . . . . . . . . : Bluetooth Device (Personal Area Network)
物理地址. . . . . . . . . . . . . : 0C-8B-FD-50-9E-5B
DHCP 已启用 . . . . . . . . . . . : 是
自动配置已启用. . . . . . . . . . : 是

隧道适配器 isatap.{74361541-BD8A-4326-BA04-5CE88A320EB7}:

媒体状态  . . . . . . . . . . . . : 媒体已断开连接
连接特定的 DNS 后缀 . . . . . . . :
描述. . . . . . . . . . . . . . . : Microsoft ISATAP Adapter
物理地址. . . . . . . . . . . . . : 00-00-00-00-00-00-00-E0
DHCP 已启用 . . . . . . . . . . . : 否
自动配置已启用. . . . . . . . . . : 是

隧道适配器 Teredo Tunneling Pseudo-Interface:

连接特定的 DNS 后缀 . . . . . . . :
描述. . . . . . . . . . . . . . . : Teredo Tunneling Pseudo-Interface
物理地址. . . . . . . . . . . . . : 00-00-00-00-00-00-00-E0
DHCP 已启用 . . . . . . . . . . . : 否
自动配置已启用. . . . . . . . . . : 是
IPv6 地址 . . . . . . . . . . . . : 2001:0:9d38:90d7:28b2:9d:3f57:ff94(首选)
本地链接 IPv6 地址. . . . . . . . : fe80::28b2:9d:3f57:ff94%6(首选)
默认网关. . . . . . . . . . . . . : ::
DHCPv6 IAID . . . . . . . . . . . : 687865856
DHCPv6 客户端 DUID  . . . . . . . : 00-01-00-01-1B-EF-C7-B5-08-9E-01-E3-24-4B
TCPIP 上的 NetBIOS  . . . . . . . : 已禁用
*/