#pragma once

class TransactionManager {
public:
	virtual void logTransaction(const std::string& type, double amount, Account* toAccount = nullptr) = 0;
	virtual void showTransactionHistory() const = 0;
};


