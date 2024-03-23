#include "LeftPanel/Category/NewListWidget.hpp"

NewListWidget::NewListWidget(CategoryListWidget* category_list): _category_list_widget(category_list) {}

void NewListWidget::mousePressEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        _category_list_widget->addCategoryWidget();
    }
}