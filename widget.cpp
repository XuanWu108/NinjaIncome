#include "widget.h"
#include "ui_widget.h"
#include <QIntValidator>
#include <QRegularExpression>
#include<QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QRegularExpression regExp("[0-9][0-9][0-9][0-9]");
    ui->lineEdit_D->setValidator(new QRegularExpressionValidator(regExp,this));
    ui->lineEdit_C->setValidator(new QRegularExpressionValidator(regExp,this));
    ui->lineEdit_B->setValidator(new QRegularExpressionValidator(regExp,this));
    ui->lineEdit_A->setValidator(new QRegularExpressionValidator(regExp,this));
    ui->lineEdit_S->setValidator(new QRegularExpressionValidator(regExp,this));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_lineEdit_D_returnPressed()
{

}


void Widget::on_pushButton_clicked()
{
    const qint64 minD = 5000;
    const qint64 minC = 30000;
    const qint64 minB = 80000;
    const qint64 minA = 150000;
    const qint64 minS = 1000000;

    const qint64 maxD = 50000;
    const qint64 maxC = 100000;
    const qint64 maxB = 200000;
    const qint64 maxA = 1000000;

    bool sExist = ui->lineEdit_S->text().toInt() != 0;

    qint64 minPay = 0;
    minPay +=  minD*ui->lineEdit_D->text().toInt();
    minPay +=  minC*ui->lineEdit_C->text().toInt();
    minPay +=  minB*ui->lineEdit_B->text().toInt();
    minPay +=  minA*ui->lineEdit_A->text().toInt();
    minPay +=  minS*ui->lineEdit_S->text().toInt();

    qint64 maxPay = maxD*ui->lineEdit_D->text().toInt()+
                     maxC*ui->lineEdit_C->text().toInt()+
                     maxB*ui->lineEdit_B->text().toInt()+
                     maxA*ui->lineEdit_A->text().toInt()+
                     minS*ui->lineEdit_S->text().toInt();


    QString calculated = "Minimum earned: "+QString::number(minPay)+"\n";

    if(sExist)
        calculated += "Maximum earned: "+QString::number(maxPay)+"+\n";
    else
        calculated += "Maximum earned: "+QString::number(maxPay)+"\n";

    QMessageBox mbCalculated;

    mbCalculated.setText(calculated);

    mbCalculated.exec();
}

