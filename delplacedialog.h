#ifndef DELPLACEDIALOG_H
#define DELPLACEDIALOG_H

#include <QDialog>

namespace Ui {
class DelPlaceDialog;
}

class DelPlaceDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DelPlaceDialog(QWidget *parent = nullptr);
    ~DelPlaceDialog();

    QString getPlaceName();

private:
    Ui::DelPlaceDialog *ui;
};

#endif // DELPLACEDIALOG_H
