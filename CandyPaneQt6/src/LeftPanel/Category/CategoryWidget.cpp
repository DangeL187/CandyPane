#include <QPainter>

#include "Draggable/OverlayDraggableWidget.hpp"
#include "LeftPanel/Category/CategoryContextMenu.hpp"
#include "LeftPanel/Category/CategoryListWidget.hpp"
#include "LeftPanel/Category/CategoryWidget.hpp"
#include "Draggable/LineEditName.hpp"

CategoryWidget::CategoryWidget(CategoryListWidget* category_list_widget, unsigned long long int id):
    _category_list_widget(category_list_widget), DraggableWidget(id)
{
    initContextMenu();
    initSelect();
    initIcon();
    initTasksAmount();
    initName();
    initLayout();
    initEditName();
    loadStyle();
    selectBackground(true);
}

candypane::Category& CategoryWidget::self() const {
    return _category_list_widget->getCategoryById(getId());
}

void CategoryWidget::checkHover() {
    if (underMouse()) {
        select(true, true);
    } else {
        select(false, true);
    }
}

void CategoryWidget::contextMenuEvent(QContextMenuEvent* event) {
    _context_menu->exec(event->globalPos());
}

void CategoryWidget::duplicate() {
    _category_list_widget->duplicateCategoryWidgetById(getId());
}

void CategoryWidget::initContextMenu() {
    _context_menu = std::make_shared<CategoryContextMenu>(this);
}

void CategoryWidget::initEditName() {
    _edit_name = new LineEditName<CategoryWidget>(this);
}

void CategoryWidget::initIcon() {
    _icon = new QWidget();
    _icon->setFixedSize(20, 20);
    _icon->setStyleSheet("background-color: red;");
}

void CategoryWidget::initName() {
    _name = new QLabel();
    updateName();
}

void CategoryWidget::initSelect() {
    _select = new QWidget();
    _select->setFixedSize(3, 15);
    select(true);
    _category_list_widget->deselectAll<CategoryWidget>();
}

void CategoryWidget::initTasksAmount() {
    _tasks_amount = new QLabel();
    _tasks_amount->setAlignment(Qt::AlignRight);
    _tasks_amount->setContentsMargins(0, 0, 10, 0);
    updateTasksAmount();
}

void CategoryWidget::initLayout() {
    _layout.setContentsMargins(0, 5, 0, 5);

    _layout.addWidget(_select);
    _layout.addWidget(_icon);
    _layout.addWidget(_name);
    _layout.addWidget(_tasks_amount);
}

void CategoryWidget::loadStyle() {
    loadBackgroundStyle(0);
    _edit_name->setStyleSheet("font-size: 16px;");
    _name->setStyleSheet("background-color: transparent; font-size: 16px;");
    _tasks_amount->setStyleSheet("background-color: transparent; font-size: 16px;");
}

void CategoryWidget::mousePressEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        select(true);
        if (onMousePress(event)) {
            setWidgetVisible(false);
            _category_list_widget->deselectAll<CategoryWidget>();
        }
    }
}

void CategoryWidget::mouseMoveEvent(QMouseEvent* event) {
    if (event->buttons() & Qt::LeftButton) {
        if (onMouseMove(event)) {
            _category_list_widget->relocateCategoryWidget(_category_list_widget->indexOf(this));
        }
    }
}

void CategoryWidget::mouseReleaseEvent(QMouseEvent* event) {
    if (onMouseRelease(event)) {
        setWidgetVisible(true);
        _category_list_widget->updateWidgets();
    }
}

void CategoryWidget::remove() {
    _category_list_widget->removeCategoryWidgetById(getId());
}

void CategoryWidget::resizeEvent(QResizeEvent* event) {
    onResize(event);
    updateName();
}

void CategoryWidget::select(bool value, bool background_only, bool highlight_border) {
    if (!background_only) {
        if (value) {
            _category_list_widget->updateMainTaskList();
            _category_list_widget->setSelectedCategoryId(getId());
            _select->setStyleSheet("background-color: rgb(118, 185, 237);");
        } else {
            _select->setStyleSheet("background-color: transparent;");
        }
    }

    if (value) {
        selectBackground(true, highlight_border);
    } else if (_select->styleSheet() == "background-color: transparent;") {
        selectBackground(false);
    } else {
        selectBackground(true, false);
    }

    if (highlight_border) {
        _category_list_widget->setHoveredCategoryId(signed(getId()));
    } else if (getId() == _category_list_widget->getHoveredCategoryId()){
        _category_list_widget->setHoveredCategoryId(-1);
    }
}

void CategoryWidget::setEditMode(bool value, bool first_time) {
    if (value) {
        _layout.removeWidget(_name);
        _layout.insertWidget(2, _edit_name);
        _edit_name->setVisible(true);
        _edit_name->setFocus();
        if (!first_time) _edit_name->setText(self().getName().c_str());
    } else {
        if (_edit_name->text() == "") {
            _category_list_widget->removeCategoryWidgetById(getId());
            return;
        }
        self().setName(_edit_name->text().toStdString());
        _edit_name->clearFocus();
        _edit_name->setVisible(false);
        _layout.insertWidget(2, _name);
        updateName();
        _category_list_widget->updateMainTaskList();
    }
}

void CategoryWidget::setWidgetVisible(bool value) {
    if (value) {
        _icon->setStyleSheet("background-color: red;");
        updateName();
        updateTasksAmount();
        //todo: replace with updateWidget
    } else {
        _icon->setStyleSheet("background-color: transparent");
        _name->setText("");
        _tasks_amount->setText("");
    }
    select(value);
}

void CategoryWidget::updateName() {
    _name->setText(self().getName().c_str());

    int name_width = _name->fontMetrics().boundingRect(_name->text()).width();
    int tasks_width = _tasks_amount->fontMetrics().boundingRect(_tasks_amount->text()).width();
    int max_size = width() - _select->width() - _icon->width() - tasks_width - 54;

    if (name_width > max_size) {
        QLabel new_text;
        new_text.setStyleSheet(_name->styleSheet());
        new_text.setText((self().getName() + "...").c_str());
        new_text.setFont(_name->font());

        while (new_text.fontMetrics().boundingRect(new_text.text()).width() > max_size) {
            std::string str = (QString::fromLocal8Bit(new_text.text().toLocal8Bit())).toStdString();
            str.erase(str.length() - 4, 1);
            new_text.setText(str.c_str());
        }
        _name->setText(new_text.text());
    }
}

void CategoryWidget::updateTasksAmount() { // todo: show only amount of uncompleted tasks
    _tasks_amount->setText(std::to_string(self().getTasks().size()).c_str());
}

void CategoryWidget::updateWidget() {
    if (!isDragging()) {
        //updateIcon();
        updateTasksAmount();
        updateName();
    }
}
