#ifndef CANDYPANEQT_UPDATABLEWINDOW_HPP
#define CANDYPANEQT_UPDATABLEWINDOW_HPP

#include <QMainWindow>

template <typename T>
class UpdatableWindow: public QMainWindow { //TODO: create custom title bar, priority slightly low
public:
    explicit UpdatableWindow(T* owner);
protected:
    bool event(QEvent* event) override;
    void resizeEvent(QResizeEvent* event) override;
    void changeEvent(QEvent* event) override;
private:
    std::vector<QSize>  _before_fullscreen_size;
    T*                  _owner;
};

#endif //CANDYPANEQT_UPDATABLEWINDOW_HPP
