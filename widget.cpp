#include "widget.h"
#include "ui_widget.h"

#include <QMessageBox>



Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pbCoke->setDisabled(1);
    ui->pbTea->setDisabled(1);
    ui->pbCoffee->setDisabled(1);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pb10_clicked()
{
    changeMoney(10);
}

void Widget::on_pb50_clicked()
{
   changeMoney(50);
}

void Widget::on_pb100_clicked()
{
    changeMoney(100);
}

void Widget::on_pb500_clicked()
{
    changeMoney(500);
}

void Widget::changeMoney(int n) {
    if(money + n >= 0) {
        money += n;
        ui->lcdNumber->display(money);
    }
    if(money >= 200) {
        ui->pbCoke->setDisabled(0);
        ui->pbTea->setDisabled(0);
        ui->pbCoffee->setDisabled(0);
    }
    else if(money >= 150) {
        ui->pbCoke->setDisabled(1);
        ui->pbTea->setDisabled(0);
        ui->pbCoffee->setDisabled(0);
    }
    else if(money >= 100) {
        ui->pbCoke->setDisabled(1);
        ui->pbTea->setDisabled(1);
        ui->pbCoffee->setDisabled(0);
    }
    else {
        ui->pbCoke->setDisabled(1);
        ui->pbTea->setDisabled(1);
        ui->pbCoffee->setDisabled(1);
    }
}

void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}

void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
}

void Widget::on_pbCoke_clicked()
{
    changeMoney(-200);
}

void Widget::on_pbReturn_clicked()
{
    int arr[4] = {0, 0, 0, 0};
    int temp = money;
    arr[0] = temp/500;
    temp%=500;
    arr[1] = temp/100;
    temp%=100;
    arr[2] = temp/50;
    temp%=50;
    arr[3] = temp/10;


    money = 0;
    ui->lcdNumber->display(money);

    ui->pbCoke->setDisabled(1);
    ui->pbTea->setDisabled(1);
    ui->pbCoffee->setDisabled(1);

    QMessageBox msg;
    msg.information(nullptr, "RETURN MONEY", "500 : " + QString::number(arr[0]) + ", 100 : " + QString::number(arr[1]) + ", 50 : " + QString::number(arr[2]) + ", 10 : " + QString::number(arr[3]));
}
