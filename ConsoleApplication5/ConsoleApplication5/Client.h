#pragma once
#include <iostream>
#include <string>
#include <cctype>
#include <stdexcept>
#include "Validation.h"
#include "Transaction.h"
#include <vector>
#include <ctime>
#include <sstream>
#include <iomanip>
using namespace std;
class Client {
private:
    int id;
    string name;
    string password;
    double balance;
    static constexpr double MIN_BALANCE = 1500.0;
    vector<Transaction> transactions;
public:
    
    Client(int id, const string& name, const string& password, double balance) {
        this->name = name;
        this->id = id;
        this->password = password;
        if (!Validation::isValidBalance(balance, MIN_BALANCE))
            throw invalid_argument("Client initial balance must be at least 1500");
        this->balance = balance;
        transactions.push_back(Transaction("open an account", balance));
    }
    void setName(const string& newName) {
        if (!Validation::isValidName(newName))
            throw invalid_argument("Invalid name.");
        name = newName;
    }
    void setPassword(const string& newPassword) {
        if (!Validation::isValidPassword(newPassword))
            throw invalid_argument("Invalid password.");
        password = newPassword;
    }
    int getId() const { return id; }
    string getName() const { return name; }
    string getPassword() const { return password; }
    double getBalance() const { return balance; }
    void deposit(double amount) {
        if (amount <= 0)
            throw invalid_argument("Deposit amount must be positive.");
        balance += amount;
        transactions.push_back(Transaction("Deposit", amount));
        cout << "amount of Deposit is " << amount << ". updated balance is: " << balance << "\n";
    }
    void withdraw(double amount) {
        if (amount <= 0)
            throw invalid_argument("Withdraw amount must be positive.");
        if (balance - amount < MIN_BALANCE)
            throw runtime_error("your balance can't decrease more than the exist balance " + to_string(MIN_BALANCE));
        balance -= amount;
        transactions.push_back(Transaction("withdraw", amount));
        cout << "the amount of withdraw " << amount << ". updated balance is : " << balance << "\n";
    }
    void transferTo(double amount, Client& recipient) {
        if (amount <= 0)
            throw invalid_argument("Transfer amount must be positive.");
        if (balance - amount < MIN_BALANCE)
            throw runtime_error("the balance of the account can't be decrease than the minimum balance after transfer .");
        balance -= amount;
        recipient.balance += amount;
        transactions.push_back(Transaction("transferTo", amount));
        recipient.transactions.push_back(Transaction("transferin", amount));
        cout << "transfer is done " << amount << " to " << recipient.name << ". the new balance is: " << balance << "\n";
    }
    void checkBalance() const {
        cout << "updated balance: " << balance << "\n";
    }
    void displayTransactions() const {
        cout << "  Client Transaction History " << name << ":\n";
        for (const auto& trans : transactions)
            trans.display();
    }
    void requestLoan(double loanAmount, int durationInMonths) {
        if (balance < 2000) {
            cout << "Your current balance does not qualify you for a loan.\n";
            return;
        }
        cout << "Loan request has been submitted for an amount of " << loanAmount << " for a period of " << durationInMonths << " month.\n";
        transactions.push_back(Transaction(" Loan Request ", loanAmount));
    }
    void payBill(double amount, const string& billType) {
        if (amount <= 0)
            throw invalid_argument("The invoice amount must be positive.");
        if (balance - amount < MIN_BALANCE)
            throw runtime_error("There is insufficient balance to pay the invoice without reducing the balance below the minimum..");
        balance -= amount;
        transactions.push_back(Transaction(" Pay Bill (" + billType + ")", amount));
        cout << " Bill has been paid. " << billType << " For an amount of " << amount << ". New balance: " << balance << "\n";
    }
    void updateProfile(const string& newName, const string& newPassword) {
        setName(newName);
        setPassword(newPassword);
        cout << " Profile has been updated.\n";
    }
    void display() const {
        cout << "client num: " << id << "\nname: " << name << "\nbalance: " << balance << "\n";
    }
};
