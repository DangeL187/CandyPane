#include "Task/Task.hpp"
#include "Task/Category.hpp"

using candypane::Date;
using candypane::Task;
using candypane::Time;

Task::Task(candypane::Category* category): _category(category) {}

std::string Task::getCategoryName() const {
    return _category->getName();
}

Date Task::getDueDate() const {
    return _due_date;
}

std::string Task::getName() const {
    return _name;
}

Date Task::getReminderDate() const {
    return _reminder_date;
}

Time Task::getReminderTime() const {
    return _reminder_time;
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

void Task::setDueDate(const Date& due_date) {
    _due_date = due_date;
}

void Task::setFavourite(bool value) {
    _favourite = value;
}

void Task::setName(const std::string& new_name) {
    _name = new_name;
}

void Task::setReminderDate(const candypane::Date& reminder_date) {
    _reminder_date = reminder_date;
}

void Task::setReminderTime(const candypane::Time& reminder_time) {
    _reminder_time = reminder_time;
}

bool Task::operator==(const Task& other) const {
    return (_completed == other.isCompleted() &&
            _due_date == other.getDueDate() &&
            _favourite == other.isFavourite() &&
            _name == other.getName());
}
