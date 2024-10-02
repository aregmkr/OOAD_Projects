#pragma once
#include "ILogger.h"

class ConsoleLogger : public ILogger {
public:
    void log(const std::string& message) const override;  
};