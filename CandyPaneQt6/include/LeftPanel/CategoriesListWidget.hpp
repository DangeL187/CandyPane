#ifndef CANDYPANEQT_CATEGORIESLISTWIDGET_HPP
#define CANDYPANEQT_CATEGORIESLISTWIDGET_HPP

#include <QVBoxLayout>
#include <Task/CategoriesList.hpp>
#include "CategoryWidget.hpp"

class CategoriesListWidget: public candypane::CategoriesList, public QVBoxLayout {
public:
    explicit CategoriesListWidget(QWidget* parent_widget, candypane::Category* main_task_list);

    void addCategoryWidget();
    void deselectAll();
    void relocateCategoryWidget(unsigned int new_index, unsigned int category_id);
    void updateCategoryWidgets();
private:
    int temp = 0;

    void initLayout();
};

#endif //CANDYPANEQT_CATEGORIESLISTWIDGET_HPP
