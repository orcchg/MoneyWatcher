/*
 * money.h
 *
 *  Created on: 08.06.2013
 *      Author: dla
 */

#ifndef MONEY_H_
#define MONEY_H_

#include <cstdint>


namespace mw {

typedef std::int64_t Money_type;

class Money {
public:
  Money(const Money_type& value = Money_type());

  inline Money_type& get() const;

private:
  Money_type _value;
};

}  // namespace mw

#endif /* MONEY_H_ */
