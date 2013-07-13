/*
 * engine.cpp
 *
 *  Created on: 13.07.2013
 *      Author: dla
 */

#include "include/engine.h"
#include "include/cycle.h"


namespace mw {

void Engine::run() const {
  Cycle cycle;
  cycle.add_page("First page");

  mw::Database db = *cycle.get_last_database();
  db.add_entry("Travel", mw::Money(5000));
  db.add_record("Travel", mw::Money(250), mw::Record::BS_INCOME, "Unplanned income");
  db.add_record("Travel", mw::Money(500), mw::Record::BS_EXPENSE, "Food in the hotel");

  db.add_entry("Incorporation", mw::Money(10000));
  db.add_record("Incorporation", mw::Money(1250), mw::Record::BS_EXPENSE, "New smartphone");

  db.add_entry("Transport", mw::Money(1000));
  db.add_record("Transport", mw::Money(700), mw::Record::BS_EXPENSE, "Metro ticket");

  db.add_entry("Food", mw::Money(2500));
  db.add_record("Food", mw::Money(600), mw::Record::BS_EXPENSE, "Ice cream coffee");
  db.add_record("Food", mw::Money(1200), mw::Record::BS_EXPENSE, "Corston's hotel food");

  db.list();
}

}  // namespace mw
