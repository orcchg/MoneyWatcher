/*
 * record.cpp
 *
 *  Created on: 08.06.2013
 *      Author: dla
 */

#include "include/record.h"


namespace mw {

Record::Record(const Money& money,
			   const BalanceStatus& bs,
			   const std::string& comment,
			   const Time& time)
  : _money(money)
  , _time(time)
  , _bs(bs)
  , _comment(comment)
  , _isEmpty(false) {
  _order = _convert_time_to_order(_time);
}

Record::Record(bool isEmpty)
  : _money(Money())
  , _time(Time())
  , _bs(BS_UNKNOWN)
  , _comment("")
  , _isEmpty(true)
  , _order(RecordOrder_type()) {
}

/* Getters */
// ----------------------------------------------
Money Record::get_money() const {
  return _money;
}

Time Record::get_time() const {
  return _time;
}

Record::BalanceStatus Record::get_status() const {
  return _bs;
}

std::string Record::get_comment() const {
  return _comment;
}

RecordOrder_type Record::get_order() const {
  return _order;
}

bool Record::empty() const {
  return _isEmpty;
}

/* Setters */
// ----------------------------------------------
void Record::set_money(const Money& money) {
  _money = money;
}

void Record::set_time(const Time& time) {
  _time = time;
}

void Record::set_status(const Record::BalanceStatus& bs) {
  _bs = bs;
}

void Record::set_comment(const std::string& comment) {
  _comment = comment;
}

/* Private members */
// --------------------------------------------------------------------------------------------------------------------
RecordOrder_type Record::_convert_time_to_order(const Time& time) const {
  //
  return RecordOrder_type();
}

}  // namespace mw
