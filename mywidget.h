#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QMouseEvent>

class MyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidget(QWidget *parent = nullptr);

protected:
    //重写鼠标点击事件
    void mouseMoveEvent(QMouseEvent *event) override;
signals:
    void clicked();
};

#endif // MYWIDGET_H
