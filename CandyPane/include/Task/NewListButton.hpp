#ifndef CANDYPANE_NEWLISTBUTTON_HPP
#define CANDYPANE_NEWLISTBUTTON_HPP

#include <string>
#include "CategoriesList.hpp"

/*! @class candypane::NewListButton
    @brief Class used to add new Category object. Stores a pointer to the CategoriesList object
*/
/*! @fn candypane::NewListButton(CategoriesList* categories_list)
    @brief Creates NewListButton object and sets pointer to the parent categories list
*/
//action
//getText
//setText

namespace candypane {

    class NewListButton {
    public:
        explicit NewListButton(CategoriesList* categories_list): _categories_list(categories_list) {}

        void action(const std::string& new_category_name);
        [[nodiscard]] std::string getText() const;
        void setText(const std::string& text);

    protected:
        CategoriesList* _categories_list;
        std::string     _text;
    };

}

#endif //CANDYPANE_NEWLISTBUTTON_HPP
