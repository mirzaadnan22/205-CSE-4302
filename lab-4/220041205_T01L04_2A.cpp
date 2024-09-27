#include <iostream>
#include <set>
using namespace std;

class Product {
private:
  string name;
  string id;
  float price;
  int qty;
  int maxAmount;
  static set<Product*> instances;

public:
  Product(string _name, string _ID, float _price, int _qty, int _max) : name{ _name }, id{ _ID }, price{ _price }, qty{ _qty }, maxAmount{ _max } {
    instances.insert(this);
  };

  ~Product() {
    instances.erase(this);
  }

  void addToInventory(int addedQuantity) {
    if (addedQuantity >= 0) {
      qty += addedQuantity;
    }
    else {
      cout << "Cannot add negative quantity\n";
    }
  }
  bool isAvailable() {
    return qty != 0;
  }
  void purchase(int purchasedQuantity) {
    if (purchasedQuantity <= qty) {
      qty -= purchasedQuantity;
    }
    else {
      cout << "Not enough in stock\n";
    }
  }
  void updatePrice(int discountPercent) {
    if (discountPercent >= 0 && discountPercent <= 100) {
      float factor = 1.0f - (discountPercent / 100.0f);
      price *= factor;
    }
  }
  void displayInventoryValue() {
    cout << "Inventory Value: " << qty * price << " BDT\n";
  }
  void displayDetails() {
    cout << "Name: " << name << "\n";
    cout << "ID: : " << id << "\n";
    cout << "Price: " << price << "\n";
    cout << "Quantity: " << qty << "\n";
    cout << "Available: " << (isAvailable() ? "Yes\n" : "No\n");
  }
  static void displayTotalInventoryValue() {
    float total = 0;
    for (auto it = instances.begin(); it != instances.end(); ++it) {
      int q = (*(*it)).qty;
      float p = (*(*it)).price;
      total += p * q;
    }

    cout << "Total Inventory Value: " << total << " BDT\n";
  }
};

set<Product*> Product::instances;

int main() {
  Product p1("Koko Krunch", "001", 300, 5, 16);
  p1.addToInventory(5);
  p1.displayDetails();
  p1.purchase(2);
  p1.displayDetails();
  p1.updatePrice(25);
  p1.displayDetails();
  p1.displayInventoryValue();

  Product p2("Aarong Strawberry Milk", "002", 30, 20, 40);
  Product p3("Pringles", "003", 250, 6, 18);

  Product::displayTotalInventoryValue();
}