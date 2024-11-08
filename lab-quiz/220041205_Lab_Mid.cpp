#include <iostream>
using namespace std;

class Vehicle {
private:
  string modelno;
  double price;
  double fuelCapacity;

public:
  Vehicle(string _m, double _p, double _fp) {
    setModelNo(_m);
    setPrice(_p);
    setFuelCapacity(_fp);
  }

  string getModelNo() const {
    return modelno;
  }

  double getPrice() const {
    return price;
  }

  double getFuelCapacity() const {
    return fuelCapacity;
  }

  void setModelNo(const string _model) {
    modelno = _model;
  }

  void setPrice(const double _price) {
    if (_price >= 0) {
      price = _price;
    }
    else {
      cout << "Price cannot be negative\n";
    }
  }

  void setFuelCapacity(const double _fCap) {
    if (_fCap >= 0) {
      fuelCapacity = _fCap;
    }
    else {
      cout << "Fuel Capacity cannot be negative\n";
    }
  }

  friend bool operator >= (const Vehicle& v1, const Vehicle& v2) {
    return v1.price >= v2.price;
  }

  friend bool operator <= (const Vehicle& v1, const Vehicle& v2) {
    return v1.price <= v2.price;
  }

  friend bool operator != (const Vehicle& v1, const Vehicle& v2) {
    return v1.price != v2.price;
  }

  void display() {
    cout << "Model Number: " << modelno << "\n";
    cout << "Price: BDT " << price << "\n";
    cout << "Fuel Capacity: " << fuelCapacity << " liters\n";
  }
};

void swapVehicles(Vehicle& v1, Vehicle& v2) {
  Vehicle temp = v1;
  v1 = v2;
  v2 = temp;
}

void sortByPriceAndFuelCapacity(Vehicle vecs[], int len) {
  for (int i = 0; i < len - 1; i++) {
    for (int j = 0; j < len - 1 - i; j++) {
      if (vecs[j] != vecs[j + 1]) {
        if (vecs[j] >= vecs[j + 1]) {
          swapVehicles(vecs[j], vecs[j + 1]);
        }
      }
      else {
        if (vecs[j].getFuelCapacity() > vecs[j + 1].getFuelCapacity()) {
          swapVehicles(vecs[j], vecs[j + 1]);
        }
      }
    }
  }
}

int main() {
  const int len = 10;
  Vehicle vecs[len] = { {"A", 88, 10}, {"B", 55, 12}, {"C", 55, 8}, {"D", 88, 6}, {"E", 55, 20}, {"F", 20, 20}, {"G", 100, 120}, {"H", 5, 1}, {"I", 5, 0.5}, {"J", 100, 111} };

  sortByPriceAndFuelCapacity(vecs, len);

  for (int i = 0; i < len; i++) {
    cout << "***** CAR " << i + 1 << " *****\n";
    vecs[i].display();
    cout << "\n";
  }
}