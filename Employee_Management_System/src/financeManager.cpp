#include "../header/financeManager.h"

FinanceManager::FinanceManager(const std::string& name, double baseSalary) : Employee(name, baseSalary, Manager) {} 


void FinanceManager::addAccountant(Accountant* acc) {
    if (acc != nullptr) {
        accountants.push_back(acc);
        accountantsCount++;
    }
}

void FinanceManager::displayInfo() {
    std::cout << "\n--- Finance Department ---" << std::endl;
    for (int i = 0; i < accountants.size(); ++i) {
        accountants[i]->displayInfo();
    }
}

double FinanceManager::calculateSalary() {
    double total = 0;
    if (accountants.empty()) {
        for (size_t i = 0; i < accountants.size(); ++i) {
            double final = accountants[i]->getBaseSalary() + accountants[i]->getfinanceReports() * (10 * (accountants[i]->getBaseSalary() / 100));
            accountants[i]->setFinalSalary(final);
            total += final;
        }  
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