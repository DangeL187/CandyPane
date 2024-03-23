#include <iostream> // todo: delete

#include <QPainter>

#include "Draggable/OverlayDraggableWidget.hpp"
#include "LeftPanel/Category/CategoryWidget.hpp"
#include "LeftPanel/Category/CategoryListWidget.hpp"
#include "LeftPanel/Category/LineEditCategoryName.hpp"

CategoryWidget::CategoryWidget(CategoryListWidget* category_list_widget, unsigned long long int id):
    _category_list_widget(category_list_widget), DraggableWidget(id)
{
    loadStyle();
    initSelect();
    initIcon();
    initTasksAmount();
    initName();
    initLayout();
    initEditName();
}

void CategoryWidget::exec() {
    if (_edit_name->text() == "") {
        _category_list_widget->removeCategoryWidgetById(getId());
        return;
    }
    self().setName(_edit_name->text().toStdString());
    _edit_name->setVisible(false);
    _layout.insertWidget(2, _name);
    updateName();
}

candypane::Category& CategoryWidget::self() const {
    return _category_list_widget->getCategoryById(getId());
}

void CategoryWidget::initEditName() {
    _edit_name = new LineEditCategoryName(this);
    _edit_name->setStyleSheet("font-size: 14px;");

    _layout.removeWidget(_name);
    _layout.insertWidget(2, _edit_name);
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
    loadBackgroundStyle();
}

void CategoryWidget::mousePressEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        std::cout << "####\n" << self().getName() << " id: " << getId() << "\n";
        for (auto& i: self().getTasks()) {
            std::cout << i.getName() << " " << i.getText() << "\n";
        } std::cout << "####\n\n";

        select(true);
        onMousePress(event);

        setWidgetVisible(false);
        _category_list_widget->deselectAll<CategoryWidget>();
    }
}

void CategoryWidget::mouseMoveEvent(QMouseEvent* event) {
    if (event->buttons() & Qt::LeftButton) {
        onMouseMove(event);
        _category_list_widget->relocateCategoryWidget(_category_list_widget->indexOf(this));
    }
}

void CategoryWidget::mouseReleaseEvent(QMouseEvent* event) {
    if (onMouseRelease(event)) {
        setWidgetVisible(true);
        _category_list_widget->updateWidgets();
    }
}

void CategoryWidget::resizeEvent(QResizeEvent* event) {
    onResize(event);
    updateName();
}

void CategoryWidget::select(bool value, bool background_only) {
    if (!background_only) {
        if (value) {
            _category_list_widget->setSelectedCategoryId(getId());
            _select->setStyleSheet("background-color: rgb(118, 185, 237);");
        } else {
            _select->setStyleSheet("background-color: transparent;");
        }
    }
    if (value) {
        selectBackground(true);
    } else if (_select->styleSheet() == "background-color: transparent;") {
        selectBackground(false);
    }
}

void CategoryWidget::setEditNameFocus() {
    _edit_name->setFocus();
}

void CategoryWidget::setWidgetVisible(bool value) {
    if (value) {
        _icon->setStyleSheet("background-color: red;");
        updateName();
        updateTasksAmount();
    } else {
        _icon->setStyleSheet("background-color: transparent");
        _name->setText("");
        _tasks_amount->setText("");
    }
    select(value);
}

void CategoryWidget::updateName() {
    _name->setStyleSheet("font-size: 14px;");
    _name->setText(self().getName().c_str());

    QLabel new_text;
    new_text.setStyleSheet("font-size: 14px;");
    new_text.setText((self().getName() + "...").c_str());
    new_text.setFont(_name->font());

    int name_width = _name->fontMetrics().boundingRect(_name->text()).width();
    int tasks_width = _tasks_amount->fontMetrics().boundingRect(_tasks_amount->text()).width();
    int max_size = width() - _select->width() - _icon->width() - tasks_width - 54;

    if (name_width > max_size) {
        while (new_text.fontMetrics().boundingRect(new_text.text()).width() > max_size) {
            std::string str = new_text.text().toStdString();
            str.erase(str.length() - 4, 1);
            new_text.setText(str.c_str());
        }
        _name->setText(new_text.text());
    }
}

void CategoryWidget::updateTasksAmount() {
    _tasks_amount->setText(std::to_string(self().getTasks().size()).c_str());
    _tasks_amount->setStyleSheet("font-size: 14px;");
}

void CategoryWidget::updateWidget() {
    //updateIcon();
    updateTasksAmount();
    updateName();
}
