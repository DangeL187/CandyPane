#include "LeftPanel/LineEditCategoryName.hpp"

void LineEditCategoryName::focusOutEvent(QFocusEvent* event) {
    _category_widget->exec();
}

void LineEditCategoryName::keyPressEvent(QKeyEvent* event) {
    if (event->key() == Qt::Key_Return) {
        _category_widget->exec();
    }
    QLineEdit::keyPressEvent(event);
}

