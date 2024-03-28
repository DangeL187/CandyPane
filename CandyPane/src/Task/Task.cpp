#include "Task/Task.hpp"

using candypane::Task;

std::string Task::getName() const {
    return _name;
}

std::string Task::getText() const {
    return _text;
}

bool Task::isCompleted() const {
    return _completed;
}

bool Task::isFavourite() const {
    return _favourite;
}

void Task::setCompleted(bool value) {
    _completed = value;
}

void Task::setFavourite(bool value) {
    _favourite = value;
}

void Task::setName(const std::string &new_name) {
    _name = new_name;
}

void Task::setText(const std::string &text) {
    _text = text;
}
