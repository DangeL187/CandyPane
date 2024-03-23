#ifndef CANDYPANEQT_CATEGORIESLISTWIDGET_HPP
#define CANDYPANEQT_CATEGORIESLISTWIDGET_HPP

#include <Task/CategoriesList.hpp>

#include "DraggableWidgetsList.hpp"

class CategoriesListWidget: public DraggableWidgetsList, public candypane::CategoriesList {
public:
    CategoriesListWidget(QWidget* parent_widget, candypane::Category* main_task_list);

    void addCategoryWidget();
private:
    int temp = 0;
};

#endif //CANDYPANEQT_CATEGORIESLISTWIDGET_HPP
