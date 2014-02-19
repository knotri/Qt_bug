#include "widget.h"

std::vector< Bullet> bullet;

void Ship::fire(){
    Bullet tmp;
    tmp.x = x;
    tmp.y = y;
    tmp.angel = angel+3.1415/2;
    tmp.speed = 5;
    bullet.push_back(tmp);
}

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QTimer* timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(update()));
    timer->start(16);
    ship.x = ship.y = 100;
    ship.angel = 45;
    ship.speed = 2;

    QTimer* timer2 = new QTimer(this);
    connect(timer2,SIGNAL(timeout()),this,SLOT(myUpdate()));
    timer2->start(16);

    bullet.resize(0);

}


void Widget::paintEvent(QPaintEvent *e){
    ship.move();
    QPainter p(this);
    p.setBrush(QColor(200,150,50));

    qWarning() << bullet.size();
    for(int i = 0; i<bullet.size(); i++){
        p.drawEllipse(QPointF(bullet[i].x,bullet[i].y),2,2);
    }


    p.translate(QPointF(ship.x,ship.y));
    p.rotate(ship.angel*180/3.1415);
    p.drawEllipse(QPointF(0,0),10,5);
    p.rotate(-ship.angel*180/3.1415);
    p.translate(-QPointF(ship.x,ship.y));


}

void Widget::keyPressEvent(QKeyEvent *e){

    if(e->key() == Qt::Key_W){
        ship.speed += 0.1;
        ship.fire(); // DONT WORK!
    }

    if(e->key() == Qt::Key_D){
        ship.angel += 0.1;
        //qWarning() << 5;
    }
    if(e->key() == Qt::Key_A){
        ship.angel -= 0.1;
    }
    if(e->key() == Qt::Key_S){
        ship.speed -= 0.1;
    }

    if(e->key() == Qt::Key_Space){
        ship.fire(); // DONT WORK!
        //qWarning() << 5;
    }
}

void Widget::myUpdate(){
    for(int i=bullet.size()-1; i>=0; i--){
        bullet[i].move();
        if(bullet[i].life<0){
            bullet.erase(bullet.begin()+i);
        }
    }
}
