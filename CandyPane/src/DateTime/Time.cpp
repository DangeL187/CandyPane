#include "DateTime/Time.hpp"

#include "split.hpp"

using candypane::Time;

Time::Time() {
    hours = 0;
    minutes = 0;
    seconds = 0;
}

Time::Time(unsigned short hours_, unsigned short minutes_, unsigned short seconds_) {
    hours = hours_;
    minutes = minutes_;
    seconds = seconds_;
}

Time::Time(const std::string& time) {
    std::vector<std::string> time_v = split(time, ':');
    hours = std::stoi(time_v[0]);
    minutes = std::stoi(time_v[1]);
    seconds = std::stoi(time_v[2]);
}

Time::Time(const std::vector<unsigned short>& time) {
    hours = time[0];
    minutes = time[1];
    seconds = time[2];
}

bool Time::isValid() const {
    if (hours == 0 && minutes == 0 && seconds == 0) {
        return false;
    }
    return true;
}

bool Time::operator==(const Time &other) const {
    return (hours == other.hours && minutes == other.minutes && seconds == other.seconds);
}
