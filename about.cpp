#include "about.h"
#include "ui_about.h"

About::About(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::About)
{
    ui->setupUi(this);
    //超链接
    //启用外部链接
    ui->label_6->setOpenExternalLinks(true);
    //设置文本交互标志
    ui->label_6->setTextInteractionFlags(Qt::TextBrowserInteraction);
    ui->label_6->setText("<a href='https://github.com/zcy946/MovieTicktesManagementSystem' style='text-decoration:none'>项目开源地址-电影售票管理系统</a>");

    ui->label_8->setOpenExternalLinks(true);
    ui->label_8->setTextInteractionFlags(Qt::TextBrowserInteraction);
    ui->label_8->setText("<a href='https://github.com/zcy946' style='text-decoration:none'>夏黎辰</a>");
}

About::~About()
{
    delete ui;
}
