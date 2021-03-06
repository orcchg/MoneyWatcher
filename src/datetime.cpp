/*
 * time.cpp
 *
 *  Created on: 08.06.2013
 *      Author: dla
 */

#include <string>
#include <sstream>
#include <boost/date_time/posix_time/posix_time.hpp>
#include "include/datetime.h"
#include "include/exception.h"


namespace mw {

DateTime::DateTime()
  : _datetime(boost::posix_time::second_clock::local_time()) {
  std::ostringstream oss;
  oss << _datetime.date().day() << " " << _datetime.date().month()
      << " " << _datetime.date().year() << " " << _datetime.date().day_of_week();
  if (!oss.good()) {
	throw exception::Exception("Error during date processing!");
  }
  _dayMonthYearWeekday = oss.str();
  oss.str("");
  oss.flush();
  oss.clear();
  oss << _datetime.time_of_day().hours() << ":"
      << _datetime.time_of_day().minutes() << ":"
      << _datetime.time_of_day().seconds();
  if (!oss.good()) {
  	throw exception::Exception("Error during time of day processing!");
  }
  _hoursMinutesSeconds = oss.str();
  oss.str("");
  oss.flush();
  oss.clear();
}

std::string DateTime::get_date() const {
  return _dayMonthYearWeekday;
}

std::string DateTime::get_time() const {
  return _hoursMinutesSeconds;
}

bool DateTime::operator < (const DateTime& rhs) const {
  return _datetime < rhs._datetime;
}

bool DateTime::operator == (const DateTime& rhs) const {
  return _datetime == rhs._datetime;
}

bool DateTime::operator != (const DateTime& rhs) const {
  return !(*this == rhs);
}

}  // namespace mw
