#ifndef MYLINEEDIT_H
#define MYLINEEDIT_H

#include <QLineEdit>
#include <QMouseEvent>

class MyLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit MyLineEdit(QWidget *parent = nullptr);

signals:
    void clicked();
    void focusOut();
protected:
    //重写鼠标点击事件
    void mousePressEvent(QMouseEvent *event) override;
    //重写失去焦点事件
    void focusOutEvent(QFocusEvent *event) override;

};

#endif // MYLINEEDIT_H
