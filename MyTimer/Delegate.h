#ifndef DELEGATE_H
#define DELEGATE_H

#include <QDataWidgetMapper>

class TimerModel;
class TimerView;
class Delegate : QObject
{
    Q_OBJECT
public:
    //Singleton Delegate should not be copyable
    Delegate(Delegate& other) = delete;

    //Singleton Delegate should not be assignable
    void operator=(const Delegate&) = delete;
    static Delegate *getInstance();
    void addConnection(TimerModel* model, TimerView* view);
private:
    Delegate();

    static Delegate* m_delegate;
    QDataWidgetMapper* m_mapper;
};

#endif // DELEGATE_H
