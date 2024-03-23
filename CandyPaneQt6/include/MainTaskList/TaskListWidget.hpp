#ifndef CANDYPANEQT_TASKLISTWIDGET_HPP
#define CANDYPANEQT_TASKLISTWIDGET_HPP

#include <Task/Category.hpp>

#include "Draggable/DraggableWidgetsList.hpp"

class CategoryListWidget;

class TaskListWidget: public DraggableWidgetsList {
public:
    TaskListWidget(QWidget* parent_widget, candypane::CategoryList* category_list);

    void addTaskWidget();
    void addTaskWidget(candypane::Task& task);
    candypane::Task& getTaskById(unsigned long long task_id);
    void loadTasks();
    //void removeCategoryWidgetById(unsigned int category_id);
private:
    candypane::CategoryList* _category_list;
};

#endif //CANDYPANEQT_TASKLISTWIDGET_HPP
