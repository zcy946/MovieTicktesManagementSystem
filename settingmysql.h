#ifndef SETTINGMYSQL_H
#define SETTINGMYSQL_H

#include <QWidget>

namespace Ui {
class SettingMySQL;
}

class SettingMySQL : public QWidget
{
    Q_OBJECT

public:
    explicit SettingMySQL(QWidget *parent = nullptr);
    ~SettingMySQL();

private:
    Ui::SettingMySQL *ui;
    //数据库信息
    QString hostName;
    QString port;
    QString userName;
    QString passWord;
    QString dataBaseName;

    //连接数据库
    void connectMySQL(const QString hostname, const QString port, const QString userName, const QString passWord, const QString dataBaseName);



private slots:
    //按钮-测试
    void onPushButtonClicked_connect();
    //按钮-保存
    void onPushButtonClicked_save();
};

#endif // SETTINGMYSQL_H
