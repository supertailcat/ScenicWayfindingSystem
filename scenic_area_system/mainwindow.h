#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "model.h"
#include "mylabel.h"
#include "drawlabel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    QPixmap * bg;
    Ui::MainWindow *ui;
    Model * model;
    int currentPoint;
    QString switchToChinese(QString str);
private slots:
    void onClicked(int pointNumber);

    void on_btn_start_clicked();
    void on_btn_end_clicked();
    void on_btn_travel_clicked();
    void on_btn_plan_clicked();
    void on_btn_clean_clicked();
};
#endif // MAINWINDOW_H
