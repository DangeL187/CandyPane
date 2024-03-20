#ifndef CANDYPANEQT_UPDATABLEWINDOW_HPP
#define CANDYPANEQT_UPDATABLEWINDOW_HPP

#include <QMainWindow>

#include <iostream>

template <typename T>
class UpdatableWindow: public QMainWindow { //TODO: create custom title bar, priority slightly low
public:
    explicit UpdatableWindow(T* owner) {
        t_owner = owner;
        _before_fullscreen_size = {size()};
        setAttribute(Qt::WA_Hover);
        setMouseTracking(true);
        setWindowIcon(QIcon("../img/logo.png"));
    }
protected:
    bool event(QEvent* event) override {
        if (event->type() == QEvent::HoverMove) {
            t_owner->checkHover();
            return true;
        }
        return QMainWindow::event(event);
    }

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
        QMainWindow::changeEvent(event);
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
    std::vector<QSize>              _before_fullscreen_size;
    T*                              t_owner;
};

#endif //CANDYPANEQT_UPDATABLEWINDOW_HPP
