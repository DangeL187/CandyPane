#include <iostream> // todo: delete

#include "LeftPanel/CategoriesListWidget.hpp"

CategoriesListWidget::CategoriesListWidget(QWidget* parent_widget, candypane::Category* main_task_list):
        QVBoxLayout(parent_widget), candypane::CategoriesList(main_task_list)
{
    initLayout();
}

void CategoriesListWidget::addCategoryWidget() {
    std::string temp_str = "wash yo ass_" + std::to_string(getCategoriesSize());

    auto* new_category_widget = new CategoryWidget(this, getCategoriesSize()-1);
    candypane::Task task; task.setName(temp_str); task.setText("yeah");
    new_category_widget->self().addTask(task);
    insertWidget(count()-1, new_category_widget); // insert before spacer
    new_category_widget->updateWidget();
    new_category_widget->setEditNameFocus();

    temp++;
    if (temp > 2) {
        std::cerr << "Loading tasks...\n";
        candypane::Task task0; task0.setName("fuck1"); task0.setText("f1");
        candypane::Task task1; task1.setName("fuck2"); task1.setText("f2");
        candypane::Task task2; task2.setName("fuck3"); task2.setText("f3");
        getCategoryById(1).setTasks({task0, task1, task2});
        qobject_cast<CategoryWidget*>(layout()->itemAt(1)->widget())->updateWidget();
    }
}

void CategoriesListWidget::deselectAll(bool background_only) {
    for (int i = 0; i < count()-1; i++) {
        qobject_cast<CategoryWidget*>(layout()->itemAt(i)->widget())->select(false, background_only);
    }
}

void CategoriesListWidget::initLayout() {
    auto* spacer = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
    setSpacing(10);
    addItem(spacer);
}

void CategoriesListWidget::relocateCategoryWidget(unsigned int new_index, unsigned int category_id) {
    if (new_index == category_id) return;

    auto* widget = qobject_cast<CategoryWidget*>(layout()->itemAt(int(category_id))->widget());
    widget->setId(new_index);
    removeWidget(widget);
    insertWidget(int(new_index), widget);

    unsigned int from, to;
    if (new_index < category_id) {
        from = new_index+1;
        to = category_id+1;
    } else {
        from = category_id;
        to = new_index;
    }

    for (unsigned i = from; i < to; i++) {
        auto* widget_i = qobject_cast<CategoryWidget*>(layout()->itemAt(int(i))->widget());
        if (i < new_index) {
            widget_i->setId(widget_i->getId()-1);
        } else {
            widget_i->setId(widget_i->getId()+1);
        }
    }
}

void CategoriesListWidget::updateCategoryWidgets() {
    for (int i = 0; i < count()-1; i++) {
        qobject_cast<CategoryWidget*>(layout()->itemAt(i)->widget())->updateWidget();
    }
}
