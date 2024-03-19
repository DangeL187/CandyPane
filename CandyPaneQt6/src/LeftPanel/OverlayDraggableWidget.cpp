#include <QPainter>
#include "LeftPanel/OverlayDraggableWidget.hpp"

OverlayDraggableWidget::OverlayDraggableWidget(CategoryWidget& category_widget): QDialog(nullptr) {
    initSelect();
    initIcon();
    initName(category_widget);
    initTasksAmount(category_widget);
    initLayout();

    setWindowFlags(Qt::ToolTip);
    resize(category_widget.size());

    setObjectName("OverlayDraggableWidget");
}

void OverlayDraggableWidget::initIcon() {
    _icon = new QWidget();
    _icon->setStyleSheet("background-color: red;");
    _icon->setFixedSize(20, 20);
}

void OverlayDraggableWidget::initLayout() {
    _layout = std::make_shared<QHBoxLayout>(this);
    _layout->setContentsMargins(0, 5, 0, 5);

    _layout->addWidget(_select);
    _layout->addWidget(_icon);
    _layout->addWidget(_name);
    _layout->addWidget(_tasks_amount);
}

void OverlayDraggableWidget::initName(CategoryWidget& category_widget) {
    _name = new QLabel(category_widget.self().getName().c_str());
}

void OverlayDraggableWidget::initSelect() {
    _select = new QWidget();
    _select->setStyleSheet("background-color: rgb(118, 185, 237);");
    _select->setFixedSize(3, 15);
}

void OverlayDraggableWidget::initTasksAmount(CategoryWidget& category_widget) {
    _tasks_amount = new QLabel(std::to_string(category_widget.self().getTasks().size()).c_str());
    _tasks_amount->setAlignment(Qt::AlignRight);
    _tasks_amount->setContentsMargins(0, 0, 10, 0);
}

void OverlayDraggableWidget::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setBrush(QColor(49, 49, 49));
    painter.setPen(Qt::NoPen);
    painter.drawRoundedRect(rect(), 6, 6);
}

