#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->ui->setupUi(this);

    this->currentPoint = 0;
    this->model = new Model();
    this->ui->label_bg->setPixmap(QPixmap(":/bg/pic/bg.jpg"));
    this->ui->label_1->setPixmap(QPixmap(":/point/pic/point.png"));
    this->ui->label_2->setPixmap(QPixmap(":/point/pic/point.png"));
    this->ui->label_3->setPixmap(QPixmap(":/point/pic/point.png"));
    this->ui->label_4->setPixmap(QPixmap(":/point/pic/point.png"));
    this->ui->label_5->setPixmap(QPixmap(":/point/pic/point.png"));
    this->ui->label_6->setPixmap(QPixmap(":/point/pic/point.png"));
    this->ui->label_7->setPixmap(QPixmap(":/point/pic/point.png"));

    this->ui->label_1->setPointNumber(1);
    this->ui->label_2->setPointNumber(2);
    this->ui->label_3->setPointNumber(3);
    this->ui->label_4->setPointNumber(4);
    this->ui->label_5->setPointNumber(5);
    this->ui->label_6->setPointNumber(6);
    this->ui->label_7->setPointNumber(7);

    QObject::connect(ui->label_1, SIGNAL(clicked(int)), this, SLOT(onClicked(int)));
    QObject::connect(ui->label_2, SIGNAL(clicked(int)), this, SLOT(onClicked(int)));
    QObject::connect(ui->label_3, SIGNAL(clicked(int)), this, SLOT(onClicked(int)));
    QObject::connect(ui->label_4, SIGNAL(clicked(int)), this, SLOT(onClicked(int)));
    QObject::connect(ui->label_5, SIGNAL(clicked(int)), this, SLOT(onClicked(int)));
    QObject::connect(ui->label_6, SIGNAL(clicked(int)), this, SLOT(onClicked(int)));
    QObject::connect(ui->label_7, SIGNAL(clicked(int)), this, SLOT(onClicked(int)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::switchToChinese(QString str)
{
    QString result = "";
    for(int i = 0; i < str.length(); i++)
    {
        switch (str[i].toLatin1() - 48)
        {
        case 1:
            result += ("天安门");
            break;
        case 2:
            result += ("长城");
            break;
        case 3:
            result += ("奥林匹克公园");
            break;
        case 4:
            result += ("国家博物馆");
            break;
        case 5:
            result += ("玉渊潭");
            break;
        case 6:
            result += ("颐和园");
            break;
        case 7:
            result += ("南锣鼓巷");
            break;
        default:
            result += str[i].toLatin1();
            break;
        }
    }
    return result;
}
void MainWindow::onClicked(int pointNumber)
{
    this->currentPoint = pointNumber;
    qDebug() << this->currentPoint;
    QString str;
    str = str + (currentPoint + 48);
    this->ui->textEdit->setText(this->switchToChinese(str));
}

void MainWindow::on_btn_start_clicked()
{
    if(this->currentPoint != 0)
    {
        this->model->setStartPoint(this->currentPoint);
    }
}

void MainWindow::on_btn_end_clicked()
{
    if(this->currentPoint != 0)
    {
        this->model->setEndPoint(this->currentPoint);
        QString str = this->model->calculateShortestPath();
        this->ui->label_bg->receivestr(str);
        this->ui->label_bg->repaint();
        this->ui->textEdit->setText(this->switchToChinese(str));
    }
}

void MainWindow::on_btn_travel_clicked()
{
    if(this->currentPoint != 0)
    {
        this->model->setStartPoint(this->currentPoint);
        QString str = this->model->travel();
        this->ui->label_bg->receivestr(str);
        this->ui->label_bg->repaint();
        this->ui->textEdit->setText(this->switchToChinese(str));
    }
}

void MainWindow::on_btn_plan_clicked()
{
    if(this->currentPoint != 0)
    {
        this->model->setStartPoint(this->currentPoint);
        QString str = this->model->pathPlan();
        this->ui->label_bg->receivestr(str);
        this->ui->label_bg->repaint();
        this->ui->textEdit->setText(this->switchToChinese(str));
    }
}

void MainWindow::on_btn_clean_clicked()
{
    this->ui->label_bg->receivestr("");
    this->ui->label_bg->repaint();
}
