#ifndef TIMERMODEL_H_20240512
#define TIMERMODEL_H_20240512

#include <QAbstractTableModel>
#include <QTime>

class TimerModel : public QAbstractTableModel
{
public:
    TimerModel();
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
private:
    QTime m_time;
};

#endif // TIMERMODEL_H
