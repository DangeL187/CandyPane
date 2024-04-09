#include "Date.hpp"
#include "Time.hpp"

namespace candypane {

    class DateTimeModule {
    public:
        static Date getTodayDate();
        static Date getTomorrowDate();

    private:
        static std::string getDateTime(int additional_days = 0);
    };

}
