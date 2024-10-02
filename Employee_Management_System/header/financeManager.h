#pragma once
#include "employee.h"
#include <vector>
#include "accountant.h"
#include "ISalaryCal.h"

class Accountant;

class FinanceManager : public Employee, public ISalaryCal {
public:
    explicit FinanceManager(const std::string& name, double baseSalary);

    double calculateSalary() override;
    void displayInfo() override;
    void addAccountant(Accountant* acc);
    int getAccountsCount() const;
    void removeAccountant(int id);
private:
    int accountantsCount;
    std::vector<Accountant*> accountants;
};