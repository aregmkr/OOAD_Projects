#pragma once
#include "employee.h"

class SalesPerson : public Employee {
public:
    explicit SalesPerson(const std::string& name, double baseSalary);

    SalesPerson(const SalesPerson&) = delete;
    SalesPerson(SalesPerson&&) = delete;
    SalesPerson& operator=(const SalesPerson&) = delete;
    SalesPerson& operator=(SalesPerson&&) = delete;

    int getTotalSales() const;
    void addSales();
    void displayInfo() override;
private:
    int totalSales;
};