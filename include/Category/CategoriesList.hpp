#ifndef CANDYPANE_CATEGORIESLIST_HPP
#define CANDYPANE_CATEGORIESLIST_HPP

#include "Task/TaskList.hpp"

/*! @class candypane::CategoriesList
    @brief Container for Category objects. Stores pointer to the main task list.
*/

namespace candypane {

    class Category; // forward declaration

    class CategoriesList {
    public:
        explicit CategoriesList(TaskList* main_task_list): _main_task_list(main_task_list) {}

        void addCategory(const Category& new_category);
        [[nodiscard]] std::vector<Category> getCategories() const;
        Category& getCategoryById(int id);
        void removeCategory(const Category& category_to_remove);
        void removeCategoryById(int id);
        void loadCategories();
        void setMainTaskList(const TaskList& new_task_list);
    private:
        std::vector<Category>   _categories;
        TaskList*               _main_task_list;
    };

}

#endif //CANDYPANE_CATEGORIESLIST_HPP
