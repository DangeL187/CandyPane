#include <Task/CategoryList.hpp>

#include "MainTaskList/Task/NewTaskWidget.hpp"
#include "MainTaskList/Task/TaskListWidget.hpp"
#include "MainTaskList/Task/TaskWidget.hpp"

TaskListWidget::TaskListWidget(QWidget* parent_widget, candypane::CategoryList* category_list):
    DraggableWidgetsList(parent_widget), _category_list(category_list)
{
    setContentsMargins(0, 21, 0, 10);
    initNewTaskWidget();
}

void TaskListWidget::addTaskWidget() {
    candypane::Task new_task(&_category_list->getCategoryById(signed(_selected_id)));
    new_task.setName(".");
    _category_list->getCategoryById(signed(_selected_id)).addTask(new_task);

    auto* new_task_widget = new TaskWidget(this, _category_list->getCategoryById(signed(_selected_id)).getTasksSize()-1);
    DraggableWidgetsList::addWidget(new_task_widget);

    new_task_widget->updateWidget();
    new_task_widget->setEditMode(true);
}

void TaskListWidget::addTaskWidget(unsigned long long task_id) {
    auto* new_task_widget = new TaskWidget(this, task_id);
    DraggableWidgetsList::addWidget(new_task_widget);
    new_task_widget->updateWidget();
}

void TaskListWidget::changeCategory(unsigned long long task_id) {
    long long hovered_id = _category_list->getHoveredId();
    if (hovered_id != -1 && hovered_id != _selected_id) {
        candypane::Task new_task = _category_list->getCategoryById(signed(_selected_id)).getTaskById(task_id);
        _category_list->getCategoryById(hovered_id).addTask(new_task);

        removeTaskWidgetById(task_id);
    }
}

void TaskListWidget::checkHover() {
    for (int i = 0; i < count()-2; i++) {
        auto task_widget = qobject_cast<TaskWidget*>(itemAt(i)->widget());
        task_widget->selectBackground(task_widget->underMouse());
    }
    _new_task_widget->selectBackground(_new_task_widget->underMouse());
}

candypane::Task& TaskListWidget::getTaskById(unsigned long long task_id) {
    return _category_list->getCategoryById(signed(_selected_id)).getTaskById(task_id);
}

unsigned long long TaskListWidget::getSelectedCategoryId() const {
    return _selected_id;
}

void TaskListWidget::initNewTaskWidget() {
    _new_task_widget = std::make_shared<NewTaskWidget>(this);
    DraggableWidgetsList::insertWidget(0, _new_task_widget.get());
    DraggableWidgetsList::setEmptyCount(2);
    _new_task_widget->setVisible(false);
}

void TaskListWidget::loadTasks() {
    try {
        clearLayout();
        candypane::Category selected_category = _category_list->getCategoryById(signed(_selected_id));
        for (unsigned long long i = 0; i < selected_category.getTasksSize(); i++) {
            addTaskWidget(i);
        }
        _new_task_widget->setVisible(true);
    } catch (std::exception& e) {
        _new_task_widget->setVisible(false);
    }
}

void TaskListWidget::relocateTaskWidget(unsigned int task_id) {
    int new_index = getNewIndex();
    if (new_index != -1) {
        _category_list->getCategoryById(signed(_selected_id)).relocateTaskById(new_index, task_id);
        relocateWidget(new_index, task_id);
    }
}

void TaskListWidget::removeTaskWidgetById(unsigned int task_id) {
    removeWidgetById(task_id);
    _category_list->getCategoryById(signed(_selected_id)).removeTaskById(task_id);
}

void TaskListWidget::revealNewTaskWidget() {
    _new_task_widget->setVisible(true);
}

void TaskListWidget::setSelectedCategoryId(unsigned long long category_id) {
    _selected_id = category_id;
    loadTasks();
}

