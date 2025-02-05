#include <iostream>
#include <string>
#include <cctype>
#include <stdexcept>
#include "Validation.h"
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include <vector>
#include <ctime>
#include <sstream>
#include <iomanip>
#include "Transaction.h"
#include <windows.h>

using namespace std;

int main() {
    
        Client client1(1, "Alice", "secret123", 2500);
        client1.display();
        client1.deposit(500);
        client1.withdraw(300);
        Client client2(2, "Brian", "pass1234", 2600);
        client1.transferTo(200, client2);
        client1.requestLoan(10000, 24);
        client1.payBill(200, "electricity bill");
        client1.updateProfile("Alica", "newpass123");
        client1.displayTransactions();
        Employee emp1(101, "Carol", "empPass123", 6000,7000);
        emp1.display();
        emp1.updateSalary(6500);
        Admin admin1(201, "Daniel", "adminPass123", 8000,7000);
        admin1.display();
        admin1.updateSalary(8500);
    }
 
   

