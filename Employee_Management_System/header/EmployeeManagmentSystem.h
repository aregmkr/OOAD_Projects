#pragma once 
#include <memory>
#include <iostream>
#include "developer.h"
#include "hrRepresentive.h"
#include "salesPerson.h"
#include "accountant.h"
#include "developerManager.h"
#include "hrManager.h"
#include "financeManager.h"
#include "sales_manager.h"

class EmployeeManagmentSystem {
public: 
    EmployeeManagmentSystem();
    void addEmployeeToDepartament(std::shared_ptr<Developer> dev);
    void addEmployeeToDepartament(std::shared_ptr<HrRepresentive> hr);
    void addEmployeeToDepartament(std::shared_ptr<Accountant> acc);
    void addEmployeeToDepartament(std::shared_ptr<SalesPerson> sales);
    void setManager(std::shared_ptr<DeveloperManager> dev_man);
    void setManager(std::shared_ptr<HrManager> hr_man);
    void setManager(std::shared_ptr<SalesManager> sale_man);
    void setManager(std::shared_ptr<FinanceManager> fin_man);
    void displayAllEmployeesByDepartament(Type type);
    void removeEmployee(int id, Type type);
    double calculateTotalSalary(Type type);
    void displayTotalSalaires() const;
private:
    std::shared_ptr<FinanceManager> financeManager;
    std::shared_ptr<HrManager> hrManager;
    std::shared_ptr<DeveloperManager> developmentManager;
    std::shared_ptr<SalesManager> salesManager;
};