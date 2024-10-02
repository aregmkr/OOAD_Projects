#include "../header/sales_manager.h"

SalesManager::SalesManager(const std::string& name, double baseSalary) : Employee(name, baseSalary, Manager) {}

void SalesManager::addSales(SalesPerson* salesPerson) {
    if (salesPerson != nullptr) {
        sales_persons.push_back(salesPerson);
        ++sales_person_count;
    }
}

void SalesManager::displayInfo() {
    for (int i = 0; i < sales_persons.size(); ++i) {
        sales_persons[i]->displayInfo();
    }
}

double SalesManager::calculateSalary(){
    double total = 0;
    for (size_t i = 0; i < sales_persons.size(); ++i) {
        double final = sales_persons[i]->getBaseSalary() + sales_persons[i]->getTotalSales() * (10 * (sales_persons[i]->getBaseSalary() / 100));
        sales_persons[i]->setFinalSalary(final);
        total += final;
    }
    return total; 
}

void SalesManager::removeSalesPerson(int id){
    for (size_t i = 0; i < sales_persons.size(); ++i) {
        if (sales_persons[i]->getId() == id ) {
            sales_persons.erase(sales_persons.begin() + i);
        }
    }
}

