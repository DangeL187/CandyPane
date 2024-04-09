#ifndef CANDYPANEQT_TIME_HPP
#define CANDYPANEQT_TIME_HPP

#include <string>
#include <vector>

namespace candypane {

    struct Time {
        unsigned short hours = 0;
        unsigned short minutes = 0;
        unsigned short seconds = 0;

        Time();
        Time(unsigned short day_, unsigned short month_, unsigned short year_);
        explicit Time(const std::string& date);
        explicit Time(const std::vector<unsigned short>& date);

        [[nodiscard]] bool isValid() const;

        bool operator==(const Time &other) const;
    };

}

#endif //CANDYPANEQT_TIME_HPP
