#include <iostream>
#include "./header/employee.h"
#include "./header/developer.h"
#include <memory>
#include "./header/developerManager.h"

int main() {
    // EmployeeManagmentSystem ems;
    auto devManager = std::make_shared<DeveloperManager>("Alice", 7000);
    std::shared_ptr<Developer> developer = std::make_shared<Developer>("Vardan", 5000);

    std::shared_ptr<Developer> developer1 = std::make_shared<Developer>("Vardan", 5000);

    std::shared_ptr<Developer> developer2 = std::make_shared<Developer>("Vardan", 5000);
    devManager->addDeveloper(developer.get());

    devManager->addDeveloper(developer1.get());
    developer->addProject();
    devManager->addDeveloper(developer2.get());
    devManager->displayInfo();
    devManager->removeDeveloper(1);
    devManager->displayInfo();
    // devManager->calculateSalary();
    std::cout << devManager->calculateSalary() << std::endl;
    return 0;
}