#include "MainTaskList/Task/TaskContentsWidget.hpp"
#include "MainTaskList/Task/TaskContextMenu.hpp"
#include "MainTaskList/Task/TaskListWidget.hpp"
#include "MainTaskList/Task/TaskWidget.hpp"

TaskWidget::TaskWidget(TaskListWidget* task_list_widget, unsigned long long id):
    _task_list_widget(task_list_widget), DraggableWidget(id)
{
    initCalendarMenu();
    initContextMenu();
    initCheckbox();
    initEditName();
    initStar();
    initTaskContents();
    initLayout();
    loadStyle();
    selectBackground(false);
    TaskWidget::updateWidget();
}

candypane::Task& TaskWidget::self() const {
    return _task_list_widget->getTaskById(getId());
}

void TaskWidget::contextMenuEvent(QContextMenuEvent* event) {
    _context_menu->exec(event->globalPos());
}

void TaskWidget::execCalendarMenu() {
    QDate current_date = QDate::currentDate();
    _calendar_menu->setCurrentPage(current_date.year(), current_date.month());
    _calendar_menu->setSelectedDate(current_date);
    _calendar_menu->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);
    _calendar_menu->show();
}

void TaskWidget::initCalendarMenu() {
    _calendar_menu = std::make_shared<QCalendarWidget>(_task_list_widget->widget());
    QObject::connect(_calendar_menu.get(), &QCalendarWidget::clicked, [&]() {
        self().setDueDate(candypane::Date(
                _calendar_menu->selectedDate().day(),
                _calendar_menu->selectedDate().month(),
                _calendar_menu->selectedDate().year()));
        _calendar_menu->close();
        updateWidget();
    });
}

void TaskWidget::initCheckbox() {
    _checkbox = new QCheckBox();
    _checkbox->setFixedSize(20, 20);
    updateCheckbox();

    QObject::connect(_checkbox, &QCheckBox::toggled, [this]()
    {
        self().setCompleted(_checkbox->isChecked());
    });
}

void TaskWidget::initContextMenu() {
    _context_menu = std::make_shared<TaskContextMenu>(this);
}

void TaskWidget::initEditName() {
    _edit_name = new LineEditName<TaskWidget>(this);
}

void TaskWidget::initLayout() {
    _layout.setContentsMargins(10, 15, 10, 15);

    _layout.addWidget(_checkbox);
    _layout.addWidget(_task_contents.get());
    _layout.addWidget(_star);
}

void TaskWidget::initStar() {
    _star = new QCheckBox();
    _star->setFixedSize(20, 20);

    QObject::connect(_star, &QCheckBox::toggled, [this]()
    {
        self().setFavourite(_star->isChecked());
    });
}

void TaskWidget::initTaskContents() {
    _task_contents = std::make_shared<TaskContentsWidget>();
}

void TaskWidget::loadStyle() {
    loadBackgroundStyle(1);
    _task_contents->loadStyle();
    _checkbox->setStyleSheet("QCheckBox { background-color: transparent; }"
                             "QCheckBox::indicator { width: 20px; height: 19px; }"
                             "QCheckBox::indicator:unchecked { image: url(../img/checkbox_unchecked.png); }"
                             "QCheckBox::indicator:unchecked:hover { image: url(../img/checkbox_unchecked_hover.png); }"
                             "QCheckBox::indicator:checked { image: url(../img/checkbox_checked.png); }");
    _edit_name->setStyleSheet("font-size: 16px;");
    _star->setStyleSheet("QCheckBox { background-color: transparent; }"
                         "QCheckBox::indicator { width: 20px; height: 19px; }"
                         "QCheckBox::indicator:unchecked { image: url(../img/checkbox_unchecked.png); }"
                         "QCheckBox::indicator:unchecked:hover { image: url(../img/checkbox_unchecked_hover.png); }"
                         "QCheckBox::indicator:checked { image: url(../img/checkbox_checked.png); }");
}

void TaskWidget::mousePressEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        if (onMousePress(event)) {
            setWidgetVisible(false);
            _task_list_widget->deselectAll<TaskWidget>();
        }
    }
}

void TaskWidget::mouseMoveEvent(QMouseEvent* event) {
    if (event->buttons() & Qt::LeftButton && !_checkbox->underMouse() && !_star->underMouse()) {
        if (onMouseMove(event)) {
            _task_list_widget->relocateTaskWidget(_task_list_widget->indexOf(this));
        }
    }
}

void TaskWidget::mouseReleaseEvent(QMouseEvent* event) {
    if (onMouseRelease(event)) {
        setWidgetVisible(true);
        _task_list_widget->updateWidgets();
        _task_list_widget->changeCategory(getId());
    }
}

void TaskWidget::remove() {
    _task_list_widget->removeTaskWidgetById(getId());
}

void TaskWidget::resizeEvent(QResizeEvent* event) {
    onResize(event);
    if (_is_visible) {
        _task_contents->updateContents(self());
        _old_size = size();
    } else {
        //resize(_old_size); // todo: keep size when dragging, priority: slightly low
    }
}

void TaskWidget::setEditMode(bool value, bool first_time) {
    if (value) {
        _task_contents->setVisible(false);
        _layout.removeWidget(_task_contents.get());
        _layout.insertWidget(1, _edit_name);
        _edit_name->setVisible(true);
        _edit_name->setFocus();
        if (!first_time) {
            _edit_name->setText(self().getName().c_str());
        }
    } else {
        _task_list_widget->revealNewTaskWidget();
        if (_edit_name->text() == "") {
            _task_list_widget->removeTaskWidgetById(getId());
            return;
        }
        _task_contents->setVisible(true);
        self().setName(_edit_name->text().toStdString());
        _edit_name->clearFocus();
        _edit_name->setVisible(false);
        _layout.insertWidget(1, _task_contents.get());
        _task_contents->updateContents(self());
    }
}

void TaskWidget::setWidgetVisible(bool value) {
    if (value) {
        _is_visible = true;
        updateWidget();
    } else {
        _is_visible = false;
        _checkbox->setStyleSheet("QCheckBox { background-color: transparent; }"
                                 "QCheckBox::indicator:unchecked { background-color: transparent; }"
                                 "QCheckBox::indicator:unchecked:hover { background-color: transparent; }"
                                 "QCheckBox::indicator:checked { background-color: transparent; }");
        _task_contents->setWidgetVisible(false);
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
    _task_contents->updateContents(self());
    updateStar();
}
