#include <iostream>
using namespace std;

enum AccountType {
  CURRENT_ACCOUNT,
  SAVINGS_ACCOUNT
};

class BankAccount {
private:
  string name;
  string accNum;
  AccountType accType;
  float currBalance;

public:
  void customerDetails(string _name, string _accNum) {
    name = _name;
    accNum = _accNum;
    currBalance = 0;
  }

  void accountType(AccountType _accType) {
    accType = _accType;
  }

  void balance() {
    cout << currBalance << " BDT\n";
  }

  void deposit(int amount) {
    if (amount >= 0) {
      currBalance += amount;
    }
    else {
      cout << "Transaction failed: Deposit amount cannot be less than zero\n";
    }
  }

  void withdraw(float amount) {
    if (amount <= currBalance) {
      currBalance -= amount;
    }
    else {
      cerr << "Transaction failed: Withdrawal amount exceeds account balance\n";
    }
  }

  void display() {
    cout << "Name: " << name << "\n";
    cout << "Account Number: " << accNum << "\n";
    cout << "Account Type: " << (accType == SAVINGS_ACCOUNT ? "Savings" : "Current") << "\n";
    cout << "Balance: " << currBalance << " BDT\n";
  }
};

int main() {
  BankAccount acc;

  acc.customerDetails("Mirza Adnan", "0224 8712 7612 9076");
  acc.accountType(SAVINGS_ACCOUNT);
  acc.balance();

  acc.deposit(200);
  acc.balance();
  acc.deposit(-5);

  acc.withdraw(70);
  acc.balance();

  acc.display();
}