#include <iostream>
#include <string>
#include <vector>
#include "../header/account.h"
#include "../header/customer.h"
#include "../header/transaction.h"

Customer::Customer() : name_{" "}, contactInfo_{" "}, accounts_{nullptr} {}

Customer::Customer(const std::string& name, const std::string& contactInfo, std::vector<Account*> accounts) : name_{name}, contactInfo_{contactInfo}, accounts_{accounts} {}

void Customer::addAccount(Account* account) {
	accounts_.push_back(account);
}

void Customer::viewAccounts() const {
	for (int i = 0; i < accounts_.size(); ++i) {
		std::cout << "Account id: " << accounts_[i]->getAccNumber() << std::endl;
		std::cout << "Account balance: " << accounts_[i]->getBalance() << std::endl;
		std::cout << "Account type: " << toString((accounts_[i]->getAccountType())) << std::endl;
		std::cout << std::endl;
	}
}

void Customer::viewTransactionHistory() const {
	for (int i = 0; i < accounts_.size(); ++i) {
		accounts_[i]->showTransactionHistory();
	}
}	

std::string Customer::getName() const {
	return name_;
}

Customer::~Customer() {
	accounts_.clear();
}

