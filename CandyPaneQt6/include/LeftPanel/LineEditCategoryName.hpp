#ifndef CANDYPANEQT_LINEEDITCATEGORYNAME_HPP
#define CANDYPANEQT_LINEEDITCATEGORYNAME_HPP

#include <QLineEdit>
#include "CategoryWidget.hpp"

class LineEditCategoryName: public QLineEdit {
public:
    explicit LineEditCategoryName(CategoryWidget* category_widget): _category_widget(category_widget) {}
    void focusOutEvent(QFocusEvent* event) override;
    void keyPressEvent(QKeyEvent* event) override;
private:
    CategoryWidget* _category_widget;
};

#endif //CANDYPANEQT_LINEEDITCATEGORYNAME_HPP
