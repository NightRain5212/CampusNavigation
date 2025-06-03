#include "searchbytimedialog.h"
#include "ui_searchbytimedialog.h"

searchByTimeDialog::searchByTimeDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::searchByTimeDialog)
{
    ui->setupUi(this);
}

searchByTimeDialog::~searchByTimeDialog()
{
    delete ui;
}

int searchByTimeDialog::getTime()
{
    return ui->timeEdit->text().toInt();
}
