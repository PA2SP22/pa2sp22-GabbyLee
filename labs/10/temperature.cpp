#include "temperature.h"

// CLASS FUNCTION DEFINITIONS GO HERE

/*
 * Class Temperature.
 * A class that converts temperatures. It will always internally store the value
 * in kelvin.
 */
Temperature::Temperature() {
  internal_tempk = 0;
}
  // constructor #2
Temperature::Temperature(double kelvin) {
     internal_tempk = kelvin;
}

  // Constructor #3
Temperature::Temperature(double temp, char unit) {
if (unit == 'F' || unit == 'f') {
  internal_tempk = (5.0 * (temp - 32) / 9) + 273.15;

} else if (unit == 'C'|| unit == 'c') {
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

double Temperature::GetTempAsKelvin() const {
  return internal_tempk;
}

double Temperature::GetTempAsCelsius() const {
double celsius = internal_tempk -273.15;
return celsius;
}

double Temperature::GetTempAsFahrenheit() const {
double fahrenheit = (((internal_tempk-273.15) * 9.0) /5) + 32;
return fahrenheit;
}

string Temperature::ToString(char unit) const {
stringstream ss;
string return_string;
ss.setf(std::ios::fixed|std::ios::showpoint);
ss.precision(2);

if( unit == 'f'|| unit == 'F' ) {
ss << GetTempAsFahrenheit() << " Fahrenheit";
    return ss.str();
}

if( unit == 'k' || unit == 'K' ) {
ss << GetTempAsKelvin() <<" Kelvin";
return  ss.str();
}

if( unit == 'c' || unit =='C' ) {
ss << GetTempAsCelsius() << " Celsius";
    return  ss.str();

} else {
ss << "Invalid Unit";
return  ss.str();
}
}
