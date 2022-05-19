#ifndef TASK_H
#define TASK_H

#include <QMainWindow>
#include <QObject>
#include <QTime>
#include <QCheckBox>

class Task
{
public:

    QString task;
    QTime begin_time;
    QTime end_time;
    QCheckBox *box;
    Task(QString _task, QTime _begin_time, QTime _end_time);

public slots:
    void on_box_clicked();
};



#endif // TASK_H
