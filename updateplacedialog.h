#ifndef UPDATEPLACEDIALOG_H
#define UPDATEPLACEDIALOG_H

#include <QDialog>

namespace Ui {
class updatePlaceDialog;
}

class updatePlaceDialog : public QDialog
{
    Q_OBJECT

public:
    explicit updatePlaceDialog(QWidget *parent = nullptr);
    ~updatePlaceDialog();
    QString getPlaceName();
    int getNewTime();

private:
    Ui::updatePlaceDialog *ui;
};

#endif // UPDATEPLACEDIALOG_H
