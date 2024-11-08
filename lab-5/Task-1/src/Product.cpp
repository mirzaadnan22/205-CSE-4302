#include "Product.h"

Product::Product() {}

Product::Product(string _name, string _category, string _desc, int _qty, float _price, float _discount) {
  pName = _name;
  pCategory = _category;
  pDesc = _desc;
  pQty = _qty;
  pPrice = _price;
  pDiscount = _discount;
}

double Product::calculateDiscount(int amountOfProducts) const {
  if (amountOfProducts <= pQty) {
    double cost = amountOfProducts * pPrice;
    if (amountOfProducts >= 10) {
      return ((pDiscount + 3.0) / 100) * cost;
    }
    else if (amountOfProducts >= 5) {
      return (pDiscount / 100) * cost;
    }
  }
  return 0;
}

int Product::netTotal(int amountOfProducts) {
  if (amountOfProducts <= pQty) {
    float cost = amountOfProducts * pPrice;
    return cost - calculateDiscount(amountOfProducts);
  }
  return 0;
}

string Product::getName() {
  return pName;
}

string Product::getCategory() {
  return pCategory;
}

string Product::getDescription() {
  return pDesc;
}

int Product::getQuantity() {
  return pQty;
}

float Product::getPrice() {
  return pPrice;
}

float Product::getDiscount() {
  return pDiscount;
}

void Product::setName(string _name) {
  pName = _name;
}

void Product::setCategory(string _cat) {
  pCategory = _cat;
}

void Product::setDescription(string _desc) {
  pDesc = _desc;
}

void Product::setQuantity(int _qty) {
  pQty = _qty;
}

void Product::setPrice(float _price) {
  pPrice = _price;
}

void Product::setDiscount(float _disc) {
  pDiscount = _disc;
}

