#include "DraggableWidget.hpp"
#include "DraggableWidgetsList.hpp"
#include "LeftPanel/Category/CategoryWidget.hpp"

DraggableWidgetsList::DraggableWidgetsList(QWidget* parent_widget): QVBoxLayout(parent_widget) {
    initLayout();
}

template<> void DraggableWidgetsList::deselectAll<CategoryWidget>() {
    for (int i = 0; i < count()-1; i++) {
        qobject_cast<CategoryWidget*>(layout()->itemAt(i)->widget())->select(false);
    }
}

/*template<> void DraggableWidgetsList::deselectAll<TaskWidget>() {
    for (int i = 0; i < count()-1; i++) {
        qobject_cast<TaskWidget*>(layout()->itemAt(i)->widget())->select(false);
    }
}*/

void DraggableWidgetsList::initLayout() {
    auto* spacer = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
    setContentsMargins(0, 10, 0, 10);
    setSpacing(10);
    addItem(spacer);
}

void DraggableWidgetsList::relocateWidget(unsigned int new_index, unsigned int category_id) {
    if (new_index == category_id) return;

    auto* widget = qobject_cast<DraggableWidget*>(layout()->itemAt(int(category_id))->widget());
    widget->setId(new_index);
    removeWidget(widget);
    insertWidget(int(new_index), widget);

    unsigned int from, to;
    if (new_index < category_id) {
        from = new_index+1;
        to = category_id+1;
    } else {
        from = category_id;
        to = new_index;
    }

    for (unsigned i = from; i < to; i++) {
        auto* widget_i = qobject_cast<DraggableWidget*>(layout()->itemAt(int(i))->widget());
        if (i < new_index) {
            widget_i->setId(widget_i->getId()-1);
        } else {
            widget_i->setId(widget_i->getId()+1);
        }
    }
}

void DraggableWidgetsList::updateWidgets() {
    for (int i = 0; i < count()-1; i++) {
        qobject_cast<DraggableWidget*>(layout()->itemAt(i)->widget())->updateWidget();
    }
}
