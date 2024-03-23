#include <QPainter>
#include <QStyle>
#include <QStyleOption>

#include "DraggableWidget.hpp"
#include "OverlayDraggableWidget.hpp"

OverlayDraggableWidget::OverlayDraggableWidget(DraggableWidget& draggable_widget): QDialog(nullptr) {
    setWindowOpacity(0.7);
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);

    initSelect();
    initIcon();
    initName();
    initTasksAmount();
    initLayout();

    resize(draggable_widget.size());
}

void OverlayDraggableWidget::initIcon() {
    _icon = std::make_shared<QWidget>();
    _icon->setStyleSheet("background-color: red;");
    _icon->setFixedSize(20, 20);
}

void OverlayDraggableWidget::initLayout() {
    _layout = std::make_shared<QHBoxLayout>(this);
    _layout->setContentsMargins(0, 5, 0, 5);

    _layout->addWidget(_select.get());
    _layout->addWidget(_icon.get());
    _layout->addWidget(_name.get());
    _layout->addWidget(_tasks_amount.get());
}

void OverlayDraggableWidget::initName() {
    //_name = std::make_shared<QLabel>(category_widget.self().getName().c_str());
    _name = std::make_shared<QLabel>("temp name");
    _name->setStyleSheet("font-size: 14px;");
}

void OverlayDraggableWidget::initSelect() {
    _select = std::make_shared<QWidget>();
    _select->setStyleSheet("background-color: rgb(118, 185, 237);");
    _select->setFixedSize(3, 15);
}

void OverlayDraggableWidget::initTasksAmount() {
    //_tasks_amount = std::make_shared<QLabel>(std::to_string(category_widget.self().getTasks().size()).c_str());
    _tasks_amount = std::make_shared<QLabel>("13");
    _tasks_amount->setAlignment(Qt::AlignRight);
    _tasks_amount->setContentsMargins(0, 0, 10, 0);
    _tasks_amount->setStyleSheet("font-size: 14px;");
}

void OverlayDraggableWidget::paintEvent(QPaintEvent* event) {
    QPainter p(this);
    QRectF rect(QPointF(0, 0), size());
    p.setRenderHint(QPainter::Antialiasing);
    p.setPen(Qt::NoPen);
    p.setBrush(QColor(49, 49, 49));
    p.drawRoundedRect(rect, 6, 6, Qt::AbsoluteSize);
    p.end();
}
