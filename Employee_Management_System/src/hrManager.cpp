#include "../header/hrManager.h"
#include <iostream>
#include "../header/hrRepresentive.h"

HrManager::HrManager(const std::string& name, double baseSalary)
    : Employee(name, baseSalary, HumanResources), hrRepresentiveCount(0) {}

void HrManager::addHr(HrRepresentive* hr) {
    if (hr != nullptr) {
        hrs.push_back(hr);
        hrRepresentiveCount++;
    }
}

double HrManager::calculateSalary() {
    double total = 0;
    for (size_t i = 0; i < hrs.size(); ++i) {
        double final = hrs[i]->getBaseSalary() + hrs[i]->getManagedCount() * (10 * (hrs[i]->getBaseSalary() / 100));
        hrs[i]->setFinalSalary(final);
        total += final;
    }
    return total;
}

void HrManager::displayInfo() {
    std::cout << "Name: " << getName() << std::endl;
    std::cout << "Hr id: " << getId() << std::endl;
    std::cout << "Base salary: " << getBaseSalary() << std::endl;
    std::cout << "Representives: " << getRepresentiveCount() << std::endl;
}

int HrManager::getRepresentiveCount() const {
    return hrRepresentiveCount;
}

void HrManager::removeHr(int id) {
    for (size_t i = 0; i < hrs.size(); ++i) {
        if (hrs[i]->getId() == id ) {
            hrs.erase(hrs.begin() + i);
        }
    }
}