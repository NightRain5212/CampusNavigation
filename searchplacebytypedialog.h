#ifndef SEARCHPLACEBYTYPEDIALOG_H
#define SEARCHPLACEBYTYPEDIALOG_H

#include <QDialog>

namespace Ui {
class searchPlaceByTypeDialog;
}

class searchPlaceByTypeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit searchPlaceByTypeDialog(QWidget *parent = nullptr);
    ~searchPlaceByTypeDialog();

    QString getType();

signals:
    void newLog(const QString& message,const QString& level);

private:
    Ui::searchPlaceByTypeDialog *ui;
};

#endif // SEARCHPLACEBYTYPEDIALOG_H
