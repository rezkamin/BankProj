#pragma once

#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>
#include <string>
#include <ctime>
#include <sstream>
#include <iomanip>
using namespace std;

class Transaction {
private:
    string type;
    double amount;
    string dateTime;
public:
    Transaction(const string& type, double amount) : type(type), amount(amount) {
        time_t now = time(0);
        tm ltm;
        localtime_s(&ltm, &now);
        stringstream ss;
        ss << setfill('0')
            << setw(2) << ltm.tm_mday << "/"
            << setw(2) << (1 + ltm.tm_mon) << "/"
            << (1900 + ltm.tm_year) << " "
            << setw(2) << ltm.tm_hour << ":"
            << setw(2) << ltm.tm_min << ":"
            << setw(2) << ltm.tm_sec;
        dateTime = ss.str();
    }
    void display() const {
        cout << "[" << dateTime << "] " << type << ": " << amount << "\n";
    }
};

#endif 







