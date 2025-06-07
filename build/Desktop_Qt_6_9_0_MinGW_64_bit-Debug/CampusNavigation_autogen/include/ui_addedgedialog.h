/********************************************************************************
** Form generated from reading UI file 'addedgedialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDEDGEDIALOG_H
#define UI_ADDEDGEDIALOG_H

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

class Ui_addedgedialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *titlelabel;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *startlabel;
    QLineEdit *startEdit;
    QLabel *endlabel;
    QLineEdit *endEdit;
    QLabel *lengthlabel;
    QLineEdit *lengthEdit;

    void setupUi(QDialog *addedgedialog)
    {
        if (addedgedialog->objectName().isEmpty())
            addedgedialog->setObjectName("addedgedialog");
        addedgedialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(addedgedialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        titlelabel = new QLabel(addedgedialog);
        titlelabel->setObjectName("titlelabel");
        titlelabel->setGeometry(QRect(0, 10, 401, 20));
        titlelabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        widget = new QWidget(addedgedialog);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(60, 60, 281, 161));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        startlabel = new QLabel(widget);
        startlabel->setObjectName("startlabel");

        gridLayout->addWidget(startlabel, 0, 0, 1, 1);

        startEdit = new QLineEdit(widget);
        startEdit->setObjectName("startEdit");

        gridLayout->addWidget(startEdit, 0, 1, 1, 1);

        endlabel = new QLabel(widget);
        endlabel->setObjectName("endlabel");

        gridLayout->addWidget(endlabel, 1, 0, 1, 1);

        endEdit = new QLineEdit(widget);
        endEdit->setObjectName("endEdit");

        gridLayout->addWidget(endEdit, 1, 1, 1, 1);

        lengthlabel = new QLabel(widget);
        lengthlabel->setObjectName("lengthlabel");

        gridLayout->addWidget(lengthlabel, 2, 0, 1, 1);

        lengthEdit = new QLineEdit(widget);
        lengthEdit->setObjectName("lengthEdit");

        gridLayout->addWidget(lengthEdit, 2, 1, 1, 1);


        retranslateUi(addedgedialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, addedgedialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, addedgedialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(addedgedialog);
    } // setupUi

    void retranslateUi(QDialog *addedgedialog)
    {
        addedgedialog->setWindowTitle(QCoreApplication::translate("addedgedialog", "Dialog", nullptr));
        titlelabel->setText(QCoreApplication::translate("addedgedialog", "\346\267\273\345\212\240\351\201\223\350\267\257", nullptr));
        startlabel->setText(QCoreApplication::translate("addedgedialog", "\350\265\267\345\247\213\345\234\260\347\202\271\357\274\232", nullptr));
        endlabel->setText(QCoreApplication::translate("addedgedialog", "\345\210\260\350\276\276\345\234\260\347\202\271\357\274\232", nullptr));
        lengthlabel->setText(QCoreApplication::translate("addedgedialog", "\350\267\257\345\276\204\351\225\277\345\272\246\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addedgedialog: public Ui_addedgedialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDEDGEDIALOG_H
