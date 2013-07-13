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
			   const DateTime& datetime)
  : _money(money)
  , _datetime(datetime)
  , _bs(bs)
  , _comment(comment)
  , _isEmpty(false) {
}

Record::Record(bool isEmpty)
  : _money(Money())
  , _datetime(DateTime())
  , _bs(BS_UNKNOWN)
  , _comment("")
  , _isEmpty(true) {
}

/* Getters */
// ----------------------------------------------
const Money& Record::get_money() const {
  return _money;
}

const DateTime& Record::get_datetime() const {
  return _datetime;
}

const Record::BalanceStatus& Record::get_status() const {
  return _bs;
}

const std::string& Record::get_comment() const {
  return _comment;
}

bool Record::empty() const {
  return _isEmpty;
}

/* Setters */
// ----------------------------------------------
void Record::set_money(const Money& money) {
  _money = money;
}

void Record::set_datetime(const DateTime& datetime) {
  _datetime = datetime;
}

void Record::set_status(const Record::BalanceStatus& bs) {
  _bs = bs;
}

void Record::set_comment(const std::string& comment) {
  _comment = comment;
}

/* Private members */
// ----------------------------------------------------------------------------

}  // namespace mw
