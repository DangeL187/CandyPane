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

    void initLayout(QHBoxLayout& layout);
    void paintEvent(QPaintEvent *event) override;
};

#endif //CANDYPANEQT_OVERLAYDRAGGABLEWIDGET_HPP
