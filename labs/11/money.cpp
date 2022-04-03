#include "money.h"

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
  /*
   * Overload of + operator. This is a friend function.
   * @param Money amount1 - The first object to add
   * @param Money amount2 - The second object to add
   * @return Money - The two objects added together
   */
 //const Money operator +(const Money& amount1, const Money& amount2) {

   
   
   
   /*
   * Overload of binary - operator. This is a friend function.
   * @param Money amount1 - The object to subtract from
   * @param Money amount2 - The object to be subtracted
   * @return Money - The result of the subtraction
   */
 const Money operator -(const Money& amount1, const Money& amount2) {
   
// Get all the cents of object 1
  int all_cents1 = amount1.cents_ + amount1.dollars_ * 100;
  // Get all the cents of object 2
  int all_cents2 = amount2.cents_ + amount2.dollars_ * 100;
  // Add all the cents together
  int subtracted_all_cents = all_cents1 - all_cents2;
  // Handle the fact that money can be negative
  int abs_all_cents = abs(subtracted_all_cents);
  
  int final_dollars = abs_all_cents / 100;
  
  int final_cents = abs_all_cents % 100;
  // If the result of the operation was negative, negate final dollars and cents
  if (subtracted_all_cents < 0) {
    final_dollars = -final_dollars;
    final_cents = -final_cents;
  }
  return  Money(final_dollars, final_cents);
   
   }
   
     /*
   * Overload of == operator. This is a friend function.
   * @param Money amount1 - The first object to compare
   * @param Money amount2 - The second object to compare
   * @return bool - True if the objects have the same values, otherwise false
   */
   
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
   const Money operator -(const Money &amount){
     
    return Money(-amount.dollars_, amount.cents_);
  }

  /*
   * Overload of << operator.
   * Outputs the money values to the output stream.
   * Should be in the form $x.xx
   * @uses setw()
   * @uses setfill()
   * @param ostream &out - The ostream object to output to
   * @param Money amount - The Money object to output from.
   * @return ostream& - The ostream object to allow for chaining of <<
   */
   ostream& operator <<(ostream &out, const Money &amount){
    out << amount.dollars_;
    return out;
  }