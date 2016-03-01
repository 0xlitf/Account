#include "stdafx.h"
#include "monthview.h"
#include <QSqlTableModel>
#include "databasemanager.h"
#include "tableview.h"
#include <ActiveQt/QAxObject>

MonthView::MonthView(QWidget *parent)
: QWidget(parent)
{
	ui.setupUi(this);
	ui.dateEdit->setDate(QDate::currentDate());
	ui.tableView->setSortingEnabled(true);
	connect(ui.dateEdit, SIGNAL(dateChanged(const QDate &)), this, SLOT(updateTableView(const QDate &)));
	connect(ui.comboBox, SIGNAL(currentTextChanged(const QString &)), this, SLOT(slot_comboBoxTextChanged(const QString &)));
	

	updateComboBox();

}

MonthView::~MonthView()
{

}

void MonthView::updateTableView(const QDate & date)
{
	showTableView();

}

void MonthView::slot_ComboBoxChanged()
{

	updateComboBox();
}

void MonthView::updateComboBox()
{
	ui.comboBox->clear();
	ui.comboBox->addItem(QString::fromLocal8Bit("ȫ��"));
	ui.comboBox->addItems(DatabaseManager::Instance().getNameList());
}


void MonthView::slot_comboBoxTextChanged(const QString &)
{

	showTableView();

}

void MonthView::on_viewBtn_clicked()
{
	QString fileName = QFileDialog::getSaveFileName(this, QString::fromLocal8Bit("Save excel"),
													".", QString::fromLocal8Bit("Microsoft Office 2003 (*.xls)"));//��ȡ����·��
	if (fileName.isEmpty()) {
		QMessageBox::critical(0, QString::fromLocal8Bit("����"), QString::fromLocal8Bit("Ҫ������ļ���Ϊ�գ�"));
		return;
	}
	//����Excel����
	QAxObject *excel = new QAxObject("Excel.Application");

	excel->dynamicCall("SetVisible(bool)", true); //���Ϊ�˿��Լ��ĳ��򵽵�������������������Ϊtrue
	excel->setProperty("Visible", false);
	QAxObject *workbooks = excel->querySubObject("WorkBooks");
	workbooks->dynamicCall("Add");
	QAxObject *workbook = excel->querySubObject("ActiveWorkBook");
	QAxObject *worksheet = workbook->querySubObject("Worksheets(int)", 1);
	for (auto i = 0; i < ui.tableView->model()->columnCount(); ++i) {
		QAxObject *range = worksheet->querySubObject("Cells(int,int)", 1, i + 1);//row  columnΪҪ������к���
		range->setProperty("Value", ui.tableView->model()->headerData(i, Qt::Horizontal)); //�˴�дҪ���������
	}
	for (auto i = 1; i < ui.tableView->model()->rowCount() + 1; ++i) {
		for (auto j = 0; j < ui.tableView->model()->columnCount(); ++j) {
			QAxObject *range = worksheet->querySubObject("Cells(int,int)", i + 1, j + 1);//row  columnΪҪ������к���
			range->setProperty("Value", ui.tableView->model()->data(ui.tableView->model()->index(i - 1, j))); //�˴�дҪ���������
		}
	}
	QAxObject *range = worksheet->querySubObject("Cells(int,int)", ui.tableView->model()->rowCount() + 1, 1);//row  columnΪҪ������к���
	range->setProperty("Value", QString::fromLocal8Bit("�ܼ�:")); //�˴�дҪ���������

	workbook->dynamicCall("SaveAs(const QString&)", QDir::toNativeSeparators(
		fileName));
	QMessageBox::information(this, QString::fromLocal8Bit("OK"), QString::fromLocal8Bit("����ɹ���"));
	workbook->dynamicCall("Close()");
	worksheet->clear();//�ͷ����й�����
	excel->dynamicCall("Quit()");
	delete excel;//�ͷ�excel
}

void MonthView::showTableView()
{
	ui.comboBox->currentText() == QString::fromLocal8Bit("ȫ��") ?
		static_cast<TableView*>(ui.tableView)->updateTableView(QString("time > '%1' and time < '%2'").arg(ui.dateEdit->text() + "-00").arg(ui.dateEdit->text() + "-32")) :
		static_cast<TableView*>(ui.tableView)->updateTableView(QString("time > '%1' and time < '%2' and name = '%3'").arg(ui.dateEdit->text() + "-00").arg(ui.dateEdit->text() + "-32").arg(ui.comboBox->currentText()));

}

void MonthView::on_deleteBtn_clicked()
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
