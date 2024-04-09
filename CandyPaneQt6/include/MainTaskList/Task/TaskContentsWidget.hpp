#ifndef CANDYPANEQT_TASKCONTENTSWIDGET_HPP
#define CANDYPANEQT_TASKCONTENTSWIDGET_HPP

#include <QFrame>
#include <QHBoxLayout>
#include <QLabel>
#include <QVBoxLayout>

#include <Task/Task.hpp>

class TaskContentsWidget: public QFrame {
public:
    TaskContentsWidget();

    void loadStyle();
    void setWidgetVisible(bool value);
    void updateContents(const candypane::Task& task);

private:
    /*===================TaskContentsWidget==================*/
    QVBoxLayout _layout;
    QHBoxLayout _under_layout;
    /*=======================================================*/

    /*=====================TaskContents======================*/
    QLabel*     _assigned_date{};
    QWidget*    _calendar_icon{};
    QWidget*    _category_icon{};
    QLabel*     _category_name{};
    QLabel*     _checklist_progress{};
    QWidget*    _dot1{};
    QWidget*    _dot2{};
    QWidget*    _dot3{};
    QLabel*     _name{};
    QLabel*     _reminder{};
    QWidget*    _reminder_icon{};
    /*=======================================================*/

    /*======================initializers=====================*/
    void initAssignedDate();
    void initCalendarIcon();
    void initCategoryIcon();
    void initCategoryName();
    void initChecklistProgress();
    void initDots();
    void initName();
    void initLayout();
    void initReminder();
    void initReminderIcon();
    void initUnderLayout();
    /*=======================================================*/

    /*========================updaters=======================*/
    void updateAssignedDate(const candypane::Date& date);
    void updateCategoryName(const std::string& category_name);
    void updateChecklistProgress(unsigned int completed, unsigned int total);
    void updateName(const std::string& name);
    void updateReminder(const candypane::Date& date, const candypane::Time& time);
    /*=======================================================*/

    static std::string getDayOfWeek(const candypane::Date& date);
    static std::string getMonth(unsigned short month);
};

#endif //CANDYPANEQT_TASKCONTENTSWIDGET_HPP
