#include "Application.hpp"
#include "UpdatableWindow.hpp"

template<> UpdatableWindow<Application>::UpdatableWindow(Application* owner): _owner(owner) {
    _before_fullscreen_size = {size()};
    setAttribute(Qt::WA_Hover);
    setMouseTracking(true);
    setWindowIcon(QIcon("../img/logo.png"));
    setStyleSheet("background-color: rgb(32, 32, 32);");
}

template<> bool UpdatableWindow<Application>::event(QEvent* event) {
    if (event->type() == QEvent::HoverMove) {
        _owner->checkHover();
        return true;
    } else {
        _owner->update();
        return QMainWindow::event(event);
    }
}

template<> void UpdatableWindow<Application>::resizeEvent(QResizeEvent* event) {
    auto* e = reinterpret_cast<QEvent *>(event);
    if (e->type() != QEvent::WindowStateChange) {
        if (_before_fullscreen_size.size() == 2) {
            _before_fullscreen_size[0] = _before_fullscreen_size[1];
            _before_fullscreen_size[1] = size();
        } else {
            _before_fullscreen_size.push_back(size());
        }
        _owner->updateWidth(_before_fullscreen_size[1].width());
    }
}

template<> void UpdatableWindow<Application>::changeEvent(QEvent* event) {
    QMainWindow::changeEvent(event);
    if (event->type() == QEvent::WindowStateChange) {
        _before_fullscreen_size[1] = _before_fullscreen_size[0];
        if (isMaximized()) {
            _owner->updateWidth(width());
        } else {
            _owner->updateWidth(_before_fullscreen_size[1].width());

            setMinimumSize(_before_fullscreen_size[1]);
            setMaximumSize(_before_fullscreen_size[1]);
            resize(_before_fullscreen_size[1]);
            setMinimumSize(1, 1);
            setMaximumSize(1920, 1080);

            _owner->updateWidth(width());
        }
    }
}
