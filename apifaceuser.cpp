#include "apifaceuser.h"

ApiFaceUser::ApiFaceUser()
{

}
ApiFaceUser::ApiFaceUser(QString name,QString checkTime,int type,int status)
{
    this->name=name;
    this->checkTime=checkTime;
    this->type=type;
    this->status=status;
}
QString ApiFaceUser::getName()
{
    return this->name;
}
QString ApiFaceUser::getCheckTime()
{
    return this->checkTime;
}
int ApiFaceUser::getType()
{
    return this->type;
}
int ApiFaceUser::getStaus()
{
    return this->status;
}
