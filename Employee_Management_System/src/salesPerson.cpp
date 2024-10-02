#include "../header/salesPerson.h"
#include "../header/employee.h"
#include <iostream>
#include <string>

SalesPerson::SalesPerson(const std::string& name, double baseSalary) : Employee(name, baseSalary, Sales), totalSales(0) {}

int SalesPerson::getTotalSales() const {
    return totalSales;
}

void SalesPerson::addSales() {
    ++totalSales;
}

void SalesPerson::displayInfo() {
    std::cout << "Name: " << getName() << std::endl;
    std::cout << "Sales Person id: " << getId() << std::endl;
    std::cout << "Base salary: " << getBaseSalary() << std::endl;
    std::cout << "Total Sales: " << getTotalSales() << std::endl;
}