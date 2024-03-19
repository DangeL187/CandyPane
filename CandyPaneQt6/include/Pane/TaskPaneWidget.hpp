#ifndef CANDYPANE_TASKPANEWIDGET_HPP
#define CANDYPANE_TASKPANEWIDGET_HPP

#include "../../include/Task/Task.hpp"
#include "POINT.hpp"

class TaskPaneWidget: public candypane::Task {
public:
    TaskPaneWidget(const std::string& name, const POINT& position) {
        setName(name);
        //setPosition(position);
    }
    TaskPaneWidget(const std::string& name, int x, int y) {
        setName(name);
        ///setPosition(x, y);
    }
};

#endif //CANDYPANE_TASKPANEWIDGET_HPP
