#pragma execution_character_set("utf-8")
#ifndef MMESSAGEBOX_H
#define MMESSAGEBOX_H

#include <QWidget>
#include "mcommon.h"
#include <QPalette>
#include <QColor>
#include <QFont>
#include <QAction>
#include <QMenu>
#include <QCursor>
#include <QList>
#include <QVector>
#include <QVBoxLayout>
#include <QScrollArea>
namespace Ui {
class MMessageBox;
class MMessageBoxs;
}
using  Common::setLabelRoundRectPixmap;
using MMessageBox_ptr=Ui::MMessageBox*;
class MMessageBox : public QWidget
{
    Q_OBJECT

public:
    explicit MMessageBox(QWidget *parent = nullptr);
    ~MMessageBox();
    void setMessageBox(const QString&pictureName,const QString&name,const QString&messageText,const QString&statusText,const QString&messageTime,bool isNotDisturb=false);
    MMessageBox& operator=(const MMessageBox&obj);
    bool getIsClick();
    void setIsClick(bool isClick);
    void cancelSelected();
    void cancelTopMessageBox();
    bool getIsTopMessageBox();
    void setIsTopMessageBox(bool isTopMessageBox);
    void setISNotDisturb(bool isNotDisturb);
    QString getName();
public slots:
    void contextMenuEvent(QContextMenuEvent*event);
    bool eventFilter(QObject*watched,QEvent*event);
    void mousePressEvent(QMouseEvent*event);
private slots:
       void topMessageBox_triggered();
       void messageNotDisturb_triggered();
private:
    void init();
    void initUi();
    void clicked();
    QString pictureName,name,messageText,statusText,messageTime;
Q_SIGNALS:
    void sigClicked(MMessageBox*);
    void sigTopMessge(MMessageBox*);
    void sigNotDisturb(MMessageBox*);
    void sigCancelTopMessage(MMessageBox*);
private:
    Ui::MMessageBox *ui;
    QMenu*menu;
    QAction*actTopMessageBox;//置顶聊天
    QAction*actRemoveMessageBox;//移除会话
    QAction*actMessageNotDisturb;//消息免打扰
    QAction*actPersonalInformation;//个人资料
    QAction*actCleanMessageRecord;//清空聊天记录
    QAction*actModifyFrinedNote;//修改好友备注
    bool isTopMessageBox;//是否置顶聊天
    bool isClick;//是否点击
    bool isNotDisturb;//是否开启免打扰
};
class MMessageBoxs: public QWidget{
        Q_OBJECT
public:
    MMessageBoxs();
   // MMessageBoxs(std::initializer_list<MMessageBox*>list);

   // void push_back(MMessageBox*messageBox);
    MMessageBox*at(int index);
   // void setLayout(QVBoxLayout*layout);
    QVBoxLayout* getLayout();
    QVBoxLayout* topMessageBox(MMessageBox*messageBox);
    QVBoxLayout* addMMessageBox(MMessageBox*messageBox);
    QVBoxLayout* cancelTopMessageBox(MMessageBox*messageBox);
    void setWidget(QWidget*widget);
    void setScrollArea(QScrollArea*scrollArea);
public slots:
       void messageBox_triggered(MMessageBox*);
       void topMessageBox_triggered(MMessageBox*);
       void cancelTopMessageBox_triggered(MMessageBox*);
private:
    QWidget*widget;
    QScrollArea*scrollArea;
    QVector<MMessageBox*>messageBoxs;
    QVBoxLayout*layout;
    MMessageBox*messageBoxClicked;
};

#endif // MMESSAGEBOX_H
