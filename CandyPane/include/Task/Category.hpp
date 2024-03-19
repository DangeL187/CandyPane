#ifndef CANDYPANE_Category_HPP
#define CANDYPANE_Category_HPP

#include <vector>
#include "Task.hpp"

/*! @class candypane::Category
    @brief Class used to store and manage Tasks, stores a pointer to the parent categories list
*/
/*! @fn candypane::Category(CategoriesList* categories_list = nullptr)
    @brief Creates Category object and sets pointer to the parent categories list
*/
/*! @fn void candypane::Category::addTask(const Task& new_task)
    @brief Adds new Task
    @param new_task New Task object
*/
/*! @fn std::vector<Task> candypane::Category::getTasks()
    @brief Return the vector with all Tasks
    @return Vector of Tasks
*/
/*! @fn std::string candypane::Category::getName()
    @brief Get the Category's name
    @return Category's name
*/
/*! @fn Task& candypane::Category::getTaskById(int id)
    @brief Return specific Task by it's index(id)
    @param id Index of the Task to get
    @return Task object
*/
/*! @fn void candypane::Category::removeTask(const Task& task_to_remove)
    @brief Remove all Tasks that match the passed Task object.
    @param task_to_remove Task object to remove
*/
/*! @fn void candypane::Category::removeTaskById(int id)
    @brief Removes Task by it's index(id)
    @param id Index of the Task to remove
*/
/*! @fn void candypane::Category::setName(const std::string& new_name)
    @brief Set new Category's name
    @param new_name New Category's name
*/
/*! @fn void candypane::Category::setTasks(const std::vector<Task>& new_tasks)
    @brief Set new tasks list
    @param new_tasks Vector of Task objects
*/

namespace candypane {

    class CategoriesList; // forward declaration

    class Category {
    public:
        explicit Category(CategoriesList* categories_list = nullptr): _categories_list(categories_list) {}

        void addTask(const Task& new_task);
        [[nodiscard]] std::string getName() const;
        [[nodiscard]] std::vector<Task> getTasks() const;
        Task& getTaskById(unsigned long long int id);
        void removeTask(const Task& task_to_remove);
        void removeTaskById(unsigned long long int id);
        void setName(const std::string& new_name);
        void setTasks(const std::vector<Task>& new_tasks);

        bool operator==(const Category &other) const {
            return (_tasks == other.getTasks());
        }

    protected:
        CategoriesList*     _categories_list;
        std::string         _name;
        std::vector<Task>   _tasks;
    };

}

#endif //CANDYPANE_Category_HPP
