#include <iostream>
#include "Category/Category.hpp"
#include "Category/CategoriesList.hpp"

using candypane::CategoriesList;
using candypane::Category;
using candypane::TaskList;

void CategoriesList::addCategory(const Category& new_category) {
    _categories.push_back(new_category);
    if (_categories.empty() || _categories.back() != new_category) {
        throw(std::runtime_error("Failed to add new category"));
    }
}

std::vector<Category> CategoriesList::getCategories() const {
    return _categories;
}

Category& CategoriesList::getCategoryById(int id) {
    if (id >= 0 && id < _categories.size()) {
        return _categories.at(id);
    } else {
        throw(std::runtime_error("Failed to get category by id: Invalid index"));
    }
}

void CategoriesList::removeCategory(const Category& category_to_remove) {
    std::erase(_categories, category_to_remove);
}

void CategoriesList::removeCategoryById(int id) {
    if (id >= 0 && id < _categories.size()) {
        _categories.erase(_categories.begin() + id);
    } else {
        throw(std::runtime_error("Failed to remove category by id: Invalid index"));
    }
}

void CategoriesList::loadCategories() {
    // todo: load from some file or database
}

void CategoriesList::setMainTaskList(const TaskList& new_task_list) {
    *_main_task_list = new_task_list;
}