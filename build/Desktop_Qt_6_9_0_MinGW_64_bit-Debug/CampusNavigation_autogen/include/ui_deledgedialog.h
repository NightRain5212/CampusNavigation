/********************************************************************************
** Form generated from reading UI file 'deledgedialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELEDGEDIALOG_H
#define UI_DELEDGEDIALOG_H

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

class Ui_delEdgeDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label_start;
    QLineEdit *startEdit;
    QLabel *label_end;
    QLineEdit *endEdit;

    void setupUi(QDialog *delEdgeDialog)
    {
        if (delEdgeDialog->objectName().isEmpty())
            delEdgeDialog->setObjectName("delEdgeDialog");
        delEdgeDialog->resize(400, 263);
        buttonBox = new QDialogButtonBox(delEdgeDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 210, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        label = new QLabel(delEdgeDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(110, 30, 181, 21));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        widget = new QWidget(delEdgeDialog);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(60, 70, 301, 111));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_start = new QLabel(widget);
        label_start->setObjectName("label_start");

        gridLayout->addWidget(label_start, 0, 0, 1, 1);

        startEdit = new QLineEdit(widget);
        startEdit->setObjectName("startEdit");

        gridLayout->addWidget(startEdit, 0, 1, 1, 1);

        label_end = new QLabel(widget);
        label_end->setObjectName("label_end");

        gridLayout->addWidget(label_end, 1, 0, 1, 1);

        endEdit = new QLineEdit(widget);
        endEdit->setObjectName("endEdit");

        gridLayout->addWidget(endEdit, 1, 1, 1, 1);


        retranslateUi(delEdgeDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, delEdgeDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, delEdgeDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(delEdgeDialog);
    } // setupUi

    void retranslateUi(QDialog *delEdgeDialog)
    {
        delEdgeDialog->setWindowTitle(QCoreApplication::translate("delEdgeDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("delEdgeDialog", "\345\210\240\351\231\244\346\214\207\345\256\232\350\276\271", nullptr));
        label_start->setText(QCoreApplication::translate("delEdgeDialog", "\350\257\267\350\276\223\345\205\245\350\265\267\347\202\271\345\220\215\347\247\260\357\274\232", nullptr));
        label_end->setText(QCoreApplication::translate("delEdgeDialog", "\350\257\267\350\276\223\345\205\245\347\273\210\347\202\271\345\220\215\347\247\260\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class delEdgeDialog: public Ui_delEdgeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELEDGEDIALOG_H
