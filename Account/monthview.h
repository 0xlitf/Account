#ifndef MONTHVIEW_H
#define MONTHVIEW_H

#include <QWidget>
#include "ui_monthview.h"

class MonthView : public QWidget {
	Q_OBJECT

public:
	MonthView(QWidget *parent = 0);
	~MonthView();
	public slots:
	void showTableView();
	void updateTableView(const QDate& date);
	void slot_ComboBoxChanged();
	void slot_comboBoxTextChanged(const QString&);
	void updateComboBox();
	private slots :
	void on_deleteBtn_clicked();
	void on_viewBtn_clicked();
private:
	Ui::MonthView ui;
};

#endif // MONTHVIEW_H
