#include "meetup.h"

namespace meetup {

scheduler::scheduler(int month, int year) : month_(month), year_(year) {}

boost::gregorian::date scheduler::find_date(boost::gregorian::greg_weekday wd, int start_day) const {
    for (int i = 0; i < 7; ++i) {
        boost::gregorian::date candidate(year_, month_, start_day + i);
        if (candidate.day_of_week() == wd) {
            return candidate;
        }
    }
    return {};
}

boost::gregorian::date scheduler::find_last(boost::gregorian::greg_weekday wd) const {
    int last_day = boost::gregorian::gregorian_calendar::end_of_month_day(year_, month_);
    for (int i = 0; i < 7; ++i) {
        boost::gregorian::date candidate(year_, month_, last_day - i);
        if (candidate.day_of_week() == wd) {
            return candidate;
        }
    }
    return {};
}

#define DEFINE_DAY_METHODS(day_prefix, day_name, boost_day) \
    boost::gregorian::date scheduler::day_prefix##teenth() const { return find_date(boost_day, 13); } \
    boost::gregorian::date scheduler::first_##day_name() const { return find_date(boost_day, 1); } \
    boost::gregorian::date scheduler::second_##day_name() const { return find_date(boost_day, 8); } \
    boost::gregorian::date scheduler::third_##day_name() const { return find_date(boost_day, 15); } \
    boost::gregorian::date scheduler::fourth_##day_name() const { return find_date(boost_day, 22); } \
    boost::gregorian::date scheduler::last_##day_name() const { return find_last(boost_day); }

DEFINE_DAY_METHODS(mon, monday, boost::gregorian::Monday)
DEFINE_DAY_METHODS(tues, tuesday, boost::gregorian::Tuesday)
DEFINE_DAY_METHODS(wednes, wednesday, boost::gregorian::Wednesday)
DEFINE_DAY_METHODS(thurs, thursday, boost::gregorian::Thursday)
DEFINE_DAY_METHODS(fri, friday, boost::gregorian::Friday)
DEFINE_DAY_METHODS(satur, saturday, boost::gregorian::Saturday)
DEFINE_DAY_METHODS(sun, sunday, boost::gregorian::Sunday)

#undef DEFINE_DAY_METHODS

}  // namespace meetup
