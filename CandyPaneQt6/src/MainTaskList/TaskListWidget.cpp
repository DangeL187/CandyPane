#include <Task/CategoryList.hpp>
#include <Task/Category.hpp>

#include "MainTaskList/TaskListWidget.hpp"
#include "MainTaskList/TaskWidget.hpp"

#include <iostream> // todo: delete

TaskListWidget::TaskListWidget(QWidget* parent_widget, candypane::CategoryList* category_list):
    DraggableWidgetsList(parent_widget), _category_list(category_list) {
    loadTasks();
}

void TaskListWidget::addTaskWidget() {

}

void TaskListWidget::addTaskWidget(candypane::Task& task) {
    auto* new_task_widget = new TaskWidget(this, _category_list->getSelectedCategory().getTasksSize()-1);
    DraggableWidgetsList::addWidget(new_task_widget);
    new_task_widget->updateWidget();
}

candypane::Task& TaskListWidget::getTaskById(unsigned long long task_id) {
    return _category_list->getSelectedCategory().getTaskById(task_id);
}

void TaskListWidget::loadTasks() {
    try {
        clearLayout();
        candypane::Category selected_category = _category_list->getSelectedCategory();
        for (int i = 0; i < selected_category.getTasksSize(); i++) {
            candypane::Task task = selected_category.getTaskById(i);
            addTaskWidget(task);
        }
    } catch (std::exception& e) {
        std::cerr << e.what() << "\n";
    }
}

