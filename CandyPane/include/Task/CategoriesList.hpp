#ifndef CANDYPANE_CATEGORIESLIST_HPP
#define CANDYPANE_CATEGORIESLIST_HPP

#include "Task/Category.hpp"

/*! @class candypane::CategoriesList
    @brief Container for Category objects. Stores pointer to the main category.
*/
/*! @fn void candypane::CategoriesList(Category* main_category)
    @brief Adds new Task
    @param main_category Pointer to the main Category object
*/
/*! @fn void candypane::CategoriesList::addCategory(const Category& new_category)
    @brief Adds new Category
    @param new_category Category object to add
*/
/*! @fn std::vector<Category> candypane::CategoriesList::getCategories()
    @brief Get list of the Category objects
    @return Vector of Category objects
*/
/*! @fn Category& candypane::CategoriesList::getCategoryById(unsigned long long int id)
    @brief Get Category object by it's index in the list of the Category objects
    @param id Category's index in the list of the Category objects
    @return Category object
*/
//...
/*! @var candypane::_categories
    @brief Stores Category objects
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
