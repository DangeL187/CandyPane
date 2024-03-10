#include "Account/AccountButton.hpp"

using candypane::AccountButton;

void AccountButton::action() {
    // --> calls Account::accountPage()
}

std::string AccountButton::getUsername() const {
    return _username;
}

void AccountButton::setUsername(const std::string& username) {
    _username = username;
}
