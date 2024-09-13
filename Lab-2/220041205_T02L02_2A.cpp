#include <iostream>
using namespace std;

enum etype {
  laborer = 'l' - 'a',
  secretary = 's' - 'a',
  manager = 'm' - 'a',
  accountant = 'a' - 'a',
  executive = 'e' - 'a',
  researcher = 'r' - 'a'
};

int main() {
  char ch;
  cout << "Enter employee type (first letter only) (laborer, secretary, manager, accountant, executive, researcher): ";
  cin >> ch;

  etype emp = static_cast<etype>(ch - 'a');

  cout << "Employee type is ";
  switch (emp) {
  case laborer:
    cout << "Laborer";
    break;

  case secretary:
    cout << "Secretary";
    break;

  case manager:
    cout << "Manager";
    break;

  case accountant:
    cout << "Accountant";
    break;

  case executive:
    cout << "Executive";
    break;

  case researcher:
    cout << "Researcher";
    break;

  default:
    cout << "\nNot a valid type\n";
    break;
  }
}