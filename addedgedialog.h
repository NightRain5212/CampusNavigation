#ifndef ADDEDGEDIALOG_H
#define ADDEDGEDIALOG_H

#include <QDialog>

namespace Ui {
class addedgedialog;
}

class addedgedialog : public QDialog
{
    Q_OBJECT

public:
    explicit addedgedialog(QWidget *parent = nullptr);
    ~addedgedialog();
    QString getStartPlace() const;
    QString getEndPlace() const;
    int getLength() const;

signals:
    void newLog(const QString& message,const QString& level);

private:
    Ui::addedgedialog *ui;
};

#endif // ADDEDGEDIALOG_H
