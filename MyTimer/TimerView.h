#ifndef TIMERVIEW_H_20240512
#define TIMERVIEW_H_20240512

#include <QDockWidget>
#include <QTextEdit>

namespace Ui {
class TimerView;
}

class TimerView : public QDockWidget
{
    Q_OBJECT

public:
    explicit TimerView(QWidget *parent = nullptr);
    ~TimerView();
    QTextEdit* getTimerLine();

private:
    Ui::TimerView *ui;
};

#endif // TIMERVIEW_H
