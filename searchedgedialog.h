#ifndef SEARCHEDGEDIALOG_H
#define SEARCHEDGEDIALOG_H

#include <QDialog>

namespace Ui {
class searchEdgeDialog;
}

class searchEdgeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit searchEdgeDialog(QWidget *parent = nullptr);
    ~searchEdgeDialog();

    QString getPlaceName();

private:
    Ui::searchEdgeDialog *ui;
};

#endif // SEARCHEDGEDIALOG_H
