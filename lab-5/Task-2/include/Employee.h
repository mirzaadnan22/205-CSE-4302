#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
using namespace std;

struct DoB {
  int date;
  int month;
  int year;
};

enum EmployeeStatus {
  LOW_STATUS,
  MODERATE_STATUS,
  HIGH_STATUS
};

class Employee {
private:
  string name;
  DoB dob;
  float baseSalary;
  int joiningYear;
  int age;
  float calculateTotalSalary();
  EmployeeStatus getStatus();
  static string months[];

public:
  void setInfo(string, DoB, float, int, int);
  void getInfo();

  string getName();
  DoB getDob();
  string getDobStr();
  float getBaseSalary();
  int getJoiningYear();
  int getAge();
  string getStatusString(EmployeeStatus);

  void setName(string);
  void setDob(DoB);
  void setBaseSalary(int);
  void setJoiningYear(int);
  void setAge(int);

  Employee& compareTotalSalary(Employee& e);
};


#endif