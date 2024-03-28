#include <QMouseEvent>

#include "Draggable/DraggableWidget.hpp"
#include "Draggable/OverlayDraggableWidget.hpp"

DraggableWidget::DraggableWidget(unsigned long long int id): _id(id) {
    _select_background = std::make_shared<WidgetBackground>(this);
    initLayout();
}

unsigned long long int DraggableWidget::getId() const {
    return _id;
}

void DraggableWidget::initLayout() {
    setLayout(&_layout);
}

void DraggableWidget::loadBackgroundStyle(unsigned short widget_type) {
    if (widget_type == 0) {
        _select_background->setColor(49, 49, 49); // todo: take from: CategoryWidgetStyle.css#background-color
    }
    else if (widget_type == 1) {
        _select_background->setColor(55, 55, 55); // todo: take from: TaskWidgetStyle.css#background-color
        _select_background->setOffColor(46, 47, 48); // todo: take from: TaskWidgetStyle.css#background-off-color
    }
}

void DraggableWidget::onMousePress(QMouseEvent* event) {
    _drag_start_pos = event->globalPosition().toPoint() - mapToGlobal(rect().topLeft());

    _dragged_object = new OverlayDraggableWidget(*this);
    _dragged_object->show();
    _dragged_object->move(event->globalPosition().toPoint() - _drag_start_pos);
}

void DraggableWidget::onMouseMove(QMouseEvent* event) {
    QPoint pos = event->globalPosition().toPoint();
    pos -= _drag_start_pos;
    _dragged_object->move(pos);
}

bool DraggableWidget::onMouseRelease(QMouseEvent* event) {
    if (_dragged_object != nullptr) {
        _dragged_object->close();
        delete _dragged_object;
        _dragged_object = nullptr;
        return true;
    } else {
        return false;
    }
}

void DraggableWidget::onResize(QResizeEvent* event) {
    _select_background->setFixedSize(size());
}

void DraggableWidget::selectBackground(bool value) {
    if (value) _select_background->select(true);
    else _select_background->select(false);
}

void DraggableWidget::setId(unsigned long long int id) {
    _id = id;
}
