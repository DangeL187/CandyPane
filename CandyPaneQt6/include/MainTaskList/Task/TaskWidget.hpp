#ifndef CANDYPANEQT_TASKWIDGET_HPP
#define CANDYPANEQT_TASKWIDGET_HPP

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
    void setEditNameFocus();
    void setWidgetVisible(bool value) override;
    void updateWidget() override;

private:
    /*=====================TaskWidget======================*/
    TaskListWidget*         _task_list_widget;
    /*=====================================================*/

    /*======================contents=======================*/
    //LineEditWidgetName*   _edit_name{};
    QCheckBox*              _checkbox{};
    QLabel*                 _name{};
    QCheckBox*              _star{};
    /*=====================================================*/

    /*=======================events========================*/
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void resizeEvent(QResizeEvent* event) override;
    /*=====================================================*/

    /*=====================initializers====================*/
    void initCheckbox();
    void initEditName();
    void initLayout();
    void initName();
    void initStar();
    /*=====================================================*/

    void updateCheckbox();
    void updateName();
    void updateStar();
};

#endif //CANDYPANEQT_TASKWIDGET_HPP
