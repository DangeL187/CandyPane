#include "LeftPanel/Category/CategoryWidget.hpp"
#include "LeftPanel/Category/CategoryContextMenu.hpp"

CategoryContextMenu::CategoryContextMenu(CategoryWidget *parent_widget): ContextMenu(parent_widget) {
    CategoryContextMenu::initActions();
    CategoryContextMenu::loadStyle();
}

void CategoryContextMenu::initActions() {
    _action_rename = addAction("Rename list");
    _action_duplicate = addAction("Duplicate list");
    _action_delete = addAction("Delete list");

    QObject::connect(_action_rename, &QAction::triggered, [&]() {
        _parent_widget->setEditMode(true, false);
    });

    QObject::connect(_action_duplicate, &QAction::triggered, [&]() {
        _parent_widget->duplicate();
    });

    QObject::connect(_action_delete, &QAction::triggered, [&]() {
        _parent_widget->remove();
    });
}

void CategoryContextMenu::loadStyle() {
    setStyleSheet("QMenu { font-size: 16px; background-color: rgb(46, 47, 48); border: 1px solid rgb(70, 70, 70); }"
                  "QMenu::item:selected { background-color: rgb(60, 60, 60); }");
}
