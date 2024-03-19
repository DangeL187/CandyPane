#ifndef CANDYPANEQT_APPLICATION_HPP
#define CANDYPANEQT_APPLICATION_HPP

#include <memory>
#include <QApplication>
#include <QHBoxLayout>
#include <QSplitter>

#include "UpdatableWindow.hpp"

//splitter:

template <typename T>
class UpdatableSplitter: public QSplitter {
public:
    explicit UpdatableSplitter(T* owner) {
        t_owner = owner;
        connect(this, &QSplitter::splitterMoved, this, &UpdatableSplitter::handleSplitterMoved);
    }
private slots:
    void handleSplitterMoved(int pos, int index) {
        //t_owner->updateWidth(t_owner->getWindowWidth());
    }
private:
    T*  t_owner;
};

//

#include "LeftPanel/LeftPanel.hpp"

class Application {
public:
    Application(int argc, char *argv[]);

    int getWindowWidth();
    void updateWidth(int window_width); // TODO: in debug process, when done - delete
private:
    /*========================Application========================*/
    QApplication                                    _application;
    std::shared_ptr<QHBoxLayout>                    _main_layout;
    std::shared_ptr<UpdatableSplitter<Application>> _splitter;
    std::shared_ptr<UpdatableWindow<Application>>   _window;
    /*===========================================================*/

    /*==========================modules==========================*/
    std::shared_ptr<LeftPanel>                      _left_panel;
    std::shared_ptr<QWidget>                        _main_category;
    /*===========================================================*/

    /*=======================initializers========================*/
    void initLeftPanel() ;
    void initMainCategory();
    void initMainLayout();
    void initSplitter();
    void initWindow();
    /*===========================================================*/
};

#endif //CANDYPANEQT_APPLICATION_HPP
