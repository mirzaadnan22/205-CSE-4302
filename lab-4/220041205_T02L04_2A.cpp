#include <iostream>
using namespace std;

enum AccountType {
  SAVINGS_ACCOUNT,
  CURRENT_ACCOUNT
};

class BankAccount {
private:
  string accNum;
  string name;
  AccountType type;
  float balance;
  const float min;
  float interest;
  static int total;
  static int curr;
  static float totalTaxed;

public:
  BankAccount(string _name, string _acc, AccountType _type, float _balance, float _min) : min(_min) {
    accNum = _acc;
    name = _name;
    type = _type;
    balance = _balance;
    interest = 3;
    total++;
    curr++;
  }

  ~BankAccount() {
    cout << "Account of " << name << " with account no " << accNum << " is destroyed with a balance of BDT " << balance << "\n";
    curr--;
  }

  void setAccNum(string newNum) {
    accNum = newNum;
  }

  string getAccNum() {
    return accNum;
  }

  void setName(string newName) {
    name = newName;
  }

  string getName() {
    return name;
  }

  void setType(AccountType t) {
    type = t;
  }

  void setBalance(float newBalance) {
    balance = newBalance;
  }

  float getBalance() const {
    return balance;
  }

  void setInterest(float newInt) {
    interest = newInt;
  }

  void displayDetails() {
    cout << "Account Holder: " << name << "\n";
    cout << "Account Number: " << accNum << "\n";
    cout << "Account Type: " << (type == SAVINGS_ACCOUNT ? "Saving\n" : "Current\n");
    cout << "Balance: " << balance << " BDT\n";
    cout << "Minimum Amount:  " << min << " BDT\n";
  }

  void showBalance() {
    cout << "Balance: " << balance << " BDT\n";
  }

  void deposit(float amount) {
    if (amount >= 0) {
      balance += amount;
    }
    else {
      cout << "Transaction Failed: Cannot deposit a negative amount\n";
    }
  }

  void withdraw(float amount) {
    if (amount >= 0) {
      if (balance - amount >= min) {
        balance -= amount;
      }
      else {
        cout << "Transaction Failed: Balance becomes less than minimum amount\n";
      }
    }
    else {
      cout << "Transaction Failed: Cannot withdraw a negative amount\n";
    }
  }

  void giveInterest() {
    float value = balance * (interest / 100);
    totalTaxed += value * 0.1;
    value *= 0.9; // 10% tax;
    balance += value;
  }

  static void displayStat() {
    cout << "Total Accounts Created: " << total << "\n";
    cout << "Existing Accounts: " << curr << "\n";
    cout << "Total Tax Collected: " << totalTaxed << "\n";
  }
};

int BankAccount::total = 0;
int BankAccount::curr = 0;
float BankAccount::totalTaxed = 0;

BankAccount Larger(const BankAccount A, const BankAccount B) {
  return A.getBalance() >= B.getBalance() ? A : B;
}

int main() {
  BankAccount acc1("Mirza Adnan", "0204228", CURRENT_ACCOUNT, 32000, 2000);
  BankAccount::displayStat();
  acc1.giveInterest();
  BankAccount::displayStat();
}