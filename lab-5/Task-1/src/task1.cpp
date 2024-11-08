#include <iostream>
#include <algorithm>
#include "Product.h"
#include <sstream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

bool compareFunction(Product& a, Product& b) { return a.getName() < b.getName(); }

int getRandomNum(int a, int b) {
  srand(time(0));
  return rand() % (b - a + 1) + a;
}

string generateRandomString(int length) {
  std::string randomString;
  const char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  int alphabetSize = sizeof(alphabet) - 1; // Exclude null character

  srand(static_cast<unsigned int>(time(0))); // Seed the random number generator

  for (int i = 0; i < length; ++i) {
    randomString += alphabet[rand() % alphabetSize];
  }

  return randomString;
}

int randomInRange(int min, int max) {
  // Ensure min is less than or equal to max
  if (min > max) {
    std::swap(min, max); // Swap if min is greater than max
  }

  return rand() % (max - min + 1) + min;
}

double randomDouble(double min, double max) {
  // Ensure min is less than or equal to max
  if (min > max) {
    std::swap(min, max); // Swap if min is greater than max
  }

  // Generate a random double between 0 and 1
  double randomFraction = static_cast<double>(rand()) / RAND_MAX;

  // Scale and shift the random value to the desired range
  return min + randomFraction * (max - min);
}


void EditInformationByKeyboard(Product& prod) {
  string str;
  int q;
  float b;
  // name
  cout << "Name: ";
  getline(cin, str);
  if (str.size()) prod.setName(str);

  // category
  cout << "Category: ";
  getline(cin, str);
  if (str.size()) prod.setCategory(str);

  // description
  cout << "Description: ";
  getline(cin, str);
  if (str.size()) prod.setDescription(str);

  // quantity
  cout << "Quantity: ";
  getline(cin, str);
  if (str.size()) prod.setQuantity(stoi(str));

  // price
  cout << "Price: ";
  getline(cin, str);
  if (str.size()) {
    stringstream ss(str);
    ss >> b;
    prod.setPrice(b);
  }

  cout << "Discount: ";
  getline(cin, str);
  if (str.size()) {
    stringstream ss(str);
    ss >> b;
    prod.setDiscount(b);
  }
}

void generateInformationRandom(Product& prod) {
  prod.setName(generateRandomString(getRandomNum(3, 7)) + " " + generateRandomString(getRandomNum(3, 7)) + " " + generateRandomString(getRandomNum(3, 7)));
  prod.setCategory(generateRandomString(getRandomNum(3, 7)));

  string desc = "";
  for (int i = 0; i < 10; i++) {
    desc += generateRandomString(getRandomNum(3, 7));
    desc += " ";
  }
  prod.setDescription(desc);
  prod.setQuantity(randomInRange(3, 50));
  prod.setPrice(randomDouble(10, 500));
  prod.setPrice(randomDouble(1, 10));
}

void ShowAllDiscount(Product ar[]) {
  cout << "DISCOUNTS\n";
  for (int i = 0; i < 100; i++) {
    cout << ar[i].getName() << ": " << ar[i].getDiscount() << "%\n";
  }
}

void grossTotal(Product ar[]) {
  cout << "GROSS TOTAL\n";
  for (int i = 0; i < 100; i++) {
    int amount = rand() % (20 - 1) + 1;
    cout << ar[i].getName() << ": " << ar[i].netTotal(amount) << " BDT \n";
  }
}

void ShowAllAlphabetically(Product ar[]) {
  sort(ar, ar + 100, compareFunction);
  for (int i = 0; i < 100; i++) {
    cout << ar[i].getName() << " - " << ar[i].getQuantity() << "\n";
  }
}

int main() {
  srand(time(0));
  Product products[100];

  for (int i = 0; i < 100; i++) {
    srand(time(0));

    generateInformationRandom(products[i]);
  }

  ShowAllAlphabetically(products);
  grossTotal(products);
}
