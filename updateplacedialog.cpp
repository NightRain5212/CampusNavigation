#include "updateplacedialog.h"
#include "ui_updateplacedialog.h"

updatePlaceDialog::updatePlaceDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::updatePlaceDialog)
{
    ui->setupUi(this);
}

updatePlaceDialog::~updatePlaceDialog()
{
    delete ui;
}

QString updatePlaceDialog::getPlaceName()
{
    return ui->placeEdit->text();
}

int updatePlaceDialog::getNewTime()
{
    return ui->newTimeEdit->text().toInt();
}
