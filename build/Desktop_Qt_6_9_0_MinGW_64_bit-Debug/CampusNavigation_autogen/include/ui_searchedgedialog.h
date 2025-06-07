/********************************************************************************
** Form generated from reading UI file 'searchedgedialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHEDGEDIALOG_H
#define UI_SEARCHEDGEDIALOG_H

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

class Ui_searchEdgeDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLineEdit *nameEdit;

    void setupUi(QDialog *searchEdgeDialog)
    {
        if (searchEdgeDialog->objectName().isEmpty())
            searchEdgeDialog->setObjectName("searchEdgeDialog");
        searchEdgeDialog->resize(400, 200);
        buttonBox = new QDialogButtonBox(searchEdgeDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(40, 150, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        label = new QLabel(searchEdgeDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(60, 19, 251, 31));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        widget = new QWidget(searchEdgeDialog);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(60, 90, 271, 24));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        nameEdit = new QLineEdit(widget);
        nameEdit->setObjectName("nameEdit");

        gridLayout->addWidget(nameEdit, 0, 1, 1, 1);


        retranslateUi(searchEdgeDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, searchEdgeDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, searchEdgeDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(searchEdgeDialog);
    } // setupUi

    void retranslateUi(QDialog *searchEdgeDialog)
    {
        searchEdgeDialog->setWindowTitle(QCoreApplication::translate("searchEdgeDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("searchEdgeDialog", "\346\237\245\346\211\276\347\233\270\345\205\263\345\234\260\347\202\271\347\232\204\346\211\200\346\234\211\350\276\271", nullptr));
        label_2->setText(QCoreApplication::translate("searchEdgeDialog", "\350\257\267\350\276\223\345\205\245\345\234\260\347\202\271\345\220\215\347\247\260\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class searchEdgeDialog: public Ui_searchEdgeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHEDGEDIALOG_H
