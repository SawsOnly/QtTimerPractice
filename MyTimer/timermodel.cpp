#include "TimerModel.h"

TimerModel::TimerModel() {

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