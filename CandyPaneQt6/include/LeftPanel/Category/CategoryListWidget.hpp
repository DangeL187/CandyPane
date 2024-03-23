#ifndef CANDYPANEQT_CATEGORYLISTWIDGET_HPP
#define CANDYPANEQT_CATEGORYLISTWIDGET_HPP

#include <Task/CategoryList.hpp>

#include "Draggable/DraggableWidgetsList.hpp"

class CategoryListWidget: public DraggableWidgetsList {
public:
    CategoryListWidget(QWidget* parent_widget, candypane::CategoryList* category_list);

    void addCategoryWidget();
    candypane::Category& getCategoryById(unsigned long long category_id);
    void relocateCategoryWidget(unsigned int widget_id);
    void removeCategoryWidgetById(unsigned int category_id);
    void setSelectedCategoryId(unsigned long long category_id);

private:
    candypane::CategoryList* _category_list;
    int temp = 0;
};

#endif //CANDYPANEQT_CATEGORYLISTWIDGET_HPP
