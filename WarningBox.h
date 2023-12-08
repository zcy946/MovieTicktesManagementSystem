#ifndef WAININGBOX_H
#define WAININGBOX_H
#include <QString>
#include <QMessageBox>

//弹出提示对话框
void showWarningMessage(const char * warningText, QMessageBox::Icon iconType = QMessageBox::Critical, QString windowTitle = "警告", QString icon = ":res/message.png");

#endif // WAININGBOX_H

/*
Qt 中的 QMessageBox 提供了不同类型的消息框，除了 QMessageBox::Critical，还有以下几种类型：

QMessageBox::Information：用于显示一般性的信息。通常用于提供一些正常操作的提示。
QMessageBox::information(parent, "标题", "信息内容");

QMessageBox::Warning：用于显示警告信息。通常用于提醒用户可能会导致问题的操作。
QMessageBox::warning(parent, "标题", "警告内容");

QMessageBox::Question：用于询问用户是否执行某个操作。通常用于需要用户确认的情况。
QMessageBox::question(parent, "标题", "询问内容", QMessageBox::Yes | QMessageBox::No);

QMessageBox::NoIcon：不显示图标的消息框，只显示文本信息。
QMessageBox::critical(parent, "标题", "错误内容", QMessageBox::NoIcon);
*/
