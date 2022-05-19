#include "task.h"

Task::Task(QString _task, QTime _begin_time, QTime _end_time)
{

    task = _task;
    begin_time = _begin_time;
    end_time = _end_time;
  //  box->setChecked(false);
}
