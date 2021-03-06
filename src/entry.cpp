/*
 * entry.cpp
 *
 *  Created on: 08.06.2013
 *      Author: dla
 */

#include <iostream>
#include <utility>
#include "include/entry.h"


namespace mw {

Entry::Entry(const std::string& name,
		     const Money& money,
		     const DateTime& datetime)
  : _name(name)
  , _money(money)
  , _datetime(datetime)
  , _isEmpty(false) {
}

Entry::Entry(bool isEmpty)
  : _name("")
  , _money(Money())
  , _datetime(DateTime())
  , _isEmpty(true) {
}

Entry::~Entry() {
}

/* Getters */
// ----------------------------------------------
const std::string& Entry::name() const {
  return _name;
}

const Money& Entry::get_balance_money() const {
  return _money;
}

const DateTime& Entry::get_datetime() const {
  return _datetime;
}

const std::shared_ptr<Record>& Entry::get_record(const DateTime& datetime) const {
  auto it = _records.find(datetime);
  if (it != _records.end()) {
	  return it->second;
  }
  return NULL;  // empty Record
}

const std::shared_ptr<Record>& Entry::get_last_record() const {
  if (!_records.empty()) {
	  return (--_records.end())->second;
  }
  return NULL;  // empty Record
}

size_t Entry::size() const {
  return _records.size();
}

bool Entry::empty() const {
  return _isEmpty;
}

/* Setters */
// ----------------------------------------------
void Entry::add_record(const Money& money,
                       const Record::BalanceStatus& bs,
                       const std::string& comment) {
  std::shared_ptr<Record> ptr(new Record(money, bs, comment));
  _records.insert(std::pair<DateTime, std::shared_ptr<Record> >(ptr->get_datetime(), ptr));
}

void Entry::set_name(const std::string& name) {
  _name = name;
}

void Entry::list() const {
  std::cout << "Entry size: " << size() << std::endl;
  for (auto it = _records.begin(); it != _records.end(); ++it) {
    std::cout << "time: " << it->second->get_datetime().get_time() << ";  date: "
              << it->second->get_datetime().get_date() << ";  money: "
              << it->second->get_money() << " " << it->second->get_status() << std::endl;
  }
}

/* Private members */
// ----------------------------------------------------------------------------
void Entry::_set_balance_money() {
  std::shared_ptr<Record> record = get_last_record();
  switch (record->get_status()) {
  case Record::BS_INCOME:
	  _money += record->get_money();
	  break;
  case Record::BS_EXPENSE:
	  _money -= record->get_money();
	  break;
  default:
	  break;
  }
}

void Entry::_set_datetime() {
  _datetime = get_last_record()->get_datetime();
}

}  // namespace mw
