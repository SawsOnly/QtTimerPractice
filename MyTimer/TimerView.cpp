#include "TimerView.h"
#include "ui_timerview.h"

TimerView::TimerView(QWidget *parent)
    : QDockWidget(parent)
    , ui(new Ui::TimerView)
{
    ui->setupUi(this);
}

TimerView::~TimerView()
{
    delete ui;
}

QTextEdit *TimerView::getTimerLine()
{
    return ui->TimerText;
}
