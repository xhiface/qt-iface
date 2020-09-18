#ifndef BAIDUAPIFACEUSER_H
#define BAIDUAPIFACEUSER_H
#include <QDebug>
#include <QMainWindow>
#include <QDateTime>
#include <QTime>

class BaiDuApiFaceUser
{
public:
//    BaiDuApiFaceUser();
    BaiDuApiFaceUser(QString userId,double score);
    QString getUserId();
    double getScore();
    void setUserId(QString userId);
    void setScore(double score);
//    QString toString();
private:
    QString userId;
    double score;
};

#endif // BAIDUAPIFACEUSER_H
