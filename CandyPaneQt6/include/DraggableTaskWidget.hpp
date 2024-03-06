#ifndef CANDYPANE_DRAGGABLETASKWIDGET_HPP
#define CANDYPANE_DRAGGABLETASKWIDGET_HPP

#include "../../include/ListPane.hpp"

struct QWidget{};

class DraggableTaskWidget: QWidget {
public:
    explicit DraggableTaskWidget(ListPane* list_pane): _list_pane(list_pane) {}

    // creates TaskPaneWidget using TaskPane object that is taken from _list_pane->getTaskPaneById(index)
    void createTaskPaneWidget(int index); // creates it using MousePos just like a separate window I guess
private:
    ListPane* _list_pane;
};

#endif //CANDYPANE_DRAGGABLETASKWIDGET_HPP
