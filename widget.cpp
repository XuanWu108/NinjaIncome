#include "widget.h"
#include "ui_widget.h"
#include "calculatedwindow.h"
#include <QIntValidator>
#include <QRegularExpression>
#include <QMessageBox>


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
    this->setWindowTitle("Ninja Salaries");
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

    QString displayedMinPay = QString::number(minPay/4);
    QString displayedMaxPay = QString::number(maxPay/4);

    for(int i = displayedMinPay.size()-3; i>0; i-=3){
        displayedMinPay.insert(i," ");
    }
    for(int i = displayedMaxPay.size()-3; i>0; i-=3){
        displayedMaxPay.insert(i," ");
    }

    if(sExist){
        displayedMaxPay+="+";
    }


    if(calculatedWindow)
        return;
    calculatedWindow = new CalculatedWindow(displayedMinPay,displayedMaxPay);
    calculatedWindow->show();
    connect(calculatedWindow, &CalculatedWindow::onDelete, this, &Widget::onCalculatedWindowClosed);
}


void Widget::on_pushButton_2_clicked()
{
    QMessageBox help;

    help.setTextFormat(Qt::RichText);
    QString helpText = "Количество выполненных миссий персонажа можно <br> "
                       "посмотреть в Датабуках или в различных Вики по Наруто.<br> "
                       "Минимальная и максимальная суммы были разделены на 4, исходя <br> "
                       "из предположения о том, что вознаграждение делится на команду. <br> "
                       "Налог не учитывается, так как он неизвестен. <br><br> "
                        "<a href=https://vk.com/igraidokonca>Сообщить об ошибке</a>";

    help.setText(helpText);
    help.exec();

}

void Widget::onCalculatedWindowClosed()
{
    calculatedWindow = nullptr;
}

