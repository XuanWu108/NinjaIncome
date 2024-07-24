#ifndef WIDGET_H
#define WIDGET_H

#include "calculatedwindow.h"

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_lineEdit_D_returnPressed();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Widget *ui;
    CalculatedWindow* calculatedWindow = nullptr;
    void onCalculatedWindowClosed();
};
#endif // WIDGET_H
