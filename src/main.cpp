/*
 * main.cpp
 *
 *  Created on: 08.06.2013
 *      Author: dla
 */

#include "include/database.h"


int main(int argc, char** argv) {
  mw::Database db;
  mw::Entry* entryTravel = new mw::Entry("Travel", 5000);
  mw::Entry* entryIncorporation = new mw::Entry("Incorporation", 10000);
  mw::Entry* entryTransport = new mw::Entry("Transport", 1000);
  mw::Entry* entryFood = new mw::Entry("Food", 2500);
  db.add_entry(entryTravel);
  db.add_entry(entryIncorporation);
  db.add_entry(entryTransport);
  db.add_entry(entryFood);
  mw::Record* recordTravel1st = new mw::Record(250, mw::Record::BS_INCOME, "Unplanned income");
  mw::Record* recordTravel2nd = new mw::Record(500, mw::Record::BS_EXPENSE, "Food in the hotel");
  entryTravel->add_record(recordTravel1st);
  entryTravel->add_record(recordTravel2nd);
  mw::Record* recordInc1st = new mw::Record(1250, mw::Record::BS_EXPENSE, "New smartphone");
  entryIncorporation->add_record(recordInc1st);
  mw::Record* recordTransport1st = new mw::Record(700, mw::Record::BS_EXPENSE, "Metro ticket");
  entryTransport->add_record(recordTransport1st);
  mw::Record* recordFood1st = new mw::Record(600, mw::Record::BS_EXPENSE, "Ice cream coffee");
  mw::Record* recordFood2nd = new mw::Record(1200, mw::Record::BS_EXPENSE, "Corston's hotel food");
  entryFood->add_record(recordFood1st);
  entryFood->add_record(recordFood2nd);
  db.list();

  /*std::map<int, std::shared_ptr<mw::Entry> > m;
  mw::Entry* entry = new mw::Entry();
  std::shared_ptr<mw::Entry> p(entry);
  m.insert(std::pair<int, std::shared_ptr<mw::Entry> >(5, std::shared_ptr<mw::Entry>(entry)));
  std::cout << "USE COUNT: " << p.use_count() << " " << m[5].use_count() << "\n";*/

  return 0;
}
