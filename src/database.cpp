/*
 * database.cpp
 *
 *  Created on: 08.06.2013
 *      Author: dla
 */

#include <iostream>
#include <utility>
#include "include/database.h"
#include "include/exception.h"


namespace mw {

Database::~Database() {
}

void Database::add_entry(const std::string& name,
                         const Money& money) {
  std::shared_ptr<Entry> ptr(new Entry(name, money));
  _database.insert(std::pair<std::string, std::shared_ptr<Entry> >(name, ptr));
}

void Database::add_record(const std::string& entryName,
                          const Money& money,
                          const Record::BalanceStatus& bs,
                          const std::string& comment) {
  std::shared_ptr<Entry> ptr = get_entry(entryName);
  if (ptr != NULL) {
    ptr->add_record(money, bs, comment);
  } else {
    throw exception::Exception("No such entry \"" + entryName + "\".");
  }
}

std::shared_ptr<Entry> Database::get_entry(const std::string& name) const {
  auto it = _database.find(name);
  if (it != _database.end()) {
	  return it->second;
  }
  return NULL;  // empty Entry
}

size_t Database::size() const {
  return _database.size();
}

void Database::list() const{
  std::cout << "Database size: " << size() << std::endl;
  for (auto it = _database.begin(); it != _database.end(); ++it) {
    std::cout << "Name: " << it->first << std::endl;
    it->second->list();
    std::cout << std::endl;
  }
}

}  // namespace mw
