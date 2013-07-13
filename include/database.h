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
#include "include/entry.h"


namespace mw {

class Database {
public:
  virtual ~Database();

  void add_entry(const std::string& name = "",
                 const Money& money = Money());
  void add_record(const std::string& entryName = "",
                  const Money& money = Money(),
                  const Record::BalanceStatus& bs = Record::BS_UNKNOWN,
                  const std::string& comment = "");

  std::shared_ptr<Entry> get_entry(const std::string& name) const;

  size_t size() const;

  void list() const;

private:
  std::map<std::string, std::shared_ptr<Entry> > _database;
};

}  // namespace mw

#endif /* DATABASE_H_ */
