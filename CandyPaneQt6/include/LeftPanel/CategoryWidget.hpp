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

class Background;
class CategoriesListWidget;
class LineEditCategoryName;
class OverlayDraggableWidget;

class CategoryWidget: public QFrame {
Q_OBJECT
public:
    CategoryWidget(CategoriesListWidget* categories_list_widget, unsigned long long int id);

    void exec();
    [[nodiscard]] candypane::Category& self() const;
    [[nodiscard]] unsigned long long int getId() const;
    QWidget* getIcon() {
        return _icon;
    }
    void select(bool value, bool background_only = false);
    void setEditNameFocus();
    void setId(unsigned long long int id);
    void setWidgetVisible(bool value);
    void updateWidget();

private:
    /*===================CategoryWidget====================*/
    CategoriesListWidget*   _categories_list_widget;
    QPoint                  _drag_start_pos;
    OverlayDraggableWidget* _dragged_object = nullptr;
    unsigned long long int  _id;
    QHBoxLayout*            _layout{};
    /*=====================================================*/

    /*======================contents=======================*/
    QWidget*                    _select{};
    std::shared_ptr<Background> _select_background;
    LineEditCategoryName*       _edit_name{};
    QWidget*                    _icon{};
    QLabel*                     _name{};
    QLabel*                     _tasks_amount{};
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
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void resizeEvent(QResizeEvent* event) override;
    bool event(QEvent* event) override;

    //void updateIcon();
    void updateName();
    void updateTasksAmount();
};

#endif //CANDYPANEQT_CATEGORYWIDGET_HPP
