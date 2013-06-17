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

typedef std::int32_t RecordOrder_type;

class Record {
public:
  enum BalanceStatus { BS_UNKNOWN = -1, BS_INCOME = 0, BS_EXPENSE = 1 };

  Record(const Money& money = Money(),
		 const BalanceStatus& bs = BS_UNKNOWN,
		 const std::string& comment = "",
		 const Time& time = Time());

  inline Money& get_money() const;
  inline Time& get_time() const;
  inline BalanceStatus& get_status() const;
  inline std::string& get_comment() const;
  inline RecordOrder_type& get_order() const;

  inline void set_money(const Money& money);
  inline void set_time(const Time& time);
  inline void set_status(const BalanceStatus& bs);
  inline void set_comment(const std::string& comment);

private:
  Money _money;
  Time _time;
  BalanceStatus _bs;
  std::string _comment;
  bool _isEmpty;
  RecordOrder_type _order;

  RecordOrder_type _convert_time_to_order(const Time& time) const;
  Record(bool isEmptry);
};

}  // namespace mw

#endif /* RECORD_H_ */
