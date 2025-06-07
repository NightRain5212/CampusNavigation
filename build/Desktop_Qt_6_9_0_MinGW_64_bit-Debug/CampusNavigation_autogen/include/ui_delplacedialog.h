/********************************************************************************
** Form generated from reading UI file 'delplacedialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELPLACEDIALOG_H
#define UI_DELPLACEDIALOG_H

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

class Ui_DelPlaceDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label_place;
    QLineEdit *placeEdit;

    void setupUi(QDialog *DelPlaceDialog)
    {
        if (DelPlaceDialog->objectName().isEmpty())
            DelPlaceDialog->setObjectName("DelPlaceDialog");
        DelPlaceDialog->resize(400, 196);
        buttonBox = new QDialogButtonBox(DelPlaceDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 130, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        label = new QLabel(DelPlaceDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(89, 20, 211, 20));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        widget = new QWidget(DelPlaceDialog);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(60, 70, 281, 24));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_place = new QLabel(widget);
        label_place->setObjectName("label_place");

        gridLayout->addWidget(label_place, 0, 0, 1, 1);

        placeEdit = new QLineEdit(widget);
        placeEdit->setObjectName("placeEdit");

        gridLayout->addWidget(placeEdit, 0, 1, 1, 1);


        retranslateUi(DelPlaceDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, DelPlaceDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, DelPlaceDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(DelPlaceDialog);
    } // setupUi

    void retranslateUi(QDialog *DelPlaceDialog)
    {
        DelPlaceDialog->setWindowTitle(QCoreApplication::translate("DelPlaceDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("DelPlaceDialog", "\345\210\240\351\231\244\346\214\207\345\256\232\345\234\260\347\202\271\345\217\212\347\233\270\345\205\263\350\276\271", nullptr));
        label_place->setText(QCoreApplication::translate("DelPlaceDialog", "\350\257\267\350\276\223\345\205\245\345\234\260\347\202\271\345\220\215\347\247\260\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DelPlaceDialog: public Ui_DelPlaceDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELPLACEDIALOG_H
