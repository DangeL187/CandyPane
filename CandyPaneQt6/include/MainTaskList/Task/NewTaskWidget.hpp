#ifndef CANDYPANEQT_NEWTASKWIDGET_HPP
#define CANDYPANEQT_NEWTASKWIDGET_HPP

#include <QFrame>
#include <QLabel>
#include <QMouseEvent>

#include "TaskListWidget.hpp"
#include "Draggable/LineEditName.hpp"

class WidgetBackground;

class NewTaskWidget: public QFrame {
public:
    explicit NewTaskWidget(TaskListWidget* task_list_widget);

    void selectBackground(bool value);

private:
    TaskListWidget*                     _task_list_widget; // TODO: doc it

    std::shared_ptr<WidgetBackground>   _background;
    QWidget                             _icon;
    QHBoxLayout                         _layout;
    QLabel                              _text;

    void initIcon();
    void initLayout();
    void initText();

    void loadStyle();

    void mousePressEvent(QMouseEvent* event) override;
    void resizeEvent(QResizeEvent* event) override;
};


#endif //CANDYPANEQT_NEWTASKWIDGET_HPP
