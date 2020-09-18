#ifndef APIFACEUSER_H
#define APIFACEUSER_H
#include <QDebug>
#include <QMainWindow>
#include <QDateTime>
#include <QTime>


class ApiFaceUser
{
public:
    ApiFaceUser();
    ApiFaceUser(QString name,QString checkTime,int type,int status);
    QString getName();
    QString getCheckTime();
    int getType();
    int getStaus();
private:
    QString name;
    QString checkTime;
    int type;
    int status;
};

#endif // APIFACEUSER_H
