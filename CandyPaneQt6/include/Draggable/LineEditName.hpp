#ifndef CANDYPANEQT_LINEEDITNAME_HPP
#define CANDYPANEQT_LINEEDITNAME_HPP

#include <QLineEdit>
#include <QKeyEvent>

template <typename T>
class LineEditName: public QLineEdit {
public:
    explicit LineEditName(T* parent_widget): _parent_widget(parent_widget) {}
    
    void focusOutEvent(QFocusEvent* event) override {
        if (_parent_widget->underMouse()) {
            _parent_widget->blockDragging(true);
        }
        _parent_widget->setEditMode(false);
    }
    
    void keyPressEvent(QKeyEvent* event) override {
        if (event->key() == Qt::Key_Return) {
            _parent_widget->blockDragging(true);
            _parent_widget->setEditMode(false);
        } else {
            QLineEdit::keyPressEvent(event);
        }
    }
private:
    T* _parent_widget;
};

#endif //CANDYPANEQT_LINEEDITNAME_HPP
