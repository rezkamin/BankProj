#pragma once
#include <iostream>
#include <string>
#include <cctype>
#include <stdexcept>

#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include <vector>
#include <ctime>
#include <sstream>
#include <iomanip>
#include "Transaction.h"
#include "Validation.h"
using namespace std;
class Admin {
private:
    int id;
    string name;
    string password;
    double salary;
    double balance;
    static constexpr double MIN_SALARY = 5000.0;
    static constexpr double MIN_BALANCE = 1500.0;

public:
    Admin(int id, const string& name, const string& password, double salary, double balance) : id(id) {
        setName(name);
        setPassword(password);
        if (!Validation::isValidBalance(salary, MIN_SALARY))
            throw invalid_argument("Admin salary must be at least 5000");
        this->salary = salary;

        if (!Validation::isValidBalance(balance, MIN_BALANCE))
            throw invalid_argument("Client initial balance must be at least 1500");
        this->balance = balance;


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
    double getSalary() const { return salary; }
    void updateSalary(double newSalary) {
        if (!Validation::isValidBalance(newSalary, MIN_SALARY))
            throw invalid_argument("Salary must be at least 5000");
        salary = newSalary;
        cout << "salary updated.\n";
    }
    void display() const {
        cout << "admin number: " << id << "\nname: " << name << "\nsalary: " << salary << "\n";
    }
};