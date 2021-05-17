#ifndef DRAWQLABEL_H
#define DRAWQLABEL_H
#include <QPainter>
#include <QObject>
#include <QLabel>
#include <QPaintEvent>

class DrawLabel : public QLabel
{
    Q_OBJECT
public:
    explicit DrawLabel(QWidget * parent = nullptr);
    void paintEvent(QPaintEvent * event);
    void receivestr(QString str);
private:
    QString str;
};

#endif // DRAWQLABEL_H
