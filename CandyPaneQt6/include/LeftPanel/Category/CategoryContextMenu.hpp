#ifndef CANDYPANEQT_CATEGORYCONTEXTMENU_HPP
#define CANDYPANEQT_CATEGORYCONTEXTMENU_HPP

#include "ContextMenu.hpp"

class CategoryWidget;

class CategoryContextMenu: public ContextMenu<CategoryWidget> {
public:
    explicit CategoryContextMenu(CategoryWidget* parent_widget);
private:
    QAction*        _action_delete{};
    QAction*        _action_duplicate{};
    QAction*        _action_rename{};

    void initActions() override;
    void loadStyle() override;
};

#endif //CANDYPANEQT_CATEGORYCONTEXTMENU_HPP
