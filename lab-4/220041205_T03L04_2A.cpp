#include <iostream>
using namespace std;

enum EmployeeStatus {
  LOW_STATUS,
  MODERATE_STATUS,
  HIGH_STATUS
};

class Employee {
private:
  string EmpName;
  int ID;
  float BaseSalary;
  int JoiningYear;
  int age;

  float calculateTotalSalary() {
    return BaseSalary + 0.1 * BaseSalary + 0.3 * BaseSalary + 0.1 * BaseSalary;
  }

  void yearlyIncrement() {
    BaseSalary *= 1.03;
  }

  EmployeeStatus getStatus() {
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

  float calculateBonus() {
    yearlyIncrement();
    float totalSalary = calculateTotalSalary();
    EmployeeStatus status = getStatus();
    if (status == LOW_STATUS) {
      return BaseSalary * 0.05;
    }
    else if (status == MODERATE_STATUS) {
      return BaseSalary * 0.1;
    }
    else {
      return BaseSalary * 0.15;
    }
  }

public:
  Employee() {}
  Employee(string _name, int _id, float _base, int _joining, int _age) {
    EmpName = _name;
    ID = _id;
    BaseSalary = _base;
    JoiningYear = _joining;
    age = _age;
  }

  ~Employee() {
    cout << EmpName << " has left the company\n";
  }

  void FeedInfo(string _name, int _id, float _base, int _joining, int _age) {
    EmpName = _name;
    ID = _id;
    BaseSalary = _base;
    JoiningYear = _joining;
    age = _age;
  }

  void ShowInfo() {
    EmployeeStatus status = getStatus();

    cout << "Name: " << EmpName << "\n";
    cout << "ID: " << ID << "\n";
    cout << "Base Salary: " << BaseSalary << "\n";
    cout << "Joining Year: " << JoiningYear << "\n";
    cout << "Age: " << age << "\n";
    cout << "Bonus: " << calculateBonus() << "\n";
  }
};

int main() {
  Employee e1;
  e1.FeedInfo("Adnan", 205, 30000, 2016, 22);
  e1.ShowInfo();

}