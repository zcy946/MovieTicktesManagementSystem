#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "settingmysql.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

//此处设置管理员账号和密码，也可自行从数据库获取
//账号
const QString userID = "admin";
//密码
const QString userPassWord = "admin";


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //初始化MySQL配置界面
    SettingMySQL * SettingMysql = new SettingMySQL;
    //数据库是否连接
    static bool isConnectedMySQL;
private:
    Ui::MainWindow *ui;
    //核对账号和密码
    bool checkUserIdAndPassWord(const QString uid, const QString passwd);


private slots:
    //设置-配置数据库
    void onActionTriggered_showSettingMySQL();
    //按钮-登录
    void onPushButtonClicked_login();
};
#endif // MAINWINDOW_H
