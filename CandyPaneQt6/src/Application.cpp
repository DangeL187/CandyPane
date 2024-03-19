#include "Application.hpp"

Application::Application(int argc, char *argv[]): _application(argc, argv) {
    initLeftPanel();
    initMainCategory();
    initSplitter();
    initMainLayout();
    initWindow();
    updateWidth(getWindowWidth());
}

int Application::getWindowWidth() {
    return _window->width();
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
    _window->setLayout(_main_layout->layout());
    _window->show();
}

void Application::updateWidth(int window_width) {
    _main_category->setMinimumWidth(window_width-_left_panel->maximumWidth());
    _main_category->setMaximumWidth(window_width-_left_panel->minimumWidth());

    _left_panel->updateWidth();
}