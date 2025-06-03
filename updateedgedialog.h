#ifndef UPDATEEDGEDIALOG_H
#define UPDATEEDGEDIALOG_H

#include <QDialog>

namespace Ui {
class updateEdgeDialog;
}

class updateEdgeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit updateEdgeDialog(QWidget *parent = nullptr);
    ~updateEdgeDialog();
    QString getStartPlace();
    QString getEndPlace();
    int getNewLength();

private:
    Ui::updateEdgeDialog *ui;
};

#endif // UPDATEEDGEDIALOG_H
