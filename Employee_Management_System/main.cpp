#include <iostream>
#include "EmployeeManagmentSystem.h"

int main() {
    auto devManager = std::make_shared<DeveloperManager>("Alice1", 7000);
    std::shared_ptr<Developer> developer1 = std::make_shared<Developer>("Areg", 5000);
    devManager->addDeveloper(developer1.get());
    devManager->displayInfo();


    // EmployeeManagmentSystem ems;
    // auto devManager = std::make_shared<DeveloperManager>("Alice1", 7000);
    // auto hrManager = std::make_shared<HrManager>("Alice2", 7000);
    // auto finManager = std::make_shared<FinanceManager>("Alice3", 7000);
    // auto saleManager = std::make_shared<SalesManager>("Alice4", 7000);

    // std::shared_ptr<Developer> developer = std::make_shared<Developer>("Vardan", 5000);
    // ems.setManager(devManager);
    // ems.setManager(hrManager);
    // ems.setManager(saleManager);
    // ems.setManager(finManager);
    // devManager->addDeveloper(developer.get());
    // ems.addEmployeeToDepartament(developer);
    // std::shared_ptr<Developer> developer1 = std::make_shared<Developer>("Areg", 5000);

    // std::shared_ptr<Developer> developer2 = std::make_shared<Developer>("Alex", 5000);
    // devManager->addDeveloper(developer2.get());

    // devManager->addDeveloper(developer1.get());
    // developer->addProject();
    // devManager->addDeveloper(developer2.get());
    // devManager->displayInfo();
    // devManager->removeDeveloper(1);
    // ems.displayAllEmployeesByDepartament(Development);
    // ems.displayAllEmployeesByDepartament(Finance);
    // ems.displayAllEmployeesByDepartament(HumanResources);
    // ems.displayAllEmployeesByDepartament(Sales);
    // ems.displayTotalSalaires();
    return 0;
}