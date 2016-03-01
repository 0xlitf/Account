#ifndef TABLEVIEWMODEL_H
#define TABLEVIEWMODEL_H

#include <QSqlRelationalTableModel>

class TableViewModel : public QSqlRelationalTableModel {
	Q_OBJECT

public:
	TableViewModel(QObject * parent = 0, QSqlDatabase db = QSqlDatabase());
//	virtual QVariant data(const QModelIndex & i, int role = Qt::DisplayRole) const;
protected:

private:

};

#endif // TABLEVIEWMODEL_H
