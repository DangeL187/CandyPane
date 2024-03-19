#ifndef CANDYPANE_CATEGORIESLIST_HPP
#define CANDYPANE_CATEGORIESLIST_HPP

#include "Task/Category.hpp"

/*! @class candypane::CategoriesList
    @brief Container for Category objects. Stores pointer to the main category.
*/
/*! @var candypane::_main_category
    @brief Used for updating main category
*/

namespace candypane {

    class CategoriesList {
    public:
        explicit CategoriesList(Category* main_category): _main_category(main_category) {}

        void addCategory(const Category& new_category);
        [[nodiscard]] std::vector<Category> getCategories() const;
        Category& getCategoryById(unsigned long long int id);
        Category& getCategoryByName(const std::string& name);
        unsigned long long getCategoriesSize();
        void insertCategory(unsigned long long index, const Category& category);
        void loadCategoriesList();
        void relocateCategoryById(unsigned long long int index, unsigned long long int category_id);
        void removeCategory(const Category& category_to_remove);
        void removeCategoryById(unsigned long long int id);
        void setMainCategory(const Category& new_main_category);
        void swapCategoriesById(unsigned long long int id1, unsigned long long int id2);

    protected:
        std::vector<Category>   _categories;
        Category*               _main_category;
    };

}

#endif //CANDYPANE_CATEGORIESLIST_HPP
