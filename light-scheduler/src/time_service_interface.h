#ifndef TIME_SERVICE_INTERFACE_INCLUDED
#define TIME_SERVICE_INTERFACE_INCLUDED

#include <chrono>
#include <functional>
#include <memory>

class ITimeService
{
public:
    struct time_t {
        int second;
        int minute;
        int hour;
        int day_of_month;
        int month;
        int year;
        int day_of_week;
    };

    using wakeup_callback = std::function<void()>;
    using callback_handler = std::unique_ptr<size_t>;

    virtual ~ITimeService() = default;
    virtual time_t current_time() const = 0;
    virtual callback_handler set_periodic_alarm(std::chrono::minutes period,
                                                wakeup_callback callback) = 0;
    virtual void unset_periodic_alarm(callback_handler handler) = 0;
};

#endif
