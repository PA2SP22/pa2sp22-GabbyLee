/*
 * Name        : money.h
 * Author      : Gabrielle Lee
 * Description : Class Header File
 */

// ADD HEADER GUARD HERE
#ifndef Lee_Money_H_
#define Lee_Money_H_


#include <string>
#include <iostream>
#include <cstdlib>
#include <iomanip>
using std::string;
using std::ostream;
using std::setfill;
using std::setw;

/*
 * Class Money.
 * A class that handles amounts of money in U.S. Currency.
 */
class Money {
 public:
  Money(int dollars = 0, int cents = 0)
      : dollars_(dollars),
        cents_(cents) {
  }

  int dollars() const {
    return dollars_;
  }


  int cents() const {
    return cents_;
  }

  void set_dollars(int dollars) {
    dollars_ = dollars;
  }

  void set_cents(int cents) {
    cents_ = cents;
  }


  friend const Money operator +(const Money& amount1, const Money& amount2);


  friend const Money operator -(const Money& amount1, const Money& amount2);


  friend bool operator ==(const Money &amount1, const Money &amount2);


  friend const Money operator -(const Money &amount);


  friend ostream& operator <<(ostream &out, const Money &amount);

 private:
  int dollars_;
  int cents_;
};

// REST OF HEADER GUARD GOES HERE
#endif
