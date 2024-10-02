#include <iostream>
#include "../header/hrRepresentive.h"
#include "../header/employee.h"

HrRepresentive::HrRepresentive(const std::string& name, double baseSalary) : Employee(name, baseSalary, HumanResources){}

void HrRepresentive::addEmployee() {
    ++employesManaged;
}

void HrRepresentive::displayInfo() {
    std::cout << "Name: " << getName() << std::endl;
    std::cout << "Hr id: " << getId() << std::endl;
    std::cout << "Base salary: " << getBaseSalary() << std::endl;
    std::cout << "Employees Managed: " << getManagedCount() << std::endl;
}

int HrRepresentive::getManagedCount() const {
    return employesManaged;
}