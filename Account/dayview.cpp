#include "stdafx.h"
#include "dayview.h"
#include <databasemanager.h>
#include <QSqlTableModel>
#include <QTableView>
#include "tableview.h"
#include <ActiveQt/QAxObject>

DayView::DayView(QWidget *parent)
: QWidget(parent)
{
	ui.setupUi(this);
	ui.dateEdit->setDate(QDate::currentDate());
	ui.tableView->setSortingEnabled(true);
	connect(ui.dateEdit, SIGNAL(dateChanged(const QDate &)), this, SLOT(updateTableView(const QDate &)));
	//ui.viewBtn->hide();
}

DayView::~DayView()
{

}

void DayView::updateTableView(const QDate & date)
{
	showTableView();

}

void DayView::showTableView()
{
	qDebug() << ui.dateEdit->text();
	static_cast<TableView*>(ui.tableView)->updateTableView(QString::fromUtf8("time = '%1'").arg(ui.dateEdit->text()));
}

void DayView::on_viewBtn_clicked()
{
	QString fileName = QFileDialog::getSaveFileName(this, QString::fromLocal8Bit("Save excel"),
													".", QString::fromLocal8Bit("Microsoft Office 2003 (*.xls)"));//获取保存路径
	if (fileName.isEmpty()) {
		QMessageBox::critical(0, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("要保存的文件名为空！"));
		return;
	}
	//建立Excel对象
	QAxObject *excel = new QAxObject("Excel.Application");

	excel->dynamicCall("SetVisible(bool)", true); //如果为了看自己的程序到底怎样工作，可以设置为true
	excel->setProperty("Visible", false);
	QAxObject *workbooks = excel->querySubObject("WorkBooks");
	workbooks->dynamicCall("Add");
	QAxObject *workbook = excel->querySubObject("ActiveWorkBook");
	QAxObject *worksheet = workbook->querySubObject("Worksheets(int)", 1);
	for (auto i = 0; i < ui.tableView->model()->columnCount(); ++i) {
		QAxObject *range = worksheet->querySubObject("Cells(int,int)", 1, i+1);//row  column为要插入的行和列
		range->setProperty("Value", ui.tableView->model()->headerData(i, Qt::Horizontal)); //此处写要插入的内容
	}
	for (auto i = 1; i < ui.tableView->model()->rowCount() + 1; ++i) {
		for (auto j = 0; j < ui.tableView->model()->columnCount(); ++j) {
			QAxObject *range = worksheet->querySubObject("Cells(int,int)", i+1, j+1);//row  column为要插入的行和列
			range->setProperty("Value", ui.tableView->model()->data(ui.tableView->model()->index(i - 1, j))); //此处写要插入的内容
		}
	}
	QAxObject *range = worksheet->querySubObject("Cells(int,int)", ui.tableView->model()->rowCount()+1, 1);//row  column为要插入的行和列
	range->setProperty("Value", QString::fromLocal8Bit("总计:")); //此处写要插入的内容

	workbook->dynamicCall("SaveAs(const QString&)", QDir::toNativeSeparators(
		fileName));
	QMessageBox::information(this, QString::fromLocal8Bit("OK"), QString::fromLocal8Bit("保存成功！"));
	workbook->dynamicCall("Close()");
	worksheet->clear();//释放所有工作表
	excel->dynamicCall("Quit()");
	delete excel;//释放excel
}

void DayView::on_deleteBtn_clicked()
{
	int row = ui.tableView->currentIndex().row();
	QAbstractItemModel* model = ui.tableView->model();

	DatabaseManager::Instance().deleteFromDatabase(
		model->data(model->index(row, 0)).toString(),
		model->data(model->index(row, 1)).toString(),
		model->data(model->index(row, 2)).toString(),
		model->data(model->index(row, 3)).toString(),
		model->data(model->index(row, 4)).toString(),
		model->data(model->index(row, 5)).toBool(),
		model->data(model->index(row, 6)).toString(),
		model->data(model->index(row, 7)).toString(),
		model->data(model->index(row, 8)).toString(),
		model->data(model->index(row, 9)).toString()
		);
	showTableView();
}
