#ifndef SQLLOG_H
#define SQLLOG_H

#include <QDialog>
#include <QDebug>

namespace Ui {
class Sqllog;
}

class Sqllog : public QDialog
{
    Q_OBJECT

public:
    explicit Sqllog(QWidget *parent = 0);
    ~Sqllog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Sqllog *ui;
};

#endif // SQLLOG_H
