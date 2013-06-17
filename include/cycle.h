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
#include "include/database.h"
#include "include/datetime.h"


namespace mw {

struct Page {
  std::shared_ptr<Database> db;
  DateTime datetime;
};

class Cycle {
public:


private:
  std::list<Page> l;
};

}  // namespace mw


#endif /* CYCLE_H_ */
