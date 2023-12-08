#include "settingmysql.h"
#include "ui_settingmysql.h"
#include <QIcon>
#include <QtDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "mainwindow.h"
#include <QMessageBox>
#include "WarningBox.h"

SettingMySQL::SettingMySQL(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingMySQL)
{
    ui->setupUi(this);
    //配置窗口信息
    this->setWindowTitle("连接数据库");
    this->setWindowIcon(QIcon(":res/dataBase.png"));
//    //lable
//    this->setStyleSheet("QLabel { qproperty-alignment: AlignCenter; "
//                        "min-width: 100px; max-width: 100px; "
//                        "min-height: 30px; max-height: 30px; "
//                        "font-size: 20px; "
//                        "font-family: 微软雅黑;}");
//    ui->label_HostName->move((this->width() - ui->lineEdit_HostName->width() + ui->label_HostName->width()) / 2, 100);
//    ui->label_Port->move((this->width() - ui->lineEdit_HostName->width() + ui->label_HostName->width()) / 2, 140);
//    ui->label_userName->move((this->width() - ui->lineEdit_HostName->width() + ui->label_HostName->width()) / 2, 180);
//    ui->label_passWord->move((this->width() - ui->lineEdit_HostName->width() + ui->label_HostName->width()) / 2, 220);
//    ui->label_DataBaseName->move((this->width() - ui->lineEdit_HostName->width() + ui->label_HostName->width()) / 2, 260);
//    //lineEdit
//    ui->lineEdit_HostName->setFixedSize(170, 30);
//    ui->lineEdit_HostName->setFocus();
//    ui->lineEdit_Port->setFixedSize(170, 30);
//    ui->lineEdit_userName->setFixedSize(170, 30);
//    ui->lineEdit_passWord->setFixedSize(170, 30);
//    ui->lineEdit_passWord->setEchoMode(QLineEdit::Password);
//    ui->lineEdit_DataBaseName->setFixedSize(170, 30);
//    ui->lineEdit_HostName->move((this->width() - ui->lineEdit_HostName->width() + ui->label_HostName->width()) / 2 + 150, 100);
//    ui->lineEdit_Port->move((this->width() - ui->lineEdit_HostName->width() + ui->label_HostName->width()) / 2 + 150, 140);
//    ui->lineEdit_userName->move((this->width() - ui->lineEdit_HostName->width() + ui->label_HostName->width()) / 2 + 150, 180);
//    ui->lineEdit_passWord->move((this->width() - ui->lineEdit_HostName->width() + ui->label_HostName->width()) / 2 + 150, 220);
//    ui->lineEdit_DataBaseName->move((this->width() - ui->lineEdit_HostName->width() + ui->label_HostName->width()) / 2 + 150, 260);
//    //button
//    ui->pushButton_Connect->setFixedSize(75, 40);
//    ui->pushButton_Confirm->setFixedSize(75, 40);
//    ui->pushButton_Connect->move(230, 310);
//    ui->pushButton_Confirm->move(230 + 75 + 50, 310);
    connect(ui->pushButton_Connect, &QPushButton::clicked, this, &SettingMySQL::onPushButtonClicked_connect);
    connect(ui->pushButton_Confirm, &QPushButton::clicked, this, &SettingMySQL::onPushButtonClicked_save);



}

SettingMySQL::~SettingMySQL()
{
    delete ui;
}

//按钮-测试
void SettingMySQL::onPushButtonClicked_connect()
{
    this->hostName = ui->lineEdit_HostName->text();
    this->port = ui->lineEdit_Port->text();
    this->userName = ui->lineEdit_userName->text();
    this->passWord = ui->lineEdit_passWord->text();
    this->dataBaseName = ui->lineEdit_DataBaseName->text();
    if (hostName == NULL || port == NULL || userName == NULL || port == NULL || passWord == NULL || dataBaseName == NULL)
    {
        showWarningMessage("信息不全，连接失败");
        return;
    }
    this->connectMySQL(hostName, port, userName, passWord, dataBaseName);
}

//按钮-保存
void SettingMySQL::onPushButtonClicked_save()
{
    if (MainWindow::isConnectedMySQL)
    {
       this->close();
    }
    else
    {
        //弹出提示框
        showWarningMessage("您还未成功连接数据库");
    }
    //文件读写部分
//    待
//    完
//    成
}

//连接数据库
void SettingMySQL::connectMySQL(const QString hostname, const QString port, const QString userName, const QString passWord, const QString dataBaseName)
{
    //连接数据库
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName(hostname);
    db.setPort(port.toInt());
    db.setUserName(userName);
    db.setPassword(passWord);
    db.setDatabaseName(dataBaseName);
    db.open();
    if(db.isOpen())
    {
        qDebug() << "连接成功!";
        MainWindow::isConnectedMySQL = true;
        showWarningMessage("登陆成功", QMessageBox::Information, "连接成功");
    }
    else
    {
        qDebug() << "连接失败!";
    }
}
