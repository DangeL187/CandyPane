#include <iostream>
#include "Task/Category.hpp"
#include "Task/CategoriesList.hpp"

using candypane::CategoriesList;
using candypane::Category;

void CategoriesList::addCategory(const Category& new_category) {
    _categories.push_back(new_category);
    if (_categories.empty() || _categories.back() != new_category) {
        throw(std::runtime_error("Failed to add new category"));
    }
}

std::vector<Category> CategoriesList::getCategories() const {
    return _categories;
}

unsigned long long CategoriesList::getCategoriesSize() {
    return _categories.size();
}

Category& CategoriesList::getCategoryById(unsigned long long int id) {
    if (id < _categories.size()) {
        return _categories.at(id);
    } else {
        throw(std::runtime_error("Failed to get category by id: Invalid index"));
    }
}

Category& CategoriesList::getCategoryByName(const std::string& name) {
    for (auto& i: _categories) {
        if (i.getName() == name) return i;
    }
    throw(std::runtime_error("Failed to get category by name: Invalid index"));
}

void CategoriesList::insertCategory(unsigned long long index, const Category& category) {
    _categories.insert(_categories.begin() + index, category);
}

void CategoriesList::loadCategoriesList() {
    // todo: load from some file or database
}

void CategoriesList::relocateCategoryById(unsigned long long int index, unsigned long long int category_id) {
    Category category_to_relocate = _categories.at(category_id);
    removeCategoryById(category_id);
    insertCategory(index, category_to_relocate);
}

void CategoriesList::removeCategory(const Category& category_to_remove) {
    std::erase(_categories, category_to_remove);
}

void CategoriesList::removeCategoryById(unsigned long long int id) {
    if (id < _categories.size()) {
        _categories.erase(_categories.begin() + id);
    } else {
        throw(std::runtime_error("Failed to remove category by id: Invalid index"));
    }
}

void CategoriesList::setMainCategory(const candypane::Category &new_main_category) {
    *_main_category = new_main_category;
}

void CategoriesList::swapCategoriesById(unsigned long long int id1, unsigned long long int id2) {
    std::swap(_categories[id1], _categories[id2]);
}
