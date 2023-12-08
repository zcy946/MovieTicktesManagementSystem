#include "mylineedit.h"
#include <QDebug>

MyLineEdit::MyLineEdit(QWidget *parent) : QLineEdit(parent)
{

}

//重写鼠标点击事件
void MyLineEdit::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        emit clicked();
    }
    else
    {
        //抛给父类处理
        QLineEdit::mousePressEvent(event);
    }
}

//重写失去焦点事件
void MyLineEdit::focusOutEvent(QFocusEvent *event)
{
    emit focusOut();
    QLineEdit::focusOutEvent(event);
}
