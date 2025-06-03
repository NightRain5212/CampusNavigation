#ifndef SEARCHPLACEBYNAMEDIALOG_H
#define SEARCHPLACEBYNAMEDIALOG_H

#include <QDialog>

namespace Ui {
class searchPlaceByNameDialog;
}

class searchPlaceByNameDialog : public QDialog
{
    Q_OBJECT

public:
    explicit searchPlaceByNameDialog(QWidget *parent = nullptr);
    ~searchPlaceByNameDialog();

    QString getName();


signals:
    void newLog(const QString& message,const QString& level);

private:
    Ui::searchPlaceByNameDialog *ui;
};

#endif // SEARCHPLACEBYNAMEDIALOG_H
