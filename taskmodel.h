#include <QAbstractTableModel>
#include "task.h"

class TaskModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    TaskModel(QObject *parent = nullptr);
    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    virtual int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    virtual bool setData(const QModelIndex &index, const QVariant &value, int role) override;
    virtual QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    virtual Qt::ItemFlags flags(const QModelIndex &index) const override;

    virtual bool insertRows(int position, int rows, const QModelIndex &index = QModelIndex()) override;

    virtual void sort(int column, Qt::SortOrder order) override;

    QVector<Task> tasks;
signals:
    void dataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight,
                     const QVector<int> &roles = QVector<int>());
};
