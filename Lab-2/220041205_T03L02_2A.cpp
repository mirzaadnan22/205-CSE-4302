#include <iostream>
using namespace std;

struct Fraction {
  int numerator;
  int denominator;
};

int main() {
  Fraction f1, f2;
  char temp;

  cout << "Enter first fraction: ";
  cin >> f1.numerator >> temp >> f1.denominator;

  cout << "Enter second fraction: ";
  cin >> f2.numerator >> temp >> f2.denominator;

  Fraction ans;
  ans.numerator = (f1.numerator * f2.denominator) + (f1.denominator * f2.numerator);
  ans.denominator = f1.denominator * f2.denominator;

  cout << "Sum: " << ans.numerator << "/" << ans.denominator << "\n";
}