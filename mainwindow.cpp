#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include "WarningBox.h"
#include "operationinterface.h"

//初始化静态成员变量-数据库是否连接
bool MainWindow::isConnectedMySQL = false;

//=================================================================================================================测试用代码
void TEST_connectMySQL()
{
    //连接数据库
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL"); //选择连接方式
    db.setHostName("localhost"); //主机名
    db.setPort(3306); //端口号
    db.setUserName("root"); //用户名
    db.setPassword("abcd1234"); //密码
    db.setDatabaseName("MovieTicktesManagementSystem"); //数据库名
    db.open(); //打开数据库
    if(!db.isOpen())
    {
        qDebug() << "数据库连接失败!";
    }
    else
    {
        qDebug() << "数据库连接成功!";
    }
}






MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //配置窗口信息
    this->setWindowTitle("电影票管理系统");
    this->setWindowIcon(QIcon(":res/movieTicket.png"));
    this->setFixedSize(QSize(1300, 750));


    //menuBar
    //设置-配置数据库
    connect(ui->actionSettingMySQL, &QAction::triggered, this, &MainWindow::onActionTriggered_showSettingMySQL);


    //账号密码lineEdit
    ui->lineEdit_userID->setFocus();

    //登入退出pushButton
    connect(ui->pushButton_Login, &QPushButton::clicked, this, &MainWindow::onPushButtonClicked_login);
    connect(ui->pushButton_Exit, &QPushButton::clicked, [=](){
        this->close();
        qDebug() << "已退出";
    });


}

MainWindow::~MainWindow()
{
    delete ui;

}

//设置-配置数据库
void MainWindow::onActionTriggered_showSettingMySQL()
{
    //设置配置数据库界面大小
    SettingMysql->setFixedSize(this->width() / 2, this->height() / 1.8);
    //定位配置数据库界面弹出位置
    SettingMysql->setGeometry(this->x() + (this->width() - SettingMysql->width()) / 2,
                              70 + this->y() + (this->height() - SettingMysql->height()) / 2,
                              SettingMysql->width(), SettingMysql->height());
    //阻塞其他窗口
    SettingMysql->setWindowModality(Qt::ApplicationModal);
    //显示配置界面
    SettingMysql->show();
}

//按钮-登录
void MainWindow::onPushButtonClicked_login()
{
    const QString uid = ui->lineEdit_userID->text();
    const QString passwd = ui->lineEdit_PassWord->text();
    //核对账号和密码
//    if (checkUserIdAndPassWord(uid, passwd))
    if (1) //=================================================================================================================测试用代码
    {
//        if (MainWindow::isConnectedMySQL)
        TEST_connectMySQL();
        if (1)//=================================================================================================================测试用代码
        {
            qDebug() << "登陆成功";
            showWarningMessage("登陆成功", QMessageBox::Information, "登陆成功");
            //隐藏本界面，打开后台
            this->hide();
            OperationInterface * opInterface = new OperationInterface;
            opInterface->show();
        }
        else
        {
            showWarningMessage("您还未链接数据库\n请前往 设置 - 配置数据库 进行配置");
        }
    }

}

bool MainWindow::checkUserIdAndPassWord(const QString uid, const QString passwd)
{
    //检测是否为空
    if (uid == NULL)
    {
        showWarningMessage("账号还未填写");
        return false;
    }
    else
    {
        if (passwd == NULL)
        {
            showWarningMessage("密码还未填写");
            return false;
        }
    }
    //检测密码是否正确
    if (uid == userID)
    {
        if (passwd != userPassWord)
        {
            showWarningMessage("账号或密码错误");
            return false;
        }
        else
        {
            return true;
        }
    }
    else
    {
        showWarningMessage("账号或密码错误");
        return false;
    }
}


