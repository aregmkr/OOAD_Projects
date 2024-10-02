#include "../header/financeManager.h"

FinanceManager::FinanceManager(const std::string& name, double baseSalary) : Employee(name, baseSalary, Manager) {} 


void FinanceManager::addAccountant(Accountant* acc) {
    if (acc != nullptr) {
        accountants.push_back(acc);
        accountantsCount++;
    }
}

void FinanceManager::displayInfo() {
    std::cout << "Name: " << getName() << std::endl;
    std::cout << "Accountant id: " << getId() << std::endl;
    std::cout << "Base salary: " << getBaseSalary() << std::endl;
    std::cout << "Accounts: " << getAccountsCount() << std::endl;
}

double FinanceManager::calculateSalary() {
    double total = 0;
    for (size_t i = 0; i < accountants.size(); ++i) {
        double final = accountants[i]->getBaseSalary() + accountants[i]->getfinanceReports() * (10 * (accountants[i]->getBaseSalary() / 100));
        accountants[i]->setFinalSalary(final);
        total += final;
    }
    return total;
}


void FinanceManager::removeAccountant(int id) {
    for (size_t i = 0; i < accountants.size(); ++i) {
        if (accountants[i]->getId() == id ) {
            accountants.erase(accountants.begin() + i);
        }
    }
}

int FinanceManager::getAccountsCount() const {
    return accountantsCount;
}