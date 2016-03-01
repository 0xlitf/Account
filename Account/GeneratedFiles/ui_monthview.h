/********************************************************************************
** Form generated from reading UI file 'monthview.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MONTHVIEW_H
#define UI_MONTHVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "tableview.h"

QT_BEGIN_NAMESPACE

class Ui_MonthView
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QDateEdit *dateEdit;
    QComboBox *comboBox;
    QPushButton *viewBtn;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout_2;
    TableView *tableView;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *deleteBtn;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *MonthView)
    {
        if (MonthView->objectName().isEmpty())
            MonthView->setObjectName(QStringLiteral("MonthView"));
        MonthView->resize(876, 697);
        gridLayout = new QGridLayout(MonthView);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        groupBox = new QGroupBox(MonthView);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        dateEdit = new QDateEdit(groupBox);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setMinimumSize(QSize(200, 0));
        dateEdit->setMaximumSize(QSize(250, 16777215));

        horizontalLayout_3->addWidget(dateEdit);

        comboBox = new QComboBox(groupBox);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setMinimumSize(QSize(200, 0));
        comboBox->setMaximumSize(QSize(300, 16777215));
        comboBox->setEditable(true);

        horizontalLayout_3->addWidget(comboBox);

        viewBtn = new QPushButton(groupBox);
        viewBtn->setObjectName(QStringLiteral("viewBtn"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Account/Resources/Entypo_e740(0)_32.png"), QSize(), QIcon::Normal, QIcon::Off);
        viewBtn->setIcon(icon);
        viewBtn->setCheckable(true);
        viewBtn->setAutoRepeat(true);
        viewBtn->setAutoExclusive(true);
        viewBtn->setAutoDefault(false);
        viewBtn->setFlat(false);

        horizontalLayout_3->addWidget(viewBtn);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        tableView = new TableView(groupBox);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView->setSelectionMode(QAbstractItemView::SingleSelection);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout_2->addWidget(tableView);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        deleteBtn = new QToolButton(groupBox);
        deleteBtn->setObjectName(QStringLiteral("deleteBtn"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Account/Resources/Entypo_e729(0)_64.png"), QSize(), QIcon::Normal, QIcon::Off);
        deleteBtn->setIcon(icon1);
        deleteBtn->setIconSize(QSize(32, 32));
        deleteBtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_2->addWidget(deleteBtn);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_2);


        verticalLayout->addLayout(verticalLayout_2);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);


        retranslateUi(MonthView);

        viewBtn->setDefault(false);


        QMetaObject::connectSlotsByName(MonthView);
    } // setupUi

    void retranslateUi(QWidget *MonthView)
    {
        MonthView->setWindowTitle(QApplication::translate("MonthView", "MonthView", 0));
        groupBox->setTitle(QApplication::translate("MonthView", "\346\234\210\350\247\206\345\233\276", 0));
        dateEdit->setDisplayFormat(QApplication::translate("MonthView", "yyyy-MM", 0));
        viewBtn->setText(QApplication::translate("MonthView", "\345\257\274\345\207\272\345\210\260Excel", 0));
        deleteBtn->setText(QApplication::translate("MonthView", "\345\210\240\351\231\244\346\255\244\350\241\214", 0));
        deleteBtn->setShortcut(QApplication::translate("MonthView", "Backspace", 0));
    } // retranslateUi

};

namespace Ui {
    class MonthView: public Ui_MonthView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MONTHVIEW_H
