#ifndef CANDYPANE_LISTPANE_HPP
#define CANDYPANE_LISTPANE_HPP

#include "TaskPane.hpp"

/*! @class candypane::ListPane
    @brief FFFFF
*/
/*! @fn candypane::ListPane()
    @brief Default constructor 
*/
/*! @fn void candypane::ListPane::addTaskPane(const TaskPane& new_task_pane)
    @brief FFFFF
    @param new_task_pane FFFFFFF
*/
/*! @fn TaskPane& candypane::ListPane::getTaskPaneById(int id)
    @brief FFFFF
    @param id FFFFFFF
    @return FFFFFFF
*/
/*! @fn void candypane::ListPane::removeTaskPane(const TaskPane& task_pane_to_remove)
    @brief FFFFF
    @param task_pane_to_remove FFFFFFF
*/
/*! @fn void candypane::ListPane::removeTaskPaneById(int id);
    @brief FFFFF
    @param id FFFFFFF
*/
/*! @fn void candypane::ListPane::resize(int width, int height);
    @brief FFFFF
    @param width FFFFFFF
    @param height FFFFFFF
*/
/*! @fn void candypane::ListPane::resize(const SIZE& new_size)
    @brief FFFFF
    @param new_size FFFFFFF
*/
/*! @fn void candypane::ListPane::setName(const std::string& new_name)
    @brief FFFFF
    @param new_name FFFFFFF
*/
/*! @fn void candypane::ListPane::setPosition(int x, int y);
    @brief FFFFF
    @param x FFFFFFF
    @param y FFFFFFF
*/
/*! @fn void candypane::ListPane::setPosition(const POINT& new_position)
    @brief FFFFF
    @param new_position FFFFFFF
*/

class ListPane {
public:
    ListPane() = default;
protected:
    void addTaskPane(const TaskPane& new_task_pane);
    TaskPane& getTaskPaneById(int id);
    void removeTaskPane(const TaskPane& task_pane_to_remove);
    void removeTaskPaneById(int id);

    void resize(int width, int height);
    void resize(const SIZE& new_size);
    void setName(const std::string& new_name);
    void setPosition(int x, int y);
    void setPosition(const POINT& new_position);
private:
    std::string             _name;
    POINT                   _position;
    SIZE                    _size;
    std::vector<TaskPane>   _task_panes;
};

#endif //CANDYPANE_LISTPANE_HPP
