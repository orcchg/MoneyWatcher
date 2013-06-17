/*
 * entry.cpp
 *
 *  Created on: 08.06.2013
 *      Author: dla
 */

#include <iostream>
#include "include/entry.h"


namespace mw {

Entry::Entry(const std::string& name,
		     const Money& money,
		     const Time& time)
  : _name(name)
  , _money(money)
  , _time(time)
  , _isEmpty(false) {
}

inline std::string& Entry::get_name() const {
  return _name;
}

inline Money& Entry::get_balance_money() const {
  return _money;
}

inline Time& Entry::get_time() const {
  return _time;
}

inline void Entry::add_record(const Record& record) {
  _records[record.get_order()] = record;
}

Record& Entry::get_record(const RecordOrder_type& order) const {
  auto it = _records.find(order);
  if (it != _records.end()) {
	return it->second;
  }
  return Record(true);  // empty Record
}

Record& Entry::get_last_record() const {
  if (!_records.empty()) {
	return *(--_records.end());
  }
  return Record(true);  // empty Record
}

inline void Entry::set_name(const std::string& name) {
  _name = name;
}

void Entry::list() const {
  for (auto it = _records.begin(); it != _records.end(); ++it) {
    std::cout << "time: " << it->second.get_time().get_time() << ";  date: "
              << it->second.get_time().get_date() << ";  money: "
              << it->second.get_money() << " " << it->second.get_status() << std::endl;
  }
}

/* Private members */
// --------------------------------------------------------------------------------------------------------------------
void Entry::_set_balance_money() {
  Record& record = get_last_record();
  switch (record.get_status()) {
  case Record::BS_INCOME:
	_money += record.get_money();
	break;
  case Record::BS_EXPENSE:
	_money -= record.get_money();
	break;
  default:
	break;
  }
}

inline void Entry::_set_time() {
  _time = get_last_record().get_time();
}

Entry::Entry(bool isEmpty)
  : _name("")
  , _money(Money())
  , _time(Time())
  , _isEmpty(true) {
}

}  // namespace mw
