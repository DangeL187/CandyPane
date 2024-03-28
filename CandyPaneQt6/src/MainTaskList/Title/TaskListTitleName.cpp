#include "MainTaskList/Title/TaskListTitleName.hpp"
#include "Draggable/WidgetBackground.hpp"

TaskListTitleName::TaskListTitleName() {
    initBackground();
    initLayout();
    loadStyle();
    selectBackground(false);
}

void TaskListTitleName::initBackground() {
    _background = std::make_shared<WidgetBackground>(this);
}

void TaskListTitleName::initLayout() {
    _layout.setContentsMargins(0, 0, 0, 0);
    _layout.addWidget(&_name);
    setLayout(&_layout);
}

void TaskListTitleName::loadStyle() {
    _background->setColor(55, 55, 55);
    _name.setStyleSheet("background-color: transparent; font-size: 28px; font-weight: bold;");
}

void TaskListTitleName::selectBackground(bool value) {
    _background->select(value);
}

void TaskListTitleName::updateName(const std::string& new_name) {
    _background->setFixedSize(_name.size());
    _name.setText(new_name.c_str());
}
