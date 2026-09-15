#pragma once

#include <boost/date_time/gregorian/gregorian.hpp>

namespace meetup {

#define DECLARE_DAY_METHODS(day_prefix, day_name) \
    boost::gregorian::date day_prefix##teenth() const; \
    boost::gregorian::date first_##day_name() const; \
    boost::gregorian::date second_##day_name() const; \
    boost::gregorian::date third_##day_name() const; \
    boost::gregorian::date fourth_##day_name() const; \
    boost::gregorian::date last_##day_name() const;

class scheduler {
public:
    scheduler(int month, int year);

    DECLARE_DAY_METHODS(mon, monday)
    DECLARE_DAY_METHODS(tues, tuesday)
    DECLARE_DAY_METHODS(wednes, wednesday)
    DECLARE_DAY_METHODS(thurs, thursday)
    DECLARE_DAY_METHODS(fri, friday)
    DECLARE_DAY_METHODS(satur, saturday)
    DECLARE_DAY_METHODS(sun, sunday)

private:
    int month_;
    int year_;

    boost::gregorian::date find_date(boost::gregorian::greg_weekday wd, int start_day) const;
    boost::gregorian::date find_last(boost::gregorian::greg_weekday wd) const;
};

#undef DECLARE_DAY_METHODS

}  // namespace meetup
