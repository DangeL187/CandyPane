#ifndef CANDYPANEQT_TASKCONTEXTMENU_HPP
#define CANDYPANEQT_TASKCONTEXTMENU_HPP

#include "ContextMenu.hpp"

class TaskWidget;

class TaskContextMenu: public ContextMenu<TaskWidget> {
public:
    explicit TaskContextMenu(TaskWidget* parent_widget);

    void exec(QPoint pos);
private:
    QAction*        _action_delete{};
    QAction*        _action_delete_date{};
    QAction*        _action_rename{};
    QAction*        _action_set_date{};
    QAction*        _action_set_today{};
    QAction*        _action_set_tomorrow{};

    void initActions() override;
    void loadActions();
    void loadStyle() override;
};


#endif //CANDYPANEQT_TASKCONTEXTMENU_HPP
