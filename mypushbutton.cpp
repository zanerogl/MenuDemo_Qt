#include "mypushbutton.h"

MyPushButton::MyPushButton(QWidget *parent) : QPushButton(parent)
{

}


bool MyPushButton::SetIcon(QString imgPath, QSize imgSize)
{
    bool ifsucceed;
    m_iconPath = imgPath;
    QPixmap pix;
    if(!pix.load(imgPath) ){
        qDebug()<<"Error! Failed to load normal image";
        ifsucceed = false;
    }
    else {
//        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIconSize(imgSize);
        this->setIcon(pix);
        ifsucceed = true;
    }
    return ifsucceed;
}

void MyPushButton::zoomDown()
{
    QPropertyAnimation *animation0 = new QPropertyAnimation(this, "geometry");  //创建动画对象
    animation0->setDuration(200);       //设置时间间隔
    animation0->setStartValue(QRect(this->x(), this->y(), this->width(), this->height()));  //设置动画起始位置
    animation0->setEndValue(QRect(this->x(), this->y()+5, this->width(), this->height()));  //设置结束起始位置
    animation0->setEasingCurve(QEasingCurve::OutBounce);    //设置动画曲线
    animation0->start();
}

void MyPushButton::zoomUp()
{
    QPropertyAnimation *animation1 = new QPropertyAnimation(this, "geometry");  //创建动画对象
    animation1->setDuration(200);       //设置时间间隔
    animation1->setStartValue(QRect(this->x(), this->y()+5, this->width(), this->height()));//设置动画起始位置
    animation1->setEndValue(QRect(this->x(), this->y(), this->width(), this->height()));    //设置结束起始位置
    animation1->setEasingCurve(QEasingCurve::OutBounce);    //设置动画曲线
    animation1->start();
}
