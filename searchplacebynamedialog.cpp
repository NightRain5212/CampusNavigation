#include "searchplacebynamedialog.h"
#include "ui_searchplacebynamedialog.h"

searchPlaceByNameDialog::searchPlaceByNameDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::searchPlaceByNameDialog)
{
    ui->setupUi(this);
}

searchPlaceByNameDialog::~searchPlaceByNameDialog()
{
    delete ui;
}

QString searchPlaceByNameDialog::getName()
{
    return ui->nameEdit->text();
}
