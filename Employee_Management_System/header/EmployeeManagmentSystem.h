#pragma once 
#include "financeManager.h"
#include "developerManager.h"
#include "hrManager.h"
#include "sales_manager.h"
#include <memory>
#include <vector>
#include <iostream>

class EmployeeManagmentSystem {
public: 
    EmployeeManagmentSystem();
    void addEmployeeToDepartament(std::shared_ptr<Developer> dev);
    void addEmployeeToDepartament(std::shared_ptr<HrRepresentive> hr);
    void addEmployeeToDepartament(std::shared_ptr<Accountant> acc);
    void addEmployeeToDepartament(std::shared_ptr<SalesPerson> sales);

    void displayAllEmployeesByDepartament(Type type);
    void removeEmployee(int id, Type type);
    double calculateTotalSalary(Type type);
private:
    std::shared_ptr<FinanceManager> financeManager;
    std::shared_ptr<HrManager> hrManager;
    std::shared_ptr<DeveloperManager> developmentManager;
    std::shared_ptr<SalesManager> salesManager;
};