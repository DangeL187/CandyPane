#include <iostream> // todo: delete

#include "Draggable/DraggableWidgetsList.hpp"
#include "LeftPanel/Category/CategoryListWidget.hpp"
#include "LeftPanel/Category/CategoryWidget.hpp"

CategoryListWidget::CategoryListWidget(QWidget* parent_widget, candypane::CategoryList* category_list, MainTaskList* main_task_list):
    DraggableWidgetsList(parent_widget), _category_list(category_list), _main_task_list(main_task_list) {}

void CategoryListWidget::addCategoryWidget() {
    candypane::Category new_category(_category_list);
    new_category.setName(".");
    _category_list->addCategory(new_category);

    auto* new_category_widget = new CategoryWidget(this, _category_list->getCategoriesSize()-1);
    DraggableWidgetsList::addWidget(new_category_widget);

    new_category_widget->updateWidget();
    new_category_widget->setEditMode(true);
}

void CategoryListWidget::duplicateCategoryWidgetById(unsigned long long category_id) {
    candypane::Category new_category(_category_list);
    new_category.setName(getCategoryById(category_id).getName());
    new_category.setTasks(getCategoryById(category_id).getTasks());
    _category_list->addCategory(new_category);

    auto* new_category_widget = new CategoryWidget(this, _category_list->getCategoriesSize()-1);
    DraggableWidgetsList::addWidget(new_category_widget);
}

candypane::Category& CategoryListWidget::getCategoryById(unsigned long long category_id) {
    return _category_list->getCategoryById(category_id);
}

long long CategoryListWidget::getHoveredCategoryId() {
    return _category_list->getHoveredId();
}

void CategoryListWidget::relocateCategoryWidget(unsigned int category_id) {
    int new_index = getNewIndex();
    if (new_index != -1) {
        _category_list->relocateCategoryById(new_index, category_id);
        relocateWidget(new_index, category_id);
    }
}

void CategoryListWidget::removeCategoryWidgetById(unsigned int category_id) {
    removeWidgetById(category_id);
    _category_list->removeCategoryById(category_id);

    if (_category_list->getCategoriesSize() != 0) {
        unsigned long long selected_id = _main_task_list->getSelectedCategoryId();
        if (selected_id >= category_id) {
            qobject_cast<CategoryWidget*>(layout()->itemAt(int(selected_id) - 1)->widget())->select(true);
        } else {
            qobject_cast<CategoryWidget*>(layout()->itemAt(int(selected_id))->widget())->select(true);
        }
    }

    _main_task_list->updateTaskList();
}

void CategoryListWidget::setHoveredCategoryId(long long category_id) {
    _category_list->setHoveredId(category_id);
}

void CategoryListWidget::setSelectedCategoryId(unsigned long long category_id) {
    _main_task_list->setSelectedCategoryId(category_id);
}

void CategoryListWidget::updateMainTaskList() {
    _main_task_list->updateTaskList();
}
