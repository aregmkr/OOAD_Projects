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
        salesManager->displayInfo();
    } else if (type == Finance) {
        financeManager->displayInfo();  
    } else {
        hrManager->displayInfo();
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
        return hrManager->calculateSalary();
    }
}

void EmployeeManagmentSystem::setManager(std::shared_ptr<DeveloperManager> dev_man) {
    developmentManager = dev_man;
}

void EmployeeManagmentSystem::setManager(std::shared_ptr<HrManager> hr_man) {
    hrManager = hr_man;
}

void EmployeeManagmentSystem::setManager(std::shared_ptr<SalesManager> sale_man) {
    salesManager = sale_man;
}

void EmployeeManagmentSystem::setManager(std::shared_ptr<FinanceManager> fin_man) {
    financeManager = fin_man;
}

void EmployeeManagmentSystem::displayTotalSalaires() const {
    std::cout << "\n--- Total Salaries by Department ---" << std::endl;
    if (developmentManager != nullptr) {
        std::cout << "Development: $" << developmentManager->calculateSalary() << std::endl;
    } else {
        std::cout << "Development: Manager not set." << std::endl;
    }
    if (hrManager != nullptr) {
        std::cout << "HR: $" << hrManager->calculateSalary() << std::endl;
    } else {
        std::cout << "HR: Manager not set." << std::endl;
    }
    if (salesManager != nullptr) {
        std::cout << "Sales: $" << salesManager->calculateSalary() << std::endl;
    } else {
        std::cout << "Sales: Manager not set." << std::endl;
    }
    if (financeManager != nullptr) {
        std::cout << "Finance: $" << financeManager->calculateSalary() << std::endl;
    } else {
        std::cout << "Finance: Manager not set." << std::endl;
    }
    
}
