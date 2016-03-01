/********************************************************************************
** Form generated from reading UI file 'billwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BILLWIDGET_H
#define UI_BILLWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "tableview.h"

QT_BEGIN_NAMESPACE

class Ui_BillWidget
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QCheckBox *relics;
    QLabel *label_3;
    QLineEdit *ranking;
    QLineEdit *costPrice;
    QLabel *label_8;
    QLabel *label_6;
    QLabel *label;
    QDateEdit *dateEdit;
    QLabel *label_10;
    QLineEdit *totalProfit;
    QLineEdit *personalProfit;
    QLabel *label_9;
    QLineEdit *totalTurnover;
    QLabel *label_2;
    QLineEdit *name;
    QLineEdit *billCount;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *importBtn;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *fundsTransfer;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *calculateBtn;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_5;
    QLabel *label_11;
    QSpacerItem *horizontalSpacer_4;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_5;
    TableView *tableView;
    QHBoxLayout *horizontalLayout;
    QToolButton *deleteBtn;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *BillWidget)
    {
        if (BillWidget->objectName().isEmpty())
            BillWidget->setObjectName(QStringLiteral("BillWidget"));
        BillWidget->resize(1260, 717);
        verticalLayout_2 = new QVBoxLayout(BillWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMinAndMaxSize);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        groupBox = new QGroupBox(BillWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        relics = new QCheckBox(groupBox);
        relics->setObjectName(QStringLiteral("relics"));
        relics->setChecked(true);

        gridLayout_3->addWidget(relics, 0, 3, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_3->addWidget(label_3, 1, 2, 1, 1);

        ranking = new QLineEdit(groupBox);
        ranking->setObjectName(QStringLiteral("ranking"));

        gridLayout_3->addWidget(ranking, 1, 1, 1, 1);

        costPrice = new QLineEdit(groupBox);
        costPrice->setObjectName(QStringLiteral("costPrice"));

        gridLayout_3->addWidget(costPrice, 1, 3, 1, 1);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_3->addWidget(label_8, 1, 5, 1, 1);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setStyleSheet(QStringLiteral(""));

        gridLayout_3->addWidget(label_6, 0, 5, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_3->addWidget(label, 1, 0, 1, 1);

        dateEdit = new QDateEdit(groupBox);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setDateTime(QDateTime(QDate(2016, 2, 14), QTime(0, 0, 0)));

        gridLayout_3->addWidget(dateEdit, 0, 1, 1, 1);

        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout_3->addWidget(label_10, 0, 0, 1, 1);

        totalProfit = new QLineEdit(groupBox);
        totalProfit->setObjectName(QStringLiteral("totalProfit"));
        totalProfit->setReadOnly(false);

        gridLayout_3->addWidget(totalProfit, 0, 6, 1, 1);

        personalProfit = new QLineEdit(groupBox);
        personalProfit->setObjectName(QStringLiteral("personalProfit"));
        personalProfit->setReadOnly(false);

        gridLayout_3->addWidget(personalProfit, 1, 6, 1, 1);

        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_3->addWidget(label_9, 0, 2, 1, 1);

        totalTurnover = new QLineEdit(groupBox);
        totalTurnover->setObjectName(QStringLiteral("totalTurnover"));

        gridLayout_3->addWidget(totalTurnover, 2, 3, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_3->addWidget(label_2, 3, 0, 1, 1);

        name = new QLineEdit(groupBox);
        name->setObjectName(QStringLiteral("name"));

        gridLayout_3->addWidget(name, 3, 1, 1, 1);

        billCount = new QLineEdit(groupBox);
        billCount->setObjectName(QStringLiteral("billCount"));

        gridLayout_3->addWidget(billCount, 2, 1, 1, 1);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_3->addWidget(label_7, 2, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        importBtn = new QPushButton(groupBox);
        importBtn->setObjectName(QStringLiteral("importBtn"));

        horizontalLayout_2->addWidget(importBtn);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        gridLayout_3->addLayout(horizontalLayout_2, 3, 6, 1, 1);

        fundsTransfer = new QLineEdit(groupBox);
        fundsTransfer->setObjectName(QStringLiteral("fundsTransfer"));
        fundsTransfer->setReadOnly(false);

        gridLayout_3->addWidget(fundsTransfer, 2, 6, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_3->addWidget(label_4, 2, 2, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        calculateBtn = new QPushButton(groupBox);
        calculateBtn->setObjectName(QStringLiteral("calculateBtn"));

        horizontalLayout_3->addWidget(calculateBtn);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        gridLayout_3->addLayout(horizontalLayout_3, 3, 3, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_3->addWidget(label_5, 2, 5, 1, 1);

        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout_3->addWidget(label_11, 3, 2, 1, 1);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);


        horizontalLayout_4->addLayout(gridLayout);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_4);

        groupBox_2 = new QGroupBox(BillWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout_3 = new QVBoxLayout(groupBox_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        tableView = new TableView(groupBox_2);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setMinimumSize(QSize(1050, 300));
        tableView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView->setSelectionMode(QAbstractItemView::SingleSelection);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

        horizontalLayout_5->addWidget(tableView);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        deleteBtn = new QToolButton(groupBox_2);
        deleteBtn->setObjectName(QStringLiteral("deleteBtn"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Account/Resources/Entypo_e729(0)_64.png"), QSize(), QIcon::Normal, QIcon::Off);
        deleteBtn->setIcon(icon);
        deleteBtn->setIconSize(QSize(32, 32));
        deleteBtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout->addWidget(deleteBtn);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_3->addLayout(horizontalLayout);


        verticalLayout->addWidget(groupBox_2);


        verticalLayout_2->addLayout(verticalLayout);

        QWidget::setTabOrder(dateEdit, ranking);
        QWidget::setTabOrder(ranking, billCount);
        QWidget::setTabOrder(billCount, name);
        QWidget::setTabOrder(name, relics);
        QWidget::setTabOrder(relics, costPrice);
        QWidget::setTabOrder(costPrice, totalTurnover);
        QWidget::setTabOrder(totalTurnover, calculateBtn);
        QWidget::setTabOrder(calculateBtn, totalProfit);
        QWidget::setTabOrder(totalProfit, personalProfit);
        QWidget::setTabOrder(personalProfit, fundsTransfer);
        QWidget::setTabOrder(fundsTransfer, importBtn);
        QWidget::setTabOrder(importBtn, deleteBtn);

        retranslateUi(BillWidget);

        QMetaObject::connectSlotsByName(BillWidget);
    } // setupUi

    void retranslateUi(QWidget *BillWidget)
    {
        BillWidget->setWindowTitle(QApplication::translate("BillWidget", "BillWidget", 0));
        groupBox->setTitle(QApplication::translate("BillWidget", "\345\275\225\345\205\245", 0));
        relics->setText(QString());
        label_3->setText(QApplication::translate("BillWidget", "\346\210\220\346\234\254\357\274\232", 0));
        ranking->setText(QString());
        costPrice->setText(QString());
        label_8->setText(QApplication::translate("BillWidget", "\344\270\252\344\272\272\345\210\251\346\266\246\357\274\232", 0));
        label_6->setText(QApplication::translate("BillWidget", "\346\200\273\345\210\251\346\266\246\357\274\232", 0));
        label->setText(QApplication::translate("BillWidget", "\346\216\222\345\220\215\357\274\232", 0));
        dateEdit->setDisplayFormat(QApplication::translate("BillWidget", "yyyy-MM-dd", 0));
        label_10->setText(QApplication::translate("BillWidget", "\346\227\245\346\234\237\357\274\232", 0));
        label_9->setText(QApplication::translate("BillWidget", "\346\230\257\345\220\246\347\234\237\350\277\271\357\274\232", 0));
        totalTurnover->setText(QString());
        label_2->setText(QApplication::translate("BillWidget", "\347\274\226\345\217\267\357\274\232", 0));
        name->setText(QString());
        billCount->setText(QString());
        label_7->setText(QApplication::translate("BillWidget", "\345\215\225\346\225\260\357\274\232", 0));
        importBtn->setText(QApplication::translate("BillWidget", "\345\257\274\345\205\245\346\225\260\346\215\256\345\272\223", 0));
        label_4->setText(QApplication::translate("BillWidget", "\346\200\273\346\210\220\344\272\244\351\242\235\357\274\232", 0));
        calculateBtn->setText(QApplication::translate("BillWidget", "\350\256\241\347\256\227", 0));
        label_5->setText(QApplication::translate("BillWidget", "\350\275\254\350\264\246\350\265\204\351\207\221\357\274\232", 0));
        label_11->setText(QApplication::translate("BillWidget", "TextLabel", 0));
        groupBox_2->setTitle(QApplication::translate("BillWidget", "\346\225\260\346\215\256", 0));
        deleteBtn->setText(QApplication::translate("BillWidget", "\345\210\240\351\231\244\346\255\244\350\241\214", 0));
    } // retranslateUi

};

namespace Ui {
    class BillWidget: public Ui_BillWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BILLWIDGET_H
