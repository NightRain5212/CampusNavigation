/********************************************************************************
** Form generated from reading UI file 'searchbytimedialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHBYTIMEDIALOG_H
#define UI_SEARCHBYTIMEDIALOG_H

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

class Ui_searchByTimeDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLineEdit *timeEdit;

    void setupUi(QDialog *searchByTimeDialog)
    {
        if (searchByTimeDialog->objectName().isEmpty())
            searchByTimeDialog->setObjectName("searchByTimeDialog");
        searchByTimeDialog->resize(400, 216);
        buttonBox = new QDialogButtonBox(searchByTimeDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(50, 150, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        label = new QLabel(searchByTimeDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(80, 30, 221, 31));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        widget = new QWidget(searchByTimeDialog);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(70, 80, 271, 41));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        timeEdit = new QLineEdit(widget);
        timeEdit->setObjectName("timeEdit");

        gridLayout->addWidget(timeEdit, 0, 1, 1, 1);


        retranslateUi(searchByTimeDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, searchByTimeDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, searchByTimeDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(searchByTimeDialog);
    } // setupUi

    void retranslateUi(QDialog *searchByTimeDialog)
    {
        searchByTimeDialog->setWindowTitle(QCoreApplication::translate("searchByTimeDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("searchByTimeDialog", "\346\214\211\346\216\250\350\215\220\346\270\270\347\216\251\346\227\266\351\227\264\346\237\245\350\257\242\345\234\260\347\202\271\344\277\241\346\201\257", nullptr));
        label_2->setText(QCoreApplication::translate("searchByTimeDialog", "\350\257\267\350\276\223\345\205\245\345\273\272\350\256\256\346\270\270\347\216\251\346\227\266\351\227\264\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class searchByTimeDialog: public Ui_searchByTimeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHBYTIMEDIALOG_H
