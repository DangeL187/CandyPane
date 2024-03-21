#include <iostream> // todo: delete

#include "DraggableWidgetsList.hpp"
#include "LeftPanel/Category/CategoriesListWidget.hpp"
#include "LeftPanel/Category/CategoryWidget.hpp"

CategoriesListWidget::CategoriesListWidget(QWidget* parent_widget, candypane::Category* main_task_list):
    DraggableWidgetsList(parent_widget), candypane::CategoriesList(main_task_list)
{

}

void CategoriesListWidget::addCategoryWidget() {
    std::string temp_str = "wish u luck_" + std::to_string(getCategoriesSize());

    auto* new_category_widget = new CategoryWidget(this, getCategoriesSize()-1);
    candypane::Task task; task.setName(temp_str); task.setText("yeah");
    new_category_widget->self().addTask(task);
    insertWidget(count()-1, new_category_widget); // insert before spacer
    new_category_widget->updateWidget();
    new_category_widget->setEditNameFocus();

    temp++;
    if (temp > 2) {
        std::cerr << "Loading tasks...\n";
        candypane::Task task0; task0.setName("luck1"); task0.setText("f1");
        candypane::Task task1; task1.setName("luck2"); task1.setText("f2");
        candypane::Task task2; task2.setName("luck3"); task2.setText("f3");
        getCategoryById(1).setTasks({task0, task1, task2});
        qobject_cast<CategoryWidget*>(layout()->itemAt(1)->widget())->updateWidget();
    }
}
