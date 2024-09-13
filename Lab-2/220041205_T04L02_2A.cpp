#include <iostream>
#include <vector>
#include <limits>
using namespace std;

const float DISTANCE = 100; // in km
const float PETROL_PRICE = 0.89;
const float DIESEL_PRICE = 3.24;
const float HYBRID_PRICE = 2.45;

struct Car {
  string brand;
  string model;
  int year;
  string fuelType;
  float mileage;
};

void displayInfo(Car& car) {
  cout << "Brand: " << car.brand << "\n";
  cout << "Model: " << car.model << "\n";
  cout << "Year: " << car.year << "\n";
  cout << "Fuel Type: " << car.fuelType << "\n";
  cout << "Mileage: " << car.mileage << "\n";
}

bool isEfficient(Car& car) {
  return car.fuelType != "Electric" && car.mileage > 15;
}

float fuelConsum(Car& car) {
  if (car.fuelType != "Electric") {
    return DISTANCE / car.mileage;
  }
  return 0;
}

float fuelCost(Car& car) {
  float liters = fuelConsum(car);

  if (car.fuelType == "Petrol") {
    return liters * PETROL_PRICE;
  }
  else if (car.fuelType == "Diesel") {
    return liters * DIESEL_PRICE;
  }
  else if (car.fuelType == "Hybrid") {
    return liters * HYBRID_PRICE;
  }
  else {
    return 0;
  }
}

int main() {
  Car cars[3];
  for (int i = 0; i < 3; i++) {
    cout << "Car " << i + 1 << "\n";

    char temp[10];
    cout << "Brand: ";
    getline(cin, cars[i].brand);

    cout << "Model: ";
    getline(cin, cars[i].model);

    cout << "Year: ";
    cin >> cars[i].year;


    cout << "Fuel Type: ";
    cin >> cars[i].fuelType;

    cout << "Mileage: ";
    cin >> cars[i].mileage;

    if (cars[i].fuelType == "Electric") {
      cout << "This car is electric, efficiency measured in km/charge.\n";
    }
    else {
      cout << "Estimated fuel cost for 100 km: $" << fuelCost(cars[i]) << "\n";
    }

    if (isEfficient(cars[i])) {
      cout << "This car is fuel-efficient\n";
    }
    else {
      cout << "This car is not fuel-efficient\n";
    }

    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
}