/********************************************************************************
** Form generated from reading UI file 'searchplacebytypedialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHPLACEBYTYPEDIALOG_H
#define UI_SEARCHPLACEBYTYPEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_searchPlaceByTypeDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLineEdit *typeEdit;

    void setupUi(QDialog *searchPlaceByTypeDialog)
    {
        if (searchPlaceByTypeDialog->objectName().isEmpty())
            searchPlaceByTypeDialog->setObjectName("searchPlaceByTypeDialog");
        searchPlaceByTypeDialog->resize(400, 211);
        buttonBox = new QDialogButtonBox(searchPlaceByTypeDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(20, 160, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        label = new QLabel(searchPlaceByTypeDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(79, 22, 211, 31));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        widget = new QWidget(searchPlaceByTypeDialog);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(60, 80, 271, 40));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        typeEdit = new QLineEdit(widget);
        typeEdit->setObjectName("typeEdit");

        gridLayout->addWidget(typeEdit, 0, 1, 1, 1);


        retranslateUi(searchPlaceByTypeDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, searchPlaceByTypeDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, searchPlaceByTypeDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(searchPlaceByTypeDialog);
    } // setupUi

    void retranslateUi(QDialog *searchPlaceByTypeDialog)
    {
        searchPlaceByTypeDialog->setWindowTitle(QCoreApplication::translate("searchPlaceByTypeDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("searchPlaceByTypeDialog", "\346\214\211\347\261\273\345\210\253\346\237\245\346\211\276\345\234\260\347\202\271", nullptr));
        label_2->setText(QCoreApplication::translate("searchPlaceByTypeDialog", "\350\257\267\350\276\223\345\205\245\347\261\273\345\210\253\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class searchPlaceByTypeDialog: public Ui_searchPlaceByTypeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHPLACEBYTYPEDIALOG_H
