#include "DateTime/Date.hpp"

#include "split.hpp"

using candypane::Date;

Date::Date() {
    day = 0;
    month = 0;
    year = 0;
}

Date::Date(unsigned short day_, unsigned short month_, unsigned short year_) {
    day = day_;
    month = month_;
    year = year_;
}

Date::Date(const std::string& date) {
    std::vector<std::string> date_v = split(date, '-');
    day = std::stoi(date_v[0]);
    month = std::stoi(date_v[1]);
    year = std::stoi(date_v[2]);
}

Date::Date(const std::vector<unsigned short>& date) {
    day = date[0];
    month = date[1];
    year = date[2];
}

bool Date::isValid() const {
    if (day == 0 && month == 0 && year == 0) {
        return false;
    }
    return true;
}

bool Date::operator==(const Date &other) const {
    return (day == other.day && month == other.month && year == other.year);
}
