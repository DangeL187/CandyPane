#ifndef CANDYPANE_TASK_HPP
#define CANDYPANE_TASK_HPP

#include <string>
#include <DateTime/DateTimeModule.hpp>

/*! @class candypane::Task
    @brief Class that represents one specific task
*/
/*! @fn candypane::Task()
    @brief Default constructor
*/
/*! @fn std::string candypane::Task::getName()
    @brief Return name of the Task
    @return Name of the task
*/
/*! @fn void candypane::Task::setName(const std::string& new_name)
    @brief Set name of the Task
    @param new_name new name of the Task
*/

namespace candypane {

    class Category; // forward declaration

    class Task {
    public:
        Task(Category* category);

        [[nodiscard]] std::string getCategoryName() const;
        [[nodiscard]] Date getDueDate() const;
        [[nodiscard]] std::string getName() const;
        [[nodiscard]] Date getReminderDate() const;
        [[nodiscard]] Time getReminderTime() const;
        [[nodiscard]] bool isCompleted() const;
        [[nodiscard]] bool isFavourite() const;
        void setCompleted(bool value);
        void setDueDate(const Date& due_date);
        void setFavourite(bool value);
        void setName(const std::string &new_name);
        void setReminderDate(const Date& reminder_date);
        void setReminderTime(const Time& reminder_time);

        bool operator==(const Task &other) const;

    protected:
        Category*   _category;
        bool        _completed = false;
        Date        _due_date;
        bool        _favourite = false;
        std::string _name;
        Date        _reminder_date;
        Time        _reminder_time;
    };

}

#endif //CANDYPANE_TASK_HPP
