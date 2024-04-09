#include "Draggable/DraggableWidget.hpp"
#include "Draggable/DraggableWidgetsList.hpp"
#include "LeftPanel/Category/CategoryWidget.hpp"
#include "MainTaskList/Task/TaskWidget.hpp"

DraggableWidgetsList::DraggableWidgetsList(QWidget* parent_widget): QVBoxLayout(parent_widget) {
    initLayout();
}

template <>
void DraggableWidgetsList::addWidget(CategoryWidget* widget) {
    insertWidget(count()-_empty_count, widget); // insert before necessary items in the layout
}

template <>
void DraggableWidgetsList::addWidget(TaskWidget* widget) {
    insertWidget(count()-_empty_count, widget); // insert before necessary items in the layout
}

void DraggableWidgetsList::clearLayout() {
    while (count() > _empty_count) {
        auto* widget = qobject_cast<DraggableWidget*>(layout()->itemAt(0)->widget());
        removeWidget(widget);
        delete widget;
    }
}

template <>
void DraggableWidgetsList::deselectAll<CategoryWidget>() {
    for (int i = 0; i < count()-_empty_count; i++) {
        qobject_cast<CategoryWidget*>(layout()->itemAt(i)->widget())->select(false);
    }
}

template <>
void DraggableWidgetsList::deselectAll<TaskWidget>() {
    for (int i = 0; i < count()-_empty_count; i++) {
        qobject_cast<TaskWidget*>(layout()->itemAt(i)->widget())->selectBackground(false);
    }
}

int DraggableWidgetsList::getNewIndex() {
    int dif = -1;
    int new_index = -1;
    for (int i = 0; i < count()-_empty_count; i++) {
        QWidget* widget = itemAt(i)->widget();
        QPoint pos = widget->mapToGlobal(widget->rect().center());
        int diff = abs(pos.y() - QCursor::pos().y()); // vertical difference between widget's center and mouse cursor
        if (dif != -1 && dif < diff) {
            break;
        } else {
            new_index = i;
            dif = diff;
        }
    }
    return new_index;
}

void DraggableWidgetsList::initLayout() {
    auto* spacer = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
    setContentsMargins(0, 10, 0, 10);
    setSpacing(10);
    addItem(spacer);
}

void DraggableWidgetsList::relocateWidget(unsigned int new_index, unsigned int widget_id) {
    if (new_index == widget_id) return;

    auto* widget = qobject_cast<DraggableWidget*>(layout()->itemAt(int(widget_id))->widget());
    widget->setId(new_index);
    removeWidget(widget);
    insertWidget(int(new_index), widget);

    unsigned int from, to;
    if (new_index < widget_id) {
        from = new_index+1;
        to = widget_id+1;
    } else {
        from = widget_id;
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

void DraggableWidgetsList::removeWidgetById(unsigned int widget_id) {
    auto* widget = qobject_cast<DraggableWidget*>(layout()->itemAt(int(widget_id))->widget());
    removeWidget(widget);
    delete widget;

    for (unsigned i = widget_id; i < count()-_empty_count; i++) {
        auto* widget_i = qobject_cast<DraggableWidget*>(layout()->itemAt(int(i))->widget());
        widget_i->setId(widget_i->getId()-1);
    }
}

void DraggableWidgetsList::setEmptyCount(int empty_count) {
    _empty_count = empty_count;
}

void DraggableWidgetsList::updateWidgets() {
    for (int i = 0; i < count()-_empty_count; i++) {
        qobject_cast<DraggableWidget*>(layout()->itemAt(i)->widget())->updateWidget();
    }
}
