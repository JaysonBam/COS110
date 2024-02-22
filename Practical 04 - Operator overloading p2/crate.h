#ifndef CRATE_H
#define CRATE_H

#include <string>

class crate {
private:
  // Members
  std::string name;
  int amount;
  float price;

public:
  // Functions
  crate();
  crate(std::string name, int amount, float price);
  crate(const crate& other);
  crate(std::string s);

  void setName(std::string name);
  void setAmount(int amount);
  void setPrice(float price);

  std::string getName();
  int getAmount();
  float getPrice();
  float getValue();

  friend std::ostream& operator<<(std::ostream& os, crate& c);
  friend std::istream& operator>>(std::istream& is, crate& c);
  crate& operator|(std::string input);

  crate& operator++();
  crate operator++(int);
  crate& operator+=(int a);
  crate& operator-=(int a);

  bool operator==(crate& other);
  bool operator<=(crate& other);
  bool operator>=(crate& other);
  bool operator<(crate& other);
  bool operator>(crate& other);
};

#endif
