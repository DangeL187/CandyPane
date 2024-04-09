#include "MainTaskList/Task/TaskWidget.hpp"
#include "MainTaskList/Task/TaskContextMenu.hpp"
#include <QCalendarWidget>

#include <iostream> // todo: delete

TaskContextMenu::TaskContextMenu(TaskWidget* parent_widget): ContextMenu(parent_widget) {
    TaskContextMenu::initActions();
    TaskContextMenu::loadStyle();
}

void TaskContextMenu::exec(QPoint pos) {
    loadActions();
    ContextMenu<TaskWidget>::exec(pos);
}

void TaskContextMenu::initActions() {
    _action_rename = new QAction(QIcon("../img/plus2.png"), "  Rename task");
    QObject::connect(_action_rename, &QAction::triggered, [&]() {
        _parent_widget->setEditMode(true, false);
    });

    _action_set_today = new QAction("  Due today");
    QObject::connect(_action_set_today, &QAction::triggered, [&]() {
        _parent_widget->self().setDueDate(candypane::DateTimeModule::getTodayDate());
        _parent_widget->updateWidget();
    });

    _action_set_tomorrow = new QAction("  Due tomorrow");
    QObject::connect(_action_set_tomorrow, &QAction::triggered, [&]() {
        _parent_widget->self().setDueDate(candypane::DateTimeModule::getTomorrowDate());
        _parent_widget->updateWidget();
    });

    _action_set_date = new QAction("  Set a due date");
    QObject::connect(_action_set_date, &QAction::triggered, [&]() {
        _parent_widget->execCalendarMenu();
    });

    _action_delete_date = new QAction("  Remove due date");
    QObject::connect(_action_delete_date, &QAction::triggered, [&]() {
        _parent_widget->self().setDueDate(candypane::Date());
        _parent_widget->updateWidget();
    });

    _action_delete = new QAction("  Delete task");
    QObject::connect(_action_delete, &QAction::triggered, [&]() {
        _parent_widget->remove();
    });
}

void TaskContextMenu::loadActions() {
    clear();

    addAction(_action_rename);

    QAction* separator_1 = addAction(""); separator_1->setSeparator(true);
    if (_parent_widget->self().getDueDate() != candypane::DateTimeModule::getTodayDate()) {
        addAction(_action_set_today);
    }

    if (_parent_widget->self().getDueDate() != candypane::DateTimeModule::getTomorrowDate()) {
        addAction(_action_set_tomorrow);
    }

    addAction(_action_set_date);

    if (_parent_widget->self().getDueDate().isValid()) {
        addAction(_action_delete_date);
    }

    QAction* separator_2 = addAction("");
    separator_2->setSeparator(true);

    addAction(_action_delete);
}

void TaskContextMenu::loadStyle() {
    setStyleSheet("QMenu { font-size: 16px; background-color: rgb(46, 47, 48); border: 1px solid rgb(70, 70, 70); }"
                  "QMenu::icon { left: 10px; }"
                  "QMenu::item:selected { background-color: rgb(60, 60, 60); }");
    // todo: recolor the "delete" item
}
