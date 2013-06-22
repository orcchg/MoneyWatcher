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
#include "include/money.h"
#include "include/record.h"
#include "include/datetime.h"


namespace mw {

class Entry {
public:
  Entry(const std::string& name = "",
        const Money& money = Money(),
        const DateTime& datetime = DateTime());
  Entry(bool isEmpty);
  virtual ~Entry();

  std::string name() const;
  Money get_balance_money() const;
  DateTime get_datetime() const;
  std::shared_ptr<Record> get_record(const DateTime& datetime) const;
  std::shared_ptr<Record> get_last_record() const;
  size_t size() const;

  bool empty() const;

  void add_record(const Money& money = Money(),
                  const Record::BalanceStatus& bs = Record::BS_UNKNOWN,
                  const std::string& comment = "");
  void set_name(const std::string& name);

  void list() const;

private:
  std::string _name;
  Money _money;
  DateTime _datetime;
  bool _isEmpty;
  std::multimap<DateTime, std::shared_ptr<Record> > _records;

  void _set_balance_money();
  void _set_datetime();
};

}  // namespace mw

#endif  /* ENTRY_H_ */
