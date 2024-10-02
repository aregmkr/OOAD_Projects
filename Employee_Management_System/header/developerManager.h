#pragma once
#include "employee.h"
#include "ISalaryCal.h"
#include "developer.h"
#include <vector>

class Developer;

class DeveloperManager : public Employee, public ISalaryCal{
public:
    explicit DeveloperManager(const std::string& name, double baseSalary);
    
    void addDeveloper(Developer* developer);
    double calculateSalary() override;
    void displayInfo() override;
    void removeDeveloper(int id);
private:
    DeveloperManager() = default;
    size_t developerCount;
    bool flag;
    std::vector<Developer*> developers;
};