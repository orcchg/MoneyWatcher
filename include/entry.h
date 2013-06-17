/*
 * entry.h
 *
 *  Created on: 08.06.2013
 *      Author: dla
 */

#ifndef ENTRY_H_
#define ENTRY_H_

#include <map>
#include <memory>
#include <string>
#include "money.h"
#include "record.h"
#include "time.h"


namespace mw {

class Entry {
public:
  Entry(const std::string& name = "",
		const Money& money = Money(),
		const Time& time = Time());
  Entry(bool isEmpty);
  virtual ~Entry();

  std::string name() const;
  Money get_balance_money() const;
  Time get_time() const;
  Record* get_record(const Time& time) const;
  Record* get_last_record() const;
  size_t size() const;

  bool empty() const;

  void add_record(Record* record);
  void set_name(const std::string& name);

  void list() const;

private:
  std::string _name;
  Money _money;
  Time _time;
  bool _isEmpty;
  std::multimap<Time, std::shared_ptr<Record> > _records;

  void _set_balance_money();
  void _set_time();
};

}  // namespace mw

#endif  /* ENTRY_H_ */
