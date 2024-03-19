#ifndef CANDYPANE_TASK_HPP
#define CANDYPANE_TASK_HPP

#include <string>

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
/*! @fn std::string candypane::Task::getText()
    @brief Return text of the Task
    @return Text of the task
*/
/*! @fn void candypane::Task::setName(const std::string& new_name)
    @brief Set name of the Task
    @param new_name new name of the Task
*/
/*! @fn void candypane::Task::setText(const std::string& text)
    @brief Set text of the Task
    @param text text of the Task to set
*/

namespace candypane {

    class Task {
    public:
        Task() = default;

        [[nodiscard]] std::string getName() const;
        [[nodiscard]] std::string getText() const;
        void setName(const std::string &new_name);
        void setText(const std::string &text);

        bool operator==(const Task &other) const {
            return (_name == other.getName() && _text == other.getText());
        }

    protected:
        std::string _name;
        std::string _text;
    };

}

#endif //CANDYPANE_TASK_HPP
