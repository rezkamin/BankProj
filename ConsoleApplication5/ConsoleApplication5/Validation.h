#pragma once
#define VALIDATION_H
#include <string>
#include <cctype>
#include <cstddef>
#include <iostream>
#include <stdexcept>
using namespace std;
class Validation {
public:
    static bool isValidName(const string & name, size_t minLen = 5, size_t maxLen = 20) {
        if (name.length() < minLen || name.length() > maxLen)
            return false;
        for (char c : name)
            if (!isalpha(c))
                return false;
        return true;
    }
    static bool isValidPassword(const string& password, size_t minLen = 8, size_t maxLen = 20) {
        return (password.length() >= minLen && password.length() <= maxLen);
    }
    static bool isValidBalance(double balance, double minBalance) {
        return balance >= minBalance;
    }
    static bool isValidSalary(double salary)  {
        return salary >= 5000;
    }



};

