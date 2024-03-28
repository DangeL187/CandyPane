#include <Task/CategoryList.hpp>
#include <Task/Category.hpp>

#include "MainTaskList/Task/TaskListWidget.hpp"
#include "MainTaskList/Task/TaskWidget.hpp"

TaskListWidget::TaskListWidget(QWidget* parent_widget, candypane::CategoryList* category_list):
    DraggableWidgetsList(parent_widget), _category_list(category_list)
{
    setContentsMargins(0, 21, 0, 10);
}

void TaskListWidget::addTaskWidget() {
    auto* new_task_widget = new TaskWidget(this, _category_list->getCategoryById(_selected_id).getTasksSize()-1);
    DraggableWidgetsList::addWidget(new_task_widget);
    new_task_widget->updateWidget();
}

void TaskListWidget::addTaskWidget(unsigned long long task_id) {
    auto* new_task_widget = new TaskWidget(this, task_id);
    DraggableWidgetsList::addWidget(new_task_widget);
    new_task_widget->updateWidget();
}

candypane::Task& TaskListWidget::getTaskById(unsigned long long task_id) {
    return _category_list->getCategoryById(_selected_id).getTaskById(task_id);
}

unsigned long long TaskListWidget::getSelectedCategoryId() const {
    return _selected_id;
}

void TaskListWidget::loadTasks() {
    try {
        clearLayout();
        candypane::Category selected_category = _category_list->getCategoryById(_selected_id);
        for (unsigned long long i = 0; i < selected_category.getTasksSize(); i++) {
            addTaskWidget(i);
        }
    } catch (std::exception& e) {}
}

void TaskListWidget::relocateTaskWidget(unsigned int task_id) {
    int new_index = getNewIndex();
    if (new_index != -1) {
        _category_list->getCategoryById(_selected_id).relocateTaskById(new_index, task_id);
        relocateWidget(new_index, task_id);
    }
}

void TaskListWidget::setSelectedCategoryId(unsigned long long category_id) {
    _selected_id = category_id;
    loadTasks();
}

