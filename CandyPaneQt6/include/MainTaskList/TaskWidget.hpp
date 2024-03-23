#ifndef CANDYPANEQT_TASKWIDGET_HPP
#define CANDYPANEQT_TASKWIDGET_HPP

#include <QFrame>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QMouseEvent>
#include <QPushButton>
#include <QScreen>

#include <Task/Task.hpp>

#include "Draggable/DraggableWidget.hpp"

class TaskListWidget;
//class LineEditWidgetName; ?
class OverlayDraggableWidget;

class TaskWidget: public DraggableWidget {
    Q_OBJECT
public:
    TaskWidget(TaskListWidget* task_list_widget, unsigned long long int id);

    void exec();
    [[nodiscard]] candypane::Task& self() const;
    void loadStyle();
    void select(bool value, bool background_only = false);
    void setEditNameFocus();
    void setWidgetVisible(bool value) override {}
    void updateWidget() override {}

private:
    /*=====================TaskWidget======================*/
    TaskListWidget*         _task_list_widget;
    /*=====================================================*/

    /*======================contents=======================*/
    //LineEditWidgetName*   _edit_name{};
    QWidget*                _icon{};
    QLabel*                 _name{};
    QWidget*                _select{};
    QLabel*                 _tasks_amount{};
    /*=====================================================*/

    /*=======================events========================*/
    //void mousePressEvent(QMouseEvent* event) override;
    //void mouseMoveEvent(QMouseEvent* event) override;
    //void mouseReleaseEvent(QMouseEvent* event) override;
    //void resizeEvent(QResizeEvent* event) override;
    /*=====================================================*/

    /*=====================initializers====================*/
    void initEditName();
    void initIcon();
    void initName();
    void initSelect();
    void initTasksAmount();
    void initLayout();
    /*=====================================================*/

    //void updateIcon();
    void updateName();
    void updateTasksAmount();
};

#endif //CANDYPANEQT_TASKWIDGET_HPP
