#include "deledgedialog.h"
#include "ui_deledgedialog.h"

delEdgeDialog::delEdgeDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::delEdgeDialog)
{
    ui->setupUi(this);
}

delEdgeDialog::~delEdgeDialog()
{
    delete ui;
}

QString delEdgeDialog::getStartPlace()
{
    return ui->startEdit->text();
}

QString delEdgeDialog::getEndPlace()
{
    return ui->endEdit->text();
}
