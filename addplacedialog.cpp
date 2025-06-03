#include "addplacedialog.h"
#include "ui_addplacedialog.h"

AddplaceDialog::AddplaceDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddplaceDialog)
{
    ui->setupUi(this);
    ui->titlelabel->setStyleSheet("QLabel {"
                                  "font-weight: bold;"      // 设置粗体
                                  "text-align: center;"     // 设置居中
                                  "font-size: 12px;"
                                  "}");
}

AddplaceDialog::~AddplaceDialog()
{
    delete ui;
}

QString AddplaceDialog::getName() const
{
    return ui->nameEdit->text();
}

QString AddplaceDialog::getType() const
{
    return ui->typeEdit->text();
}

int AddplaceDialog::getTime() const
{
    return (ui->timeEdit->text().toInt());
}
