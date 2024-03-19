#include "LeftPanel/LeftPanel.hpp"

LeftPanel::LeftPanel(candypane::Category* main_task_list) {
    initModules(main_task_list);
    initCategoriesListScrollArea();
    initLayout();

    setMinimumWidth(1920/9);
    setMaximumWidth(1920/5);
}

void LeftPanel::initCategoriesListScrollArea() {
    _scroll_area.setFrameShape(QFrame::NoFrame);
    _scroll_area.setWidgetResizable(true);
    _scroll_area.setWidget(&_scroll_area_widget);
}

void LeftPanel::initLayout() {
    _left_panel_layout.setSpacing(0);
    _left_panel_layout.setContentsMargins(0, 0, 0, 0);

    _account_widget.setFixedHeight(30); //temp
    _account_widget.setStyleSheet("background-color: blue;"); //temp

    _left_panel_layout.addWidget(&_account_widget);
    _left_panel_layout.addWidget(&_scroll_area);
    _left_panel_layout.addWidget(_new_list_widget.get());

    setLayout(&_left_panel_layout);
}

void LeftPanel::initModules(candypane::Category* main_task_list) {
    _categories_list_widget = std::make_shared<CategoriesListWidget>(&_scroll_area_widget, main_task_list);
    _new_list_widget = std::make_shared<NewListWidget>(_categories_list_widget.get());
}
