/********************************************************************************
** Form generated from reading UI file 'addplacedialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDPLACEDIALOG_H
#define UI_ADDPLACEDIALOG_H

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

class Ui_AddplaceDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *titlelabel;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *name_label;
    QLineEdit *nameEdit;
    QLabel *type_label;
    QLineEdit *typeEdit;
    QLabel *time_label;
    QLineEdit *timeEdit;

    void setupUi(QDialog *AddplaceDialog)
    {
        if (AddplaceDialog->objectName().isEmpty())
            AddplaceDialog->setObjectName("AddplaceDialog");
        AddplaceDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(AddplaceDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        titlelabel = new QLabel(AddplaceDialog);
        titlelabel->setObjectName("titlelabel");
        titlelabel->setGeometry(QRect(60, 10, 241, 20));
        titlelabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        widget = new QWidget(AddplaceDialog);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(40, 40, 321, 181));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        name_label = new QLabel(widget);
        name_label->setObjectName("name_label");

        gridLayout->addWidget(name_label, 0, 0, 1, 1);

        nameEdit = new QLineEdit(widget);
        nameEdit->setObjectName("nameEdit");

        gridLayout->addWidget(nameEdit, 0, 1, 1, 1);

        type_label = new QLabel(widget);
        type_label->setObjectName("type_label");

        gridLayout->addWidget(type_label, 1, 0, 1, 1);

        typeEdit = new QLineEdit(widget);
        typeEdit->setObjectName("typeEdit");

        gridLayout->addWidget(typeEdit, 1, 1, 1, 1);

        time_label = new QLabel(widget);
        time_label->setObjectName("time_label");

        gridLayout->addWidget(time_label, 2, 0, 1, 1);

        timeEdit = new QLineEdit(widget);
        timeEdit->setObjectName("timeEdit");

        gridLayout->addWidget(timeEdit, 2, 1, 1, 1);


        retranslateUi(AddplaceDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, AddplaceDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, AddplaceDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(AddplaceDialog);
    } // setupUi

    void retranslateUi(QDialog *AddplaceDialog)
    {
        AddplaceDialog->setWindowTitle(QCoreApplication::translate("AddplaceDialog", "AddPlace", nullptr));
        titlelabel->setText(QCoreApplication::translate("AddplaceDialog", "\346\267\273\345\212\240\345\234\260\347\202\271\344\277\241\346\201\257", nullptr));
        name_label->setText(QCoreApplication::translate("AddplaceDialog", "Name\357\274\232", nullptr));
        type_label->setText(QCoreApplication::translate("AddplaceDialog", "Type\357\274\232", nullptr));
        time_label->setText(QCoreApplication::translate("AddplaceDialog", "Time\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddplaceDialog: public Ui_AddplaceDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDPLACEDIALOG_H
