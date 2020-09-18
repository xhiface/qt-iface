#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <dialog.h>
#include <sqllog.h>
#include <QMap>
#include <QMessageBox>
#include <QString>
#include <QDateTime>



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    Dialog *dialog;
    Sqllog *sqllog;
    QMap<QString,QString> map;
};

#endif // MAINWINDOW_H
