#include "../header/developer.h"
#include <iostream>

#include "../header/developer.h"

Developer::Developer(const std::string& name, double baseSalary, size_t projects) 
    : Employee(name, baseSalary, Development), projects_{projects} {}

void Developer::addProject() {
    ++projects_;
}

size_t Developer::getProjects() const {
    return projects_;
}

void Developer::displayInfo() {
    std::cout << "Name: " << getName() << std::endl;
    std::cout << "Developer id: " << getId() << std::endl;
    std::cout << "Base salary: " << getBaseSalary() << std::endl;
    std::cout << "Projects: " << getProjects() << std::endl;
}
