/*
 * database.cpp
 *
 *  Created on: 08.06.2013
 *      Author: dla
 */

#include <iostream>
#include "include/database.h"


namespace mw {

inline void Database::add_entry(const Entry& entry) {
  _database[entry.get_name()] = entry;
}

Entry& Database::get_entry(const std::string& name) const {
  auto it = _database.find(name);
  if (it != _database.end()) {
	return it->second;
  }
  return _emptyEntry;
}

void Database::list() const{
  for (auto it = _database.begin(); it != _database.end(); ++it) {
    std::cout << "Name: " << it->first;
    it->second.list();
  }
}

}  // namespace mw
