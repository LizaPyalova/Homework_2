#include "taskmodel.h"
#include <QCheckBox>
TaskModel::TaskModel(QObject *parent)
    : QAbstractTableModel(parent)
{

   // tasks << Task( "Прога", QTime(12, 20), QTime(13, 30))
     //     << Task( "МА", QTime(10, 25), QTime(12, 10));


}

int TaskModel::rowCount(const QModelIndex & /*parent*/) const
{
   return tasks.count();

}

int TaskModel::columnCount(const QModelIndex & /*parent*/) const
{
    return 3;
}

void Task::on_box_clicked(){
   box->setChecked(true);


}

QVariant TaskModel::data(const QModelIndex &index, int role) const
{
    if(role==Qt::CheckStateRole){
switch(index.column()){
case 0:
return Qt::CheckState::Unchecked|Qt::CheckState::Checked;
    }}

    if(role != Qt::DisplayRole)
    {
        return QVariant();
    }
    if (role == Qt::EditRole && index.column() == 1) {
        return tasks[index.row()].begin_time;
    }
    switch(index.column())
    {

    case 0: return tasks[index.row()].task;
    case 1: return tasks[index.row()].begin_time;
    case 2: return tasks[index.row()].end_time;
    default: return QVariant();
    }

    return QVariant();
}

QVariant TaskModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role != Qt::DisplayRole)
    {
        return QVariant();
    }

    if(orientation == Qt::Horizontal)
    {
        switch(section)
        {

        case 0: return tr("Task");
        case 1: return tr("Begin Time");
        case 2: return tr("End Time");
        default: return QVariant();
        }
    }
    else
    {
        return QString("%1").arg(section + 1);
    }
}

Qt::ItemFlags TaskModel::flags(const QModelIndex &index) const
{
    if (!index.isValid()) {
        return Qt::NoItemFlags;
    }
    if (index.column() == 0) {
        return Qt::ItemIsEditable | Qt::ItemIsUserCheckable | Qt::ItemIsSelectable | Qt::ItemIsEnabled;
    }
    return Qt::ItemIsEditable | Qt::ItemIsSelectable | Qt::ItemIsEnabled;
}

bool TaskModel::insertRows(int position, int rows, const QModelIndex &parent)
{
    beginInsertRows(QModelIndex(), position, position+rows-1);

    for (int row = 0; row < rows; ++row) {

        tasks.insert(position, Task( "", QTime(0, 0), QTime(0, 0)));
    }

    endInsertRows();
    return true;
}

bool TaskModel::setData(const QModelIndex &index, const QVariant &value, int role)
{

    if (role == Qt::EditRole) {
        switch (index.column()) {
        case 0:
            tasks[index.row()].task = value.toString();
            break;
        case 1:
            tasks[index.row()].begin_time = value.toTime();
            break;
        case 2:
            tasks[index.row()].end_time = value.toTime();
            break;
        }
        return true;
    }
    if (role==Qt::CheckStateRole){
        return true;
    }
   return false;
}

void TaskModel::sort(int column, Qt::SortOrder order)
{
    emit layoutAboutToBeChanged();
    if (order == Qt::AscendingOrder) {
        switch(column) {
        case 0: std::sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b){
                return a.task < b.task;
            });
            break;
        case 1: std::sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b){
                return a.begin_time < b.begin_time;
            });
            break;
        case 2: std::sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b){
                return a.end_time < b.end_time;
            });
            break;


        }

    }
    else {
        switch(column) {
        case 0: std::sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b){
                return a.task > b.task;
            });
            break;
        case 1: std::sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b){
                return a.begin_time > b.begin_time;
            });
            break;
        case 2: std::sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b){
                return a.end_time > b.end_time;
            });
            break;

        }
    }
    emit layoutChanged();
}
