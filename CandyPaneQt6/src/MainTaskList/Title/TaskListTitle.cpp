#include "MainTaskList/Title/TaskListTitle.hpp"

TaskListTitle::TaskListTitle(candypane::CategoryList* category_list): _category_list(category_list) {
    initLayout();
    updateTitle();
}

void TaskListTitle::checkHover() {
    if (_category_list->getCategoriesSize() > 0) {
        _icon.selectBackground(_icon.underMouse());
        _name.selectBackground(_name.underMouse());
    } else {
        _icon.selectBackground(false);
        _name.selectBackground(false);
    }
}

void TaskListTitle::initLayout() {
    _layout.setContentsMargins(0, 0, 0, 0);
    _layout.addWidget(&_icon);
    _layout.addWidget(&_name);
    setLayout(&_layout);
}

void TaskListTitle::resizeEvent(QResizeEvent* event) {
    updateTitle();
}

void TaskListTitle::setSelectedCategoryId(unsigned long long category_id) {
    _selected_id = category_id;
    updateTitle();
}

void TaskListTitle::updateTitle() {
    _icon.updateIcon();
    try {
        _name.updateName(_category_list->getCategoryById(_selected_id).getName());
    } catch (std::exception& e) {
        _name.updateName("");
    }
}