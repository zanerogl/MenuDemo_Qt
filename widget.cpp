#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setFixedSize(120, 600);

    m_menuBtn = new MyPushButton(this);
    setBtnUi(m_menuBtn, "Menu", this->width()/2-m_menuBtn->width()/2, 20, ":/res/menu_icon.png");
    m_homeBtn = new MyPushButton(this);
    setBtnUi(m_homeBtn, "Home", this->width()/2-m_menuBtn->width()/2, 70, ":/res/home_icon.png");
    m_newBtn = new MyPushButton(this);
    setBtnUi(m_newBtn, "New", this->width()/2-m_menuBtn->width()/2, 120, ":/res/newProject.png");
    m_settingsBtn = new MyPushButton(this);
    setBtnUi(m_settingsBtn, "Settings", this->width()/2-m_menuBtn->width()/2, 170, ":/res/settings_icon.png");
}

Widget::~Widget()
{
    delete ui;
}

