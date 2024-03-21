#ifndef CANDYPANEQT_DRAGGABLEWIDGET_HPP
#define CANDYPANEQT_DRAGGABLEWIDGET_HPP

#include <QFrame>
#include <QHBoxLayout>

#include "WidgetBackground.hpp"

class OverlayDraggableWidget;

class DraggableWidget: public QFrame {
Q_OBJECT
public:
    DraggableWidget(unsigned long long int id);

    [[nodiscard]] unsigned long long int getId() const;
    void loadBackgroundStyle();
    void selectBackground(bool value);
    void setId(unsigned long long int id);
    virtual void setWidgetVisible(bool value) = 0;
    virtual void updateWidget() = 0;

protected:
    /*=======================events========================*/
    void onMousePress(QMouseEvent* event);
    void onMouseMove(QMouseEvent* event);
    bool onMouseRelease(QMouseEvent* event);
    void onResize(QResizeEvent* event);
    /*=====================================================*/

private:
    /*===================CategoryWidget====================*/
    QPoint                              _drag_start_pos;
    OverlayDraggableWidget*             _dragged_object = nullptr;
    unsigned long long int              _id;
    std::shared_ptr<WidgetBackground>   _select_background;
    /*=====================================================*/
};

#endif //CANDYPANEQT_DRAGGABLEWIDGET_HPP
