#include <iostream>
using namespace std;

class Car {
private:
  string make;
  string model;
  double fuelCapacity;
  double fuelLevel;

public:
  Car() {
    fuelLevel = 0;
  }
  Car(string _make, string _model, double _cap) {
    make = _make;
    model = _model;
    fuelCapacity = _cap;
    fuelLevel = 0;
  }

  double getFuelLevel() const {
    return fuelLevel;
  }

  void operator+(float fuelAdded) {
    if (fuelAdded + fuelLevel <= fuelCapacity) {
      fuelLevel += fuelAdded;
    }
    else {
      cout << "Failed to add fuel: Capacity exceeded\n";
    }
  }

  void operator-(float fuelRemoved) {
    if (fuelRemoved <= fuelLevel) {
      fuelLevel -= fuelRemoved;
    }
    else {
      cout << "Failed to remove fuel: Fuel cannot be negative\n";
    }
  }

  void operator+=(float fuelAdded) {
    if (fuelAdded + fuelLevel <= fuelCapacity) {
      fuelLevel += fuelAdded;
    }
    else {
      cout << "Failed to add fuel: Capacity exceeded\n";
    }
  }

  bool operator==(const Car& car) const {
    return make == car.make && model == car.model && fuelCapacity == car.fuelCapacity;
  }

  bool operator<(const Car& car) const {
    return fuelLevel < car.fuelLevel;
  }

  bool operator>(const Car& car) const {
    return fuelLevel > car.fuelLevel;
  }

  friend ostream& operator<<(ostream& output, const Car& car) {
    output << "Make: " << car.make << "\n";
    output << "Model: " << car.model << "\n";
    output << "Fuel Capacity: " << car.fuelCapacity << " liters \n";
    output << "Fuel Level: " << car.fuelLevel << " liters \n";

    return output;
  }

  friend istream& operator>>(istream& is, Car& car) {
    cout << "Make: ";
    is >> car.make;
    cout << "Model: ";
    is >> car.model;
    cout << "Fuel Capacity: ";
    is >> car.fuelCapacity;

    return is;
  }

  Car operator+(const Car& c) {
    Car newCar(make, model, fuelCapacity);
    newCar += fuelLevel + c.fuelLevel;
    return newCar;
  }
};

int main() {
  Car cars[3];
  for (int i = 0; i < 3; i++) {
    cout << "Car " << i + 1 << "\n";
    cin >> cars[i];
  }

  cars[0] += 93;
  cars[1] + 55;
  cars[2] + 92;
  cars[2] - 2;

  for (int i = 0; i < 3; i++) {
    cout << "Car " << i + 1 << "\n";
    cout << cars[i];
  }
}