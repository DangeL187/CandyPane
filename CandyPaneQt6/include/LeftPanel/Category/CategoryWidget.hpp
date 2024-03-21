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

#include "DraggableWidget.hpp"

class CategoriesListWidget;
class LineEditCategoryName;
class OverlayDraggableWidget;

class CategoryWidget: public DraggableWidget {
Q_OBJECT
public:
    CategoryWidget(CategoriesListWidget* categories_list_widget, unsigned long long int id);

    void exec();
    [[nodiscard]] candypane::Category& self() const;
    QWidget* getIcon() {
        return _icon;
    }
    void loadStyle();
    void select(bool value, bool background_only = false);
    void setEditNameFocus();
    void setWidgetVisible(bool value) override;
    void updateWidget() override;

private:
    /*===================CategoryWidget====================*/
    CategoriesListWidget*   _categories_list_widget;
    QHBoxLayout*            _layout{};
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

    int getNewIndex();
    //void updateIcon();
    void updateName();
    void updateTasksAmount();
};

#endif //CANDYPANEQT_CATEGORYWIDGET_HPP
