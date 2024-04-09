#include "LeftPanel/Category/CategoryWidget.hpp"
#include "LeftPanel/LeftPanel.hpp"

LeftPanel::LeftPanel(candypane::CategoryList* category_list, MainTaskList* main_task_list) {
    initModules(category_list, main_task_list);
    initCategoryListScrollArea();
    initLayout();

    setMinimumWidth(1920/9);
    setMaximumWidth(1920/5);
}

void LeftPanel::checkHover() {
    for (int i = 0; i < _category_list_widget->count()-1; i++) {
        auto category_widget = qobject_cast<CategoryWidget*>(_category_list_widget->itemAt(i)->widget());
        QRect rect(category_widget->mapToGlobal(category_widget->rect().topLeft()), category_widget->size());

        if (rect.contains(QCursor::pos()) && !category_widget->underMouse()) {
            category_widget->select(true, true, true);
        } else if (category_widget->underMouse()) {
            category_widget->select(true, true);
        } else {
            category_widget->select(false, true);
        }
    }
}

void LeftPanel::initCategoryListScrollArea() {
    _scroll_area.setFrameShape(QFrame::NoFrame);
    _scroll_area.setWidgetResizable(true);
    _scroll_area.setWidget(&_scroll_area_widget);
}

void LeftPanel::initLayout() {
    _layout.setSpacing(0);
    _layout.setContentsMargins(6, 0, 0, 10);

    _account_widget.setFixedHeight(30); //temp
    _account_widget.setStyleSheet("background-color: blue;"); //temp

    _layout.addWidget(&_account_widget);
    _layout.addWidget(&_scroll_area);
    _layout.addWidget(_new_list_widget.get());

    setLayout(&_layout);
}

void LeftPanel::initModules(candypane::CategoryList* category_list, MainTaskList* main_task_list) {
    _category_list_widget = std::make_shared<CategoryListWidget>(&_scroll_area_widget, category_list, main_task_list);
    _new_list_widget = std::make_shared<NewListWidget>(_category_list_widget.get());
}

void LeftPanel::updateLeftPanel() {
    for (int i = 0; i < _category_list_widget->count()-1; i++) {
        auto category_widget = qobject_cast<CategoryWidget*>(_category_list_widget->itemAt(i)->widget());
        category_widget->updateWidget();
    }
}
