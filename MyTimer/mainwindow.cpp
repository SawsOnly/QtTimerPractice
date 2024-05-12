#include "mainwindow.h"
#include "TimerView.h"
#include "./ui_mainwindow.h"

#include <QWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QWidget* timer = new TimerView(this);
    ui->Stack = timer;
    ui->centralwidget->show();
    ui->Stack->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
