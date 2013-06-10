/*
 * money.cpp
 *
 *  Created on: 08.06.2013
 *      Author: dla
 */

#include "money.h"


namespace mw {

Money::Money(const Money_type& value)
  : _value(value) {
}

inline Money_type& Money::get() const {
  return _value;
}

}  // namespace mw
