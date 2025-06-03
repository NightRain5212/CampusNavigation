#include "updateedgedialog.h"
#include "ui_updateedgedialog.h"

updateEdgeDialog::updateEdgeDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::updateEdgeDialog)
{
    ui->setupUi(this);
}

updateEdgeDialog::~updateEdgeDialog()
{
    delete ui;
}

QString updateEdgeDialog::getStartPlace()
{
    return ui->startEdit->text();
}

QString updateEdgeDialog::getEndPlace()
{
    return ui->endEdit->text();
}

int updateEdgeDialog::getNewLength()
{
    return ui->lengthEdit->text().toInt();
}
