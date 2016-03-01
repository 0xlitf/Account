/********************************************************************************
** Form generated from reading UI file 'dayview.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DAYVIEW_H
#define UI_DAYVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
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

class Ui_DayView
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QDateEdit *dateEdit;
    QPushButton *viewBtn;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    TableView *tableView;
    QHBoxLayout *horizontalLayout_3;
    QToolButton *deleteBtn;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *DayView)
    {
        if (DayView->objectName().isEmpty())
            DayView->setObjectName(QStringLiteral("DayView"));
        DayView->resize(855, 698);
        gridLayout = new QGridLayout(DayView);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        groupBox = new QGroupBox(DayView);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        dateEdit = new QDateEdit(groupBox);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setMinimumSize(QSize(220, 0));
        dateEdit->setMaximumSize(QSize(270, 16777215));

        horizontalLayout_2->addWidget(dateEdit);

        viewBtn = new QPushButton(groupBox);
        viewBtn->setObjectName(QStringLiteral("viewBtn"));
        viewBtn->setEnabled(true);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Account/Resources/Entypo_e740(0)_32.png"), QSize(), QIcon::Normal, QIcon::Off);
        viewBtn->setIcon(icon);

        horizontalLayout_2->addWidget(viewBtn);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        tableView = new TableView(groupBox);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView->setSelectionMode(QAbstractItemView::SingleSelection);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

        horizontalLayout->addWidget(tableView);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        deleteBtn = new QToolButton(groupBox);
        deleteBtn->setObjectName(QStringLiteral("deleteBtn"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Account/Resources/Entypo_e729(0)_64.png"), QSize(), QIcon::Normal, QIcon::Off);
        deleteBtn->setIcon(icon1);
        deleteBtn->setIconSize(QSize(32, 32));
        deleteBtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_3->addWidget(deleteBtn);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_3);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);


        retranslateUi(DayView);

        QMetaObject::connectSlotsByName(DayView);
    } // setupUi

    void retranslateUi(QWidget *DayView)
    {
        DayView->setWindowTitle(QApplication::translate("DayView", "DayView", 0));
        groupBox->setTitle(QApplication::translate("DayView", "\346\227\245\350\247\206\345\233\276", 0));
        dateEdit->setDisplayFormat(QApplication::translate("DayView", "yyyy-MM-dd", 0));
        viewBtn->setText(QApplication::translate("DayView", "\345\257\274\345\207\272\345\210\260Excel", 0));
        deleteBtn->setText(QApplication::translate("DayView", "\345\210\240\351\231\244\346\255\244\350\241\214", 0));
        deleteBtn->setShortcut(QApplication::translate("DayView", "Backspace", 0));
    } // retranslateUi

};

namespace Ui {
    class DayView: public Ui_DayView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DAYVIEW_H
