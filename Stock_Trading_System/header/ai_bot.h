#pragma once
#include "observer.h"
#include "stock.h"

class Ai_bot : public Observer {
public:
    void update(Stock& stock, double price) override;
};