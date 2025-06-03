#ifndef DELEDGEDIALOG_H
#define DELEDGEDIALOG_H

#include <QDialog>

namespace Ui {
class delEdgeDialog;
}

class delEdgeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit delEdgeDialog(QWidget *parent = nullptr);
    ~delEdgeDialog();
    QString getStartPlace();
    QString getEndPlace();


private:
    Ui::delEdgeDialog *ui;
};

#endif // DELEDGEDIALOG_H
