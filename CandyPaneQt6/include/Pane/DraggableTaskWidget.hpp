#ifndef CANDYPANE_DRAGGABLETASKWIDGET_HPP
#define CANDYPANE_DRAGGABLETASKWIDGET_HPP

#include <Task/TaskList.hpp>

struct QWidget{};

class DraggableTaskWidget: QWidget {
public:
    explicit DraggableTaskWidget(candypane::TaskList* task_list): _task_list(task_list) {}

    // auto& task_by_id = _task_list_pane->getTaskById(index)
    // task_pane_widget = new TaskPaneWidget(task_by_id);
    void createTaskPaneWidget(int index); // creates it using MousePos just like a separate window I guess
private:
    candypane::TaskList* _task_list;
};

#endif //CANDYPANE_DRAGGABLETASKWIDGET_HPP
