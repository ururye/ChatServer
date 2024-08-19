#pragma once
#include "const.h"
#include "MysqlDao.h"
class MysqlMgr : public Singleton<MysqlMgr>
{
    friend class Singleton<MysqlMgr>;
public:
    ~MysqlMgr();
    bool CheckEmail(const std::string& name, const std::string& email);
    bool CheckPwd(const std::string& name, const std::string& pwd, UserInfo& userInfo);

    bool UpdatePwd(const std::string& name, const std::string& pwd);
    int RegUser(const std::string& name, const std::string& email, const std::string& pwd);
private:

    MysqlMgr();
    MysqlDao  _dao;
};
