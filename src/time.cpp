/*
 * time.cpp
 *
 *  Created on: 08.06.2013
 *      Author: dla
 */

#include <string>
#include <sstream>
#include <boost/date_time/posix_time/posix_time.hpp>
#include "include/time.h"


namespace mw {

Time::Time()
  : _time(boost::posix_time::second_clock::local_time()) {
  std::ostringstream oss;
  oss << _time.date().day() << " " << _time.date().month()
      << " " << _time.date().year() << " " << _time.date().day_of_week();
  if (!oss.good()) {
	throw ExceptionTime("Error during date processing!");
  }
  _dayMonthYearWeekday = oss.str();
  oss.flush();
  oss.clear();
  oss << _time.time_of_day().hours() << ":"
      << _time.time_of_day().minutes() << ":"
      << _time.time_of_day().seconds();
  if (!oss.good()) {
  	throw ExceptionTime("Error during time of day processing!");
  }
  _hoursMinutesSeconds = oss.str();
  oss.flush();
  oss.clear();
}

std::string Time::get_date() const {
  return _dayMonthYearWeekday;
}

std::string Time::get_time() const {
  return _hoursMinutesSeconds;
}

}  // namespace mw
