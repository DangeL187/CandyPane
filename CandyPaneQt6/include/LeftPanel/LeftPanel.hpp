#ifndef CANDYPANEQT_LEFTPANEL_HPP
#define CANDYPANEQT_LEFTPANEL_HPP

#include <QSplitter>
#include <QScrollArea>
#include <QFrame>
#include <QGridLayout>

#include "AccountWidget.hpp"
#include "CategoriesListWidget.hpp"
#include "NewListWidget.hpp"

class LeftPanel: public QFrame {
public:
    explicit LeftPanel(candypane::Category* main_task_list);

    void updateWidth();
private:
    /*=========================LeftPanel===========================*/
    QVBoxLayout                             _left_panel_layout;
    /*=============================================================*/

    /*===========================contents==========================*/
    AccountWidget                           _account_widget;
    std::shared_ptr<CategoriesListWidget>   _categories_list_widget;
    std::shared_ptr<NewListWidget>          _new_list_widget;
    QScrollArea                             _scroll_area;
    QWidget                                 _scroll_area_widget;
    /*=============================================================*/

    /*=========================initializers========================*/
    void initCategoriesListScrollArea();
    void initLayout();
    void initModules(candypane::Category* main_task_list);
    /*=============================================================*/
};

#endif //CANDYPANEQT_LEFTPANEL_HPP
