#include <iostream>
#include "Task/Category.hpp"

using candypane::Category;
using candypane::Task;

Category::Category(CategoryList* category_list): _category_list(category_list) {}

void Category::addTask(const Task& new_task) {
    _tasks.push_back(new_task);
    if (_tasks.empty() || _tasks.back() != new_task) {
        throw(std::runtime_error("Failed to add new task"));
    }
}

std::string Category::getName() const {
    return _name;
}

std::vector<Task> Category::getTasks() const {
    return _tasks;
}

unsigned long long Category::getTasksSize() {
    return _tasks.size();
}

Task& Category::getTaskById(unsigned long long int id) {
    if (id < _tasks.size()) {
        return _tasks.at(id);
    } else {
        throw(std::runtime_error("Failed to get task by id: Invalid index"));
    }
}

void Category::insertTask(unsigned long long index, const Task& task) {
    _tasks.insert(_tasks.begin() + index, task);
}

void Category::relocateTaskById(unsigned long long int index, unsigned long long int category_id) {
    Task task_to_relocate = _tasks.at(category_id);
    removeTaskById(category_id);
    insertTask(index, task_to_relocate);
}

void Category::removeTask(const Task& task_to_remove) {
    std::erase(_tasks, task_to_remove);
}

void Category::removeTaskById(unsigned long long int task_id) {
    if (task_id < _tasks.size()) {
        _tasks.erase(_tasks.begin() + signed(task_id));
    } else {
        throw(std::runtime_error("Failed to remove task by id: Invalid index"));
    }
}

void Category::setName(const std::string& new_name) {
    _name = new_name;
}

void Category::setTasks(const std::vector<Task>& new_tasks) {
    for (auto& i: new_tasks) {
        std::cout << "new_task: " << i.getName() << "\n";
    }
    _tasks = std::vector(new_tasks);
}
