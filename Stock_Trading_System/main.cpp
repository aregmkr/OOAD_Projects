#include <iostream>
#include "stock.h"
#include "stockExchange.h"
#include "broker.h"
#include "ai_bot.h"
#include "mobile_app.h"

int main() {
    Stock s1("Apple", 120);
    Observer* broker = new Broker();
    Observer* ai_bot = new Ai_bot();
    Observer* mobile_app = new Mobile_app();

    StockExchange* stockExchange = new StockExchange();

    stockExchange->addObserver(broker, 'A');
    stockExchange->addObserver(ai_bot, 'B');
    stockExchange->addObserver(mobile_app, 'C');
    stockExchange->notify(s1, 5); 

    delete broker;
    delete ai_bot;
    delete mobile_app;
    delete stockExchange;

    return 0;
}
