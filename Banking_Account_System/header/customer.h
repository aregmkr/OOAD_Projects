#pragma once
#include <string>
#include <vector>
#include "account.h"
#include "transaction.h"
#include "transactionManager.h"

class Customer {
public:
	Customer();
	Customer(const std::string& name, const std::string& contactInfo, std::vector<Account*> accounts);
	~Customer();

	void addAccount(Account* account);
	void viewAccounts() const;
	void viewTransactionHistory() const;
	std::string getName() const;
private:
	std::string name_;
	std::string contactInfo_;
	std::vector<Account*> accounts_;
};
