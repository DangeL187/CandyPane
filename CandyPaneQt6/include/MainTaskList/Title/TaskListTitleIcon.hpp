#ifndef CANDYPANEQT_TASKLISTTITLEICON_HPP
#define CANDYPANEQT_TASKLISTTITLEICON_HPP

#include <QFrame>
#include <QVBoxLayout>
#include <QWidget>

class WidgetBackground;

class TaskListTitleIcon: public QFrame {
public:
    TaskListTitleIcon();
    void selectBackground(bool value);
    void updateIcon();
private:
    std::shared_ptr<WidgetBackground>   _background;
    QWidget                             _icon;
    QVBoxLayout                         _layout;

    void initBackground();
    void initIcon();
    void initLayout();
    void loadStyle();
};

#endif //CANDYPANEQT_TASKLISTTITLEICON_HPP
