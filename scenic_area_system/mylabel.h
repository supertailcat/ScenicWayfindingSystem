#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>
#include <QObject>
#include <QMouseEvent>

class MyLabel : public QLabel
{
    Q_OBJECT
public:
    explicit MyLabel(QWidget * parent = nullptr);
    void setPointNumber(int pointNumber);
    int getPointNumber();
protected:
    virtual void mouseReleaseEvent(QMouseEvent *ev);
signals:
    void clicked(int pointNumber);
private:
    int pointNumber;
};

#endif // MYLABEL_H
