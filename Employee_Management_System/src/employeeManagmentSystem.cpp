#include "../header/EmployeeManagmentSystem.h"

EmployeeManagmentSystem::EmployeeManagmentSystem() : financeManager{nullptr}, hrManager{nullptr}, developmentManager{nullptr}, salesManager{nullptr} {}

void EmployeeManagmentSystem::addEmployeeToDepartament(std::shared_ptr<Developer> dev) {
    if (developmentManager != nullptr) {
        developmentManager->addDeveloper(dev.get());
    } else {
        std::cout << "No manager yet." << std::endl;
    }
}

void EmployeeManagmentSystem::addEmployeeToDepartament(std::shared_ptr<HrRepresentive> hr) {
    if (hrManager != nullptr) {
        hrManager->addHr(hr.get());
    } else {
        std::cout << "No manager yet." << std::endl;
    }
}

void EmployeeManagmentSystem::addEmployeeToDepartament(std::shared_ptr<Accountant> acc) {
    if (financeManager != nullptr) {
        financeManager->addAccountant(acc.get());
    } else {
        std::cout << "No manager yet." << std::endl;
    }
}

void EmployeeManagmentSystem::addEmployeeToDepartament(std::shared_ptr<SalesPerson> sale) {
    if (salesManager != nullptr) {
        salesManager->addSales(sale.get());
    } else {
        std::cout << "No manager yet." << std::endl;
    } 
}

void EmployeeManagmentSystem::displayAllEmployeesByDepartament(Type type) {
    if (type == Development) {
        developmentManager->displayInfo();
    } else if (type == Sales) {
        hrManager->displayInfo();
    } else if (type == Finance) {
        financeManager->displayInfo();
    } else {
        salesManager->displayInfo();
    }
}

void EmployeeManagmentSystem::removeEmployee(int id, Type type) {
    if (type == Development) {
        developmentManager->removeDeveloper(id);
    }
}

double EmployeeManagmentSystem::calculateTotalSalary(Type type) {
    if (type == Development) {
        return developmentManager->calculateSalary();
    } else if (type == Sales) {
        return salesManager->calculateSalary();
    } else if (type == Finance) {
        return financeManager->calculateSalary();
    } else {
        return salesManager->calculateSalary();
    }
}