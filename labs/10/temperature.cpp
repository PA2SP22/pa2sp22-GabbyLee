#include "temperature.h"

// CLASS FUNCTION DEFINITIONS GO HERE

/*
 * Class Temperature.
 * A class that converts temperatures. It will always internally store the value
 * in kelvin.
 */

  /*
   * Constructor #1.
   * Sets kelvin to 0
   */
  //Constructor #1
  Temperature::Temperature() {
  internal_tempk = 0;

}
  /*
   * Constructor #2.
   * Sets kelvin to the supplied value
   * @param double kelvin - The value to set the internal kelvin to
   */
   
   //Constructor #2.
   Temperature::Temperature (double kelvin) {
     internal_tempk = kelvin;
}

  /*
   * Constructor #3.
   * Converts the supplied temperature to kelvin and internally stores it.
   * The temperature's unit will be provided in the second argument.
   * If the second argument is not value (i.e. not 'F' or 'C') assume the
   * temperature is in kelvin
   * @param double temp - The value to set the internal kelvin to once
   *                    - converted.
   * @param char unit - The type of unit temp is. Will be either 'F' or 'C',
   *                    case-insensitive
   */
   Temperature::Temperature(double temp, char unit) {
       
       
   if( unit =='F' || unit == 'f') {
     internal_tempk = (5.0 * (temp - 32) / 9) + 273.15;
    
    
   }
   else if (unit =='C'|| unit== 'c') {
    internal_tempk  = temp + 273.15;
    
   } else { 
       internal_tempk = temp; 
       
   }  
   }
   
  void Temperature::SetTempFromKelvin(double kelvin) {
         internal_tempk = kelvin;
  }
  
  
  void Temperature::SetTempFromCelsius(double celsius) {
     double c = celsius;
     internal_tempk = c + 273.15;
    
  }
  
  
  void Temperature::SetTempFromFahrenheit(double fahrenheit) {
   double f = fahrenheit;
    internal_tempk = (5.0 * (f - 32) / 9) + 273.15;
  }
  

   
  double Temperature::GetTempAsKelvin() const{
      return internal_tempk;
      
  }
 
 /*
   * Returns the internal temp converted to Celsius
   * Formula: k - 273.15
   * @return double - The temperature in Celsius
   */

  double Temperature::GetTempAsCelsius() const{
    
   double celsius = internal_tempk -273.15;
   return celsius; 
  
  }

  /*
   * Returns the internal temp converted to Fahrenheit
   * Formula: ((c * 9.0) / 5) + 32;
    (K − 273.15) × 9/5 + 32 = °F.
   * @return double - The temperature in Fahrenheit
   */
   
  double Temperature::GetTempAsFahrenheit() const{
     double fahrenheit = (( ( internal_tempk-273.15) * 9.0 ) /5) + 32;
     return fahrenheit;
}
  /*
   * Get a string representation of the temperature.
   * The string will be formatted as:
   * "TEMP UNIT"
   * where TEMP is the temperature to 2 decimal places and UNIT is either
   * "Kelvin", "Celsius", or "Fahrenheit".
   * The conversion to perform is denoted by the parameter.
   * If the unit given through the argument is invalid, set the string to:
   * "Invalid Unit"
   * @uses stringstream
   * @param char unit - The conversion to perform, either 'K', 'C' or 'F',
   *                    defaults to 'K' and is case-insensitive
   * @return string - A string representation of the temperature or invalid if
   *                  the provided unit is not recognized
   */
  
  string Temperature::ToString( char unit ) const {
  stringstream ss;
  string return_string;
  ss.setf(std::ios::fixed|std::ios::showpoint);
  ss.precision(2);
  
  if( unit == 'f'|| unit == 'F' ){
      ss << GetTempAsFahrenheit() << " Fahrenheit";
      return ss.str();
  }
   if( unit == 'k' || unit == 'K' ){
    ss<< GetTempAsKelvin() <<" Kelvin";
   return  ss.str();
  }
    
 if( unit == 'c' || unit =='C' ) {
    ss << GetTempAsCelsius() << " Celsius";
    return  ss.str();
  }
  else { 
   ss << "Invalid Unit";
   return  ss.str();
   }
  


}