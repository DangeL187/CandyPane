#ifndef CANDYPANEQT_OVERLAYDRAGGABLEWIDGET_HPP
#define CANDYPANEQT_OVERLAYDRAGGABLEWIDGET_HPP

#include <QDialog>
#include <QHBoxLayout>
#include <QLabel>
#include "CategoryWidget.hpp"

class OverlayDraggableWidget: public QDialog {
    Q_OBJECT
public:
    explicit OverlayDraggableWidget(CategoryWidget& category_widget);

private:
    /*=============OverlayDraggableWidget==============*/
    std::shared_ptr<QHBoxLayout>    _layout;
    /*=================================================*/

    /*====================contents=====================*/
    QWidget*                        _select{};
    QWidget*                        _icon{};
    QLabel*                         _name{};
    QLabel*                         _tasks_amount{};
    /*=================================================*/

    void initIcon();
    void initLayout();
    void initName(CategoryWidget& category_widget);
    void initSelect();
    void initTasksAmount(CategoryWidget& category_widget);
    void paintEvent(QPaintEvent *event) override;
};

#endif //CANDYPANEQT_OVERLAYDRAGGABLEWIDGET_HPP
