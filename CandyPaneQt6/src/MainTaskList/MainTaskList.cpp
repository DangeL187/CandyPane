#include "MainTaskList/MainTaskList.hpp"
#include "MainTaskList/TaskListWidget.hpp"

void MainTaskList::tempUpdateTasks() {
    _task_list_widget->loadTasks();
}

MainTaskList::MainTaskList(candypane::CategoryList* category_list) {
    initModules(category_list);
    initTaskListScrollArea();
    initLayout();
}

void MainTaskList::initLayout() {
    _layout.setSpacing(0);
    _layout.setContentsMargins(6, 0, 0, 10);

    _layout.addWidget(&_scroll_area);
    //_layout.addWidget(_new_list_widget.get());

    setLayout(&_layout);
}

void MainTaskList::initModules(candypane::CategoryList* category_list) {
    _task_list_widget = std::make_shared<TaskListWidget>(&_scroll_area_widget, category_list);
    //_new_list_widget = std::make_shared<NewListWidget>(_category_list_widget.get());
}

void MainTaskList::initTaskListScrollArea() {
    _scroll_area.setFrameShape(QFrame::NoFrame);
    _scroll_area.setWidgetResizable(true);
    _scroll_area.setWidget(&_scroll_area_widget);
}