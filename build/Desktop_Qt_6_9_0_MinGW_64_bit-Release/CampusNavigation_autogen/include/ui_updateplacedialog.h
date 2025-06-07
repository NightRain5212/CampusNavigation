/********************************************************************************
** Form generated from reading UI file 'updateplacedialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPDATEPLACEDIALOG_H
#define UI_UPDATEPLACEDIALOG_H

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

class Ui_updatePlaceDialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLineEdit *placeEdit;
    QLabel *label_3;
    QLineEdit *newTimeEdit;
    QLabel *label;

    void setupUi(QDialog *updatePlaceDialog)
    {
        if (updatePlaceDialog->objectName().isEmpty())
            updatePlaceDialog->setObjectName("updatePlaceDialog");
        updatePlaceDialog->resize(400, 255);
        buttonBox = new QDialogButtonBox(updatePlaceDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 190, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        layoutWidget = new QWidget(updatePlaceDialog);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(70, 70, 271, 101));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        placeEdit = new QLineEdit(layoutWidget);
        placeEdit->setObjectName("placeEdit");

        gridLayout->addWidget(placeEdit, 0, 1, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        newTimeEdit = new QLineEdit(layoutWidget);
        newTimeEdit->setObjectName("newTimeEdit");

        gridLayout->addWidget(newTimeEdit, 1, 1, 1, 1);

        label = new QLabel(updatePlaceDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(90, 30, 221, 20));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        retranslateUi(updatePlaceDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, updatePlaceDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, updatePlaceDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(updatePlaceDialog);
    } // setupUi

    void retranslateUi(QDialog *updatePlaceDialog)
    {
        updatePlaceDialog->setWindowTitle(QCoreApplication::translate("updatePlaceDialog", "Dialog", nullptr));
        label_2->setText(QCoreApplication::translate("updatePlaceDialog", "\350\257\267\350\276\223\345\205\245\345\234\260\347\202\271\345\220\215\347\247\260\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("updatePlaceDialog", "\350\257\267\350\276\223\345\205\245\346\226\260\347\232\204\345\273\272\350\256\256\345\217\202\350\247\202\346\227\266\351\225\277\357\274\232", nullptr));
        label->setText(QCoreApplication::translate("updatePlaceDialog", "\346\233\264\346\226\260\345\234\260\347\202\271\344\277\241\346\201\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class updatePlaceDialog: public Ui_updatePlaceDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPDATEPLACEDIALOG_H
