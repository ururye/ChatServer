#ifndef CHATDIALOG_H
#define CHATDIALOG_H
#include"global.h"
#include "qlistwidget.h"
#include <QDialog>

namespace Ui {
class ChatDialog;
}

class ChatDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChatDialog(QWidget *parent = nullptr);
    ~ChatDialog();
    void addChatUserList();
protected:
        void CloseFindDlg();
private:
    Ui::ChatDialog *ui;
    void ShowSearch(bool bsearch = false);
    ChatUIMode _mode;
    ChatUIMode _state;
    QWidget* _last_widget;
    //todo...
    bool _b_loading;
    QMap<int, QListWidgetItem*> _chat_items_added;
    int _cur_chat_uid;
private slots:
    void slot_loading_chat_user();
};

#endif // CHATDIALOG_H
