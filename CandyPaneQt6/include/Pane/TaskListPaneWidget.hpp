#ifndef CANDYPANE_TASKLISTPANEWIDGET_HPP
#define CANDYPANE_TASKLISTPANEWIDGET_HPP

#include "DraggableTaskWidget.hpp"
#include "POINT.hpp"

struct QVBoxLayout{};

class TaskListPaneWidget: public candypane::TaskList {
public:
    TaskListPaneWidget(const std::string& name, const POINT& position);

    TaskListPaneWidget(const std::string& name, int x, int y);

    void onDraggableTaskWidgetDrag(); // fake, calls createTaskPaneWidget

private:
    std::vector<DraggableTaskWidget>    _draggable_tasks;
    QVBoxLayout                         _layout;
    TaskList                            _list_pane;
};

#endif //CANDYPANE_TASKLISTPANEWIDGET_HPP
