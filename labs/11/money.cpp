#include "money.h"
#include <math.h>

// This function definition provided as an example
const Money operator +(const Money& amount1, const Money& amount2) {
  // Get all the cents of object 1
  int all_cents1 = amount1.cents_ + amount1.dollars_ * 100;
  // Get all the cents of object 2
  int all_cents2 = amount2.cents_ + amount2.dollars_ * 100;
  // Add all the cents together
  int sum_all_cents = all_cents1 + all_cents2;
  // Handle the fact that money can be negative
  int abs_all_cents = abs(sum_all_cents);
  int final_dollars = abs_all_cents / 100;
  int final_cents = abs_all_cents % 100;
  // If the result of the operation was negative, negate final dollars and cents
  if (sum_all_cents < 0) {
    final_dollars = -final_dollars;
    final_cents = -final_cents;
  }
  return Money(final_dollars, final_cents);
}

// CLASS FUNCTION DEFINITIONS GO HERE
  const Money operator -(const Money& amount1, const Money& amount2) {
// Get all the cents of object 1
  int all_cents1 = amount1.cents_ + amount1.dollars_ * 100;
  // Get all the cents of object 2
  int all_cents2 = amount2.cents_ + amount2.dollars_ * 100;
  // Add all the cents together
  int subtracted_all_cents = all_cents1 - all_cents2;
  // absolute value of cents
  int abs_subtracted_cents = abs(subtracted_all_cents);
  // final dollars & cents
  int final_dollars = abs_subtracted_cents / 100;

  int final_cents = abs_subtracted_cents % 100;

  if (subtracted_all_cents < 0) {
    final_dollars = -final_dollars;
    final_cents = -final_cents;
  }
  return  Money(final_dollars, final_cents);
  }


  bool operator ==(const Money &amount1, const Money &amount2) {
    bool isTrue = false;
      int all_cents1 = amount1.cents_ + amount1.dollars_ * 100;
  // Get all the cents of object 2
     int all_cents2 = amount2.cents_ + amount2.dollars_ * 100;
  // Add all the cents together
  if (all_cents1 == all_cents2) {
    isTrue = true;
  } else {
    isTrue = false;
  }
  return isTrue;
  }

  /*
   * Overload of unary - operator. This is a friend function.
   * @param Money amount - The object to negate
   * @return Money - The result of the negation of the two member variables
   */
  const Money operator -(const Money &amount) {
    return Money (-amount.dollars_, -amount.cents_);
  }

  ostream& operator << (ostream &out, const Money &amount) {
  // setting format
  out << std::fixed;
  out << std::setprecision(2);
  // adding dollars and cents
  double amount2 = amount.dollars_ + (amount.cents_*0.01);
  // overlaoding out
  out << setfill('-') << std::setw(1) << "$" << amount2;

  return out;
  }

