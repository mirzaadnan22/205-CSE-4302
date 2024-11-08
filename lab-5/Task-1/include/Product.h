#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>
using namespace std;

class Product {
private:
  string pName;
  string pCategory;
  string pDesc;
  int pQty;
  float pPrice;
  float pDiscount;

public:
  Product();
  Product(string _name, string _category, string _desc, int _qty, float _price, float _discount);
  double calculateDiscount(int) const;
  int netTotal(int);
  string getName();
  void setName(string);
  string getCategory();
  void setCategory(string);
  string getDescription();
  void setDescription(string);
  int getQuantity();
  void setQuantity(int);
  float getPrice();
  void setPrice(float);
  float getDiscount();
  void setDiscount(float);
};



#endif