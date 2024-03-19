#ifndef CANDYPANE_CATEGORY_HPP
#define CANDYPANE_CATEGORY_HPP

#include <string>

#include "Task/TaskList.hpp"

/*! @class candypane::Category
    @brief Container for TaskList object. Stores pointer to the CategoriesList it belongs to.
*/

namespace candypane {

    class CategoriesList; // forward declaration

    class Category {
    public:
        TaskList task_list;

        explicit Category(CategoriesList* categories_list): _categories_list(categories_list) {}

        void action();
        [[nodiscard]] std::string getName() const;
        void setName(const std::string& new_name);

        bool operator==(const Category &other) const {
            return (_name == other.getName() && task_list == other.task_list);
        }

    private:
        CategoriesList* _categories_list;
        std::string     _name;
    };

}

#endif //CANDYPANE_CATEGORY_HPP
