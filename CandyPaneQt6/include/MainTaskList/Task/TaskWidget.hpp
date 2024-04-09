#ifndef CANDYPANEQT_TASKWIDGET_HPP
#define CANDYPANEQT_TASKWIDGET_HPP

#include <QCalendarWidget>
#include <QCheckBox>
#include <QFrame>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QMouseEvent>
#include <QPushButton>
#include <QScreen>

#include <Task/Task.hpp>

#include "Draggable/DraggableWidget.hpp"
#include "Draggable/LineEditName.hpp"

class TaskContentsWidget;
class TaskContextMenu;
class TaskListWidget;
class OverlayDraggableWidget;

class TaskWidget: public DraggableWidget {
    Q_OBJECT
public:
    TaskWidget(TaskListWidget* task_list_widget, unsigned long long int id);

    [[nodiscard]] candypane::Task& self() const;

    void execCalendarMenu();
    void loadStyle();
    void remove();
    void setEditMode(bool value, bool first_time = true);
    void setWidgetVisible(bool value) override;
    void updateWidget() override;

private:
    /*======================TaskWidget=======================*/
    bool                                _is_visible = true;
    QSize                               _old_size;
    TaskListWidget*                     _task_list_widget;
    /*=======================================================*/

    /*=======================contents========================*/
    std::shared_ptr<QCalendarWidget>    _calendar_menu;
    QCheckBox*                          _checkbox{};
    std::shared_ptr<TaskContextMenu>    _context_menu;
    LineEditName<TaskWidget>*           _edit_name{};
    QCheckBox*                          _star{};
    std::shared_ptr<TaskContentsWidget> _task_contents;
    /*=======================================================*/

    /*========================events=========================*/
    void contextMenuEvent(QContextMenuEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void resizeEvent(QResizeEvent* event) override;
    /*=======================================================*/

    /*======================initializers=====================*/
    void initCalendarMenu();
    void initCheckbox();
    void initContextMenu();
    void initEditName();
    void initLayout();
    void initStar();
    void initTaskContents();
    /*=======================================================*/

    /*========================updaters=======================*/
    void updateCheckbox();
    void updateStar();
    /*=======================================================*/
};

#endif //CANDYPANEQT_TASKWIDGET_HPP
