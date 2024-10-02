#pragma once
#include "employee.h"

class HrRepresentive : public Employee {
public:
    explicit HrRepresentive(const std::string& name, double baseSalary);
    void addEmployee();
    void displayInfo() override;
    int getManagedCount() const;
private:
    int employesManaged;
};