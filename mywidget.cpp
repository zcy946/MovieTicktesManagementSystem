#include "mywidget.h"

MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{

}

//重写鼠标点击事件
void MyWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        emit clicked();
    }
    //把其余的事件抛出
    QWidget::mousePressEvent(event);
}
