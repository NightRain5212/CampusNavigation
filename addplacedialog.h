#ifndef ADDPLACEDIALOG_H
#define ADDPLACEDIALOG_H

#include <QDialog>

namespace Ui {
class AddplaceDialog;
}

class AddplaceDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddplaceDialog(QWidget *parent = nullptr);
    ~AddplaceDialog();

    QString getName() const;
    QString getType() const;
    int getTime() const;

signals:
    void newLog(const QString& message,const QString& level);

private:
    Ui::AddplaceDialog *ui;
};

#endif // ADDPLACEDIALOG_H
