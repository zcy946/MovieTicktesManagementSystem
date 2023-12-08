#include "addnewdata.h"
#include "ui_addnewdata.h"

AddNewData::AddNewData(QString tableName, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddNewData)
{
    ui->setupUi(this);
    //根据表名初始化数据
    this->tableName = tableName;
    if (!query.exec("SELECT * FROM " + tableName))
    {
        qDebug() << "查询失败：" << query.lastError().text();
        query.exec("ROLLBACK");
    }
    else
    {
        //记录水平表头
        for (int i = 0; i < query.record().count(); ++i)
        {
            this->horizontalHeaders.append(query.record().fieldName(i));
        }
        //设置列数
        this->columnCount = query.record().count();
        //设置行数
        this->rowCount = query.size();
        //必须设置列数，列数默认为 0
        ui->tableWidget->setColumnCount(this->columnCount);
        //设置表头
        ui->tableWidget->setHorizontalHeaderLabels(this->horizontalHeaders);
        //预先插入一行
        this->addLine();
    }




    //button功能区
    //添加
    connect(ui->label_add, &MyLabel::clicked, [=](){
        this->addLine();
    });

    //删除
    //获取当前选中单元格信息
    connect(ui->tableWidget, &QTableWidget::cellClicked, [=](int row){
        this->clickedRowIndex = row;
        //        qDebug() << "被点击单元格所属行：[" << row << "]";
        query.exec();
    });
    connect(ui->label_delete, &MyLabel::clicked, [=](){
        ui->tableWidget->removeRow(this->clickedRowIndex);
    });

    //保存
    connect(ui->label_save, &MyLabel::clicked, this, &AddNewData::save);

//    //--------------------------------------------------------------------------------------测试
//    connect(ui->pushButton_test, &QPushButton::clicked, [=](){

//    });
}

AddNewData::~AddNewData()
{
    delete ui;
}

//增加行
void AddNewData::addLine()
{
    //获取当前行数
    int row = ui->tableWidget->rowCount();
    //插入新的一行
    ui->tableWidget->insertRow(row);
    for (int col = 0; col < this->columnCount; col++)
    {
        //创建item并填入数据
        QTableWidgetItem *item = new QTableWidgetItem();
        item->setText("");
        if (col == 0)
        {
            item->setText(QString::number(++rowCount));
        }
        //设置内容水平居中和垂直居中
        item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        //根据单双数设置item的背景颜色
        if (rowCount % 2 != 0)
        {
            item->setBackground(QBrush(QColor(222, 235, 246)));
        }
        //插入item
        ui->tableWidget->setItem(row, col, item);
    }
}


//保存槽函数
void AddNewData::save()
{
    bool isSave = false;
    QTableWidgetItem *items[this->columnCount];
    for (int row = 0; row < ui->tableWidget->rowCount(); row++)
    {
        for (int col = 0; col < columnCount; col++)
        {
           items[col] = ui->tableWidget->item(row, col);
        }
        //根据表名选择对应的插入函数
        if (this->tableName == "Movies")
        {
            isSave = this->insertToMovies(items);
        }
        else if (this->tableName == "")
        {

        }
    }
    if(isSave)
    {
        showWarningMessage("保存成功", QMessageBox::Information, "消息", ":res/addNewData.png");
        //插入完成就将表格清空
        ui->tableWidget->setRowCount(0);
        emit this->newDataAdded();
    }
}

//Movies表的插入语句
bool AddNewData::insertToMovies(QTableWidgetItem* items[])
{
    query.prepare("INSERT INTO Movies (MovieID, MovieName, ReleaseDate, Duration, Director, Genre) VALUES (:MovieID, :MovieName, :ReleaseDate, :Duration, :Director, :Genre);");
    query.bindValue(":MovieID", items[0]->text().toInt());
    query.bindValue(":MovieName", items[1]->text());
    query.bindValue(":ReleaseDate", items[2]->text());
    query.bindValue(":Duration", items[3]->text().toInt());
    query.bindValue(":Director", items[4]->text());
    query.bindValue(":Genre", items[5]->text());
    if(!query.exec())
    {
        qDebug() << "插入失败" << query.lastError().text();
        showWarningMessage(query.lastError().text().toUtf8().constData(), QMessageBox::Critical, "插入失败", ":res/addNewData.png");
        query.exec("ROLLBACK");
        return false;
    }
    else
    {
        qDebug() << "已成功保存到Movies表";
        return true;
    }
}
