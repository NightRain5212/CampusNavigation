#include "searchplacebytypedialog.h"
#include "ui_searchplacebytypedialog.h"

searchPlaceByTypeDialog::searchPlaceByTypeDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::searchPlaceByTypeDialog)
{
    ui->setupUi(this);
}

searchPlaceByTypeDialog::~searchPlaceByTypeDialog()
{
    delete ui;
}

QString searchPlaceByTypeDialog::getType()
{
    return ui->typeEdit->text();
}


