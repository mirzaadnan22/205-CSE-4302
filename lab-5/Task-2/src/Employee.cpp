#include "Employee.h"

EmployeeStatus Employee::getStatus() {
  float totalSalary = calculateTotalSalary();
  if (age <= 25) {
    if (totalSalary <= 2000) {
      return LOW_STATUS;
    }
    else {
      return MODERATE_STATUS;
    }
  }
  else {
    if (totalSalary <= 21000) return LOW_STATUS;
    else if (totalSalary > 21000 && totalSalary <= 60000) return MODERATE_STATUS;
    else return HIGH_STATUS;
  }
}

float Employee::calculateTotalSalary() {
  return baseSalary + 0.1 * baseSalary + 0.3 * baseSalary + 0.1 * baseSalary;
}

string Employee::getStatusString(EmployeeStatus st) {
  if (st == LOW_STATUS) {
    return "Low";
  }
  else if (st == MODERATE_STATUS) {
    return "Moderate";
  }
  else {
    return "High";
  }
}

void Employee::getInfo() {
  cout << "Name: " << name << "\n";
  cout << "Date of Birth: " << getDobStr() << "\n";
  cout << "Base Salary: " << baseSalary << "\n";
  cout << "Joining Year: " << joiningYear << "\n";
  cout << "Status: " << getStatusString(getStatus()) << "\n";
}

void Employee::setInfo(string _name, DoB _dob, float _salary, int _year, int _age) {
  setName(_name);
  setDob(_dob);
  setBaseSalary(_salary);
  setJoiningYear(_year);
  setAge(_age);
}

string Employee::getName() {
  return name;
}

DoB Employee::getDob() {
  return dob;
}

string Employee::getDobStr() {
  return to_string(dob.date) + " " + months[dob.month - 1] + " " + to_string(dob.year);
}

float Employee::getBaseSalary() {
  return baseSalary;
}

int Employee::getJoiningYear() {
  return joiningYear;
}

int Employee::getAge() {
  return age;
}

void Employee::setName(string _name) {
  if (name.size() > 2) {
    name = _name;
  }
  else {
    cout << "Name has to be at least 2 characters\n";
  }
}

void Employee::setAge(int _age) {
  age = _age;
}

void Employee::setBaseSalary(int _salary) {
  if (_salary >= 10'000 and _salary <= 100'000) {
    baseSalary = _salary;
  }
  else {
    baseSalary = 10'000;
  }
}

void Employee::setJoiningYear(int _year) {
  joiningYear = _year;
}

void Employee::setDob(DoB _dob) {
  if (2024 - _dob.year < 18) {
    _dob.date = 1;
    _dob.month = 1;
    _dob.year = 2002;
  }
  else {
    dob.date = _dob.date;
    dob.month = _dob.month;
    dob.year = _dob.year;
  }
}

Employee& Employee::compareTotalSalary(Employee& e) {
  return e.baseSalary > baseSalary ? e : *this;
}

string Employee::months[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };






