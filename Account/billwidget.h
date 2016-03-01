#ifndef BILLWIDGET_H
#define BILLWIDGET_H

#include <QWidget>
#include "ui_billwidget.h"
#include <QtSql/qsqltablemodel.h>

class QSqlTableModel;

class BillWidget : public QWidget {
	Q_OBJECT

public:
	BillWidget(QWidget *parent = 0);
	~BillWidget();
	public slots:
	void showTableView();
	private slots :
	void on_calculateBtn_clicked();
	void on_importBtn_clicked();
	void on_deleteBtn_clicked();
	void updateTableView(const QDate & date);
signals:
	void signal_addData();
private:
	Ui::BillWidget ui;
};

#endif // BILLWIDGET_H
