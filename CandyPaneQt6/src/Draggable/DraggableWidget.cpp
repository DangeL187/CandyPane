#include <QMouseEvent>

#include "Draggable/DraggableWidget.hpp"
#include "Draggable/OverlayDraggableWidget.hpp"

DraggableWidget::DraggableWidget(unsigned long long int id): _id(id) {
    _select_background = std::make_shared<WidgetBackground>(this);
    initLayout();
}

void DraggableWidget::blockDragging(bool value) {
    _is_dragging_blocked = value;
}

unsigned long long int DraggableWidget::getId() const {
    return _id;
}

QHBoxLayout& DraggableWidget::getLayout() {
    return _layout;
}

void DraggableWidget::initLayout() {
    setLayout(&_layout);
}

bool DraggableWidget::isDragging() {
    return (_dragged_object != nullptr);
}

void DraggableWidget::loadBackgroundStyle(unsigned short widget_type) {
    if (widget_type == 0) {
        _select_background->setColor(49, 49, 49); // todo: take from: CategoryWidgetStyle.css#background-color
        _select_background->setBorderColor(200, 200, 200); // todo: take from: CategoryWidgetStyle.css#border-color
    }
    else if (widget_type == 1) {
        _select_background->setColor(55, 55, 55); // todo: take from: TaskWidgetStyle.css#background-color
        _select_background->setOffColor(46, 47, 48); // todo: take from: TaskWidgetStyle.css#background-off-color
    }
}

bool DraggableWidget::onMousePress(QMouseEvent* event) {
    if (!_is_dragging_blocked) {
        _drag_start_pos = event->globalPosition().toPoint() - mapToGlobal(rect().topLeft());

        _dragged_object = new OverlayDraggableWidget(*this);
        _dragged_object->show();
        _dragged_object->move(event->globalPosition().toPoint() - _drag_start_pos);

        return true;
    }
    return false;
}

bool DraggableWidget::onMouseMove(QMouseEvent* event) {
    if (_dragged_object != nullptr) {
        QPoint pos = event->globalPosition().toPoint();
        pos -= _drag_start_pos;
        _dragged_object->move(pos);

        return true;
    } else {
        return false;
    }
}

bool DraggableWidget::onMouseRelease(QMouseEvent* event) {
    _is_dragging_blocked = false;
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

void DraggableWidget::selectBackground(bool value, bool border) {
    _select_background->select(value, border);
}

void DraggableWidget::setId(unsigned long long int id) {
    _id = id;
}
