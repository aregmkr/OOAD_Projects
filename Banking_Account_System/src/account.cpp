#include <iostream>
#include "account.h"
#include "transaction.h"

std::string toString(AccountType type) {
	switch(type) {
		case AccountType::Checking:
			return "Checking";
		case AccountType::Saving:
			return "Saving";
		case AccountType::Joint:
			return "Joint";
		default:
			return "Error";
	}
}

Account::Account(int accountNumber, double balance, AccountType accountType) : accountNumber_{accountNumber}, balance_{balance}, accountType_{accountType} {}

Account::~Account() {
    for (Transaction* transaction : accountTransactions) {
        delete transaction;
    }
}

CheckingAccount::CheckingAccount(int accNum, double balance, double overdraftLimit) : Account(accNum, balance, AccountType::Checking), overdraftLimit_{overdraftLimit} {}

void CheckingAccount::deposit(double amount) {
	if (amount > 0) {
		logTransaction("Deposit", amount);
		balance_ += amount;
		std::cout << "Deposit: " << amount << "$\n";
	} else {
		std::cout << "Invalid value\n";
	}
}

void CheckingAccount::withdraw(double amount) {

	if (balance_ >= amount) {
		logTransaction("Withdrew", amount);
		balance_ -= amount;
		std::cout << "Withdraw: " << amount << "$" << std::endl;
		return;
	} else if (overdraftLimit_ + balance_ >= amount) {
		balance_ -= amount;
		overdraftLimit_ += balance_;
		balance_ = 0;
		std::cout << "Withdraw: " << amount << "$" << std::endl;
		logTransaction("Withdrew", amount);
	} else {
		std::cout << "Insufficient funds\n";
	}
}

void CheckingAccount::transfer(Account& destination, double amount) {
	if (balance_ >= amount) {
		logTransaction("Transfer", amount, &destination);
		withdraw(amount);
		std::cout << "Transfer: " << amount << "$" << std::endl;
		destination.deposit(amount);
	} else if (overdraftLimit_ + balance_ >= amount){
		overdraftLimit_ -= amount;
		logTransaction("Transfer", amount, &destination);
		} else {
		std::cout << "Insufficient funds\n"; 
	}
}

void CheckingAccount::showBalance() const {
	std::cout << "Account balance: " << balance_ << std::endl;
}

AccountType CheckingAccount::getAccountType () const {
	return accountType_;
}

double CheckingAccount::getOverdraftLimit() const{
	return overdraftLimit_;
}

void CheckingAccount::showTransactionHistory() const {
    for (int i = 0; i < accountTransactions.size(); ++i) {
		accountTransactions[i]->log();
	} 
}

void CheckingAccount::logTransaction(const std::string& type, double amount, Account* toAccount) {
	Transaction* ptr = new Transaction(this, toAccount, amount, type);
	accountTransactions.push_back(ptr);
} 

SavingAccount::SavingAccount(int accNum, double balance, double interestRate) : Account(accNum, balance, AccountType::Saving), interestRate_{interestRate} {}

void SavingAccount::deposit(double amount) {
	if (amount > 0) {
		logTransaction("Deposit", amount);
		balance_ += amount;
		std::cout << "Deposited: " << amount << "$ " << std::endl;
		return ;
	}
	std::cout << "Insuffiscient funds\n";
}

void SavingAccount::withdraw(double amount) {
	if (amount <= balance_) {
		logTransaction("Withdraw", amount);
		balance_ -= amount;
		std::cout << "Withdraw: " << amount << "$ " << std::endl;
		return ;
	}
	std::cout << "Insufficient funds\n";
}

void SavingAccount::transfer(Account& destination, double amount) {
	if (balance_ >= amount) {
		logTransaction("Transfer", amount, &destination);
		std::cout << "Transfer: " << amount << "$" << std::endl;
		destination.deposit(amount);
		balance_ -= amount;
	} else {
		std::cout << "Insufficient funds\n";
	}
}

void SavingAccount::showBalance() const {
	std::cout << "Account balance: " << balance_ << std::endl;
}

AccountType SavingAccount::getAccountType() const {
	return accountType_;
}

void SavingAccount::applyInterest() {
	balance_ += balance_ * interestRate_;
	std::cout << "Interese applied. New balance: " << balance_ << "$" << std::endl;
}

void SavingAccount::showTransactionHistory() const {
    for (const auto& transaction : accountTransactions) {
    	transaction->log();
    }
}

void SavingAccount::logTransaction(const std::string& type, double amount, Account* toAccount) {
	Transaction* ptr = new Transaction(this, toAccount, amount, type);
	accountTransactions.push_back(ptr);
} 

JointAccount::JointAccount(int accNum, double balance) : Account(accNum, balance, AccountType::Joint) {}

JointAccount::~JointAccount() {
	jointOwners_.clear();
}

void JointAccount::addCustomer(const std::string& customerName) {
	jointOwners_.push_back(customerName);
}

void JointAccount::deposit(double amount) {
	if (amount > 0) {
		logTransaction("Depoist", amount);
		std::cout << "Deposited: " << amount << "$" << std::endl;
		balance_ += amount;
	} 
}

void JointAccount::withdraw(double amount) {
	if (balance_ >= amount) {
		logTransaction("Withdraw", amount);
		balance_ -= amount;
		std::cout << "Withdraw: " << amount << "$\n";
	} else {
		std::cout << "Insufficient funds\n";
	}
}

void JointAccount::transfer(Account& destination, double amount) {
	if (balance_ >= amount){
		logTransaction("Transfer", amount, &destination);
		balance_ -= amount;
		destination.deposit(amount);
		std::cout << "Transfer: " << amount << "$\n"; 
	} else {
		std::cout << "Insufficient funds\n";
	}
}

void JointAccount::showBalance() const {
	std::cout << "Account balance: " << balance_  << "$" << std::endl;
}

AccountType JointAccount::getAccountType()  const {
	return accountType_;
}

void JointAccount::showTransactionHistory() const {
    for (const auto& transaction : accountTransactions) {
    	transaction->log();
    }
}

void JointAccount::logTransaction(const std::string& type, double amount, Account* toAccount) {
	Transaction* ptr = new Transaction(this, toAccount, amount, type);
	accountTransactions.push_back(ptr);
} 