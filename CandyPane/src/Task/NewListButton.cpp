#include "Category/NewListButton.hpp"
#include "Category/Category.hpp"

using candypane::NewListButton;

void NewListButton::action(const std::string& new_category_name) {
    Category new_category(_categories_list);
    new_category.setName(new_category_name);
    _categories_list->addCategory(new_category);
}

std::string NewListButton::getText() const {
    return _text;
}

void NewListButton::setText(const std::string& text) {
    _text = text;
}
