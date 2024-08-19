#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include"logindialog.h"
#include <QMainWindow>
#include "registerdialog.h"
#include"resetdialog.h"
#include"chatdialog.h"
#include"tcpmgr.h"
/******************************************************************************
 *
 * @file       mainwindow.h
 * @brief      主窗口
 *
 * @author     ururye
 * @date       2024/08/12
 * @history
 *****************************************************************************/
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void SlotSwitchReg();
    void SlowSwitchLogin();
    void SlotSwitchLogin2();
    void SlotSwitchReset();
    void SlotSwitchChat();
private:
    Ui::MainWindow *ui;
    LoginDialog * _login_dlg;
    RegisterDialog* _reg_dlg;
    ResetDialog* _reset_dlg;
    ChatDialog* _chat_dlg;
};
#endif // MAINWINDOW_H
