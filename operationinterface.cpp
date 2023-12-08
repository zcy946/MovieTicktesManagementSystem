#include "operationinterface.h"
#include "ui_operationinterface.h"
#include <QBitmap>
#include <QDebug>
#include <QPixmap>
#include "mainwindow.h"
#include "mylabel.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include "mylineedit.h"

OperationInterface::OperationInterface(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OperationInterface)
{
    ui->setupUi(this);
    //设置窗口信息
    this->setWindowTitle("电影售票管理系统");
    this->setWindowIcon(QIcon(":/res/operationinterface.png"));
    this->setMinimumSize(1300, 750);

    //设置全局字体
    this->setStyleSheet("* {font-family: 微软雅黑;}");
    //设置背景颜色
    this->setStyleSheet("QWidget {background-color: #f9faff;}");

    //设置默认stackWidget界面
    ui->stackedWidget->setCurrentIndex(0);
    

    //sideBar
    //label-头像
    ui->label_userPhoto->setGeometry(10, 20, 100 , 100);
    //加载头像
    QPixmap pix;
    pix.load(":res/icon2.png");
    //拉伸图片
    pix = pix.scaled(ui->label_userPhoto->width(), ui->label_userPhoto->height(), Qt::KeepAspectRatio);
    //填充图片
    ui->label_userPhoto->setPixmap(pix);

    //label-userId & label-userGroup
    ui->label_userID->setGeometry(10, 20 + 100, 100, 30);
    ui->label_userGroup->setGeometry(10, 20 + 100 + 30 * 1, 100, 30);
    ui->label_userID->setText(QString(userID));
    if (ui->label_userID->text() == "admin")
    {
        ui->label_userGroup->setText("@管理员");
    }
    else
    {
        ui->label_userGroup->setText("@游客");
    }
    ui->label_userID->setStyleSheet("QLabel {font-family: 微软雅黑;"
                                    "font-size: 20px;}");
    ui->label_userGroup->setStyleSheet("QLabel {font-family: 微软雅黑;"
                                    "font-size: 18px;}");

    //label_btn
    QString label_btn_style = "QLabel {background-color: #4c86eb;"
                              "font-family: 微软雅黑;"
                              "font-size: 23px;}"
                              "QLabel:hover {background-color: #4074dd;}";
    ui->label_btnToPg1->setGeometry(0, 20 + 100 + 30 * 2, 120, 70);
    ui->label_btnToPg1->setStyleSheet(label_btn_style);
    ui->label_btnToPg1->setCursor(Qt::PointingHandCursor);
    ui->label_btnToPg1->setText("电影表");
    ui->label_btnToPg2->setGeometry(0, 20 + 100 + 30 * 2 + 70 * 1, 120, 70);
    ui->label_btnToPg2->setStyleSheet(label_btn_style);
    ui->label_btnToPg2->setCursor(Qt::PointingHandCursor);
    ui->label_btnToPg2->setText("影院表");
    ui->label_btnToPg3->setGeometry(0, 20 + 100 + 30 * 2 + 70 * 2, 120, 70);
    ui->label_btnToPg3->setStyleSheet(label_btn_style);
    ui->label_btnToPg3->setCursor(Qt::PointingHandCursor);
    ui->label_btnToPg3->setText("放映厅表");
    ui->label_btnToPg4->setGeometry(0, 20 + 100 + 30 * 2 + 70 * 3, 120, 70);
    ui->label_btnToPg4->setStyleSheet(label_btn_style);
    ui->label_btnToPg4->setCursor(Qt::PointingHandCursor);
    ui->label_btnToPg4->setText("场次表");
    ui->label_btnToPg5->setGeometry(0, 20 + 100 + 30 * 2 + 70 * 4, 120, 70);
    ui->label_btnToPg5->setStyleSheet(label_btn_style);
    ui->label_btnToPg5->setCursor(Qt::PointingHandCursor);
    ui->label_btnToPg5->setText("订单表");

    //label_btn功能实现
    //点击后跳转对应的页数,更新选中状态
    connect(ui->label_btnToPg1, &MyLabel::clicked, [=](){
        ui->stackedWidget->setCurrentIndex(0);
    });
    connect(ui->label_btnToPg2, &MyLabel::clicked, [=](){
        ui->stackedWidget->setCurrentIndex(1);
    });
    connect(ui->label_btnToPg3, &MyLabel::clicked, [=](){
        ui->stackedWidget->setCurrentIndex(2);
    });
    connect(ui->label_btnToPg4, &MyLabel::clicked, [=](){
        ui->stackedWidget->setCurrentIndex(3);
    });
    connect(ui->label_btnToPg5, &MyLabel::clicked, [=](){
        ui->stackedWidget->setCurrentIndex(4);
    });



    //widget_search
    ui->widget_search->setGeometry(10, 10, 500 - 40, 50);
    ui->widget_search->setStyleSheet("QWidget {border:1px solid #8cb8fa;"
                                     "border-radius: 5px;"
                                     "}");
    //label_search
    ui->label_search->setGeometry(5, 5, 40, 40);
    ui->label_search->setStyleSheet("QLabel {border: none;"
                                    "}");
    ui->label_search->setCursor(Qt::PointingHandCursor);
    //加载图标
    pix.load(":res/search.png");
    pix = pix.scaled(ui->label_search->width() / 2, ui->label_search->height() / 2, Qt::KeepAspectRatio);
    ui->label_search->setPixmap(pix);

    //lineEdit_search
    ui->lineEdit_search->setGeometry(5 + 40, 5, ui->widget_search->width() - ui->label_search->width() - 5 - 5 - 40 - 80 - 50, 40);
    ui->lineEdit_search->setStyleSheet("QLineEdit {border: none;"
                                       "color: #697789;"
                                       "font-family: 微软雅黑;}");
    ui->lineEdit_search->setText("Search");
    //comboBox
    ui->comboBox->setGeometry(45 + 270, 0, ui->widget_search->width() - 45 - 270, 50);
    ui->comboBox->setStyleSheet("QComboBox {"
                                "background-color: #4c82eb;"
                                "border: none;"
                                "border-radius: none;"
                                "color: white;"
                                "font-family: 微软雅黑;"
                                "font-size: 20px;"
                                "}");

    //点击搜索框时，清空
    connect(ui->lineEdit_search, &MyLineEdit::clicked, [=](){
        if (ui->lineEdit_search->text() == "Search")
        {
            ui->lineEdit_search->setText("");
            ui->lineEdit_search->setStyleSheet("QLineEdit {border: none;"
                                               "color: black;"
                                               "font-family: 微软雅黑;}");
        }
    });
    //搜索框为空时点出搜索框，添加文字 Search
    connect(ui->lineEdit_search, &MyLineEdit::focusOut, [=](){
        if (ui->lineEdit_search->text() == NULL)
        {
            ui->lineEdit_search->setText("Search");
            ui->lineEdit_search->setStyleSheet("QLineEdit {border: none;"
                                               "color: #697789;"
                                               "font-family: 微软雅黑;}");
        }
    });
    //按下回车开始搜索
    connect(ui->lineEdit_search, &QLineEdit::returnPressed, [=](){
        if (ui->lineEdit_search->text() != NULL)
        {
            qDebug() << "开始搜索";
            //搜索
            this->search("Movies", ui->comboBox->currentText(), ui->lineEdit_search->text());
        }
    });


    //按钮功能区
    //label_update
    ui->label_update->setCursor(Qt::PointingHandCursor);
    connect(ui->label_update, &MyLabel::clicked, [=](){
        this->updateTableWidget("Movies");
//        showWarningMessage("刷新成功", QMessageBox::Information, "消息");
    });
    //label_add
    //改变样式为手
    ui->label_add->setCursor(Qt::PointingHandCursor);
    connect(ui->label_add, &MyLabel::clicked, [=](){
        this->addNewData();
    });
    //label_delete
    //改变样式为手
    ui->label_delete->setCursor(Qt::PointingHandCursor);
    //获取当前选中单元格信息
    connect(ui->tableWidget, &QTableWidget::cellClicked, [=](int row){
        qDebug() << "被点击单元格所属行：[" << row << "]";
        this->itemClicked = ui->tableWidget->item(row, 0);
        query.exec();
    });
    //在数据库中删除当前行
    connect(ui->label_delete, &MyLabel::clicked, [=](){
        this->deleteDate("Movies");
        this->updateTableWidget("Movies");
    });

    //label_save
    //改变样式为手
    ui->label_save->setCursor(Qt::PointingHandCursor);
    connect(ui->label_save, &MyLabel::clicked, [=](){
        this->saveChangedData(ui->tableWidget, "Movies", ui->tableWidget->rowCount(), ui->tableWidget->columnCount());
        this->updateTableWidget("Movies");
        showWarningMessage("保存成功", QMessageBox::Information, "消息");
    });



    //stackedWidget
    //tableWidget
    //由数据库获取数据
    this->updateTableWidget("Movies");
}

OperationInterface::~OperationInterface()
{
    delete ui;
}

//重写resizeEvent事件
void OperationInterface::resizeEvent(QResizeEvent *event)
{
    //屏蔽未使用变量警告
    Q_UNUSED(event);
    //实时更改sideBar
    ui->widget_SideBar->setGeometry(0, 0, 120, this->height());
    ui->widget_SideBar->setStyleSheet("QWidget {background-color: #4c86eb;"
                                      "color: #ffffff;}");
    //实时更改stackedWidget大小
    ui->stackedWidget->setGeometry(130, 0, this->width() - ui->widget_SideBar->width(), this->height());
//    ui->stackedWidget->setStyleSheet("QStackedWidget { background-color:  #282c34; }");
    //实时更改tableWidget的大小
    ui->tableWidget->setGeometry(10, 10 + 100, this->width() - ui->widget_SideBar->width() - 40, ui->stackedWidget->height() - 130);
    ui->tableWidget->setStyleSheet("QTableWidget { border: 1px solid #4c86eb;"
                                   "background-color: #ffffff;}");

    //实时更改widget_operate的大小
    ui->widget_operate->setGeometry(10, 25, this->width() - 160, 70);
    ui->widget_operate->setStyleSheet("QWidget { background-color: #ffffff;"
                                      "border:1px solid #4c86eb;}");

    //实时更改label_update位置
    ui->label_update->setGeometry(ui->widget_operate->width() - 150 * 4 - 10 * 4, 10, 150, ui->widget_search->height());
    ui->label_update->setStyleSheet("QLabel {border: none;"
                                 "border-radius: 5px;"
                                 "background-color: #4c82eb;"
                                 "font-family: 微软雅黑;"
                                 "color: #ffffff;"
                                 "font-size: 22px;}"
                                 "QLabel:hover {background-color: #4074dd;}");

    //实时更改label_add位置
    ui->label_add->setGeometry(ui->widget_operate->width() - 150 * 3 - 10 * 3, 10, 150, ui->widget_search->height());
    ui->label_add->setStyleSheet("QLabel {border: none;"
                                 "border-radius: 5px;"
                                 "background-color: #4c82eb;"
                                 "font-family: 微软雅黑;"
                                 "color: #ffffff;"
                                 "font-size: 22px;}"
                                 "QLabel:hover {background-color: #4074dd;}");

    //实时更改label_delete
    ui->label_delete->setGeometry(ui->widget_operate->width() - 150 * 2 - 10 * 2, 10, 150, ui->widget_search->height());
    ui->label_delete->setStyleSheet("QLabel {border: none;"
                                 "border-radius: 5px;"
                                 "background-color: #4c82eb;"
                                 "font-family: 微软雅黑;"
                                 "color: #ffffff;"
                                 "font-size: 22px;}"
                                 "QLabel:hover {background-color: #4074dd;}");
    //实时更改label_save
    ui->label_save->setGeometry(ui->widget_operate->width() - 150 * 1 - 10 * 1, 10, 150, ui->widget_search->height());
    ui->label_save->setStyleSheet("QLabel {border: none;"
                                 "border-radius: 5px;"
                                 "background-color: #4c82eb;"
                                 "font-family: 微软雅黑;"
                                 "color: #ffffff;"
                                 "font-size: 22px;}"
                                 "QLabel:hover {background-color: #4074dd;}");

}

//查询
void OperationInterface::search(QString tableName, QString selectedText, QString info)
{
    this->query.clear();
    query.prepare("SELECT * FROM " + tableName + " WHERE " + selectedText + " = :info;");
    if (selectedText == "MovieID" || selectedText == "Duration")
    {
        this->query.bindValue(":info", info.toInt());
    }
    else
    {
        this->query.bindValue(":info", info);
    }
    if (!this->query.exec())
    {
        qDebug() << "查找失败：" << query.lastError().text();
        query.exec("ROLLBACK");
        showWarningMessage(query.lastError().text().toUtf8().constData());
    }
    else
    {
        qDebug() << "查找成功";
        //改变表
        ui->tableWidget->setRowCount(0);
        QSqlRecord record = query.record();
        //把水平表头放入list容器
        QStringList lineHeaders;
        for (int i = 0; i < record.count(); i++)
        {
            lineHeaders.append(record.fieldName(i));
        }
        //设置列数和表头标签
        ui->tableWidget->setColumnCount(record.count());
        ui->tableWidget->setHorizontalHeaderLabels(lineHeaders);
        while (query.next())
        {
            //获取当前行数
            int row = ui->tableWidget->rowCount();
            //插入新的一行
            ui->tableWidget->insertRow(row);
            for (int col = 0; col < query.record().count(); col++)
            {
                //创建item并填入数据
                QTableWidgetItem *item = new QTableWidgetItem(query.value(col).toString());
                //设置内容水平居中和垂直居中
                item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
                //根据单双数设置item的背景颜色
                if (row % 2 == 0)
                {
                    item->setBackground(QBrush(QColor(222, 235, 246)));
                }
                //插入item
                ui->tableWidget->setItem(row, col, item);
            }
        }
        qDebug() << "查找数据已显示";
    }
}

//更新表
void OperationInterface::updateTableWidget(QString tableName)
{
    // 清除所有行，包括表头
    ui->tableWidget->setRowCount(0);
    this->query.clear();
    query.prepare("SELECT * FROM "+ tableName);
    if (!query.exec())
    {
        qDebug() << "查询失败：" << query.lastError().text();
        query.exec("ROLLBACK");
    }
    else
    {
        QSqlRecord record = query.record();
        //把水平表头放入list容器
        QStringList lineHeaders;
        for (int i = 0; i < record.count(); i++)
        {
            lineHeaders.append(record.fieldName(i));
        }
        //隐藏垂直表头
        ui->tableWidget->verticalHeader()->setVisible(false);
        //设置列数和表头标签
        ui->tableWidget->setColumnCount(record.count());
        ui->tableWidget->setHorizontalHeaderLabels(lineHeaders);
        while (query.next())
        {
            //获取当前行数
            int row = ui->tableWidget->rowCount();
            //插入新的一行
            ui->tableWidget->insertRow(row);
            for (int col = 0; col < query.record().count(); col++)
            {
                //创建item并填入数据
                QTableWidgetItem *item = new QTableWidgetItem(query.value(col).toString());
                //设置内容水平居中和垂直居中
                item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
                //根据单双数设置item的背景颜色
                if (row % 2 == 0)
                {
                    item->setBackground(QBrush(QColor(222, 235, 246)));
                }
                //插入item
                ui->tableWidget->setItem(row, col, item);
            }
        }
    }
    qDebug() << "更新" + tableName + "表成功";
}

//保存修改
void OperationInterface::saveChangedData(QTableWidget * tableWidgetName, QString tableName, int rowCount, int colCount)
{
    for (int row = 0; row < rowCount; row++)
    {
        for (int col = 0; col < colCount; col++)
        {
            item = tableWidgetName->item(row, col);
            if (col == 0)
            {
                ID = item->text().toInt();
                ThingID = tableWidgetName->horizontalHeaderItem(col)->text();
            }
            if (item != nullptr)
            {
                //获取新数据
                newDataHeaderText = tableWidgetName->horizontalHeaderItem(col)->text();
                newData = item->text();

                query.prepare("UPDATE " + tableName + " SET " + newDataHeaderText + " = :newData WHERE " + ThingID + " = :ID;");
                query.bindValue(":ID", ID);
                query.bindValue(":newData", newData);
                if (query.exec())
                {
                    qDebug() << "[" << row << "," << col << "]" << "保存成功";
                }
                else
                {
                    qDebug() << "保存失败：" << query.lastError().text();
                    query.exec("ROLLBACK");
                }
            }
        }
    }
}

//新增
void OperationInterface::addNewData()
{
    AddNewData * addNewDataWindow = new AddNewData("Movies");
    //阻塞其他窗口
    addNewDataWindow->setWindowModality(Qt::ApplicationModal);
    addNewDataWindow->move(this->x(), this->y());
    addNewDataWindow->show();
    //每次新增完毕之后更新当前表
    connect(addNewDataWindow, &AddNewData::newDataAdded, [=](){
        this->updateTableWidget("Movies");
    });
}

//删除
void OperationInterface::deleteDate(QString tableName)
{
    query.clear();
    if (tableName == "Movies")
    {
        query.prepare("DELETE FROM Movies WHERE MovieID = :MovieID;");
        query.bindValue(":MovieID", this->itemClicked->text().toInt());
        if (query.exec())
        {
            qDebug() << "已成功删除Movies表中的MoviesID为" << this->itemClicked->text().toInt() << "的数据";
        }
        else
        {
            qDebug() << "删除失败：" << query.lastError().text();
            query.exec("ROLLBACK");
            showWarningMessage(query.lastError().text().toUtf8().constData());
        }

    }
}

/////////////////////////////////////////////////////////////////////////////////////////////未使用↓
//增加行
void OperationInterface::addLine(int columnNum)
{
    //获取当前行数
    int row = ui->tableWidget->rowCount();
    //插入新的一行
    ui->tableWidget->insertRow(row);
    for (int col = 0; col < columnNum; col++)
    {
        //创建item并填入数据
        QTableWidgetItem *item = new QTableWidgetItem();
        if (col == 0)
        {
            item->setText(QString::number(row + 1));
        }
        //设置内容水平居中和垂直居中
        item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        //根据单双数设置item的背景颜色
        if ((row + 1) % 2 != 0)
        {
            item->setBackground(QBrush(QColor(222, 235, 246)));
        }
        //插入item
        ui->tableWidget->setItem(row, col, item);
    }
}

//待定
//void OperationInterface::saveData2(int rowCount, int colCount, QString TABLE)
//{
//    //删表-创表-插入
//    //删表
//    query.prepare("DROP TABLE " + TABLE + ";");
//    if (query.exec())
//    {
//        qDebug() << "已删除表：[" << TABLE << "]";
//    }
//    else
//    {
//        qDebug() << "删除表：[" << TABLE << "] 失败：" << query.lastError().text();
//        query.exec("ROLLBACK");
//    }
//    //创建表
//    this->createTable(TABLE);
//    //遍历表格-插入数据

//}


//创建Movies表
void OperationInterface::createTable(QString tableName)
{
    if (tableName == "Movies")
    {
        query.prepare("CREATE TABLE Movies ( "
                      "MovieID INT PRIMARY KEY, "
                      "MovieName VARCHAR(255) NOT NULL, "
                      "ReleaseDate DATE, "
                      "Duration INT, "
                      "Director VARCHAR(255), "
                      "Genre VARCHAR(255) "
                      ");");
        if (query.exec())
        {
            qDebug() << "创建" << tableName << "表成功";
        }
        else
        {
            qDebug() << "创建" << tableName << "表失败：" << query.lastError().text();
            query.exec("ROLLBACK");
        }
    }
}

////遍历
//void OperationInterface::readData(int rowCount, int colCount, QString TABLE)////////////////////////////////////////////////BUG
//{
//    for (int row = 0; row < rowCount; ++row)
//    {
//        for (int col = 0; col < colCount; ++col)
//        {
//            QTableWidgetItem *item = ui->tableWidget->item(row, col);
//            if (col == 0)
//            {
//                ID = item->text().toInt();
//                ThingID = ui->tableWidget->horizontalHeaderItem(col)->text();
//            }
//            if (item != nullptr)
//            {
//                //获取新数据
//                newDataHeaderText = ui->tableWidget->horizontalHeaderItem(col)->text();
//                newData = item->text();

//                query.prepare("UPDATE " + TABLE + " SET " + newDataHeaderText + " = :newData WHERE " + ThingID + " = :ID;");
//                query.bindValue(":ID", ID);
//                query.bindValue(":newData", newData);
//                if (query.exec())
//                {
//                    qDebug() << "[" << row << "," << col << "]" << "更新/保存成功";
//                }
//                else
//                {
//                    qDebug() << "更新/保存失败：" << query.lastError().text();
//                    query.exec("ROLLBACK");
//                }
//            }
//        }
//    }
//}
