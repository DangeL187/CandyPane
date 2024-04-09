#include "MainTaskList/Task/TaskContentsWidget.hpp"
#include <QDate>

TaskContentsWidget::TaskContentsWidget() {
    initName();
    initAssignedDate();
    initCalendarIcon();
    initCategoryName();
    initChecklistProgress();
    initDots();
    initReminder();
    initReminderIcon();
    initUnderLayout();
    initLayout();
}

std::string TaskContentsWidget::getDayOfWeek(const candypane::Date& date) {
    QDate q_date;
    q_date.setDate(date.year, date.month, date.day);
    switch (q_date.dayOfWeek()) {
        case 1: return "Mon";
        case 2: return "Tue";
        case 3: return "Wed";
        case 4: return "Thu";
        case 5: return "Fri";
        case 6: return "Sat";
        case 7: return "Sun";
    }
}

std::string TaskContentsWidget::getMonth(unsigned short month) {
    switch (month) {
        case 1: return "Jan";
        case 2: return "Feb";
        case 3: return "Mar";
        case 4: return "Apr";
        case 5: return "May";
        case 6: return "Jun";
        case 7: return "Jul";
        case 8: return "Aug";
        case 9: return "Sep";
        case 10: return "Oct";
        case 11: return "Nov";
        case 12: return "Dec";
        default: return "";
    }
}

void TaskContentsWidget::initAssignedDate() {
    _assigned_date = new QLabel();
}

void TaskContentsWidget::initCalendarIcon() {
    _calendar_icon = new QWidget();
    _calendar_icon->setFixedSize(11, 10);
}

void TaskContentsWidget::initCategoryName() {
    _category_name = new QLabel();
}

void TaskContentsWidget::initChecklistProgress() {
    _checklist_progress = new QLabel();
}

void TaskContentsWidget::initDots() {
    _dot1 = new QWidget();
    _dot2 = new QWidget();
    _dot3 = new QWidget();
    _dot1->setFixedSize(3, 3);
    _dot2->setFixedSize(3, 3);
    _dot3->setFixedSize(3, 3);
}

void TaskContentsWidget::initName() {
    _name = new QLabel();
}

void TaskContentsWidget::initLayout() {
    _layout.setContentsMargins(0, 0, 0, 0);
    _layout.addWidget(_name);
    _layout.addLayout(&_under_layout);

    setLayout(&_layout);
}

void TaskContentsWidget::initReminder() {
    _reminder = new QLabel();
}

void TaskContentsWidget::initReminderIcon() {
    _reminder_icon = new QWidget();
    _reminder_icon->setFixedSize(10, 10);
}

void TaskContentsWidget::initUnderLayout() {
    _under_layout.setContentsMargins(0, 0, 0, 0);
    _under_layout.addWidget(_category_name); // todo if not the same with the title
    _under_layout.addWidget(_dot1);
    _under_layout.addWidget(_checklist_progress);
    _under_layout.addWidget(_dot2);
    _under_layout.addWidget(_calendar_icon);
    _under_layout.addWidget(_assigned_date);
    _under_layout.addWidget(_dot3);
    _under_layout.addWidget(_reminder_icon);
    _under_layout.addWidget(_reminder);
    _under_layout.addStretch(1);
}

void TaskContentsWidget::loadStyle() {
    setStyleSheet("background-color: transparent;");
    _assigned_date->setStyleSheet("color: rgb(199, 202, 200); font-size: 14px;");
    _category_name->setStyleSheet("color: rgb(199, 202, 200); font-size: 14px;");
    _checklist_progress->setStyleSheet("color: rgb(199, 202, 200); font-size: 14px;");
    _name->setStyleSheet("font-size: 16px;");
    _reminder->setStyleSheet("color: rgb(199, 202, 200); font-size: 14px;");
}

void TaskContentsWidget::setWidgetVisible(bool value) {
    if (!value) {
        _assigned_date->setText("");
        _calendar_icon->setStyleSheet("");
        _category_name->setText("");
        _checklist_progress->setText("");
        _dot1->setStyleSheet("");
        _dot2->setStyleSheet("");
        _dot3->setStyleSheet("");
        _name->setWordWrap(false);
        _name->setText("");
        _reminder->setText("");
        _reminder_icon->setStyleSheet("");
    }
}

void TaskContentsWidget::updateAssignedDate(const candypane::Date& date) {
    if (date.isValid()) {
        _dot2->setStyleSheet("background-image: url(../img/dot.png);");
        _calendar_icon->setStyleSheet("background-image: url(../img/calendar.png);");
        _assigned_date->setText((getDayOfWeek(date) +
                                std::string(", ") +
                                std::to_string(date.day) +
                                std::string(" ") +
                                getMonth(date.month)).c_str());
    } else {
        _dot2->setStyleSheet("");
        _calendar_icon->setStyleSheet("");
        _assigned_date->setText("");
    }
}

void TaskContentsWidget::updateCategoryName(const std::string& category_name) {
    _category_name->setText(category_name.c_str());
}

void TaskContentsWidget::updateChecklistProgress(unsigned int completed, unsigned int total) {
    if (total != 0) {
        _dot1->setStyleSheet("background-image: url(../img/dot.png);");
        _checklist_progress->setText((std::to_string(completed) + " of " + std::to_string(total)).c_str());
    } else {
        _dot1->setStyleSheet("");
        _checklist_progress->setText("");
    }
}

void TaskContentsWidget::updateContents(const candypane::Task& task) {
    updateName(task.getName());
    updateCategoryName(task.getCategoryName());
    updateChecklistProgress(1, 3);
    updateAssignedDate(task.getDueDate());
    updateReminder(task.getReminderDate(), task.getReminderTime());
}

void TaskContentsWidget::updateName(const std::string& name) {
    _name->setText(name.c_str());
    _name->setWordWrap(true);

    //todo: fix bug when 1 word is not wrapping
}

void TaskContentsWidget::updateReminder(const candypane::Date& date, const candypane::Time& time) {
    // todo: if reminder.date == today date
    if (date.isValid()) {
        _dot3->setStyleSheet("background-image: url(../img/dot.png);");
        _reminder_icon->setStyleSheet("background-image: url(../img/reminder.png);");
        _reminder->setText((getDayOfWeek(date) +
                            std::string(", ") +
                            std::to_string(date.day) +
                            std::string(" ") +
                            getMonth(date.month)).c_str());
    } else {
        _dot3->setStyleSheet("");
        _reminder_icon->setStyleSheet("");
        _reminder->setText("");
    }
}
