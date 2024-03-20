#ifndef CANDYPANEQT_NEWLISTWIDGET_HPP
#define CANDYPANEQT_NEWLISTWIDGET_HPP

#include <QMouseEvent>
#include <QPushButton>
#include <Task/NewListButton.hpp>
#include "CategoriesListWidget.hpp"
#include "NewListDialog.hpp"

class NewListWidget: public QPushButton, public candypane::NewListButton {
public:
    explicit NewListWidget(CategoriesListWidget* categories_list):
        _categories_list_widget(categories_list), candypane::NewListButton(categories_list) {}

    void mousePressEvent(QMouseEvent* event) override;

    void addCategory();

private:
    CategoriesListWidget*   _categories_list_widget; // TODO: doc it
    NewListDialog           _new_list_dialog; // TODO: doc it too
};

#endif //CANDYPANEQT_NEWLISTWIDGET_HPP