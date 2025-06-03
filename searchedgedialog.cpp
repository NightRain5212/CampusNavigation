#include "searchedgedialog.h"
#include "ui_searchedgedialog.h"

searchEdgeDialog::searchEdgeDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::searchEdgeDialog)
{
    ui->setupUi(this);
}

searchEdgeDialog::~searchEdgeDialog()
{
    delete ui;
}

QString searchEdgeDialog::getPlaceName()
{
    return ui->nameEdit->text();
}
