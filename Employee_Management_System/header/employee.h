#pragma once
#include <string>

enum Type {
    Development,
    Sales,
    Finance,
    HumanResources,
    Manager
};

class Employee {
public:
    explicit Employee(const std::string& name, double baseSalary, Type dep);
    Employee(const Employee&) = delete;
    Employee(Employee&&) = delete;
    Employee& operator=(const Employee&) = delete;
    Employee& operator=(Employee&&) = delete;
    ~Employee() = default;

    virtual void displayInfo() = 0;
    void displayTotalSalaires() const;
    double getBaseSalary() const;
    int getId() const;
    const std::string& getName() const;
    double getFinalSalary() const;
    void setFinalSalary(double value);
private:
    std::string name_;
    double baseSalary_;
    Type dep;
    int id_;
    double finalSalary_;
};