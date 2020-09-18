#include "dialog.h"
#include "ui_dialog.h"
#include "json.h"
#include <QHostAddress>

using QtJson::JsonObject;
using QtJson::JsonArray;

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    socket=new QTcpSocket(this);
    manager1 = new QNetworkAccessManager(this);
    manager2 = new QNetworkAccessManager(this);
    //关联信号槽，收到信号执行
        connect(socket,SIGNAL(readyRead()),this,SLOT(net_recv()));

    connect(manager1,SIGNAL(finished(QNetworkReply*)),this,SLOT(baiduApi_recy(QNetworkReply*)));
    connect(manager2,SIGNAL(finished(QNetworkReply*)),this,SLOT(baiduApi_recy2(QNetworkReply*)));

    socket->connectToHost("192.168.1.3",6666);

}
void Dialog::net_recv()
{

    socket->waitForReadyRead();
    char filesiez[10];
    socket->read(filesiez,10);

    int len;
    sscanf(filesiez,"%d",&len);
    qDebug()<<len;

    while(1){

        if(socket->bytesAvailable() < len){

            socket->waitForReadyRead();
        }

        else{
            break;
        }

    }


        imag = socket->readAll();

        qDebug()<<imag.size();
        QPixmap map;
        map.loadFromData(imag,"JPG");
        ui->label_2->setPixmap(map);


    Dialog::http_request();
}

void Dialog::baiduApi_recy2(QNetworkReply *reply)
{
    QByteArray data2=reply->readAll();
    qDebug()<<data2;

    QString apiJson=QString(data2);

    int code=reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).value<int>();

    qDebug()<<code;
    qDebug()<<apiJson;
    ApiFaceUser *apiFaceUser=getApiUser(apiJson);
    QMessageBox::information(NULL,"打卡成功",apiFaceUser->getName()+" 打卡成功"+" 时间:"+apiFaceUser->getCheckTime()+"点",QMessageBox::Yes);
    if(apiFaceUser->getStaus()==2)
    {
        QMessageBox::information(NULL,"提示","你已迟到",QMessageBox::Yes);
    }
    else if(apiFaceUser->getStaus()==3)
    {
        QMessageBox::information(NULL,"提示","你已早退",QMessageBox::Yes);
    }
}
void Dialog::baiduApi_recy(QNetworkReply *reply)
{
    //接受百度结果
    QByteArray data=reply->readAll();
    QString baiduApiJson=QString(data);
    qDebug()<<baiduApiJson;
    BaiDuApiFaceUser *baiduApiFaceUser=getBaiduApiFaceUser(baiduApiJson);
    qDebug()<<baiduApiFaceUser->getScore();
    if(baiduApiFaceUser->getScore()>80.0)
    {
        QApplication::setQuitOnLastWindowClosed(false);
        //发起http post请求
        QNetworkRequest request;
        request.setUrl(QUrl("http://139.224.119.162:80/attend/add-attend"));
        request.setHeader(QNetworkRequest::ContentTypeHeader,"application/json");
        //json生成
        QJsonObject obj;
        obj.insert("phoneNumber",baiduApiFaceUser->getUserId());
        //qjson 转换为array
        QJsonDocument doc(obj);
        QByteArray data1 = doc.toJson();
        manager2->post(request,data1);
    }
    else
    {
        QMessageBox::warning(NULL,"失败","查无此人，打卡失败",QMessageBox::Yes);
    }
}

BaiDuApiFaceUser* Dialog:: getBaiduApiFaceUser(const QString json) {
    bool ok;
    JsonObject obj = QtJson::parse(json, ok).toMap();
    if (!ok) {
        qFatal("An error occurred during parsing");
        return NULL;
    }
    if (obj["error_code"].toInt() == 0){
        JsonObject result = obj["result"].toMap();
        if(!result.isEmpty()){
            JsonArray userList = result["user_list"].toList();
            JsonObject user = userList[0].toMap();
            return new BaiDuApiFaceUser(user["user_id"].toString(),user["score"].toString().toDouble()) ;
        }
    }
    return new BaiDuApiFaceUser(QString(""),0.0);
}
ApiFaceUser* Dialog:: getApiUser(const QString json)
{
    bool ok;
    JsonObject obj = QtJson::parse(json, ok).toMap();
    if (!ok) {
        qFatal("An error occurred during parsing");
        return NULL;
    }
    QString username = obj["username"].toString();
    QString checkTime=obj["checkTime"].toString();
    int type=int(obj["type"].toInt());
    int status=int(obj["status"].toInt());
    return new ApiFaceUser(username,checkTime,type,status);
}
Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    //parentWidget()->show();
    this->deleteLater();
    qDebug()<<"成功关闭:";
}
void Dialog::on_pushButton_2_clicked()
{

    //char buf[4];
//    char ch = 0x1f;

    //buf[0]=1
//    socket->write(&ch,1);?

    socket->write("picture");

//    net_recv();

}

void Dialog::http_request()
{
    QApplication::setQuitOnLastWindowClosed(false);
    //发起http post请求
    QNetworkRequest request;
    request.setUrl(QUrl("https://aip.baidubce.com/rest/2.0/face/v3/search?access_token=24.78c2261c73a18ccab5718ad385a9c7f2.2592000.1602666046.282335-22583648"));
    request.setHeader(QNetworkRequest::ContentTypeHeader,"application/json");

    //    //本地测试
    //    QString filename =QFileDialog::getOpenFileName();
    //    QFile file(filename);
    //    file.open(QIODevice::ReadOnly);
    //    QByteArray image =file.readAll();
    //    Dialog::on_label_2_linkActivated(filename);
    //    file.close();
    //json生成
    QJsonObject obj;
    obj.insert("image",QString(imag.toBase64()));
    obj.insert("image_type","BASE64");
    obj.insert("group_id_list","user");
    //qjson 转换为array
    QJsonDocument doc(obj);
    QByteArray data = doc.toJson();
    manager1->post(request,data);
}

void Dialog::on_label_2_linkActivated(const QString &link)
{
    QImage *img=new QImage();
    img->load(link);
    Dialog::ui->label_2->setPixmap(QPixmap::fromImage(*img));
}

void Dialog::on_label_3_linkActivated(const QString &link)
{

}
