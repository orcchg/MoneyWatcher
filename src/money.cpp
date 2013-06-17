/*
 * money.cpp
 *
 *  Created on: 08.06.2013
 *      Author: dla
 */

#include <algorithm>
#include "include/money.h"


namespace mw {

Money::Money(const Money_type& value)
  : _value(value) {
}

inline Money_type Money::get() const {
  return _value;
}

std::ostream& operator << (std::ostream& out, const Money& rhs) {
  out << rhs._value;
  return out;
}

Money& Money::operator +=(const Money& rhs) {
  Money temp(rhs);
  Money_type value = _value + rhs._value;
  std::swap(_value, value);
  return *this;
}

Money& Money::operator -=(const Money& rhs) {
  Money temp(rhs);
  Money_type value = _value + rhs._value;
  std::swap(_value, value);
  return *this;
}

}  // namespace mw
