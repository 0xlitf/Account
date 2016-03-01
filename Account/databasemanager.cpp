#include "stdafx.h"
#include "databasemanager.h"
#include <QtSql>
#include <QMessageBox>

QString DatabaseManager::qAppDir;

DatabaseManager::DatabaseManager(QObject *parent)
: QObject(parent)
{

}

DatabaseManager::DatabaseManager(DatabaseManager const&)
{

}

DatabaseManager::~DatabaseManager()
{
	db.close();
	QString fileName = QString("%1/account.sqlite").arg(qAppDir);
	QString destinationFileName = QString::fromLocal8Bit("%1/DatabaseBackup/数据库备份于%2年%3月%4日%5时%6分%7秒.sqlite")
		.arg(qAppDir)
		.arg(QDate::currentDate().year())
		.arg(QDate::currentDate().month())
		.arg(QDate::currentDate().day())
		.arg(QTime::currentTime().hour())
		.arg(QTime::currentTime().minute())
		.arg(QTime::currentTime().second());
	QDir().mkdir(qAppDir + "/DatabaseBackup");

	qDebug() << "fileName:" << fileName;
	qDebug() << "destinationFileName:" << destinationFileName;
	qDebug() << "qAppDir + \" / DatabaseBackup\":" << qAppDir + "/DatabaseBackup";

	qDebug() << QString(QFile::copy(fileName, destinationFileName) ? QString::fromLocal8Bit("数据库备份成功") : QString::fromLocal8Bit("数据库备份失败"));

//	system("pause");
}

DatabaseManager::DatabaseManager()
{
	db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName(qApp->applicationDirPath() + "/account.sqlite");
	qDebug() << QSqlDatabase::drivers();
	qDebug() << "1";
	if (!db.open())
	{
		QMessageBox::information(NULL, "Error", "数据库未能打开");
		qDebug() << "2";
	}
	QSqlQuery query(db);
	qDebug() << "3";
	bool ok = query.exec("create table if not exists account ("
						 "time DATETIME, "
						 "ranking INTEGER,"
						 "name VARCHAR(30) not null,"
						 "costPrice DOUBLE,"
						 "totalTurnover DOUBLE,"
						 "relics integer,"
						 "billCount DOUBLE,"
						 "totalProfit DOUBLE,"
						 "personalProfit DOUBLE,"
						 "fundsTransfer DOUBLE);"
						 );
	if (!ok)
	{
		qDebug() << "create table failed";
	}
}

bool DatabaseManager::insertIntoDatabase(QString& time, QString& ranking, QString& name, QString& costPrice, QString& totalTurnover, bool relics, QString& billCount, QString& totalProfit, QString& personalProfit, QString& fundsTransfer)
{
	qDebug() << QString::fromLocal8Bit("insertIntoDatabase");
	QSqlQuery sql_query;
	QString selectAll = QString("select * from account;");

	sql_query.prepare(selectAll);
	if (!sql_query.exec())
	{
		qDebug() << sql_query.lastError();
	}
	else
	{
		while (sql_query.next())
		{
			if (sql_query.value(0) == time&&
				sql_query.value(1) == ranking.toInt() &&
				sql_query.value(2) == name&&
				sql_query.value(3) == costPrice.toDouble() &&
				sql_query.value(4) == totalTurnover.toDouble() &&
				sql_query.value(5) == relics &&
				sql_query.value(6) == billCount.toDouble() &&
				sql_query.value(7) == totalProfit.toDouble() &&
				sql_query.value(8) == personalProfit.toDouble() &&
				sql_query.value(9) == fundsTransfer.toDouble()
				)
			{
				qDebug() << QString::fromLocal8Bit("已有重复数据:'%1',%2,'%3',%4,%5,%6,%7,%8,%9,%10")
					.arg(time)
					.arg(ranking.toInt())
					.arg(name)
					.arg(costPrice)
					.arg(totalTurnover)
					.arg(relics)
					.arg(billCount)
					.arg(totalProfit)
					.arg(personalProfit)
					.arg(fundsTransfer);
				return 0;
			}

		}
	}



	QString str = QString("insert into account (time,ranking,name,costPrice,totalTurnover,relics,billCount,totalProfit,personalProfit,fundsTransfer) values ('%1',%2,'%3',%4,%5,%6,%7,%8,%9,%10);")
		.arg(time)
		.arg(ranking.toInt())
		.arg(name)
		.arg(PRECISION(costPrice.toDouble()))
		.arg(PRECISION(totalTurnover.toDouble()))
		.arg(relics)
		.arg(PRECISION(billCount.toDouble()))
		.arg(PRECISION(totalProfit.toDouble()))
		.arg(PRECISION(personalProfit.toDouble()))
		.arg(PRECISION(fundsTransfer.toDouble()));

	qDebug() << QString::fromLocal8Bit("插入数据库:'%1',%2,'%3',%4,%5,%6,%7,%8,%9,%10")
		.arg(time)
		.arg(ranking.toInt())
		.arg(name)
		.arg(costPrice)
		.arg(totalTurnover)
		.arg(relics)
		.arg(billCount)
		.arg(totalProfit)
		.arg(personalProfit)
		.arg(fundsTransfer);
	QSqlQuery query(db);
	if (!query.exec(str))
	{
		return false;
	}
	qDebug() << db.lastError();
	return true;
}

bool DatabaseManager::deleteFromDatabase(QString& time, QString& ranking, QString& name, QString& costPrice, QString& totalTurnover, bool relics, QString& billCount, QString& totalProfit, QString& personalProfit, QString& fundsTransfer)
{
	QString str = QString("delete from account where time = '%1'"
						  " and ranking = %2"
						  " and name = '%3'"
						  " and costPrice = %4"
						  " and totalTurnover = %5"
						  " and relics = %6"
						  " and billCount = %7"
						  " and totalProfit = %8"
						  " and personalProfit = %9"
						  " and fundsTransfer = %10"
						  ";"
						  )
						  .arg(time)
						  .arg(ranking.toInt())
						  .arg(name)
						  .arg(costPrice)
						  .arg(totalTurnover)
						  .arg(relics)
						  .arg(billCount)
						  .arg(totalProfit)
						  .arg(personalProfit)
						  .arg(fundsTransfer);

	QMessageBox *_msgBox = new QMessageBox;
	QPushButton *yes = _msgBox->addButton(QString::fromLocal8Bit("确定"), QMessageBox::YesRole);
	QPushButton *no = _msgBox->addButton(QString::fromLocal8Bit("取消"), QMessageBox::NoRole);

	_msgBox->setText(QString::fromLocal8Bit("确认删除？"));
	_msgBox->exec();

	if (_msgBox->clickedButton() == yes)
	{
		QSqlQuery query(db);
		if (!query.exec(str))
		{
			return false;
		}
		qDebug() << QString::fromLocal8Bit("从数据库删除:'%1',%2,'%3',%4,%5,%6,%7,%8,%9,%10")
			.arg(time)
			.arg(ranking.toInt())
			.arg(name)
			.arg(costPrice)
			.arg(totalTurnover)
			.arg(relics)
			.arg(billCount)
			.arg(totalProfit)
			.arg(personalProfit)
			.arg(fundsTransfer);
	}
	if (_msgBox->clickedButton() == no)
	{
	}


}

QStringList DatabaseManager::getNameList()
{
	QSqlQuery query;
	QString qryStr = QString::fromLocal8Bit("select name from account");

	if (query.exec(qryStr))
	{
		while (query.next())
		{
			//qDebug() << query.value(0);
			if (!nameList.contains(query.value(0).toString())
				&& !query.value(0).toString().isEmpty())
			{
				nameList.append(query.value(0).toString());
			}
		}
	}

	return this->nameList;
}

