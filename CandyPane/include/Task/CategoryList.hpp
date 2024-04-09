#ifndef CANDYPANE_CATEGORYLIST_HPP
#define CANDYPANE_CATEGORYLIST_HPP

#include "Category.hpp"

/*! @class candypane::CategoryList
    @brief Container for Category objects
*/

namespace candypane {

    class CategoryList {
    public:
        CategoryList();

        void addCategory(const Category& new_category);
        [[nodiscard]] std::vector<Category> getCategories() const;
        Category& getCategoryById(long long id);
        Category& getCategoryByName(const std::string& name);
        unsigned long long getCategoriesSize();
        [[nodiscard]] long long getHoveredId() const;
        void insertCategory(long long index, const Category& category);
        void loadCategoryList();
        void relocateCategoryById(long long index, long long category_id);
        void removeCategory(const Category& category_to_remove);
        void removeCategoryById(long long category_id);
        void setHoveredId(long long category_id);
        void swapCategoriesById(unsigned long long id1, unsigned long long id2);

    protected:
        std::vector<Category>   _categories;
        long long               _hovered_id = -1;
    };

}

#endif //CANDYPANE_CATEGORYLIST_HPP
