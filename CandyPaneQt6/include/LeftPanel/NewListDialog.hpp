#ifndef CANDYPANEQT_NEWLISTDIALOG_HPP
#define CANDYPANEQT_NEWLISTDIALOG_HPP

#include <memory>
#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>

class NewListDialog {
public:
    NewListDialog() {
        initDialog();
        initOkButton();
        initLayout();
    }

    void execDialog();
    [[nodiscard]] std::string getLineEdit() const;

private:
    QDialog                         _dialog;
    std::shared_ptr<QVBoxLayout>    _layout;
    QLineEdit                       _line_edit;
    std::shared_ptr<QPushButton>    _ok_button;

    void initDialog();
    void initLayout();
    void initOkButton();
};

#endif //CANDYPANEQT_NEWLISTDIALOG_HPP
