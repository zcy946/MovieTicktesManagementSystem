#ifndef OPERATIONINTERFACE_H
#define OPERATIONINTERFACE_H

#include <QMainWindow>
#include <QSqlQuery>
#include <QTableWidget>
#include "addnewdata.h"

namespace Ui {
class OperationInterface;
}

class OperationInterface : public QMainWindow
{
    Q_OBJECT

public:
    explicit OperationInterface(QWidget *parent = nullptr);
    ~OperationInterface();

private:
    Ui::OperationInterface *ui;
    //重写resizeEvent事件
    void resizeEvent(QResizeEvent *event);

    //初始化query
    QSqlQuery query;
    //数据库操作变量
    int ID;
    QString ThingID;
    QString newDataHeaderText;
    QString newData;
    QTableWidgetItem *item;
    QTableWidgetItem *itemClicked;

    //保存修改
    void saveChangedData(QTableWidget * tableWidgetName, QString tableName, int rowCount, int colCount);
    //删除
    void deleteDate(QString tableName);
    //新增
    void addNewData();
    //查询
    void search(QString tableName, QString selectedText, QString info);
    //更新表
    void updateTableWidget(QString tableName);

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //增加行
    void addLine(int colNum);
    //创建表
    void createTable(QString tableName);
    //待定
    void saveData2(int rowCount, int colCount, QString TABLE);
//    //遍历
//    void readData(int rowCount, int columnCount, QString TABLE = NULL);
};

#endif // OPERATIONINTERFACE_H
