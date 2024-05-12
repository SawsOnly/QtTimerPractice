#include "TimerView.h"
#include "views/ui_timerview.h"

TimerView::TimerView(QWidget *parent)
    : QDockWidget(parent)
    , ui(new Ui::TimerView)
{
    ui->setupUi(this);
    QObject::connect(ui->TimerStartButton, &QPushButton::clicked, this, &TimerView::timerButtonClicked);
}

TimerView::~TimerView()
{
    delete ui;
}

QTextEdit *TimerView::getTimerLine()
{
    return ui->TimerText;
}

QPushButton *TimerView::getTimerButton()
{
    return ui->TimerStartButton;
}

void TimerView::timerButtonClicked()
{
    QString text = ui->TimerText->toPlainText();
    emit receiveTimerText(text);
}

void TimerView::changeTimerButton(bool started)
{
    if(started)
    {
        ui->TimerStartButton->setText("Stop");
        return;
    }
    ui->TimerStartButton->setText("Start");
}
