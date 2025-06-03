#include "shortestpathdialog.h"
#include "ui_shortestpathdialog.h"

shortestPathDialog::shortestPathDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::shortestPathDialog)
{
    ui->setupUi(this);
}

shortestPathDialog::~shortestPathDialog()
{
    delete ui;
}

QString shortestPathDialog::getStartPlaceName()
{
    return ui->startEdit->text();
}

QString shortestPathDialog::getEndPlaceName()
{
    return ui->endEdit->text();
}
