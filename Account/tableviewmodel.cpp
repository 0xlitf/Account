#include "stdafx.h"
#include "tableviewmodel.h"

TableViewModel::TableViewModel(QObject * parent, QSqlDatabase db)
{
	//QSqlTableModel(parent, db);
}

// QVariant TableViewModel::data(const QModelIndex & i, int role) const
// {
// 	QVariant d = QSqlQueryModel::data(i, role);
// 	if (i.column() == 4 && 
// 		//i.column() <= 9 &&
// 		role == Qt::DisplayRole
// 		) {
// 		return QVariant(QString::number(d.toDouble(), 'f', 2));
// 	}
// 
// 	return d;
// }


// QVariant TableViewModel::data(const QModelIndex &index, int role) const{
// 
// 	QVariant value;
// 	if (role < Qt::UserRole) {
// 		value = QSqlQueryModel::data(index, role);
// 	}
// 	else {
// 		int columnIdx = role - Qt::UserRole - 1;
// 		QModelIndex modelIndex = this->index(index.row(), columnIdx);
// 		value = QSqlQueryModel::data(modelIndex, Qt::DisplayRole);
// 	}
// 	return value;
// }
