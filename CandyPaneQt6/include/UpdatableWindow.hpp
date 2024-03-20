#ifndef CANDYPANEQT_UPDATABLEWIDGETWINDOW_HPP
#define CANDYPANEQT_UPDATABLEWIDGETWINDOW_HPP

#include <QWidget>

#include <iostream>

template <typename T>
class UpdatableWindow: public QWidget {
public:
    explicit UpdatableWindow(T* owner) {
        t_owner = owner;
        _before_fullscreen_size = {size()};
    }
protected:
    void resizeEvent(QResizeEvent* event) override {
        auto* e = reinterpret_cast<QEvent *>(event);
        if (e->type() != QEvent::WindowStateChange) {
            if (_before_fullscreen_size.size() == 2) {
                _before_fullscreen_size[0] = _before_fullscreen_size[1];
                _before_fullscreen_size[1] = size();
            } else {
                _before_fullscreen_size.push_back(size());
            }
            t_owner->updateWidth(_before_fullscreen_size[1].width());
        }
    }

    void changeEvent(QEvent* event) override {
        QWidget::changeEvent(event);
        if (event->type() == QEvent::WindowStateChange) {
            _before_fullscreen_size[1] = _before_fullscreen_size[0];
            if (isMaximized()) {
                t_owner->updateWidth(width());
            } else {
                t_owner->updateWidth(_before_fullscreen_size[1].width());

                setMinimumSize(_before_fullscreen_size[1]);
                setMaximumSize(_before_fullscreen_size[1]);
                resize(_before_fullscreen_size[1]);
                setMinimumSize(1, 1);
                setMaximumSize(1920, 1080);

                t_owner->updateWidth(width());
            }
        }
    }
private:
    std::vector<QSize>  _before_fullscreen_size;
    T*                  t_owner;
};

#endif //CANDYPANEQT_UPDATABLEWIDGETWINDOW_HPP
