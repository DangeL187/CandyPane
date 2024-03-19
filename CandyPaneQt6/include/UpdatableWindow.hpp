#ifndef CANDYPANEQT_UPDATABLEWIDGETWINDOW_HPP
#define CANDYPANEQT_UPDATABLEWIDGETWINDOW_HPP

#include <QWidget>

#include <iostream>

template <typename T>
class UpdatableWindow: public QWidget {
public:
    explicit UpdatableWindow(T* owner) {
        t_owner = owner;
        _before_fullscreen = {size()};
    }
protected:
    void resizeEvent(QResizeEvent* event) override {
        auto* e = reinterpret_cast<QEvent *>(event);
        if (e->type() != QEvent::WindowStateChange) {
            if (_before_fullscreen.size() == 2) {
                _before_fullscreen[0] = _before_fullscreen[1];
                _before_fullscreen[1] = size();
            } else {
                _before_fullscreen.push_back(size());
            }
            t_owner->updateWidth(_before_fullscreen[1].width());
        }
    }

    void changeEvent(QEvent* event) override {
        if (event->type() == QEvent::WindowStateChange) {
            _before_fullscreen[1] = _before_fullscreen[0];
            if (isMaximized()) {
                t_owner->updateWidth(width());
            } else {
                t_owner->updateWidth(_before_fullscreen[1].width());

                setMinimumSize(_before_fullscreen[1]);
                setMaximumSize(_before_fullscreen[1]);
                resize(_before_fullscreen[1]);
                setMinimumSize(1, 1);
                setMaximumSize(1920, 1080);

                t_owner->updateWidth(width());
            }
        }
        QWidget::changeEvent(event);
    }
private:
    std::vector<QSize>  _before_fullscreen;
    T*                  t_owner;
};

#endif //CANDYPANEQT_UPDATABLEWIDGETWINDOW_HPP