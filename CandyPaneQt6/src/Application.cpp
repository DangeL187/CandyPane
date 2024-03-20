#include "Application.hpp"

Application::Application(int argc, char *argv[]): _application(argc, argv) {
    //_application.setStyleSheet("background-color: rgb(49, 49, 49);");
    initLeftPanel();
    initMainCategory();
    initSplitter();
    initMainLayout();
    initWindow();
    updateWidth(_window->width());
}

void Application::checkHover() {
    _left_panel->checkHover();
}

void Application::initLeftPanel() {
    candypane::Category fake_main_category;
    _left_panel = std::make_shared<LeftPanel>(&fake_main_category);
}

void Application::initMainCategory() {
    _main_category = std::make_shared<QWidget>();
    _main_category->setStyleSheet("background-color: black;");
}

void Application::initMainLayout() {
    _main_layout = std::make_shared<QHBoxLayout>(_window.get());
    _main_layout->addWidget(_splitter.get());
    _main_layout->setContentsMargins(0, 0, 0, 0);
}

void Application::initSplitter() {
    _splitter = std::make_shared<UpdatableSplitter<Application>>(this);
    _splitter->setOrientation(Qt::Horizontal);
    _splitter->setHandleWidth(6);

    _splitter->addWidget(_left_panel.get());
    _splitter->addWidget(_main_category.get());
}

void Application::initWindow() {
    _window = std::make_shared<UpdatableWindow<Application>>(this);
    _window->resize(600, 400);

    auto* layout = _window->layout();
    delete layout;

    _window->setLayout(_main_layout->layout());
    _window->show();
}

void Application::updateWidth(int window_width) { // TODO: [BUGS] bad resizing, priority: low
    _main_category->setMinimumWidth(window_width-_left_panel->maximumWidth());
    _main_category->setMaximumWidth(window_width-_left_panel->minimumWidth());
}