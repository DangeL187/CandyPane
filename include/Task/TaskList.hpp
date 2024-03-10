#ifndef CANDYPANE_TASKLIST_HPP
#define CANDYPANE_TASKLIST_HPP

#include <vector>
#include "Task.hpp"

/*! @class candypane::TaskList
    @brief Class used to store and manage Tasks
    @det TaskLists main purpose is only to manage Tasks
    @det Unlike Tasks, TaskList object do not have names or any identifiers
    @det The only way to compare TaskList objects is to compare their vectors of Tasks
*/
/*! @fn candypane::TaskList()
    @brief Default constructor 
*/
/*! @fn void candypane::TaskList::addTask(const Task& new_task)
    @brief Adds new Task
    @param new_task new Task object
*/
/*! @fn std::vector<Task> candypane::TaskList::getTasks()
    @brief Return the vector with all Tasks
    @return Vector of Tasks
*/
/*! @fn Task& candypane::TaskList::getTaskById(int id)
    @brief Return specific Task by it's index(id)
    @param id index of the Task to get
    @return Task object
*/
/*! @fn void candypane::TaskList::removeTask(const Task& task_to_remove)
    @brief Remove all Tasks that match the passed Task object.
    @param task_to_remove Task object to remove
*/
/*! @fn void candypane::TaskList::removeTaskById(int id);
    @brief Removes Task by it's index(id)
    @param id index of the Task to remove
*/

namespace candypane {

    class TaskList {
    public:
        TaskList() = default;

        void addTask(const Task& new_task);
        [[nodiscard]] std::vector<Task> getTasks() const;
        Task& getTaskById(int id);
        void removeTask(const Task& task_to_remove);
        void removeTaskById(int id);

        bool operator==(const TaskList &other) const {
            return (_tasks == other.getTasks());
        }

    private:
        std::vector<Task>   _tasks;
    };

}

#endif //CANDYPANE_TASKLIST_HPP
