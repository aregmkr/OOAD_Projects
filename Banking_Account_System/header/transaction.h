#pragma once
#include <string>
//#include "./account.h"
class Account;

class Transaction {
public:
	Transaction();
	Transaction(Account* fromAccount, Account* toAccount, double amount, const std::string& transactionType);
	~Transaction();
	Transaction(const Transaction&) = delete;
	Transaction(Transaction&&) = delete;
	Transaction& operator=(const Transaction&) = delete;
	Transaction& operator=(Transaction&&) = delete;

	void log();
	double getAmount() const;

private:
	Account* fromAccount_;
	Account* toAccount_;
	double amount_;
	std::string transactionType_;
	//std::chrono::time_point timestamp_;
};