#include "TimerModel.h"
#include <QDebug>

TimerModel::TimerModel() {
    m_started = false;
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
    emit sendStartState(m_started);
}