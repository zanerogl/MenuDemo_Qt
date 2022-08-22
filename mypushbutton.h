#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QToolButton>
#include <QDebug>
#include <QPropertyAnimation>

class MyPushButton : public QPushButton //自定义按钮类
{
    Q_OBJECT
public:
    explicit MyPushButton(QWidget *parent = nullptr);

    /**
     * @brief SetIcon   设置按钮的图标路径，图标尺寸
     * @param imgPath   图片路径
     * @param imgSize   图片尺寸
     * @return          返回状态，设置成功为true否则为false
     */
    bool SetIcon(QString imgPath, QSize imgSize);

    /**
     * @brief zoomDown  设置按钮动作，按下。
     */
    void zoomDown();

    /**
     * @brief zoomUp    设置按钮动作，弹起。
     */
    void zoomUp();

private:
    QString m_iconPath;
signals:

};

#endif // MYPUSHBUTTON_H
