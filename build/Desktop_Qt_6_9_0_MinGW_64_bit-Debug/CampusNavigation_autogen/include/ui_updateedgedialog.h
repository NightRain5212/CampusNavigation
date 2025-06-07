/********************************************************************************
** Form generated from reading UI file 'updateedgedialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPDATEEDGEDIALOG_H
#define UI_UPDATEEDGEDIALOG_H

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

class Ui_updateEdgeDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLineEdit *startEdit;
    QLabel *label_3;
    QLineEdit *endEdit;
    QLabel *label_4;
    QLineEdit *lengthEdit;

    void setupUi(QDialog *updateEdgeDialog)
    {
        if (updateEdgeDialog->objectName().isEmpty())
            updateEdgeDialog->setObjectName("updateEdgeDialog");
        updateEdgeDialog->resize(400, 258);
        buttonBox = new QDialogButtonBox(updateEdgeDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(40, 200, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        label = new QLabel(updateEdgeDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(100, 20, 211, 20));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        widget = new QWidget(updateEdgeDialog);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(60, 50, 281, 121));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        startEdit = new QLineEdit(widget);
        startEdit->setObjectName("startEdit");

        gridLayout->addWidget(startEdit, 0, 1, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        endEdit = new QLineEdit(widget);
        endEdit->setObjectName("endEdit");

        gridLayout->addWidget(endEdit, 1, 1, 1, 1);

        label_4 = new QLabel(widget);
        label_4->setObjectName("label_4");
        label_4->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        lengthEdit = new QLineEdit(widget);
        lengthEdit->setObjectName("lengthEdit");

        gridLayout->addWidget(lengthEdit, 2, 1, 1, 1);


        retranslateUi(updateEdgeDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, updateEdgeDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, updateEdgeDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(updateEdgeDialog);
    } // setupUi

    void retranslateUi(QDialog *updateEdgeDialog)
    {
        updateEdgeDialog->setWindowTitle(QCoreApplication::translate("updateEdgeDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("updateEdgeDialog", "\346\233\264\346\226\260\345\234\260\347\202\271\344\277\241\346\201\257", nullptr));
        label_2->setText(QCoreApplication::translate("updateEdgeDialog", "\350\257\267\350\276\223\345\205\245\351\201\223\350\267\257\347\232\204\350\265\267\347\202\271\345\220\215\347\247\260\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("updateEdgeDialog", "\350\257\267\350\276\223\345\205\245\351\201\223\350\267\257\347\232\204\347\273\210\347\202\271\345\220\215\347\247\260\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("updateEdgeDialog", "\350\257\267\350\276\223\345\205\245\346\226\260\347\232\204\351\225\277\345\272\246\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class updateEdgeDialog: public Ui_updateEdgeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPDATEEDGEDIALOG_H
