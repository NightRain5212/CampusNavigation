/********************************************************************************
** Form generated from reading UI file 'shortestpathdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHORTESTPATHDIALOG_H
#define UI_SHORTESTPATHDIALOG_H

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

class Ui_shortestPathDialog
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

    void setupUi(QDialog *shortestPathDialog)
    {
        if (shortestPathDialog->objectName().isEmpty())
            shortestPathDialog->setObjectName("shortestPathDialog");
        shortestPathDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(shortestPathDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        label = new QLabel(shortestPathDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(89, 21, 221, 21));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        widget = new QWidget(shortestPathDialog);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(50, 80, 301, 91));
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


        retranslateUi(shortestPathDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, shortestPathDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, shortestPathDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(shortestPathDialog);
    } // setupUi

    void retranslateUi(QDialog *shortestPathDialog)
    {
        shortestPathDialog->setWindowTitle(QCoreApplication::translate("shortestPathDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("shortestPathDialog", "\346\237\245\350\257\242\344\270\244\347\202\271\351\227\264\347\232\204\346\234\200\347\237\255\350\267\257\345\276\204", nullptr));
        label_2->setText(QCoreApplication::translate("shortestPathDialog", "\350\257\267\350\276\223\345\205\245\350\265\267\347\202\271\345\220\215\347\247\260\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("shortestPathDialog", "\350\257\267\350\276\223\345\205\245\347\273\210\347\202\271\345\220\215\347\247\260\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class shortestPathDialog: public Ui_shortestPathDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHORTESTPATHDIALOG_H
