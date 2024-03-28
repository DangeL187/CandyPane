#ifndef CANDYPANEQT_LEFTPANEL_HPP
#define CANDYPANEQT_LEFTPANEL_HPP

#include <QFrame>
#include <QSplitter>
#include <QScrollArea>
#include <QVBoxLayout>

#include "AccountWidget.hpp"
#include "Category/CategoryListWidget.hpp"
#include "Category/NewListWidget.hpp"
#include "MainTaskList/MainTaskList.hpp"

class LeftPanel: public QFrame {
public:
    LeftPanel(candypane::CategoryList* category_list, MainTaskList* main_task_list);

    void checkHover();
private:
    /*=========================LeftPanel===========================*/
    QVBoxLayout                             _layout;
    /*=============================================================*/

    /*===========================contents==========================*/
    AccountWidget                           _account_widget;
    std::shared_ptr<CategoryListWidget>     _category_list_widget;
    std::shared_ptr<NewListWidget>          _new_list_widget;
    QScrollArea                             _scroll_area;
    QWidget                                 _scroll_area_widget;
    /*=============================================================*/

    /*=========================initializers========================*/
    void initCategoryListScrollArea();
    void initLayout();
    void initModules(candypane::CategoryList* category_list, MainTaskList* main_task_list);
    /*=============================================================*/
};

#endif //CANDYPANEQT_LEFTPANEL_HPP
