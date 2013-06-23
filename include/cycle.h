/*
 * cycle.h
 *
 *  Created on: Jun 17, 2013
 *      Author: Alov Maxim <m.alov@samsung.com>
 */

#ifndef CYCLE_H_
#define CYCLE_H_

#include <list>
#include <memory>
#include <string>
#include "include/database.h"
#include "include/datetime.h"
#include "include/policy.h"


namespace mw {

struct Page {
  std::string name;
  DateTime datetime;
  std::shared_ptr<Database> db;
  Policy policy;
};

class Cycle {
public:
  void history() const;

private:
  std::list<Page> _pages;
  std::list<Page>::iterator _currentPage;
};

}  // namespace mw


#endif /* CYCLE_H_ */
