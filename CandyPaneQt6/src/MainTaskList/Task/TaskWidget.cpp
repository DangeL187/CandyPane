#include "MainTaskList/Task/TaskListWidget.hpp"
#include "MainTaskList/Task/TaskWidget.hpp"

TaskWidget::TaskWidget(TaskListWidget* task_list_widget, unsigned long long id):
    _task_list_widget(task_list_widget), DraggableWidget(id)
{
    initCheckbox();
    initName();
    initStar();
    initLayout();
    //initEditName();
    loadStyle();
    selectBackground(false);
    QObject::connect(_checkbox, &QCheckBox::toggled, [this]()
    {
        self().setCompleted(_checkbox->isChecked());
    });
    QObject::connect(_star, &QCheckBox::toggled, [this]()
    {
        self().setFavourite(_star->isChecked());
    });
}

candypane::Task& TaskWidget::self() const {
    return _task_list_widget->getTaskById(getId());
}

void TaskWidget::initCheckbox() {
    _checkbox = new QCheckBox();
    _checkbox->setFixedSize(20, 20);
    updateCheckbox();
}

void TaskWidget::initName() {
    _name = new QLabel();
    updateName();
}

void TaskWidget::initLayout() {
    _layout.setContentsMargins(10, 15, 10, 15);

    _layout.addWidget(_checkbox);
    _layout.addWidget(_name);
    _layout.addWidget(_star);
}

void TaskWidget::initStar() {
    _star = new QCheckBox();
    _star->setFixedSize(20, 20);
    updateStar();
}

void TaskWidget::loadStyle() {
    loadBackgroundStyle(1);
    _checkbox->setStyleSheet("QCheckBox { background-color: transparent; }"
                             "QCheckBox::indicator { width: 20px; height: 19px; }"
                             "QCheckBox::indicator:unchecked { image: url(../img/checkbox_unchecked.png); }"
                             "QCheckBox::indicator:unchecked:hover { image: url(../img/checkbox_unchecked_hover.png); }"
                             "QCheckBox::indicator:checked { image: url(../img/checkbox_checked.png); }");
    _name->setStyleSheet("background-color: transparent; font-size: 14px;");
    _star->setStyleSheet("QCheckBox { background-color: transparent; }"
                         "QCheckBox::indicator { width: 20px; height: 19px; }"
                         "QCheckBox::indicator:unchecked { image: url(../img/checkbox_unchecked.png); }"
                         "QCheckBox::indicator:unchecked:hover { image: url(../img/checkbox_unchecked_hover.png); }"
                         "QCheckBox::indicator:checked { image: url(../img/checkbox_checked.png); }");
}

void TaskWidget::mousePressEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        selectBackground(true);
        onMousePress(event);

        setWidgetVisible(false);
        _task_list_widget->deselectAll<TaskWidget>();
    }
}

void TaskWidget::mouseMoveEvent(QMouseEvent* event) {
    if (event->buttons() & Qt::LeftButton && !_checkbox->underMouse() && !_star->underMouse()) {
        onMouseMove(event);
        _task_list_widget->relocateTaskWidget(_task_list_widget->indexOf(this));
    }
}

void TaskWidget::mouseReleaseEvent(QMouseEvent* event) {
    if (onMouseRelease(event)) {
        setWidgetVisible(true);
        _task_list_widget->updateWidgets();
    }
}

void TaskWidget::resizeEvent(QResizeEvent* event) {
    onResize(event);
    updateName();
}

void TaskWidget::setWidgetVisible(bool value) {
    if (value) {
        updateWidget();
    } else {
        _checkbox->setStyleSheet("QCheckBox { background-color: transparent; }"
                                 "QCheckBox::indicator:unchecked { background-color: transparent; }"
                                 "QCheckBox::indicator:unchecked:hover { background-color: transparent; }"
                                 "QCheckBox::indicator:checked { background-color: transparent; }");
        _name->setText("");
        _star->setStyleSheet("QCheckBox { background-color: transparent; }"
                             "QCheckBox::indicator:unchecked { background-color: transparent; }"
                             "QCheckBox::indicator:unchecked:hover { background-color: transparent; }"
                             "QCheckBox::indicator:checked { background-color: transparent; }");
    }
    selectBackground(value);
}

void TaskWidget::updateCheckbox() {
    _checkbox->setChecked(self().isCompleted());
    _checkbox->setStyleSheet("QCheckBox { background-color: transparent; }"
                             "QCheckBox::indicator { width: 20px; height: 19px; }"
                             "QCheckBox::indicator:unchecked { image: url(../img/checkbox_unchecked.png); }"
                             "QCheckBox::indicator:unchecked:hover { image: url(../img/checkbox_unchecked_hover.png); }"
                             "QCheckBox::indicator:checked { image: url(../img/checkbox_checked.png); }");
}

void TaskWidget::updateName() {
    _name->setText(self().getName().c_str());
}

void TaskWidget::updateStar() {
    _star->setChecked(self().isFavourite());
    _star->setStyleSheet("QCheckBox { background-color: transparent; }"
                         "QCheckBox::indicator { width: 20px; height: 19px; }"
                         "QCheckBox::indicator:unchecked { image: url(../img/checkbox_unchecked.png); }"
                         "QCheckBox::indicator:unchecked:hover { image: url(../img/checkbox_unchecked_hover.png); }"
                         "QCheckBox::indicator:checked { image: url(../img/checkbox_checked.png); }");
}

void TaskWidget::updateWidget() {
    updateCheckbox();
    updateName();
    updateStar();
}
