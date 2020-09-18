#include "baiduapifaceuser.h"
BaiDuApiFaceUser::BaiDuApiFaceUser(QString userId,double score)
{
    this->userId=userId;
    this->score=score;
}
double BaiDuApiFaceUser::getScore()
{
    return this->score;
}
QString BaiDuApiFaceUser::getUserId()
{
    return this->userId;
}
void BaiDuApiFaceUser::setUserId(QString userId)
{
    this->userId=userId;
}
void BaiDuApiFaceUser::setScore(double score)
{
    this->userId=userId;
}
