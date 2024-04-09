#include "MainTaskList/Task/NewTaskWidget.hpp"
#include "Draggable/WidgetBackground.hpp"

NewTaskWidget::NewTaskWidget(TaskListWidget* task_list_widget): _task_list_widget(task_list_widget) {
    _background = std::make_shared<WidgetBackground>(this);
    initIcon();
    initText();
    initLayout();
    loadStyle();
    selectBackground(false);
}

void NewTaskWidget::initIcon() {
    _icon.setFixedSize(20, 20);
}

void NewTaskWidget::initLayout() {
    _layout.setContentsMargins(10, 15, 10, 15);
    _layout.addWidget(&_icon);
    _layout.addWidget(&_text);
    setLayout(&_layout);
}

void NewTaskWidget::initText() {
    _text.setText("Add task");
}

void NewTaskWidget::loadStyle() {
    _background->setColor(55, 55, 55);
    _background->setOffColor(46, 47, 48);
    //_icon.setStyleSheet("background-color: orange");
    _icon.setStyleSheet("background-color: transparent; image: url(../img/plus2.png);");
    _text.setStyleSheet("background-color: transparent; color: rgb(118, 185, 237); font-size: 16px;");
}

void NewTaskWidget::mousePressEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        _task_list_widget->addTaskWidget();
        setVisible(false);
    }
}

void NewTaskWidget::resizeEvent(QResizeEvent* event) {
    _background->setFixedSize(size());
}

void NewTaskWidget::selectBackground(bool value) {
    _background->select(value);
}
