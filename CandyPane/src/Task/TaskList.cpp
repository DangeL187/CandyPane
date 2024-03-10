#include <iostream>
#include "Task/TaskList.hpp"

using candypane::TaskList;
using candypane::Task;

void TaskList::addTask(const Task& new_task) {
    _tasks.push_back(new_task);
    if (_tasks.empty() || _tasks.back() != new_task) {
        throw(std::runtime_error("Failed to add new task"));
    }
}

std::vector<Task> TaskList::getTasks() const {
    return _tasks;
}

Task& TaskList::getTaskById(int id) {
    if (id >= 0 && id < _tasks.size()) {
        return _tasks.at(id);
    } else {
        throw(std::runtime_error("Failed to get task by id: Invalid index"));
    }
}

void TaskList::removeTask(const Task& task_to_remove) {
    std::erase(_tasks, task_to_remove);
}

void TaskList::removeTaskById(int id) {
    if (id >= 0 && id < _tasks.size()) {
        _tasks.erase(_tasks.begin() + id);
    } else {
        throw(std::runtime_error("Failed to remove task by id: Invalid index"));
    }
}
