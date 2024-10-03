#include "../header/developerManager.h"
#include <iostream>

DeveloperManager::DeveloperManager(const std::string& name, double baseSalary) : Employee(name, baseSalary, Manager) {}

void DeveloperManager::addDeveloper(Developer* developer) {
    developers.push_back(developer);
}

double DeveloperManager::calculateSalary() {
    double total = 0;
    if (developers.empty()) {
        for (size_t i = 0; i < developers.size(); ++i) {
            double final = developers[i]->getBaseSalary() + developers[i]->getProjects() * (10 * (developers[i]->getBaseSalary() / 100));
            developers[i]->setFinalSalary(final);
            total += final;
        }
    }
    return total;
}

void DeveloperManager::displayInfo() {
    std::cout << "\n--- Development Department ---" << std::endl;
    for (size_t i = 0; i < developers.size(); ++i) {
        developers[i]->displayInfo();
    }
}

void DeveloperManager::removeDeveloper(int id) {
    for (size_t i = 0; i < developers.size(); ++i) {
        if (developers[i]->getId() == id ) {
            developers.erase(developers.begin() + i);
        }
    }
    calculateSalary();
}
