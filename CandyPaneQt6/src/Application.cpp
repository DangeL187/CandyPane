#include "Application.hpp"
#include "UpdatableWindow.hpp"
#include "LeftPanel/LeftPanel.hpp"
#include "MainTaskList/MainTaskList.hpp"

Application::Application(int argc, char *argv[]): _application(argc, argv) {
    initCategoryList();
    initMainTaskList(&_category_list);
    initLeftPanel(&_category_list, _main_task_list.get());
    initSplitter();
    initMainLayout();
    initWindow();
    updateWidth(_window->width());
}

void Application::checkHover() {
    _left_panel->checkHover();
    _main_task_list->checkHover();
}

void Application::initCategoryList() { // todo: It does nothing now
    _category_list.loadCategoryList(); // todo: implement loadCategoryList in candypane and than use it here.
}

void Application::initLeftPanel(candypane::CategoryList* category_list, MainTaskList* main_task_list) {
    _left_panel = std::make_shared<LeftPanel>(category_list, main_task_list);
}

void Application::initMainTaskList(candypane::CategoryList* category_list) {
    _main_task_list = std::make_shared<MainTaskList>(category_list);
}

void Application::initMainLayout() {
    _main_layout = std::make_shared<QHBoxLayout>(_window.get());
    _main_layout->addWidget(&_splitter);
    _main_layout->setContentsMargins(0, 0, 0, 0);
}

void Application::initSplitter() {
    _splitter.setOrientation(Qt::Horizontal);
    _splitter.setHandleWidth(6);

    _splitter.addWidget(_left_panel.get());
    _splitter.addWidget(_main_task_list.get());
}

void Application::initWindow() {
    _window = std::make_shared<UpdatableWindow<Application>>(this);
    _window->resize(700, 400);

    auto* layout = _window->layout();
    delete layout;

    _window->setLayout(_main_layout->layout());
    _window->show();
}

void Application::update() {
    _left_panel->updateLeftPanel();
}

void Application::updateWidth(int window_width) { // TODO: [BUGS] bad resizing, priority: low
    _main_task_list->setMinimumWidth(window_width-_left_panel->maximumWidth());
    _main_task_list->setMaximumWidth(window_width-_left_panel->minimumWidth());
}
