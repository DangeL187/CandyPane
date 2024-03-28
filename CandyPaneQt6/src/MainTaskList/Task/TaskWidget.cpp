#include "MainTaskList/TaskListWidget.hpp"
#include "MainTaskList/TaskWidget.hpp"

TaskWidget::TaskWidget(TaskListWidget* task_list_widget, unsigned long long id):
    _task_list_widget(task_list_widget), DraggableWidget(id)
{
    //loadStyle();
    //initSelect();
    //initIcon();
    initName();
    initLayout();
    //initEditName();
}

candypane::Task& TaskWidget::self() const {
    return _task_list_widget->getTaskById(getId());
}

void TaskWidget::initName() {
    _name = new QLabel();
    updateName();
}

void TaskWidget::initLayout() {
    _layout.setContentsMargins(0, 5, 0, 5);

    //_layout.addWidget(_select);
    //_layout.addWidget(_icon);
    _layout.addWidget(_name);
    //_layout.addWidget(_tasks_amount);
}

void TaskWidget::updateName() {
    _name->setStyleSheet("font-size: 14px;");
    _name->setText(self().getName().c_str());
}
