#include "MysqlMgr.h"

MysqlMgr::~MysqlMgr() {
}
int MysqlMgr::RegUser(const std::string& name, const std::string& email, const std::string& pwd)
{
    return _dao.RegUser(name, email, pwd);
}

MysqlMgr::MysqlMgr() {
}
bool MysqlMgr::CheckPwd(const std::string& email, const std::string& pwd, UserInfo& userInfo) {
        return _dao.CheckPwd(email, pwd, userInfo);
    }
bool MysqlMgr::CheckEmail(const std::string& name, const std::string& email) {
    return _dao.CheckEmail(name, email);
}
bool MysqlMgr::UpdatePwd(const std::string& name, const std::string& pwd) {
    return _dao.UpdatePwd(name, pwd);
}