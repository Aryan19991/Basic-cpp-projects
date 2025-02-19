//Basic Banking System 
#include <iostream>
#include <string>
#include <list>
#include <limits>
#include <unordered_map>
#include <fstream>

class BankAccount
{
private:
  std::string accountNumber;
  double balance;
  std::list<std::string> transactions;

public:
  BankAccount(std::string accNum, double initialDeposit)
      : accountNumber(accNum), balance(initialDeposit)
  {
    transactions.push_back("Account created with initial deposit: Rs." + std::to_string(initialDeposit));
  }

  BankAccount() : accountNumber(), balance(0.0) {}

  void deposit(double amount)
  {
    if (std::cin.fail() || amount <= 0)
    {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Please enter a valid amount to deposit!" << std::endl;
      return;
    }

    balance += amount;
    transactions.push_back("Deposited Rs." + std::to_string(amount));
    std::cout << "You have deposited Rs." << amount << ". Your total balance is Rs." << balance << std::endl;
  }

  void withdraw(double amount)
  {
    if (std::cin.fail() || amount <= 0)
    {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Please enter a valid amount to withdraw!" << std::endl;
      return;
    }

    if (amount > balance)
    {
      std::cout << "Insufficient funds!" << std::endl;
    }
    else
    {
      balance -= amount;
      transactions.push_back("Withdrawn Rs." + std::to_string(amount));
      std::cout << "You have withdrawn Rs." << amount << ". Your total balance is Rs." << balance << std::endl;
    }
  }

  void checkBalance() const
  {
    std::ofstream MyFile("AccountHistory.txt", std::ios::app);
    if (!MyFile)
    {
      std::cerr << "Error opening file for writing!" << std::endl;
      return;
    }
    std::cout << "Your balance is Rs." << balance << std::endl;
    MyFile << "Your Balance is Rs. " << balance << std::endl;
    MyFile << "----------------------------------------------------------------------------------" << std::endl;
    MyFile.close();
  }

  void showTransactions() const
  {
    std::cout << "Transaction History:" << std::endl;
    for (const auto &transaction : transactions)
    {
      std::cout << transaction << std::endl;
    }
  }
};

class BankingSystem
{
private:
  std::unordered_map<std::string, BankAccount> accounts;

public:
  void createAccount()
  {
    std::ofstream MyFile("AccountHistory.txt", std::ios::app);
    if (!MyFile)
    {
      std::cerr << "Error opening file for writing" << std::endl;
      return;
    }

    const long long maxAccountNumber = 999999999;
    std::string accountNumber;
    double initialDeposit;

    std::cout << "Enter your account number: ";
    std::cin >> accountNumber;

    try
    {
      long long accountNumberValue = std::stoll(accountNumber);
      if (accountNumberValue > maxAccountNumber)
      {
        std::cout << "The account number should be under the limit which is: " << maxAccountNumber << std::endl;
        return;
      }
    }
    catch (const std::invalid_argument &e)
    {
      std::cout << "Invalid account number! Please enter a valid number." << std::endl;
      return;
    }
    catch (const std::out_of_range &e)
    {
      std::cout << "Account number is out of range! Please enter a smaller number." << std::endl;
      return;
    }

    if (accounts.find(accountNumber) != accounts.end())
    {
      std::cout << "Account with this number already exists!" << std::endl;
      return;
    }

    std::cout << "Enter your initial deposit: ";
    std::cin >> initialDeposit;

    if (std::cin.fail() || initialDeposit <= 0)
    {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Initial deposit must be greater than zero." << std::endl;
      return;
    }

    accounts.emplace(accountNumber, BankAccount(accountNumber, initialDeposit)); // Use emplace
    std::cout << "Account Successfully Created!" << std::endl;
    MyFile << "Account number: " << accountNumber << std::endl;
    MyFile.close();
  }

  void depositToAccount()
  {
    std::ofstream MyFile("AccountHistory.txt", std::ios::app);
    if (!MyFile)
    {
      std::cerr << "Error opening file for writing!" << std::endl;
      return;
    }

    std::string accountNumber;
    double amount;

    std::cout << "Enter your account number: ";
    std::cin >> accountNumber;

    if (accounts.find(accountNumber) == accounts.end())
    {
      std::cout << "Account not found!" << std::endl;
      return;
    }

    std::cout << "Enter the amount to deposit: ";
    std::cin >> amount;

    if (amount <= 0)
    {
      std::cout << "The deposited amount cannot be negative or zero." << std::endl;
      return;
    }

    accounts[accountNumber].deposit(amount);
    MyFile << "Rs " << amount << " has been deposited to your account with account number: " << accountNumber << std::endl;
    MyFile.close();
  }

  void withdrawFromAccount()
  {
    std::ofstream MyFile("AccountHistory.txt", std::ios::app);
    if (!MyFile)
    {
      std::cerr << "Error opening file for writing!" << std::endl;
      return;
    }

    std::string accountNumber;
    double amount;

    std::cout << "Enter your account number: ";
    std::cin >> accountNumber;

    if (accounts.find(accountNumber) == accounts.end())
    {
      std::cout << "Account not found!" << std::endl;
      return;
    }

    std::cout << "Enter the amount you want to withdraw: ";
    std::cin >> amount;

    if (amount <= 0)
    {
      std::cout << "The withdrawn amount cannot be negative or zero." << std::endl;
      return;
    }

    accounts[accountNumber].withdraw(amount);
    MyFile << "Rs " << amount << " has been withdrawn from your account with account number: " << accountNumber << std::endl;
    MyFile.close();
  }

  void checkAccountBalance() const
  {
    std::ofstream MyFile("AccountHistory.txt", std::ios::app);
    if (!MyFile)
    {
      std::cerr << "Error opening the file for writing" << std::endl;
      return;
    }

    std::string accountNumber;

    std::cout << "Enter your account number: ";
    std::cin >> accountNumber;

    if (accounts.find(accountNumber) == accounts.end())
    {
      std::cout << "Account not found!" << std::endl;
      return;
    }

    accounts.at(accountNumber).checkBalance();
    MyFile.close();
  }

  void showAccountTransactions() const
  {
    std::string accountNumber;

    std::cout << "Enter your account number: ";
    std::cin >> accountNumber;

    if (accounts.find(accountNumber) == accounts.end())
    {
      std::cout << "Account not found!" << std::endl;
      return;
    }

    accounts.at(accountNumber).showTransactions();
  }
};

int main()
{
  BankingSystem bank;

  while (true)
  {
    int choice;
    std::cout << "Welcome to Aryan's Bank." << std::endl;
    std::cout << "Please choose what would you like to do{1,2,3,4,5}." << std::endl;
    std::cout << "\n1. Create Account\n2. Deposit\n3. Withdraw\n4. Check Balance\n5. Show Transactions\n6. Exit\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    if (std::cin.fail())
    {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input! Please enter a number between 1 and 6." << std::endl;
      continue;
    }

    switch (choice)
    {
    case 1:
      bank.createAccount();
      break;
    case 2:
      bank.depositToAccount();
      break;
    case 3:
      bank.withdrawFromAccount();
      break;
    case 4:
      bank.checkAccountBalance();
      break;
    case 5:
      bank.showAccountTransactions();
      break;
    case 6:
      std::cout << "Exiting the program. Goodbye!" << std::endl;
      return 0;
    default:
      std::cout << "Invalid choice! Please try again." << std::endl;
    }
  }

  return 0;
}
