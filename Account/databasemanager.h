#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QObject>
#include <QtSql/qsqldatabase.h>
#include <QApplication>
#include <QtSql/QtSql>

class DatabaseManager : public QObject
{
	Q_OBJECT

	static QString qAppDir;
public:
	static DatabaseManager& Instance()
	{
		static DatabaseManager theDatabaseManager;
		theDatabaseManager.qAppDir = qApp->applicationDirPath();

		return theDatabaseManager;
	}
	QStringList nameList;
	/* more (non-static) functions here */
	bool insertIntoDatabase(QString& time, QString& ranking, QString& name, QString& costPrice, QString& totalTurnover, bool relics, QString& billCount, QString& totalProfit, QString& personalProfit, QString& fundsTransfer);
	bool deleteFromDatabase(QString& time, QString& ranking, QString& name, QString& costPrice, QString& totalTurnover, bool relics, QString& billCount, QString& totalProfit, QString& personalProfit, QString& fundsTransfer);

	QStringList getNameList();

	QSqlDatabase db;
private:
	DatabaseManager();                            // ctor hidden

	DatabaseManager(DatabaseManager const&);            // copy ctor hidden
	DatabaseManager& operator=(DatabaseManager const&);
	DatabaseManager(QObject* parent);
	// assign op. hidden
	~DatabaseManager();                           // dtor hidden
};

#endif // DATABASEMANAGER_H
