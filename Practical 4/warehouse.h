#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include <string>
#include <vector>

class crate;

class warehouse {
private:
  // Members
  int numCrates;
  crate** crates;

public:
  // Functions
  warehouse();
  warehouse(int numCrates);
  warehouse(int numCrates, crate** crates);
  warehouse(const warehouse& w);
  ~warehouse();

  int getNumCrates();
  crate** getCrates();
  float getValue();

  friend std::ostream& operator<<(std::ostream& os, warehouse& w);
  friend std::istream& operator>>(std::istream& is, warehouse& w);
  warehouse& operator+=(crate& c);
  warehouse& operator-=(crate& c);
  warehouse operator|(int method);
  warehouse& operator|=(int method);
  crate& operator[](int index);
  warehouse& operator()();
  warehouse& operator()(crate& c);
};

#endif
