#ifndef TIMERMODEL_H_20240512
#define TIMERMODEL_H_20240512

#include <QAbstractTableModel>
#include <QTime>
#include <QTimer>

class TimerModel : public QAbstractTableModel
{
        Q_OBJECT
public:
    TimerModel();
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

public slots:
    void startTimer(QString time);
    void updateTime();

signals:
    void sendStartState(bool state);
    void sendUpdateToView(QString time);

private:
    QTime m_time;
    QTimer m_timer;
    bool m_started;
};

#endif // TIMERMODEL_H
