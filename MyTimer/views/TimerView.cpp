#include "TimerView.h"
#include "views/ui_timerview.h"

TimerView::TimerView(QWidget *parent)
    : QDockWidget(parent)
    , ui(new Ui::TimerView)
{
    ui->setupUi(this);
    ui->TimerText->setAlignment(Qt::AlignmentFlag::AlignCenter | Qt::AlignmentFlag::AlignAbsolute);
    ui->TimerText->setInputMask("99:99:99");
    QObject::connect(ui->TimerStartButton, &QPushButton::clicked, this, &TimerView::timerButtonClicked);
}

TimerView::~TimerView()
{
    delete ui;
}

QLineEdit *TimerView::getTimerLine()
{
    return ui->TimerText;
}

QPushButton *TimerView::getTimerButton()
{
    return ui->TimerStartButton;
}

void TimerView::timerButtonClicked()
{
    QString text = ui->TimerText->text();
    emit receiveTimerText(text);
}

void TimerView::changeTimerButton(bool started)
{
    //Timer text should not be editable by user when button has started
    ui->TimerText->setDisabled(started);
    if(started)
    {
        ui->TimerStartButton->setText("Stop");
        return;
    }
    ui->TimerStartButton->setText("Start");
}

void TimerView::updateTimer(QString time)
{
    ui->TimerText->setText(time);
}
