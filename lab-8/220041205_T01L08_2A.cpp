#include <iostream>
using namespace std;

class Person {
protected:
  string name;

public:
  Person(string _name) : name(_name) {}

  virtual void display() {
    cout << "Name: " << name << "\n";
  }
};

class Employee : public Person {
private:
  int employeeID;

protected:
  float salary;

public:
  Employee(string _name, int _ID, float _salary) : Person(_name), employeeID(_ID), salary(_salary) {}

  void display() {
    Person::display();
    cout << "Employee ID: " << employeeID << "\n";
    cout << "Salary: " << salary << "\n";
  }
};

class Intern : public Employee {
private:
  string schoolName;

public:
  Intern(string _name, int _ID, float _salary, string _school) : Employee(_name, _ID, _salary), schoolName(_school) {}

  void display() {
    Employee::display();
    cout << "School: " << schoolName << "\n";
  }
};

class Manager : protected Employee {
private:
  string department;

public:
  Manager(string _name, int _ID, float _salary, string _dept) : Employee(_name, _ID, _salary), department(_dept) {}

  virtual void display() {
    Employee::display();
    cout << "Department: " << department << "\n";
  }
};

class Director : public Manager {
private:
  float bonus;

public:
  Director(string _name, int _ID, float _salary, string _dept, float _bonus) : Manager(_name, _ID, _salary, _dept), bonus(_bonus) {}

  void display() {
    Manager::display();
    cout << "Bonus: " << bonus << "\n";
  }
};



int main() {
  Person* intern = new Intern("adnan", 5, 8934754, "Stanford");
  intern->display();

  Manager* dir = new Director("DHH", 99, 947587345, "Sales", 300000);
  dir->display();

  delete intern;
  delete dir;
}