#ifndef DAYVIEW_H
#define DAYVIEW_H

#include <QWidget>
#include "ui_dayview.h"

class DayView : public QWidget {
	Q_OBJECT

public:
	DayView(QWidget *parent = 0);
	~DayView();
public slots:
	void showTableView();
	void updateTableView(const QDate& date);
	private slots :
	void on_deleteBtn_clicked();
	void on_viewBtn_clicked();
private:
	Ui::DayView ui;
};

#endif // DAYVIEW_H
