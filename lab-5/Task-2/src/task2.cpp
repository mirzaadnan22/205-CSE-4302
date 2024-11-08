#include "Employee.h"
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int getRandomNum(int a, int b) {
  srand(time(0));
  return rand() % (b - a + 1) + a;
}

string generateRandomString(int length) {
  std::string randomString;
  const char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  int alphabetSize = sizeof(alphabet) - 1; // Exclude null character

  srand(static_cast<unsigned int>(time(0))); // Seed the random number generator

  for (int i = 0; i < length; ++i) {
    randomString += alphabet[rand() % alphabetSize];
  }

  return randomString;
}

int randomInRange(int min, int max) {
  // Ensure min is less than or equal to max
  if (min > max) {
    std::swap(min, max); // Swap if min is greater than max
  }

  return rand() % (max - min + 1) + min;
}

void generateInformationRandom(Employee& e) {
  string name = generateRandomString(8) + " " + generateRandomString(6);
  DoB dob;
  dob.date = randomInRange(1, 30);
  dob.month = randomInRange(1, 12);
  dob.year = randomInRange(1990, 2010);
  float baseSalary = randomInRange(0, 200000);
  int joiningYear = randomInRange(2000, 2024);
  e.setInfo(name, dob, baseSalary, joiningYear, 2024 - dob.year);
}


int main() {
  srand(time(0));
  Employee emps[100];

  for (int i = 0; i < 100; i++) {
    generateInformationRandom(emps[i]);
  }

  for (int i = 0; i < 100; i++) {
    emps[i].getInfo();
  }
}