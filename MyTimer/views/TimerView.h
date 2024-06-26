#ifndef TIMERVIEW_H_20240512
#define TIMERVIEW_H_20240512

#include <QDockWidget>
#include <QLineEdit>
#include <QPushButton>

namespace Ui {

class TimerView;
}

class TimerView : public QDockWidget
{
    Q_OBJECT

public:
    explicit TimerView(QWidget *parent = nullptr);
    ~TimerView();
    QLineEdit* getTimerLine();
    QPushButton* getTimerButton();

public slots:
    void timerButtonClicked();
    void changeTimerButton(bool started);
    void updateTimer(QString time);

signals:
    void receiveTimerText(QString text);

private:
    Ui::TimerView *ui;
};

#endif // TIMERVIEW_H
