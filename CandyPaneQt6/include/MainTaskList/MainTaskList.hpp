#ifndef CANDYPANEQT_MAINTASKLIST_HPP
#define CANDYPANEQT_MAINTASKLIST_HPP

#include <QFrame>
#include <QSplitter>
#include <QScrollArea>
#include <QVBoxLayout>

#include <Task/Category.hpp>

class TaskListTitle;
class TaskListWidget;
class NewTaskWidget;

class MainTaskList: public QFrame {
public:
    explicit MainTaskList(candypane::CategoryList* category_list);

    void checkHover();
    unsigned long long int getSelectedCategoryId();
    void setSelectedCategoryId(unsigned long long category_id);
    void updateTaskList();
private:
    /*========================MainTaskList=========================*/
    QVBoxLayout                         _layout;
    /*=============================================================*/

    /*===========================contents==========================*/
    std::shared_ptr<TaskListTitle>      _main_task_list_title;
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
