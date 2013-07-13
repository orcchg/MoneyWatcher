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

class Cycle {
public:
  virtual ~Cycle();

  void add_page(const std::string& name = "");

  void history() const;

private:
  struct Page {
    std::string name;
    DateTime datetime;
    std::shared_ptr<Database> db;
    Policy policy;

    Page(const std::string& name, const DateTime& datetime = DateTime());

    bool operator < (const Page& rhs) const;
    bool operator == (const Page& rhs) const;
    bool operator != (const Page& rhs) const;
  };

  std::list<std::shared_ptr<Page> > _pages;
  std::list<std::shared_ptr<Page> >::iterator _currentPage;

  static bool _compare_pages(const std::shared_ptr<Page>& first, const std::shared_ptr<Page>& second);
};

}  // namespace mw


#endif /* CYCLE_H_ */
