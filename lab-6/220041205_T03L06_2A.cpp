#include <iostream>
using namespace std;

class Fahrenheit;
class Kelvin;
class Celsius;

class Kelvin {
private:
  float temp;

public:
  Kelvin() {
    temp = 0;
  }

  Kelvin(float _temp) {
    temp = _temp;
  }

  void assign(float _temp) {
    if (_temp >= 0) {
      temp = _temp;
    }
  }

  void display() {
    cout << "The temperature is " << temp << " Kelvin\n";
  }

  operator Fahrenheit();
  operator Celsius();
};

class Fahrenheit {
private:
  float temp;

public:
  Fahrenheit() {
    temp = 0;
  }

  Fahrenheit(float _temp) {
    temp = _temp;
  }

  void assign(float _temp) {
    if (_temp >= -460.0f) {
      temp = _temp;
    }
  }

  void display() {
    cout << "The temperature is " << temp << " Fahrenheit\n";
  }

  operator Celsius();
  operator Kelvin();
};


class Celsius {
private:
  float temp;

public:
  Celsius() {
    temp = 0;
  }

  Celsius(float _temp) {
    temp = _temp;
  }

  void assign(float _temp) {
    if (_temp >= -273.15f) {
      temp = _temp;
    }
  }

  void display() {
    cout << "The temperature is " << temp << " Celsius\n";
  }

  operator Fahrenheit();
  operator Kelvin();
};

Celsius::operator Fahrenheit() {
  return Fahrenheit((temp * ((float)9 / 5)) + 32);
}

Celsius::operator Kelvin() {
  return Kelvin(temp + 273.15);
}

Fahrenheit::operator Celsius() {
  return Celsius((temp - 32) * ((float)5 / 9));
}

Fahrenheit::operator Kelvin() {
  return Kelvin(((temp - 32) * ((float)5 / 9)) + 273.15);
}

Kelvin::operator Celsius() {
  return Celsius(temp - 273.15);
}

Kelvin::operator Fahrenheit() {
  return Fahrenheit(((temp - 273.15) * ((float)9 / 5)) + 32);
}

int main() {
  Celsius boiling(100);
  Fahrenheit fboiling = boiling;
  Kelvin kboiling = boiling;

  boiling.display();
  fboiling.display();
  kboiling.display();
}