#pragma once
#include "employee.h"

class Developer : public Employee {
public:
    explicit Developer(const std::string& name, double baseSalary, size_t projects = 0);
    void addProject();
    size_t getProjects() const;
    void displayInfo() override;
    Developer(const Developer&) = delete;
    Developer(Developer&&) = delete;
    Developer& operator=(const Developer&) = delete;
    Developer& operator=(Developer&&) = delete;
private:
    Developer() = default;
    size_t projects_;
};

