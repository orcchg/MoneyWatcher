/*
 * record.cpp
 *
 *  Created on: 08.06.2013
 *      Author: dla
 */

#include "include/record.h"


namespace mw {

Record::Record(const Money& money = Money(),
			   const BalanceStatus& bs = BS_UNKNOWN,
			   const std::string& comment = "",
			   const Time& time = Time())
  : _money(money)
  , _time(time)
  , _bs(bs)
  , _comment(comment) {
  _order = _convert_time_to_order(_time);
}

inline Money& Record::get_money() const {
  return _money;
}

inline Time& Record::get_time() const {
  return _time;
}

inline Record::BalanceStatus& Record::get_status() const {
  return _bs;
}

inline std::string& Record::get_comment() const {
  return _comment;
}

inline RecordOrder_type& Record::get_order() const {
  return _order;
}

inline void Record::set_money(const Money& money) {
  _money = money;
}

inline void Record::set_time(const Time& time) {
  _time = time;
}

inline void Record::set_status(const Record::BalanceStatus& bs) {
  _bs = bs;
}

inline void Record::set_comment(const std::string& comment) {
  _comment = comment;
}

/* Private members */
// --------------------------------------------------------------------------------------------------------------------
RecordOrder_type _convert_time_to_order(const Time& time) const {
  //
  return RecordOrder_type();
}

}  // namespace mw
