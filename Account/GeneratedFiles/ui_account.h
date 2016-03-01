/********************************************************************************
** Form generated from reading UI file 'account.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCOUNT_H
#define UI_ACCOUNT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AccountClass
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;

    void setupUi(QWidget *AccountClass)
    {
        if (AccountClass->objectName().isEmpty())
            AccountClass->setObjectName(QStringLiteral("AccountClass"));
        AccountClass->resize(600, 400);
        verticalLayout_2 = new QVBoxLayout(AccountClass);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout->setContentsMargins(0, 0, 0, 0);

        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(AccountClass);

        QMetaObject::connectSlotsByName(AccountClass);
    } // setupUi

    void retranslateUi(QWidget *AccountClass)
    {
        AccountClass->setWindowTitle(QApplication::translate("AccountClass", "Account", 0));
    } // retranslateUi

};

namespace Ui {
    class AccountClass: public Ui_AccountClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCOUNT_H
