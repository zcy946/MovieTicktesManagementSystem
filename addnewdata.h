#ifndef ADDNEWDATA_H
#define ADDNEWDATA_H

#include <QWidget>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QTableWidgetItem>
#include "WarningBox.h"

namespace Ui {
class AddNewData;
}

class AddNewData : public QWidget
{
    Q_OBJECT

public:
    explicit AddNewData(QString tableName, QWidget *parent = nullptr);
    ~AddNewData();

private:
    Ui::AddNewData *ui;
    //表名
    QString tableName;
    //水平表头
    QStringList horizontalHeaders;
    //列数
    int columnCount;
    //起始行数
    int rowCount;
    //增加行
    void addLine();
    //被选中的行号
    int clickedRowIndex;
    //初始化sql执行语句
    QSqlQuery query;
    //Movies表的插入语句
    bool insertToMovies(QTableWidgetItem* items[]);
signals:
    //有新增数据
    void newDataAdded();
private slots:
    //保存槽函数
    void save();

};

#endif // ADDNEWDATA_H
