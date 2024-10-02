#pragma once
#include <iostream>

class ILogger {
public:
    virtual void log(const std::string& message) const  = 0;
    virtual ~ILogger() = default;
};
