#ifndef CANDYPANEQT_MAINTASKLIST_HPP
#define CANDYPANEQT_MAINTASKLIST_HPP

#include <QFrame>
#include <QSplitter>
#include <QScrollArea>
#include <QVBoxLayout>

#include <Task/Category.hpp>

class TaskListWidget;

class MainTaskList: public QFrame {
public:
    explicit MainTaskList(candypane::CategoryList* category_list);

    void checkHover();
    void tempUpdateTasks();
private:
    /*========================MainTaskList=========================*/
    QVBoxLayout                         _layout;
    /*=============================================================*/

    /*===========================contents==========================*/
    //std::shared_ptr<NewListWidget>          _new_list_widget;
    QScrollArea                         _scroll_area;
    QWidget                             _scroll_area_widget;
    std::shared_ptr<TaskListWidget>     _task_list_widget;
    /*=============================================================*/

    /*=========================initializers========================*/
    void initLayout();
    void initModules(candypane::CategoryList* category_list);
    void initTaskListScrollArea();
    /*=============================================================*/
};

#endif //CANDYPANEQT_MAINTASKLIST_HPP
