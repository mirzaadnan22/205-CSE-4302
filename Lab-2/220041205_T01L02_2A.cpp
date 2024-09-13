#include <cstdio>
#include <iostream>
using namespace std;

int main() {
  int a, b, c, d;
  char temp;

  cout << "Enter first fraction: ";
  cin >> a >> temp >> b;

  cout << "Enter second fraction: ";
  cin >> c >> temp >> d;

  int numerator = (a * d) + (c * b);
  int denominator = b * d;

  cout << "Sum: " << numerator << "/" << denominator << "\n";
}