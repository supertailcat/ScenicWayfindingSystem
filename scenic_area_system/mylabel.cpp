#include "mylabel.h"

MyLabel::MyLabel(QWidget * parent):QLabel(parent)
{

}

void MyLabel::mouseReleaseEvent(QMouseEvent *ev)
{
    Q_UNUSED(ev)
    emit clicked(this->pointNumber);
}

void MyLabel::setPointNumber(int pointNumber)
{
    this->pointNumber = pointNumber;
}

int MyLabel::getPointNumber()
{
    return this->pointNumber;
}
