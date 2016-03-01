#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QtWidgets/QWidget>
#include "GeneratedFiles/ui_account.h"

class BillWidget;
class DayView;
class MonthView;

class Account : public QWidget {
	Q_OBJECT

public:
	Account(QWidget *parent = 0);
	void createButtons();
	void createStackedWidget();
	~Account();

	private slots:
	void on_pBtn1_clicked();
	void on_pBtn2_clicked();
	void on_pBtn3_clicked();
	void on_pBtn4_clicked();
	void on_pBtn5_clicked();
	void on_closeLabel_clicked();
protected:
	virtual void paintEvent(QPaintEvent *);
	void mousePressEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
protected:
	bool eventFilter(QObject *obj, QEvent *ev);
private:
	QPoint m_movePoint; //移动的距离
	bool m_mousePress; //按下鼠标左键
	QLabel* labelMini;
	QLabel* labelClose;

	BillWidget *billWidget;
	DayView *dayView;
	MonthView *monthView;
private:
	Ui::AccountClass ui;

	QToolButton* pBtn1;
	QToolButton* pBtn2;
	QToolButton* pBtn3;
	QToolButton* pBtn4;
	QToolButton* pBtn5;

// 	QPushButton* pBtn1;
// 	QPushButton* pBtn2;
// 	QPushButton* pBtn3;
// 	QPushButton* pBtn4;
// 	QPushButton* pBtn5;

	QLabel *label1;
	QLabel *label2;
	QLabel *label3;
	QLabel *label4;
	QLabel *label5;
	QStackedWidget* sWgt;
};

#endif // ACCOUNT_H
