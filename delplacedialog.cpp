#include "delplacedialog.h"
#include "ui_delplacedialog.h"

DelPlaceDialog::DelPlaceDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DelPlaceDialog)
{
    ui->setupUi(this);
}

DelPlaceDialog::~DelPlaceDialog()
{
    delete ui;
}

QString DelPlaceDialog::getPlaceName()
{
    return ui->placeEdit->text();
}
