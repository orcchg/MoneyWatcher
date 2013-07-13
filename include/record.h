/*
 * record.h
 *
 *  Created on: 08.06.2013
 *      Author: dla
 */

#ifndef RECORD_H_
#define RECORD_H_

#include <cstdint>
#include <string>
#include "include/money.h"
#include "include/datetime.h"


namespace mw {

class Record {
public:
  enum BalanceStatus { BS_UNKNOWN = -1, BS_INCOME = 0, BS_EXPENSE = 1 };

  Record(const Money& money = Money(),
         const BalanceStatus& bs = BS_UNKNOWN,
         const std::string& comment = "",
         const DateTime& datetime = DateTime());
  Record(bool isEmptry);

  const Money& get_money() const;
  const DateTime& get_datetime() const;
  const BalanceStatus& get_status() const;
  const std::string& get_comment() const;

  bool empty() const;

  void set_money(const Money& money);
  void set_datetime(const DateTime& datetime);
  void set_status(const BalanceStatus& bs);
  void set_comment(const std::string& comment);

private:
  Money _money;
  DateTime _datetime;
  BalanceStatus _bs;
  std::string _comment;
  bool _isEmpty;
};

}  // namespace mw

#endif /* RECORD_H_ */
