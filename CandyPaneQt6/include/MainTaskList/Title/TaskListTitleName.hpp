#ifndef CANDYPANEQT_TASKLISTTITLENAME_HPP
#define CANDYPANEQT_TASKLISTTITLENAME_HPP

#include <QFrame>
#include <QLabel>
#include <QVBoxLayout>

class WidgetBackground;

class TaskListTitleName: public QFrame {
public:
    TaskListTitleName();
    void selectBackground(bool value);
    void updateName(const std::string& new_name);
private:
    std::shared_ptr<WidgetBackground>   _background;
    QVBoxLayout                         _layout;
    QLabel                              _name;

    void initBackground();
    void initLayout();
    void loadStyle();
};

#endif //CANDYPANEQT_TASKLISTTITLENAME_HPP
