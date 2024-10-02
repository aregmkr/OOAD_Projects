#include "../header/accountant.h"
#include "../header/employee.h"
#include <iostream>

void Accountant::addReports() {
    financeReports++;
}

int Accountant::getfinanceReports() const {
    return financeReports;
}

Accountant::Accountant(const std::string& name, double baseSalary, size_t reports) 
    : Employee(name, baseSalary, Finance), financeReports{reports} {}

void Accountant::displayInfo() {
    std::cout << "Name: " << getName() << std::endl;
    std::cout << "Accountant id: " << getId() << std::endl;
    std::cout << "Base salary: " << getBaseSalary() << std::endl;
    std::cout << "Reports: " << financeReports << std::endl;
}

