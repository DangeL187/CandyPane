#ifndef CANDYPANE_NEWLISTBUTTON_HPP
#define CANDYPANE_NEWLISTBUTTON_HPP

#include <string>
#include "CategoriesList.hpp"

namespace candypane {

    class NewListButton {
    public:
        explicit NewListButton(CategoriesList* categories_list): _categories_list(categories_list) {}

        void action(const std::string& new_category_name);
        [[nodiscard]] std::string getText() const;
        void setText(const std::string& text);

    private:
        CategoriesList* _categories_list;
        std::string     _text;
    };

}

#endif //CANDYPANE_NEWLISTBUTTON_HPP
