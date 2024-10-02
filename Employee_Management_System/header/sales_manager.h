#pragma once
#include "employee.h"
#include "ISalaryCal.h"
#include <vector>
#include "salesPerson.h"
class SalesPerson;

class SalesManager: public Employee, public ISalaryCal {
public:
    explicit SalesManager(const std::string& name, double baseSalary);

    void addSales(SalesPerson* salesPerson);
    int getCount() const;
    void displayInfo() override;
    double calculateSalary() override;
    void removeSalesPerson(int id);
private:
    int sales_person_count;
    std::vector<SalesPerson*> sales_persons;
};