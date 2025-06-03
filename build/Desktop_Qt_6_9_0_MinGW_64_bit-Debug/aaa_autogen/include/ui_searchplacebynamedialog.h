/********************************************************************************
** Form generated from reading UI file 'searchplacebynamedialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHPLACEBYNAMEDIALOG_H
#define UI_SEARCHPLACEBYNAMEDIALOG_H

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

class Ui_searchPlaceByNameDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLineEdit *nameEdit;

    void setupUi(QDialog *searchPlaceByNameDialog)
    {
        if (searchPlaceByNameDialog->objectName().isEmpty())
            searchPlaceByNameDialog->setObjectName("searchPlaceByNameDialog");
        searchPlaceByNameDialog->resize(400, 202);
        buttonBox = new QDialogButtonBox(searchPlaceByNameDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 150, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        label = new QLabel(searchPlaceByNameDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(80, 30, 231, 20));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        widget = new QWidget(searchPlaceByNameDialog);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(70, 90, 261, 24));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        nameEdit = new QLineEdit(widget);
        nameEdit->setObjectName("nameEdit");

        gridLayout->addWidget(nameEdit, 0, 1, 1, 1);


        retranslateUi(searchPlaceByNameDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, searchPlaceByNameDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, searchPlaceByNameDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(searchPlaceByNameDialog);
    } // setupUi

    void retranslateUi(QDialog *searchPlaceByNameDialog)
    {
        searchPlaceByNameDialog->setWindowTitle(QCoreApplication::translate("searchPlaceByNameDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("searchPlaceByNameDialog", "\346\214\211\345\220\215\347\247\260\346\237\245\346\211\276\345\234\260\347\202\271\344\277\241\346\201\257", nullptr));
        label_2->setText(QCoreApplication::translate("searchPlaceByNameDialog", "\350\257\267\350\276\223\345\205\245\345\220\215\345\255\227\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class searchPlaceByNameDialog: public Ui_searchPlaceByNameDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHPLACEBYNAMEDIALOG_H
