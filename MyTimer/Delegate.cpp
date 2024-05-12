#include "Delegate.h"

Delegate* Delegate::m_delegate = 0;
Delegate::Delegate() {
    m_mapper = new QDataWidgetMapper();
}

Delegate *Delegate::getInstance()
{
    if(m_delegate == nullptr)
    {
        m_delegate = new Delegate();
    }
    return m_delegate;
}

void Delegate::addConnection(TimerModel *model, TimerView *view)
{
    m_mapper->setModel(model);
    m_mapper->addMapping(view->getTimerLine(), 0);
    //QObject::connect(view,)
    return;
}
