#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QDebug>
#include <QMainWindow>
#include <QDateTime>
#include <QTime>
#include <QMessageBox>
#include <QFileDialog>
#include <QApplication>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QList>
#include <regex>
#include <cmath>
#include <QLabel>
#include "baiduapifaceuser.h"
#include "apifaceuser.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void baiduApi_recy(QNetworkReply *reply);
    void baiduApi_recy2(QNetworkReply *reply);
    void http_request();
    void net_recv();
    void on_label_2_linkActivated(const QString &link);
    BaiDuApiFaceUser* getBaiduApiFaceUser(const QString json);
    ApiFaceUser* getApiUser(const QString json);

    void on_label_3_linkActivated(const QString &link);

private:
    Ui::Dialog *ui;
    QNetworkAccessManager *manager1;
    QNetworkAccessManager *manager2;
    QTcpSocket *socket;
    QByteArray imag;

};

#endif // DIALOG_H
