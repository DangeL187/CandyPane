#ifndef CANDYPANEQT_TASKLISTWIDGET_HPP
#define CANDYPANEQT_TASKLISTWIDGET_HPP

#include <Task/Category.hpp>

#include "Draggable/DraggableWidgetsList.hpp"

/*! @fn unsigned long long TaskListWidget::getSelectedCategoryId()
    @brief Get currently selected Category's ID
    @det We don't use any algorithm to find the selected category as it may impact performance in case of large number of categories.
    @det Instead, we use the ID of the currently selected category and set it manually each time the user selects a category.
    @return unsigned long long int representing the category ID
*/

class CategoryListWidget;
class NewTaskWidget;

class TaskListWidget: public DraggableWidgetsList {
public:
    TaskListWidget(QWidget* parent_widget, candypane::CategoryList* category_list);

    void addTaskWidget();
    void addTaskWidget(unsigned long long task_id);
    void changeCategory(unsigned long long task_id);
    void checkHover();
    candypane::Task& getTaskById(unsigned long long task_id);
    [[nodiscard]] unsigned long long getSelectedCategoryId() const;
    void loadTasks();
    void relocateTaskWidget(unsigned int task_id);
    void removeTaskWidgetById(unsigned int task_id);
    void revealNewTaskWidget();
    void setSelectedCategoryId(unsigned long long category_id);

private:
    candypane::CategoryList*        _category_list;
    std::shared_ptr<NewTaskWidget>  _new_task_widget;
    unsigned long long              _selected_id = 0;

    void initNewTaskWidget();
};

#endif //CANDYPANEQT_TASKLISTWIDGET_HPP
