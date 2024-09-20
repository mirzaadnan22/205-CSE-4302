#include <iostream>
using namespace std;

class RationalNumber {
private:
  int numerator;
  int denominator;

public:
  void assign(int num, int deno) {
    if (deno == 0) {
      cerr << "Error: Denominator cannot be 0\n";
    }
    else {
      numerator = num;
      denominator = deno;
    }
  }

  float convert() {
    return (float)numerator / denominator;
  }

  void invert() {
    if (numerator == 0) {
      cerr << "Error: Denominator becomes 0 after inversion\n";
    }
    else {
      int tmp = numerator;
      numerator = denominator;
      denominator = tmp;
    }
  }

  void print() {
    cout << "The Rational Number is " << numerator << "/" << denominator << endl;
  }
};

int main() {
  RationalNumber num;

  num.assign(3, 7);
  num.print();

  cout << "Converted value: " << num.convert() << "\n";

  num.invert();
  num.print();

  num.assign(5, 0);
}