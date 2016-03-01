#include "stdafx.h"
#include "tableview.h"
#include <QSqlTableModel>
#include "databasemanager.h"
#include "tableviewmodel.h"

TableView::TableView(QWidget *parent)
: QTableView(parent)
{
// 	this->setStyleSheet("\
// 						QTableView{\
// color: white;\
// 	gridline-color: white;\
// 	background-color: rgb(108, 108, 108);\
// 	alternate-background-color: rgb(64, 64, 64);\
// 	selection-color: white;\
// 	selection-background-color: rgba(0, 0, 200, 0.2);\
// border: 2px groove gray;\
// 	border-radius: 0px;\
// padding: 2px 4px;\
// }\
// 						QHeaderView {\
// 					color: white;\
// font: bold 10pt;\
// 	background-color: rgb(108, 108, 108);\
// border: 0px solid rgb(144, 144, 144);\
// border:0px solid rgb(191, 191, 191);\
// 	border-left-color: rgba(255, 255, 255, 0);\
// 	border-top-color: rgba(255, 255, 255, 0);\
// 	border-radius:0px;\
// 	min-height:29px;\
// }\
// QHeaderView::section{\
// color: white;\
// 	background-color: rgb(64, 64, 64);\
// border: 5px solid #f6f7fa;\
// 	border-radius:0px;\
// 	border-color: rgb(64, 64, 64);\
// }\
// ");

	//可用样式表
// 	this->setStyleSheet("QHeaderView::section { background-color:blue; "
// 						"color:yellow;"
// 						"}");

/*
QTableCornerButton:section{
 	background-color: #000000;
}
*/
 
//	this->setStyleSheet("QTableCornerButton::section{background-color:red;}");
	this->setContextMenuPolicy(Qt::CustomContextMenu);
	connect(this->horizontalHeader(), SIGNAL(sectionClicked(int)), this, SLOT(updateView(int)));

}

TableView::~TableView()
{

}

void TableView::updateView(int column)
{
	insertTotalRow();
}

void TableView::updateTableView(QString& filterStr)
{

	tableModel = new TableViewModel(this, DatabaseManager::Instance().db);
	tableModel->setTable("account");
	tableModel->setFilter(filterStr);
	tableModel->select();
	tableModel->sort(2, Qt::AscendingOrder);
	tableModel->select();

//	tableModel->setHeaderData(0, Qt::Horizontal, QColor(Qt::blue),Qt::BackgroundRole);

	tableModel->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit("时间"));
	tableModel->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("排名"));
	tableModel->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("编号"));
	tableModel->setHeaderData(3, Qt::Horizontal, QString::fromLocal8Bit("成本"));
	tableModel->setHeaderData(4, Qt::Horizontal, QString::fromLocal8Bit("总成交额"));
	tableModel->setHeaderData(5, Qt::Horizontal, QString::fromLocal8Bit("是否真迹"));
	tableModel->setHeaderData(6, Qt::Horizontal, QString::fromLocal8Bit("单数"));
	tableModel->setHeaderData(7, Qt::Horizontal, QString::fromLocal8Bit("总利润"));
	tableModel->setHeaderData(8, Qt::Horizontal, QString::fromLocal8Bit("个人利润"));
	tableModel->setHeaderData(9, Qt::Horizontal, QString::fromLocal8Bit("转账资金"));

	

	this->setModel(tableModel);
	insertTotalRow();
}

void TableView::insertTotalRow()
{
	TableViewModel* model = static_cast<TableViewModel*>(this->model());
	//auto model = this->model();
	int rowNum = model->rowCount();
	if (rowNum==0)
	{
		return;
	}
	model->insertRow(rowNum);
	model->setData(model->index(rowNum, 0), QString::fromLocal8Bit("总计："));
	
	double total_costPrice = 0;
	double total_totalTurnover = 0;
	double total_relics = 0;
	double total_billCount = 0;
	double total_totalProfit = 0;
	double total_personalProfix = 0;
	double total_fundsTransfer = 0;
	for (int i = 0; i < rowNum; ++i) {
		total_costPrice += NUMBER(this->model()->data(model->index(i, 3)).toDouble());
		total_totalTurnover += NUMBER(this->model()->data(model->index(i, 4)).toDouble());
		total_relics += NUMBER(this->model()->data(model->index(i, 5)).toDouble());
		total_billCount += NUMBER(this->model()->data(model->index(i, 6)).toDouble());
		total_totalProfit += NUMBER(this->model()->data(model->index(i, 7)).toDouble());
		total_personalProfix += NUMBER(this->model()->data(model->index(i, 8)).toDouble());
		total_fundsTransfer += NUMBER(this->model()->data(model->index(i, 9)).toDouble());
	}
// 	qDebug() << PRECISION(total_costPrice) << ","
// 		<< PRECISION(total_totalTurnover) << ","
// 		<< PRECISION(total_relics) << ","
// 		<< PRECISION(total_billCount) << ","
// 		<< PRECISION(total_totalProfit) << ","
// 		<< PRECISION(total_personalProfix) << ","
// 		<< PRECISION(total_fundsTransfer) << ",";
	model->setData(model->index(rowNum, 1), QString::fromLocal8Bit(""));
	model->setData(model->index(rowNum, 2), QString::fromLocal8Bit(""));
	model->setData(model->index(rowNum, 3), total_costPrice);
	model->setData(model->index(rowNum, 4), PRECISION(total_totalTurnover));
	model->setData(model->index(rowNum, 5), PRECISION(total_relics));
	model->setData(model->index(rowNum, 6), PRECISION(total_billCount));
	model->setData(model->index(rowNum, 7), PRECISION(total_totalProfit));
	model->setData(model->index(rowNum, 8), PRECISION(total_personalProfix));
	model->setData(model->index(rowNum, 9), PRECISION(total_fundsTransfer));
}
