/*
 * entry.h
 *
 *  Created on: 08.06.2013
 *      Author: dla
 */

#ifndef ENTRY_H_
#define ENTRY_H_

#include <map>
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

  inline std::string& get_name() const;
  inline Money& get_balance_money() const;
  inline Time& get_time() const;
  inline void add_record(const Record& record);
  Record& get_record(const RecordOrder_type& order) const;
  Record& get_last_record() const;

  inline void set_name(const std::string& name);

  void list() const;

private:
  std::string _name;
  Money _money;
  Time _time;
  bool _isEmpty;
  std::map<RecordOrder_type, Record> _records;

  void _set_balance_money();
  inline void _set_time();
  Entry(bool isEmpty);
};

}  // namespace mw

#endif  /* ENTRY_H_ */
