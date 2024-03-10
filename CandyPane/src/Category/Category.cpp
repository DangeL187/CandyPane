#include "Category/Category.hpp"
#include "Category/CategoriesList.hpp"

using candypane::Category;

void Category::action() {
    _categories_list->setMainTaskList(task_list);
}

std::string Category::getName() const {
    return _name;
}

void Category::setName(const std::string& new_name) {
    _name = new_name;
}
