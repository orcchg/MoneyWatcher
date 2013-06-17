/*
 * database.cpp
 *
 *  Created on: 08.06.2013
 *      Author: dla
 */

#include <iostream>
#include <utility>
#include "include/database.h"


namespace mw {

Database::~Database() {
}

void Database::add_entry(Entry* entry) {
  _database.insert(std::pair<std::string, std::shared_ptr<Entry> >(entry->name(), std::shared_ptr<Entry>(entry)));
}

Entry* Database::get_entry(const std::string& name) const {
  auto it = _database.find(name);
  if (it != _database.end()) {
	return it->second.get();
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
