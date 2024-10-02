#pragma once
#include "employee.h"
#include <vector>
#include <string>
#include "hrRepresentive.h"
#include "ISalaryCal.h"

class HrRepresentive;

class HrManager : public Employee, public ISalaryCal {
public:
    explicit HrManager(const std::string& name, double baseSalary);

    double calculateSalary() override;
    void displayInfo() override;
    void addHr(HrRepresentive* hr);
    int getRepresentiveCount() const;
    void removeHr(int id);
private:
    int hrRepresentiveCount;
    std::vector<HrRepresentive*> hrs;
};