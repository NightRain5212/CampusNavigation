#ifndef SHORTESTPATHDIALOG_H
#define SHORTESTPATHDIALOG_H

#include <QDialog>

namespace Ui {
class shortestPathDialog;
}

class shortestPathDialog : public QDialog
{
    Q_OBJECT

public:
    explicit shortestPathDialog(QWidget *parent = nullptr);
    ~shortestPathDialog();

    QString getStartPlaceName();
    QString getEndPlaceName();

private:
    Ui::shortestPathDialog *ui;
};

#endif // SHORTESTPATHDIALOG_H
