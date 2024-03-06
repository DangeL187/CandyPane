#ifndef CANDYPANE_LISTPANE_HPP
#define CANDYPANE_LISTPANE_HPP

#include "TaskPane.hpp"

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
