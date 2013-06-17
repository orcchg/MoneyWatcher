/*
 * time.h
 *
 *  Created on: 08.06.2013
 *      Author: dla
 */

#ifndef TIME_H_
#define TIME_H_

#include <string>
#include <boost/date_time/posix_time/posix_time_types.hpp>


namespace mw {

/// @class DateTime
/// @brief Class always represents current Date and Time when it's instance is constructed.
class DateTime {
public:
  /// @brief Record current Date and Time into class' new instance.
  /// @note Date and Time cannot be changed after construction.
  DateTime();

  std::string get_date() const;
  std::string get_time() const;

  bool operator < (const DateTime& rhs) const;
  bool operator == (const DateTime& rhs) const;
  bool operator != (const DateTime& rhs) const;

  // --------------------------------------------
  class ExceptionTime {
  public:
    ExceptionTime(const std::string& msg)
      : _msg(msg) {
    }

  private:
    std::string _msg;
  };

private:
  boost::posix_time::ptime _datetime;
  std::string _dayMonthYearWeekday;
  std::string _hoursMinutesSeconds;
};

}  // namespace mw

#endif /* TIME_H_ */
