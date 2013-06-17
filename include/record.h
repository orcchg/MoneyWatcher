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
#include "money.h"
#include "time.h"


namespace mw {

class Record {
public:
  enum BalanceStatus { BS_UNKNOWN = -1, BS_INCOME = 0, BS_EXPENSE = 1 };

  Record(const Money& money = Money(),
		 const BalanceStatus& bs = BS_UNKNOWN,
		 const std::string& comment = "",
		 const Time& time = Time());
  Record(bool isEmptry);

  Money get_money() const;
  Time get_time() const;
  BalanceStatus get_status() const;
  std::string get_comment() const;

  bool empty() const;

  void set_money(const Money& money);
  void set_time(const Time& time);
  void set_status(const BalanceStatus& bs);
  void set_comment(const std::string& comment);

private:
  Money _money;
  Time _time;
  BalanceStatus _bs;
  std::string _comment;
  bool _isEmpty;
};

}  // namespace mw

#endif /* RECORD_H_ */
