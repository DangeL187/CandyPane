#ifndef CANDYPANEQT_OVERLAYDRAGGABLEWIDGET_HPP
#define CANDYPANEQT_OVERLAYDRAGGABLEWIDGET_HPP

#include <QDialog>
#include <QHBoxLayout>
#include <QLabel>

class CategoryWidget;
class DraggableWidget;

class OverlayDraggableWidget: public QDialog {
    Q_OBJECT
public:
    explicit OverlayDraggableWidget(DraggableWidget& draggable_widget);

private:
    /*=============OverlayDraggableWidget==============*/
    std::shared_ptr<QHBoxLayout>    _layout;
    /*=================================================*/

    /*====================contents=====================*/
    std::shared_ptr<QWidget>        _select;
    std::shared_ptr<QWidget>        _icon;
    std::shared_ptr<QLabel>         _name;
    std::shared_ptr<QLabel>         _tasks_amount;
    /*=================================================*/

    void initIcon();
    void initLayout();
    void initName();
    void initSelect();
    void initTasksAmount();
    void paintEvent(QPaintEvent *event) override;
};

#endif //CANDYPANEQT_OVERLAYDRAGGABLEWIDGET_HPP
