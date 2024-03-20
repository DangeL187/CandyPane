#include <iostream> // todo: delete
#include "LeftPanel/CategoryWidget.hpp"
#include "LeftPanel/CategoriesListWidget.hpp"
#include "LeftPanel/LineEditCategoryName.hpp"
#include "LeftPanel/OverlayDraggableWidget.hpp"

#include <QPainter>

class Background: public QWidget {
public:
    explicit Background(QWidget* parent): QWidget(parent) {}

    void setColor(unsigned short r, unsigned short g, unsigned short b) {
        std::string color = "background-color: rgb(" + std::to_string(r) + ", " + std::to_string(g) + ", " + std::to_string(b) + ");";
        std::string border = "border-radius: 6px;";
        setStyleSheet((color + border).c_str());
    }
    void setColor() {
        std::string color = "background-color: transparent;";
        std::string border = "border-radius: 6px;";
        setStyleSheet((color + border).c_str());
    }
};

CategoryWidget::CategoryWidget(CategoriesListWidget* categories_list_widget, unsigned long long int id):
    _categories_list_widget(categories_list_widget), _id(id)
{
    initSelect();
    initIcon();
    initTasksAmount();
    initName();
    initLayout();
    initEditName();
}

void CategoryWidget::exec() {
    if (_edit_name->text() == "") {
        //_categories_list_widget->removeCategoryWidget(this);
        return;
    }
    self().setName(_edit_name->text().toStdString());
    _edit_name->setVisible(false);
    _layout->insertWidget(2, _name);
    updateName();
}

candypane::Category& CategoryWidget::self() const {
    return _categories_list_widget->getCategoryById(_id);
}

int CategoryWidget::getNewIndex() {
    int dif = -1;
    int new_index = -1;
    for (int i = 0; i < _categories_list_widget->count()-1; i++) {
        QWidget* widget = _categories_list_widget->itemAt(i)->widget();
        QPoint pos = widget->mapToGlobal(widget->rect().center());
        int diff = abs(pos.y() - QCursor::pos().y()); // vertical difference between widget's center and mouse cursor
        if (dif != -1 && dif < diff) {
            break;
        } else {
            new_index = i;
            dif = diff;
        }
    }
    return new_index;
}

unsigned long long int CategoryWidget::getId() const {
    return _id;
}

void CategoryWidget::initEditName() {
    _edit_name = new LineEditCategoryName(this);
    _edit_name->setStyleSheet("font-size: 14px;");

    _layout->removeWidget(_name);
    _layout->insertWidget(2, _edit_name);
}

void CategoryWidget::initIcon() {
    _icon = new QWidget();
    _icon->setFixedSize(20, 20);
    _icon->setStyleSheet("background-color: red;");
}

void CategoryWidget::initName() {
    _name = new QLabel();
    updateName();
}

void CategoryWidget::initSelect() {
    _select = new QWidget();
    _select->setFixedSize(3, 15);
    _select->setStyleSheet("background-color: rgb(118, 185, 237);");
    _categories_list_widget->deselectAll();

    _select_background = std::make_shared<Background>(this);
    _select_background->setColor(49, 49, 49);
}

void CategoryWidget::initTasksAmount() {
    _tasks_amount = new QLabel();
    _tasks_amount->setAlignment(Qt::AlignRight);
    _tasks_amount->setContentsMargins(0, 0, 10, 0);
    updateTasksAmount();
}

void CategoryWidget::initLayout() {
    _layout = new QHBoxLayout();
    _layout->setContentsMargins(0, 5, 0, 5);

    _layout->addWidget(_select);
    _layout->addWidget(_icon);
    _layout->addWidget(_name);
    _layout->addWidget(_tasks_amount);

    setLayout(_layout);
}

void CategoryWidget::mousePressEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        std::cout << "####\n" << self().getName() << " id: " << _id << "\n";
        for (auto& i: self().getTasks()) {
            std::cout << i.getName() << " " << i.getText() << "\n";
        } std::cout << "####\n\n";

        _drag_start_pos = event->globalPosition().toPoint() - mapToGlobal(rect().topLeft());

        _dragged_object = new OverlayDraggableWidget(*this);
        _dragged_object->show();
        _dragged_object->move(event->globalPosition().toPoint() - _drag_start_pos);

        setWidgetVisible(false);
        _categories_list_widget->deselectAll();
    }
}

void CategoryWidget::mouseMoveEvent(QMouseEvent* event) {
    if (event->buttons() & Qt::LeftButton) {
        QPoint pos = event->globalPosition().toPoint();
        pos -= _drag_start_pos;
        _dragged_object->move(pos);

        int new_index = getNewIndex();
        if (new_index != -1) {
            _categories_list_widget->relocateCategoryById(new_index, _categories_list_widget->indexOf(this));
            _categories_list_widget->relocateCategoryWidget(new_index, _categories_list_widget->indexOf(this));
        }
    }
}

void CategoryWidget::mouseReleaseEvent(QMouseEvent* event) {
    if (_dragged_object != nullptr) {
        _dragged_object->close();
        delete _dragged_object;
        _dragged_object = nullptr;
        setWidgetVisible(true);
        _categories_list_widget->updateCategoryWidgets();
    }
}

void CategoryWidget::resizeEvent(QResizeEvent* event) {
    _select_background->setFixedWidth(qobject_cast<QWidget*>(parent()->parent())->width() - 18); // 18 is padding
    updateName();
}

void CategoryWidget::select(bool value, bool background_only) {
    if (!background_only) {
        if (value) _select->setStyleSheet("background-color: rgb(118, 185, 237);");
        else _select->setStyleSheet("background-color: transparent;");
    }
    if (value) _select_background->setColor(49, 49, 49);
    else if (_select->styleSheet() == "background-color: transparent;") _select_background->setColor();
}

void CategoryWidget::setEditNameFocus() {
    _edit_name->setFocus();
}

void CategoryWidget::setId(unsigned long long int id) {
    _id = id;
}

void CategoryWidget::setWidgetVisible(bool value) {
    if (value) {
        _icon->setStyleSheet("background-color: red;");
        updateName();
        updateTasksAmount();
    } else {
        _icon->setStyleSheet("background-color: transparent");
        _name->setText("");
        _tasks_amount->setText("");
    }
    select(value);
}

void CategoryWidget::updateName() {
    _name->setStyleSheet("font-size: 14px;");
    _name->setText(self().getName().c_str());

    QLabel new_text;
    new_text.setStyleSheet("font-size: 14px;");
    new_text.setText((self().getName() + "...").c_str());
    new_text.setFont(_name->font());

    int name_width = _name->fontMetrics().boundingRect(_name->text()).width();
    int tasks_width = _tasks_amount->fontMetrics().boundingRect(_tasks_amount->text()).width();
    int max_size = _select_background->width() - _select->width() - _icon->width() - tasks_width - 54;

    if (name_width > max_size) {
        while (new_text.fontMetrics().boundingRect(new_text.text()).width() > max_size) {
            std::string str = new_text.text().toStdString();
            str.erase(str.length() - 4, 1);
            new_text.setText(str.c_str());
        }
        _name->setText(new_text.text());
    }
}

void CategoryWidget::updateTasksAmount() {
    _tasks_amount->setText(std::to_string(self().getTasks().size()).c_str());
    _tasks_amount->setStyleSheet("font-size: 14px;");
}

void CategoryWidget::updateWidget() {
    //updateIcon();
    updateTasksAmount();
    updateName();
}
