#include "LeftPanel/Category/NewListWidget.hpp"

void NewListWidget::addCategory() {
    action("_");
    _categories_list_widget->addCategoryWidget();
}

void NewListWidget::mousePressEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        addCategory();
    }
}