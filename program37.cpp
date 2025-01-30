#include <iostream>
#include <string>
using namespace std;


class Account {
protected:
    string customerName;
    int accountNumber;
    string accountType;
    double balance;

public:
  
    Account(string name, int accNum, string type, double initialBalance) {
        customerName = name;
        accountNumber = accNum;
        accountType = type;
        balance = initialBalance;
    }

  
    void deposit(double amount) {
        balance += amount;
        cout << "Amount deposited successfully.\n";
    }

    
    void displayBalance() {
        cout << "Current Balance: " << balance << endl;
    }
};


class Sav_Account : public Account {
private:
    double interestRate;

public:
 
    Sav_Account(string name, int accNum, double initialBalance, double rate)
        : Account(name, accNum, "Savings", initialBalance) {
        interestRate = rate;
    }


    void computeInterest() {
        double interest = balance * (interestRate / 100);
        balance += interest;
        cout << "Interest added: " << interest << endl;
    }


    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << "Withdrawal successful.\n";
        } else {
            cout << "Insufficient balance.\n";
        }
    }
};


class Cur_Account : public Account {
private:
    double minBalance;
    double penaltyAmount;

public:

    Cur_Account(string name, int accNum, double initialBalance, double minBal, double penalty)
        : Account(name, accNum, "Current", initialBalance) {
        minBalance = minBal;
        penaltyAmount = penalty;
    }


    void checkMinBalance() {
        if (balance < minBalance) {
            balance -= penaltyAmount;
            cout << "Minimum balance not maintained. Penalty of " << penaltyAmount << " imposed.\n";
        }
    }


    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << "Withdrawal successful.\n";
            checkMinBalance(); 
        } else {
            cout << "Insufficient balance.\n";
        }
    }
};


int main() {

    Sav_Account savings("Alice", 1001, 5000, 5);
    savings.deposit(2000);
    savings.displayBalance();
    savings.computeInterest();
    savings.displayBalance();
    savings.withdraw(3000);
    savings.displayBalance();

    cout << "----------------------\n";


    Cur_Account current("Bob", 2001, 3000, 5000, 500);
    current.deposit(1000);
    current.displayBalance();
    current.withdraw(2500);
    current.displayBalance();
    current.withdraw(2000);
    current.displayBalance();

    return 0;
}
