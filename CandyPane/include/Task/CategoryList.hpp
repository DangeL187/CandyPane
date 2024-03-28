#ifndef CANDYPANE_CATEGORYLIST_HPP
#define CANDYPANE_CATEGORYLIST_HPP

#include "Task/Category.hpp"

/*! @class candypane::CategoryList
    @brief Container for Category objects
*/

namespace candypane {

    class CategoryList {
    public:
        CategoryList();

        void addCategory(const Category& new_category);
        [[nodiscard]] std::vector<Category> getCategories() const;
        Category& getCategoryById(unsigned long long int id);
        Category& getCategoryByName(const std::string& name);
        unsigned long long getCategoriesSize();
        void insertCategory(unsigned long long index, const Category& category);
        void loadCategoryList();
        void relocateCategoryById(unsigned long long int index, unsigned long long int category_id);
        void removeCategory(const Category& category_to_remove);
        void removeCategoryById(unsigned long long int id);
        void swapCategoriesById(unsigned long long int id1, unsigned long long int id2);

    protected:
        std::vector<Category>   _categories;
    };

}

#endif //CANDYPANE_CATEGORYLIST_HPP
