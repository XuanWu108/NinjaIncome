#include "calculatedwindow.h"
#include <QtWidgets>

#include "widget.h"
#include "ui_widget.h"
#include "calculatedwindow.h"
#include <QIntValidator>
#include <QRegularExpression>
#include <QMessageBox>
#include <widget.cpp>

CalculatedWindow::CalculatedWindow(QString min, QString max, QWidget *parent)
    : QWidget(parent, Qt::Window)

{
    auto grid = new QGridLayout;
    auto lMinText = new QLabel("Минимум заработано: ");
    auto lMaxText = new QLabel("Максимум заработано: ");
    lMin = new QLabel;
    lMax = new QLabel;
    lMin->setText(min);
    lMax->setText(max);
    auto pbCopyMin = new QPushButton;
    auto pbCopyMax = new QPushButton;
    grid->addWidget(lMinText, 0, 0);
    grid->addWidget(lMaxText, 1, 0);
    grid->addWidget(lMin, 0, 1);
    grid->addWidget(lMax, 1, 1);
    grid->addWidget(pbCopyMin, 0, 2);
    grid->addWidget(pbCopyMax, 1, 2);
    this->setLayout(grid);
    this->setWindowTitle("Calculated income");
    this->setAttribute(Qt::WA_DeleteOnClose);
    QPixmap copy(":/image/copy");
    QIcon icon(copy);
    pbCopyMin->setIcon(icon);
    pbCopyMax->setIcon(icon);

    connect(pbCopyMin, &QPushButton::clicked, [=](){
        QClipboard *clip = QGuiApplication::clipboard();
        clip->setText(lMin->text());
    });

    connect(pbCopyMax, &QPushButton::clicked, [=](){
        QClipboard *clip = QGuiApplication::clipboard();
        clip->setText(lMax->text());
    });

    pbCopyMin->setToolTip("Копировать");
    pbCopyMax->setToolTip("Копировать");

}

CalculatedWindow::~CalculatedWindow()
{
    emit onDelete();
    qDebug()<<"window deleted";
}
