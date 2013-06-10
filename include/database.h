/*
 * database.h
 *
 *  Created on: 08.06.2013
 *      Author: dla
 */

#ifndef DATABASE_H_
#define DATABASE_H_

#include <map>
#include "entry.h"


namespace mw {

class Database {
public:
  inline void add_entry(const Entry& entry);
  Entry& get_entry(const std::string& name) const;

  void list() const;

private:
  std::map<std::string, Entry> _database;

  static const Entry _emptyEntry = Entry();
};

}  // namespace mw

#endif /* DATABASE_H_ */
