#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "mypushbutton.h"
#include <QPushButton>
#include <QString>
#include <QIcon>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();


    template <typename MyPushButton>
    /**
     * @brief setBtnUi  按钮UI的模板函数
     * @param btn       按钮对象
     * @param text      设置的文字
     * @param ax        关于x方向的位置，y方向默认为5
     */
    void setBtnUi(MyPushButton *btn, QString text, int ax, int ay, const char *iconPath, const char *code = "")
    {
        btn->setText(text);
        btn->setFixedSize(100, 30);
        btn->move(ax, ay);
        btn->setStyleSheet(QString::fromUtf8("QPushButton{ background: white; color: blacke; border: 2px solid black; border-radius:10px; padding:2px 4px; }"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(iconPath), QSize(), QIcon::Normal, QIcon::Off);
        btn->setIcon(icon);
        connect(btn, &MyPushButton::clicked, this, [=]()
        {
            emit sendCode(code);
            btn->zoomDown();
            btn->zoomUp();
        });
    }
signals:
    void sendCode(const char *code);

private:
    Ui::Widget *ui;

    MyPushButton *m_menuBtn;
    MyPushButton *m_homeBtn;
    MyPushButton *m_newBtn;
    MyPushButton *m_settingsBtn;
};
#endif // WIDGET_H
