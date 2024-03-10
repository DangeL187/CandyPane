#ifndef CANDYPANE_ACCOUNTBUTTON_HPP
#define CANDYPANE_ACCOUNTBUTTON_HPP

#include <string>

namespace candypane {

    class AccountButton { // Todo: inherit from Account
    public:
        AccountButton() = default;

        void action();
        [[nodiscard]] std::string getUsername() const;
        void setUsername(const std::string& username);

    private:
        std::string _username;
    };

}

#endif //CANDYPANE_ACCOUNTBUTTON_HPP
