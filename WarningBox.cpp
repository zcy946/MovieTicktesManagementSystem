#include "WarningBox.h"
#include <QMessageBox>
#include <QIcon>

//弹出提示对话框
void showWarningMessage(const char * warningText, QMessageBox::Icon iconType, QString windowTitle, QString icon)
{
    QMessageBox warningBox;
    warningBox.setIcon(iconType);
    warningBox.setWindowTitle(windowTitle);
    warningBox.setWindowIcon(QIcon(icon));
    warningBox.setText(warningText);
    warningBox.addButton("确定", QMessageBox::AcceptRole);
    warningBox.resize(350, 190);
    warningBox.exec();
}
