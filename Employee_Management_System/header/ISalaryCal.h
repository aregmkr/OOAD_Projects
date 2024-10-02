#pragma once
#include "employee.h"
#include <memory>
#include <iostream>

class ISalaryCal {
public:
    virtual double calculateSalary() = 0;
    virtual ~ISalaryCal() = default;
};