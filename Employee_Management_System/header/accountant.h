#pragma once
#include "employee.h"

class Accountant : public Employee {
public:
    explicit Accountant(const std::string& name, double baseSalary, size_t reports = 0);

    Accountant(const Accountant&) = delete;
    Accountant(Accountant&&) = delete;
    Accountant& operator=(const Accountant&) = delete;
    Accountant& operator=(Accountant&&) = delete;

    void addReports();
    int getfinanceReports() const;
    void displayInfo() override;
private:
    Accountant() = default;
    int financeReports;
};