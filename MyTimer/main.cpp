#include "TimerView.h"
#include "Delegate.h"
#include "TimerModel.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TimerView* w = new TimerView();
    TimerModel* timerModel(new TimerModel());
    //Delegate* delegate = Delegate::getInstance();
    //delegate->addConnection(timerModel, w);

    w->show();
    return a.exec();
}
