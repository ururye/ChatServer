#ifndef REGISTERDIALOG_H
#define REGISTERDIALOG_H

#include <QDialog>
#include "global.h"
#include <functional>
#include <QMap>
#include <QJsonObject>
#include <QSet>
#include <QTimer>

namespace Ui {
class RegisterDialog;
}

class RegisterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RegisterDialog(QWidget *parent = nullptr);
    ~RegisterDialog();

private slots:
    void on_get_code_clicked();
    void slot_reg_mod_finish(ReqId id,QString res,ErrorCodes err);
    void on_sure_btn_clicked();

    void on_return_btn_clicked();
    void on_cancel_btn_clicked();
private:

    void initHttpHandlers();
    void showTip(QString str,bool b_ok);
    bool checkUserValid();
    bool checkPassValid();
    bool checkEmailValid();
    bool checkVarifyValid();
    bool checkConfirmValid();
    void AddTipErr(TipErr te,QString tips);
    void DelTipErr(TipErr te);
    void ChangeTipPage();
    Ui::RegisterDialog *ui;
    QMap<TipErr, QString> _tip_errs;
    QMap<ReqId,std::function<void(const QJsonObject&)>> _handlers;
    QTimer * _countdown_timer;
    int _countdown;
signals:
    void sigSwitchLogin();
};

#endif // REGISTERDIALOG_H
