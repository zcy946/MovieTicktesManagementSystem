#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>
#include <QMouseEvent>

class MyLabel : public QLabel
{
    Q_OBJECT
public:
    explicit MyLabel(QWidget *parent = nullptr);

protected:
    //重写鼠标点击事件
    void mousePressEvent(QMouseEvent *event) override;

signals:
    void clicked();

};

#endif // MYLABEL_H
