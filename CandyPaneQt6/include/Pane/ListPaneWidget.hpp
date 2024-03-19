#ifndef CANDYPANE_LISTPANEWIDGET_HPP
#define CANDYPANE_LISTPANEWIDGET_HPP

#include "DraggableTaskWidget.hpp"

struct QVBoxLayout{};

class ListPaneWidget: public ListPane {
public:
    ListPaneWidget(const std::string& name, const POINT& position) {
        setName(name);
        setPosition(position);
    }
    ListPaneWidget(const std::string& name, int x, int y) {
        setName(name);
        setPosition(x, y);
    }

    void onDraggableTaskWidgetDrag(); // fake, calls createTaskPaneWidget
private:
    std::vector<DraggableTaskWidget>    _draggable_tasks;
    ListPane                            _list_pane;
    QVBoxLayout                         _layout;
};

#endif //CANDYPANE_LISTPANEWIDGET_HPP
