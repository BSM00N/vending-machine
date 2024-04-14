#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pbCoffee->setEnabled(false);
    ui->pbTea->setEnabled(false);
    ui->pbMilk->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int diff){
    money += diff;
    ui->lcdNumber->display(money);

    // 음료 버튼의 활성화/비활성화 설정
    ui->pbCoffee->setEnabled(money >= 100);
    ui->pbTea->setEnabled(money >= 150);
    ui->pbMilk->setEnabled(money >= 200);
}

void Widget::on_pbCoin10_clicked()
{
    changeMoney(10);
}

void Widget::on_pbCoin50_clicked()
{
    changeMoney(50);
}

void Widget::on_pbCoin100_clicked()
{
    changeMoney(100);
}

void Widget::on_pbCoin500_clicked()
{
    changeMoney(500);
}

void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}

void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
}

void Widget::on_pbMilk_clicked()
{
    changeMoney(-200);
}

void Widget::on_pbReset_clicked()
{
    int remain = money;
    int coin500 = remain / 500;
    remain %= 500;
    int coin100 = remain / 100;
    remain %= 100;
    int coin50 = remain / 50;
    remain %= 50;
    int coin10 = remain / 10;

    // 잔돈 정보를 메시지박스로 출력
    QMessageBox MB;
    MB.information(this, "Reset", QString("500원: %1개\n100원: %2개\n50원: %3개\n10원: %4개").arg(coin500).arg(coin100).arg(coin50).arg(coin10));
}
