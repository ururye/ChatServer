 #ifndef HTTPMGR_H
#define HTTPMGR_H
#include "singleton.h"
#include <QString>
#include <QObject>
#include <QNetworkAccessManager>
#include<QJsonObject>
#include<QJsonDocument>

//crtp
class HttpMgr:public QObject,public Singleton<HttpMgr>,
                public std::enable_shared_from_this<HttpMgr>
{
    Q_OBJECT
public:
    //shared_ptr指针析构需调用HttpMgr析构函数
    ~HttpMgr();
    void PostHttpReq(QUrl url,QJsonObject json, ReqId req_id,Modules mod);

private:
    friend class Singleton<HttpMgr>;
    HttpMgr();
    QNetworkAccessManager _manager;

//私有槽函数
private slots:
    void slot_http_finish(ReqId id,QString res,ErrorCodes err,Modules mod );

signals:
    //发送结束信号
    void sig_http_finish(ReqId id,QString res,ErrorCodes err,Modules mod );
    void sig_reg_mod_finish(ReqId id,QString res,ErrorCodes err);
    void sig_reset_mod_finish(ReqId id,QString res,ErrorCodes err);
    void sig_login_mod_finish(ReqId id, QString res, ErrorCodes err);
};

#endif // HTTPMGR_H
