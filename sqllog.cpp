#include "sqllog.h"
#include "ui_sqllog.h"

Sqllog::Sqllog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Sqllog)
{
    ui->setupUi(this);


}

Sqllog::~Sqllog()
{
    delete ui;
}

void Sqllog::on_pushButton_clicked()
{
    parentWidget()->show();
    this->deleteLater();
    qDebug()<<"成功关闭:";
}

void Sqllog::on_pushButton_2_clicked()
{


}


void Sqllog::on_pushButton_3_clicked()
{


}
