#include "LeftPanel/Category/NewListWidget.hpp"

NewListWidget::NewListWidget(CategoryListWidget* category_list_widget): _category_list_widget(category_list_widget) {}

void NewListWidget::mousePressEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        _category_list_widget->addCategoryWidget();
    }
}
