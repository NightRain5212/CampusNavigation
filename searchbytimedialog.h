#ifndef SEARCHBYTIMEDIALOG_H
#define SEARCHBYTIMEDIALOG_H

#include <QDialog>

namespace Ui {
class searchByTimeDialog;
}

class searchByTimeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit searchByTimeDialog(QWidget *parent = nullptr);
    ~searchByTimeDialog();
    int getTime();

private:
    Ui::searchByTimeDialog *ui;
};

#endif // SEARCHBYTIMEDIALOG_H
