#ifndef CANDYPANEQT_NEWLISTWIDGET_HPP
#define CANDYPANEQT_NEWLISTWIDGET_HPP

#include <QMouseEvent>
#include <QPushButton>
#include "CategoryListWidget.hpp"

class NewListWidget: public QPushButton {
public:
    explicit NewListWidget(CategoryListWidget* category_list_widget);

    void mousePressEvent(QMouseEvent* event) override;

private:
    CategoryListWidget*   _category_list_widget; // TODO: doc it
};

#endif //CANDYPANEQT_NEWLISTWIDGET_HPP
