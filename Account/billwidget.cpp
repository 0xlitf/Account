#include "stdafx.h"
#include "billwidget.h"
#include <databasemanager.h>
#include "tableview.h"

BillWidget::BillWidget(QWidget *parent)
: QWidget(parent)
{
	ui.setupUi(this);
	ui.dateEdit->setDate(QDate::currentDate());
	ui.dateEdit->setFocus();
	ui.tableView->setSortingEnabled(true);

	connect(ui.dateEdit, SIGNAL(dateChanged(const QDate &)), this, SLOT(updateTableView(const QDate &)));

	showTableView();
}
void BillWidget::updateTableView(const QDate & date)
{
	showTableView();

}

BillWidget::~BillWidget()
{

}

void BillWidget::on_calculateBtn_clicked()
{
	qDebug() << ui.label->colorCount();

	double profit = ui.totalTurnover->text().toDouble() - ui.costPrice->text().toDouble();
	ui.totalProfit->setText(QString::number(profit, 'f', 2));
	double rate = ui.relics->isChecked() ? 0.4 : 0.6;
	ui.personalProfit->setText(QString::number(profit*rate, 'f', 2));
	
	double transfer = ui.totalTurnover->text().toDouble() - profit*rate;
	ui.fundsTransfer->setText(QString::number(transfer,'f',2));
}

void BillWidget::on_importBtn_clicked()
{
	on_calculateBtn_clicked();
	DatabaseManager::Instance().insertIntoDatabase(ui.dateEdit->text(),
												   ui.ranking->text(),
												   ui.name->text(),
												   ui.costPrice->text(),
												   ui.totalTurnover->text(),
												   ui.relics->isChecked(),
												   ui.billCount->text(),
												   ui.totalProfit->text(),
												   ui.personalProfit->text(),
												   ui.fundsTransfer->text());
	emit signal_addData();
	showTableView();
}

void BillWidget::on_deleteBtn_clicked()
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

void BillWidget::showTableView()
{
	static_cast<TableView*>(ui.tableView)->updateTableView(QString::fromUtf8("time = '%1'").arg(ui.dateEdit->text()));
}


