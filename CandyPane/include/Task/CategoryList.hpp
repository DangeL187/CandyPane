#ifndef CANDYPANE_CATEGORYLIST_HPP
#define CANDYPANE_CATEGORYLIST_HPP

#include "Task/Category.hpp"

/*! @class candypane::CategoryList
    @brief Container for Category objects
*/

/*! @fn Category& candypane::CategoryList::getSelectedCategory()
    @brief Get currently selected Category
    @det We don't use any algorithm to find the selected category as it may impact performance in case of large number of categories.
    @det Instead, we use the ID of the currently selected category and set it manually each time the user selects a category.
    @return a Category object, but only if the category list is not empty.
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
        Category& getSelectedCategory();
        [[nodiscard]] unsigned long long getSelectedCategoryId() const;
        void insertCategory(unsigned long long index, const Category& category);
        void loadCategoryList();
        void relocateCategoryById(unsigned long long int index, unsigned long long int category_id);
        void removeCategory(const Category& category_to_remove);
        void removeCategoryById(unsigned long long int id);
        void setSelectedCategoryId(unsigned long long category_id);
        void swapCategoriesById(unsigned long long int id1, unsigned long long int id2);

    protected:
        std::vector<Category>   _categories;
        unsigned long long      _selected_category_id = 0;
    };

}

#endif //CANDYPANE_CATEGORYLIST_HPP
