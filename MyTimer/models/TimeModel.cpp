#include "TimerModel.h"
#include <QDebug>

TimerModel::TimerModel() :
    m_timer(QTimer(this)),
    m_time(QTime(0, 0)),
    m_started(false)
{
    m_timer.setInterval(1000);
    QObject::connect(&m_timer, &QTimer::timeout, this, &TimerModel::updateTime);
}

int TimerModel::rowCount(const QModelIndex &parent) const
{
    return 0;
}

int TimerModel::columnCount(const QModelIndex &parent) const
{
    return 0;
}

QVariant TimerModel::data(const QModelIndex &index, int role) const
{
    return QVariant();
}

void TimerModel::startTimer(QString time)
{
    qInfo() << qPrintable(time);
    m_started = !m_started;
    //Stop timer logic
    if(!m_started)
    {
        m_timer.stop();
        emit sendStartState(m_started);
        return;
    }

    //Start timer logic
    QStringList parsedTime = time.split(':');
    //Data checking
    if(parsedTime.size() != 3)
    {
        m_started = false;
    }
    //Check for errors
    bool ok = true;
    int hours = parsedTime.at(0).toInt(&ok);
    int minutes = parsedTime.at(1).toInt(&ok);
    int seconds = parsedTime.at(2).toInt(&ok);
    if(!ok || hours > 23 || hours < 0 || minutes > 59 || minutes < 0 || seconds > 59 || seconds < 0)
    {
        m_started = false;
    }

    //Actually start the timer
    if(m_started)
    {
        m_time = QTime(hours, minutes, seconds);
        m_timer.start();
    }
    emit sendStartState(m_started);
}

void TimerModel::updateTime()
{
    //Create QTime at zero to compare to internal time state
    QTime newTime = QTime(0, 0);
    //Check if timer has reached the end
    m_time = newTime.addSecs(newTime.secsTo(m_time) - 1);
    if(m_time == QTime(0, 0))
    {
        m_timer.stop();
        m_started = false;
        emit sendStartState(m_started);
    }
    emit sendUpdateToView(m_time.toString());
}
