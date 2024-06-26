#include "MainTaskList/MainTaskList.hpp"
#include "MainTaskList/Task/NewTaskWidget.hpp"
#include "MainTaskList/Task/TaskListWidget.hpp"
#include "MainTaskList/Task/TaskWidget.hpp"
#include "MainTaskList/Title/TaskListTitle.hpp"

MainTaskList::MainTaskList(candypane::CategoryList* category_list) {
    initModules(category_list);
    initTaskListScrollArea();
    initLayout();
    setStyleSheet("background-color: rgb(28, 28, 28);");
}

void MainTaskList::checkHover() {
    _task_list_widget->checkHover();
    _main_task_list_title->checkHover();
}

unsigned long long MainTaskList::getSelectedCategoryId() {
    return _task_list_widget->getSelectedCategoryId();
}

void MainTaskList::initLayout() {
    _layout.setSpacing(0);
    _layout.setContentsMargins(48, 35, 48, 10);

    _layout.addWidget(_main_task_list_title.get());
    _layout.addWidget(&_scroll_area);

    setLayout(&_layout);
}

void MainTaskList::initModules(candypane::CategoryList* category_list) {
    _main_task_list_title = std::make_shared<TaskListTitle>(category_list);
    _task_list_widget = std::make_shared<TaskListWidget>(&_scroll_area_widget, category_list);
}

void MainTaskList::initTaskListScrollArea() {
    _scroll_area.setFrameShape(QFrame::NoFrame);
    _scroll_area.setWidgetResizable(true);
    _scroll_area.setWidget(&_scroll_area_widget);
}

void MainTaskList::setSelectedCategoryId(unsigned long long category_id) {
    _task_list_widget->setSelectedCategoryId(category_id);
    _main_task_list_title->setSelectedCategoryId(category_id);
}

void MainTaskList::updateTaskList() {
    _main_task_list_title->updateTitle();
    _task_list_widget->loadTasks();
}
