#include "drawlabel.h"

DrawLabel::DrawLabel(QWidget * parent):QLabel(parent)
{

}

void DrawLabel::paintEvent(QPaintEvent *event)
{
    QLabel::paintEvent(event);
    QPainter painter(this);
    painter.setPen(QPen(Qt::red, 5));

    QPoint p1(0,0);
    QPoint p2(0,0);
    QPoint currentpoint(0,0);
    bool isp1 = true;
    if(str != "")
    {
        for(int i = 0; i < str.length(); i += 2)
        {
            switch (str[i].toLatin1() - 48)
            {
            case 1:
                currentpoint.setX(255);
                currentpoint.setY(181);
                break;
            case 2:
                currentpoint.setX(44);
                currentpoint.setY(70);
                break;
            case 3:
                currentpoint.setX(127);
                currentpoint.setY(265);
                break;
            case 4:
                currentpoint.setX(338);
                currentpoint.setY(352);
                break;
            case 5:
                currentpoint.setX(440);
                currentpoint.setY(220);
                break;
            case 6:
                currentpoint.setX(401);
                currentpoint.setY(96);
                break;
            case 7:
                currentpoint.setX(244);
                currentpoint.setY(37);
                break;
            }
            if(isp1)
            {
                p1 = currentpoint;
                isp1 = false;
            }
            else
            {
                p2 = currentpoint;
                isp1 = true;
                painter.drawLine(p1, p2);
            }
        }
    }

}

void DrawLabel::receivestr(QString str)
{
    this->str = str;
}
