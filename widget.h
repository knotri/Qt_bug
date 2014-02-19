#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <vector>
#include <qmath.h>
#include <QTimer>
#include <QKeyEvent>
#include <QDebug>

class Bullet{
public:
    float x,y,angel,speed;
    int life;
    void move(){
        life--;
        x+=speed*cos(angel);
        y+=speed*sin(angel);
    }

};

class Ship{
public:
    float x,y,angel,speed;
    void move(){
        x += cos(angel)*speed;
        y += sin(angel)*speed;
        speed *= 0.999;
    }
    void fire();
};

class vector {
    float x,y;
    float normal(){
        float dist = sqrt(x*x + y*y);
        x/=dist;
        y/=dist;

    }

    float angel(){
        float aaan;
        if(y == 0){
            aaan = 0;
        }else{
            aaan = -atan(x/y)+3.1415926/2;
        }
        if(y > 0){aaan += 3.1415926;}
        return aaan;
    }
};


class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    void paintEvent(QPaintEvent *e);
    void keyPressEvent(QKeyEvent *);
    Ship ship;

public slots:
    void myUpdate();

};

#endif // WIDGET_H
