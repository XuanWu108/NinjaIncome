#ifndef CALCULATEDWINDOW_H
#define CALCULATEDWINDOW_H
#include <QtWidgets>

class CalculatedWindow : public QWidget
{
    Q_OBJECT
public:
    explicit CalculatedWindow(QString min, QString max, QWidget *parent = nullptr);

    ~CalculatedWindow();

signals:

    void onDelete();

private:
    QLabel* lMin = nullptr;
    QLabel* lMax = nullptr;

};



#endif // CALCULATEDWINDOW_H
