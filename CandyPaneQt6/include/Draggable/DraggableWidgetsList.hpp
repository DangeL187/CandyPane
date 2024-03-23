#ifndef CANDYPANEQT_DRAGGABLEWIDGETSLIST_HPP
#define CANDYPANEQT_DRAGGABLEWIDGETSLIST_HPP

#include <QVBoxLayout>

class DraggableWidgetsList: public QVBoxLayout {
public:
    explicit DraggableWidgetsList(QWidget* parent_widget);

    template <typename T> void addWidget(T* widget);
    void clearLayout();
    template <typename T> void deselectAll();
    int getNewIndex();
    void relocateWidget(unsigned int new_index, unsigned int widget_id);
    void removeWidgetById(unsigned int widget_id);
    void updateWidgets();
private:
    void initLayout();
};

#endif //CANDYPANEQT_DRAGGABLEWIDGETSLIST_HPP
