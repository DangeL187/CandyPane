#ifndef CANDYPANEQT_TASKLISTTITLE_HPP
#define CANDYPANEQT_TASKLISTTITLE_HPP

#include <QFrame>
#include <QHBoxLayout>
#include <QLabel>

#include <Task/CategoryList.hpp>

#include "TaskListTitleIcon.hpp"
#include "TaskListTitleName.hpp"

class WidgetBackground;

class TaskListTitle: public QFrame {
public:
    explicit TaskListTitle(candypane::CategoryList* category_list);
    void checkHover();
    void setSelectedCategoryId(unsigned long long category_id);
    void updateTitle();
private:
    /*=================TaskListTitle===================*/
    candypane::CategoryList*    _category_list;
    QHBoxLayout                 _layout;
    unsigned long long          _selected_id = 0;
    /*=====================================================*/

    /*======================contents=======================*/
    TaskListTitleIcon           _icon;
    TaskListTitleName           _name;
    /*=====================================================*/

    /*=======================events========================*/
    void resizeEvent(QResizeEvent* event) override;
    /*=====================================================*/

    /*=====================initializers====================*/
    void initLayout();
    /*=====================================================*/
};

#endif //CANDYPANEQT_TASKLISTTITLE_HPP
