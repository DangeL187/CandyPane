#include "DateTime/DateTimeModule.hpp"

#include <chrono>

using candypane::Date;
using candypane::Time;
using candypane::DateTimeModule;

std::string DateTimeModule::getDateTime(int additional_days) {
    time_t now = time(nullptr);
    struct tm* t_struct = localtime(&now);

    t_struct->tm_mday += additional_days;
    mktime(t_struct);

    char buf[80];
    strftime(buf, sizeof(buf), "%d-%m-%Y-%X", t_struct);

    return buf;
}

Date DateTimeModule::getTodayDate() {
    return Date(getDateTime());
}

Date DateTimeModule::getTomorrowDate() {
    return Date(getDateTime(1));
}
