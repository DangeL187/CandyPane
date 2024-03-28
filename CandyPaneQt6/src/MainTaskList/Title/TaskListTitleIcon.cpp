#include "MainTaskList/Title/TaskListTitleIcon.hpp"
#include "Draggable/WidgetBackground.hpp"

TaskListTitleIcon::TaskListTitleIcon() {
    setFixedSize(46, 46);
    initBackground();
    initIcon();
    initLayout();
    loadStyle();
    selectBackground(false);
}

void TaskListTitleIcon::initBackground() {
    _background = std::make_shared<WidgetBackground>(this);
}

void TaskListTitleIcon::initIcon() {
    _icon.setFixedSize(32, 32);
}

void TaskListTitleIcon::initLayout() {
    _layout.setContentsMargins((width() - _icon.width()) / 2, 0, 0, 0);
    _layout.addWidget(&_icon);
    setLayout(&_layout);
}

void TaskListTitleIcon::loadStyle() {
    _background->setColor(55, 55, 55);
}

void TaskListTitleIcon::selectBackground(bool value) {
    _background->select(value);
}

void TaskListTitleIcon::updateIcon() {
    _background->setFixedSize(46, 46);
    _icon.setStyleSheet("background-color: green");
}
