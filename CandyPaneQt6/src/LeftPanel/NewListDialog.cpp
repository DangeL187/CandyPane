#include "LeftPanel/NewListDialog.hpp"

void NewListDialog::execDialog() {
    _line_edit.clear();
    _line_edit.setFocus();
    _dialog.exec();
}

std::string NewListDialog::getLineEdit() const {
    return _line_edit.text().toStdString();
}

void NewListDialog::initDialog() {
    _dialog.setWindowTitle("Rename Element");
    _dialog.setMinimumWidth(220);
}

void NewListDialog::NewListDialog::initLayout() {
    _layout = std::make_shared<QVBoxLayout>(&_dialog);
    _layout->addWidget(&_line_edit);
    _layout->addWidget(_ok_button.get());
}

void NewListDialog::initOkButton() {
    _ok_button = std::make_shared<QPushButton>("OK");

    QObject::connect(_ok_button.get(), &QPushButton::clicked, [&]() {
        if (!_line_edit.text().toStdString().empty()) {
            _dialog.accept();
        }
    });
}