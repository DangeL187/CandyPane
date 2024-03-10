#include "Task/Task.hpp"

using candypane::Task;

std::string Task::getName() const {
    return _name;
}

std::string Task::getText() const {
    return _text;
}

void Task::setName(const std::string &new_name) {
    _name = new_name;
}

void Task::setText(const std::string &text) {
    _text = text;
}
