#include <string>
#include <vector>

namespace candypane {

    struct Date {
        unsigned short day = 0;
        unsigned short month = 0;
        unsigned short year = 0;

        Date();
        Date(unsigned short day_, unsigned short month_, unsigned short year_);
        explicit Date(const std::string& date);
        explicit Date(const std::vector<unsigned short>& date);

        [[nodiscard]] bool isValid() const;

        bool operator==(const Date &other) const;
    };

}