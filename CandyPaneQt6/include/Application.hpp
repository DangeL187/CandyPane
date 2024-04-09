#ifndef CANDYPANEQT_APPLICATION_HPP
#define CANDYPANEQT_APPLICATION_HPP

#include <memory>

#include <QApplication>
#include <QHBoxLayout>
#include <QSplitter>

#include <Task/CategoryList.hpp>

template <typename T> class UpdatableWindow;
class LeftPanel;
class MainTaskList;

class Application {
public:
    Application(int argc, char *argv[]);

    void checkHover();
    void update();
    void updateWidth(int window_width);
private:
    /*==========================Application==========================*/
    QApplication                                    _application;
    std::shared_ptr<QHBoxLayout>                    _main_layout;
    QSplitter                                       _splitter;
    std::shared_ptr<UpdatableWindow<Application>>   _window;
    /*===============================================================*/

    /*============================modules============================*/
    std::shared_ptr<LeftPanel>                      _left_panel;
    std::shared_ptr<MainTaskList>                   _main_task_list;
    /*===============================================================*/

    /*=============================DATA==============================*/
    candypane::CategoryList                         _category_list;
    /*===============================================================*/

    /*=========================initializers==========================*/
    void initCategoryList();
    void initLeftPanel(candypane::CategoryList* category_list, MainTaskList* main_task_list);
    void initMainLayout();
    void initMainTaskList(candypane::CategoryList* category_list);
    void initSplitter();
    void initWindow();
    /*===============================================================*/
};

#endif //CANDYPANEQT_APPLICATION_HPP
