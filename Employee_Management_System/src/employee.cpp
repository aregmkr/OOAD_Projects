#include "../header/employee.h"
#include "../header/idCount.h"

Employee::Employee(const std::string& name, double baseSalary, Type dep) : name_{name}, baseSalary_{baseSalary}, id_{ID::generateId()} {}

double Employee::getBaseSalary() const {
    return baseSalary_;
}

int Employee::getId() const {
    return id_;
}

const std::string& Employee::getName() const {
    return name_;
}

void Employee::setFinalSalary(double value) {
    finalSalary_ = value;
}

double Employee::getFinalSalary() const {
    return finalSalary_;
}