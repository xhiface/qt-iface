#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->lineEdit->setPlaceholderText(tr("请输入用户名!"));

    ui->lineEdit_2->setEchoMode(QLineEdit::Password);

    map.insert("a","1");
    map.insert("b","2");
    //qDebug()<<"name:"<<name;

   /* connect(ui->pushButton_2, &QPushButton::clicked, this, [=]()
    {
        MainWindow dialog;
        dialog.show();
    });*/

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{


     if(ui->lineEdit->text().trimmed().isEmpty()|| ui->lineEdit_2->text().trimmed().isEmpty())
    {
        QMessageBox::warning(NULL,"登录失败","用户名或密码不能为空",QMessageBox::Yes);
    }
     else
     {
        if(map.contains(ui->lineEdit->text().trimmed()))
        {
            if(/*ui->lineEdit->text().trimmed()==(n)&&ui->lineEdit_2->text().trimmed()==(p)*/
               map.value(ui->lineEdit->text().trimmed()).compare(ui->lineEdit_2->text().trimmed()) == 0)
            {
                sqllog=new Sqllog(this);
                sqllog->setModal(false);
                sqllog->show();
                /*this->hide();
                dialog=new Dialog(this);
                dialog->setModal(false);
                dialog->show();*/
                qDebug()<<"登陆成功:";
                this->hide();
                ui->lineEdit->clear();
                ui->lineEdit_2->clear();
            }
            else  /*if(ui->lineEdit->text().trimmed()!=n&&ui->lineEdit_2->text().trimmed()!=p)*/
            {
                qDebug()<<"登陆失败:";
                QMessageBox::warning(NULL,"登录失败","用户名或密码错误",QMessageBox::Yes);
                //ui->lineEdit->clear();
                ui->lineEdit_2->clear();
            }
        }
        else  /*if(ui->lineEdit->text().trimmed()!=n&&ui->lineEdit_2->text().trimmed()!=p)*/
        {
            qDebug()<<"登陆失败:";
            QMessageBox::warning(NULL,"登录失败","用户名或密码错误",QMessageBox::Yes);
            //ui->lineEdit->clear();
            ui->lineEdit_2->clear();
        }


    }




}

void MainWindow::on_pushButton_clicked()
{
    if(ui->lineEdit->text().trimmed().isEmpty()|| ui->lineEdit_2->text().trimmed().isEmpty())
   {
       QMessageBox::warning(NULL,"注册失败","用户名或密码不能为空",QMessageBox::Yes);

   }
     else
   {
        if(map.contains(ui->lineEdit->text().trimmed())==0)
        {
        map.insert(ui->lineEdit->text().trimmed(),ui->lineEdit_2->text().trimmed());
        QMessageBox::information(NULL,"成功","注册成功",QMessageBox::Yes);
        }

        else
        {
        QMessageBox::warning(NULL,"失败","用户名存在注册失败",QMessageBox::Yes);
        }
   }




}

void MainWindow::on_pushButton_3_clicked()
{

    dialog=new Dialog(this);
    dialog->setModal(false);
    dialog->show();

}

