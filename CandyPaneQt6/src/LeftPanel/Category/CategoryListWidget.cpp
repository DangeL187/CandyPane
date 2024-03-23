#include <iostream> // todo: delete

#include "Draggable/DraggableWidgetsList.hpp"
#include "LeftPanel/Category/CategoryListWidget.hpp"
#include "LeftPanel/Category/CategoryWidget.hpp"

CategoryListWidget::CategoryListWidget(QWidget* parent_widget, candypane::CategoryList* category_list):
    DraggableWidgetsList(parent_widget), _category_list(category_list) {}

void CategoryListWidget::addCategoryWidget() {
    candypane::Category new_category(_category_list);
    new_category.setName(".");
    _category_list->addCategory(new_category);

    auto* new_category_widget = new CategoryWidget(this, _category_list->getCategoriesSize()-1);
    DraggableWidgetsList::addWidget(new_category_widget);

    //
    std::string temp_str = "wish u luck_" + std::to_string(_category_list->getCategoriesSize());
    candypane::Task task; task.setName(temp_str); task.setText("yeah");
    new_category_widget->self().addTask(task);
    //

    new_category_widget->updateWidget();
    new_category_widget->setEditNameFocus();

    temp++;
    if (temp > 2) {
        std::cerr << "Loading tasks...\n";
        candypane::Task task0; task0.setName("luck1"); task0.setText("f1");
        candypane::Task task1; task1.setName("luck2"); task1.setText("f2");
        candypane::Task task2; task2.setName("luck3"); task2.setText("f3");
        _category_list->getCategoryById(1).setTasks({task0, task1, task2});
        qobject_cast<CategoryWidget*>(layout()->itemAt(1)->widget())->updateWidget();
    }
}

candypane::Category& CategoryListWidget::getCategoryById(unsigned long long category_id) {
    return _category_list->getCategoryById(category_id);
}

void CategoryListWidget::relocateCategoryWidget(unsigned int category_id) {
    int new_index = getNewIndex();
    if (new_index != -1) {
        if (category_id == _category_list->getSelectedCategoryId()) {
            _category_list->setSelectedCategoryId(new_index);
        }
        _category_list->relocateCategoryById(new_index, category_id);
        relocateWidget(new_index, category_id);
    }
}

void CategoryListWidget::removeCategoryWidgetById(unsigned int category_id) {
    if (_category_list->getSelectedCategoryId() > category_id) {
        _category_list->setSelectedCategoryId(_category_list->getSelectedCategoryId()-1);
    }
    removeWidgetById(category_id);
    _category_list->removeCategoryById(category_id);
}

void CategoryListWidget::setSelectedCategoryId(unsigned long long category_id) {
    _category_list->setSelectedCategoryId(category_id);
}
