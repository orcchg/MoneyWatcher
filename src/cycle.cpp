/*
 * cycle.cpp
 *
 *  Created on: Jun 17, 2013
 *      Author: Alov Maxim <m.alov@samsung.com>
 */

#include "include/cycle.h"


namespace mw {

Cycle::~Cycle() {
}

void Cycle::add_page(const std::string& name) {
  std::shared_ptr<Page> ptr(new Page(name));
  _pages.push_back(ptr);
  _pages.sort(&_compare_pages);
}

std::shared_ptr<Database> Cycle::get_last_database() const {
  return _pages.back()->get_database();
}

void Cycle::history() const {
  //
}

/* Private members */
// ----------------------------------------------------------------------------
Cycle::Page::Page(const std::string& name, const DateTime& datetime)
  : name(name)
  , datetime(datetime)
  , db(std::shared_ptr<Database>(new Database()))
  , policy(Policy()) {
}

std::shared_ptr<Database> Cycle::Page::get_database() const {
  return db;
}

bool Cycle::Page::operator < (const Page& rhs) const {
  return datetime < rhs.datetime;
}

bool Cycle::Page::operator == (const Page& rhs) const {
  return datetime == rhs.datetime;
}

bool Cycle::Page::operator != (const Page& rhs) const {
  return datetime != rhs.datetime;
}

// ----------------------------------------------
bool Cycle::_compare_pages(const std::shared_ptr<Page>& first, const std::shared_ptr<Page>& second) {
  return *first < *second;
}

}  // namespace mw
