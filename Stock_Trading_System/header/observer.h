#pragma once
#include "stock.h"

class Observer {
public:
    virtual void update(Stock& stock, double price) = 0;
};