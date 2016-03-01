#ifndef TABLEVIEW_H
#define TABLEVIEW_H

#include <QTableView>
#include <QtSql/QSqlTableModel>
#include "tableviewmodel.h"

class TableView : public QTableView
{
	Q_OBJECT

public:
	TableView(QWidget *parent);
	~TableView();
	QSqlTableModel* tableModel;
	public slots:
void updateView(int column);

void updateTableView(QString& dateStr);
void insertTotalRow();
private:
};

#endif // TABLEVIEW_H
