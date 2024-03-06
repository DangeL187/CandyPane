#ifndef CANDYPANE_TASKPANEWIDGET_HPP
#define CANDYPANE_TASKPANEWIDGET_HPP

#include "../../include/TaskPane.hpp"

class TaskPaneWidget: public TaskPane {
public:
    TaskPaneWidget(const std::string& name, const POINT& position) {
        setName(name);
        setPosition(position);
    }
    TaskPaneWidget(const std::string& name, int x, int y) {
        setName(name);
        setPosition(x, y);
    }
private:

};

#endif //CANDYPANE_TASKPANEWIDGET_HPP
