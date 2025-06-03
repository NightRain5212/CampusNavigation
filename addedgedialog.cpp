#include "addedgedialog.h"
#include "ui_addedgedialog.h"

addedgedialog::addedgedialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::addedgedialog)
{
    ui->setupUi(this);
}

addedgedialog::~addedgedialog()
{
    delete ui;
}

QString addedgedialog::getStartPlace() const
{
    return ui->startEdit->text();
}

QString addedgedialog::getEndPlace() const
{
    return ui->endEdit->text();
}

int addedgedialog::getLength() const
{
    return ui->lengthEdit->text().toInt();
}


