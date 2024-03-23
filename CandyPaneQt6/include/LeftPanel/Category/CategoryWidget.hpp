#ifndef CANDYPANEQT_CATEGORYWIDGET_HPP
#define CANDYPANEQT_CATEGORYWIDGET_HPP

#include <iostream>
#include <QDialog>
#include <QFrame>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QMouseEvent>
#include <QPushButton>
#include <QScreen>

#include <Task/Category.hpp>

#include "Draggable/DraggableWidget.hpp"

class CategoryListWidget;
class LineEditCategoryName;
class OverlayDraggableWidget;

class CategoryWidget: public DraggableWidget {
Q_OBJECT
public:
    CategoryWidget(CategoryListWidget* category_list_widget, unsigned long long int id);

    void exec();
    [[nodiscard]] candypane::Category& self() const;
    void loadStyle();
    void select(bool value, bool background_only = false);
    void setEditNameFocus();
    void setWidgetVisible(bool value) override;
    void updateWidget() override;

private:
    /*===================CategoryWidget====================*/
    CategoryListWidget*     _category_list_widget;
    /*=====================================================*/

    /*======================contents=======================*/
    LineEditCategoryName*   _edit_name{};
    QWidget*                _icon{};
    QLabel*                 _name{};
    QWidget*                _select{};
    QLabel*                 _tasks_amount{};
    /*=====================================================*/

    /*=======================events========================*/
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void resizeEvent(QResizeEvent* event) override;
    /*=====================================================*/

    /*=====================initializers====================*/
    void initEditName();
    void initIcon();
    void initName();
    void initSelect();
    void initTasksAmount();
    void initLayout();
    /*=====================================================*/

    //void updateIcon();
    void updateName();
    void updateTasksAmount();
};

#endif //CANDYPANEQT_CATEGORYWIDGET_HPP
