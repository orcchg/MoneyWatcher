/*
 * database.h
 *
 *  Created on: 08.06.2013
 *      Author: dla
 */

#ifndef DATABASE_H_
#define DATABASE_H_

#include <map>
#include <memory>
#include "entry.h"


namespace mw {

class Database {
public:
  virtual ~Database();

  void add_entry(Entry* entry);
  Entry* get_entry(const std::string& name) const;

  size_t size() const;

  void list() const;

private:
  std::map<std::string, std::shared_ptr<Entry> > _database;
};

}  // namespace mw

#endif /* DATABASE_H_ */
