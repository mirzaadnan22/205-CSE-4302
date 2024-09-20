#include <iostream>
using namespace std;

class Temperature {
private:
  float temperature;
  float incStep;

public:
  void setIncrementStep(float value) {
    incStep = value;
  }

  float getTemperature() {
    return temperature;
  }

  void increment() {
    temperature += incStep;
  }

  void resetTemperature() {
    temperature = 0;
  }
};

int main() {
  Temperature temp;
  temp.resetTemperature();
  temp.setIncrementStep(5);

  temp.increment();
  temp.increment();

  temp.setIncrementStep(-3);
  temp.increment();

  cout << "Temperature: " << temp.getTemperature() << endl;
}