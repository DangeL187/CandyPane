#ifndef CANDYPANEQT_DRAGGABLEWIDGETSLIST_HPP
#define CANDYPANEQT_DRAGGABLEWIDGETSLIST_HPP

#include <QVBoxLayout>

class DraggableWidgetsList: public QVBoxLayout {
public:
    DraggableWidgetsList(QWidget* parent_widget);

    template <typename T>
    void deselectAll();

    void relocateWidget(unsigned int new_index, unsigned int category_id);
    void updateWidgets();
private:
    void initLayout();
};

#endif //CANDYPANEQT_DRAGGABLEWIDGETSLIST_HPP
