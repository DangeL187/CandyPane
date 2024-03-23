#include <iostream>
#include "Task/Category.hpp"
#include "Task/CategoryList.hpp"

using candypane::CategoryList;
using candypane::Category;

CategoryList::CategoryList() = default;

void CategoryList::addCategory(const Category& new_category) {
    _categories.push_back(new_category);
    if (_categories.empty() || _categories.back() != new_category) {
        throw(std::runtime_error("Failed to add new category"));
    }
}

std::vector<Category> CategoryList::getCategories() const {
    return _categories;
}

unsigned long long CategoryList::getCategoriesSize() {
    return _categories.size();
}

Category& CategoryList::getCategoryById(unsigned long long int id) {
    if (id < _categories.size()) {
        return _categories.at(id);
    } else {
        throw(std::runtime_error("Failed to get category by id: Invalid index"));
    }
}

Category& CategoryList::getCategoryByName(const std::string& name) {
    for (auto& i: _categories) {
        if (i.getName() == name) return i;
    }
    throw(std::runtime_error("Failed to get category by name: Invalid index"));
}

Category& CategoryList::getSelectedCategory() {
    if (!_categories.empty()) {
        return getCategoryById(_selected_category_id);
    } else {
        throw(std::runtime_error("Failed to get selected category: CategoryList is empty"));
    }
}

unsigned long long CategoryList::getSelectedCategoryId() const {
    return _selected_category_id;
}

void CategoryList::insertCategory(unsigned long long index, const Category& category) {
    _categories.insert(_categories.begin() + index, category);
}

void CategoryList::loadCategoryList() {
    // todo: load from some file or database
}

void CategoryList::relocateCategoryById(unsigned long long int index, unsigned long long int category_id) {
    Category category_to_relocate = _categories.at(category_id);
    removeCategoryById(category_id);
    insertCategory(index, category_to_relocate);
}

void CategoryList::removeCategory(const Category& category_to_remove) {
    std::erase(_categories, category_to_remove);
}

void CategoryList::removeCategoryById(unsigned long long int id) {
    if (id < _categories.size()) {
        _categories.erase(_categories.begin() + id);
    } else {
        throw(std::runtime_error("Failed to remove category by id: Invalid index"));
    }
}

void CategoryList::setSelectedCategoryId(unsigned long long category_id) {
    _selected_category_id = category_id;
}

void CategoryList::swapCategoriesById(unsigned long long int id1, unsigned long long int id2) {
    std::swap(_categories[id1], _categories[id2]);
}
