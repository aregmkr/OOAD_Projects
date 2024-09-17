#pragma once
#include <string>
#include "transaction.h"
#include "transactionManager.h"
#include <vector>

// enums for transaction types and accaount types its elegeant bro

enum AccountType {
	Checking,
	Saving,
	Joint
};

std::string toString(AccountType type);

class Account {
public:
	//Account();
	Account(int accountNumber, double balance, AccountType accountType);
	Account(const Account&) = delete;
	Account(Account&&) = delete;
	Account& operator=(const Account&) = delete;
	Account& operator=(Account&&) = delete;

	virtual ~Account();

	virtual void deposit(double amount) = 0;
	virtual void withdraw(double amount) = 0;
	virtual void transfer(Account& destination, double amount) = 0;
	virtual void showBalance() const = 0;
	void setBalance(double value) {
		balance_ = value;
	}
	double getBalance() const {
		return balance_;
	}
	int getAccNumber() const {
		return accountNumber_;
	}
	virtual AccountType getAccountType()const  = 0;
	virtual void showTransactionHistory() const = 0;
protected:
	int accountNumber_;
	double balance_;
	AccountType accountType_;
	std::vector<Transaction*> accountTransactions;
};

class CheckingAccount : public Account, public TransactionManager {
public:
	CheckingAccount() = default;
	CheckingAccount(int accNumber, double balance, double overdraftLimit);
	~CheckingAccount() = default;

	void deposit(double amount) override;
	void withdraw(double amount) override;
	void transfer(Account& destination, double amount) override;
	void showBalance() const override;
	void showTransactionHistory() const override;
	void logTransaction(const std::string& type, double amount, Account* toAccount = nullptr) override;
	double getOverdraftLimit() const;
	AccountType getAccountType() const override;
private:
	double overdraftLimit_ = 500;
};

class SavingAccount : public Account, public TransactionManager{
public:
	SavingAccount() = default;
	SavingAccount(int accNumber, double balance, double interestRate);	
	~SavingAccount() = default;

	void deposit(double amount) override;
	void withdraw(double amount) override;
	void transfer(Account& destination, double amount) override;
	void showBalance() const override;
	AccountType getAccountType() const override;
	void  applyInterest();
	void showTransactionHistory() const override;
	void logTransaction(const std::string& type, double amount, Account* toAccount = nullptr) override;
private:
	double interestRate_;
};

class JointAccount : public Account, public TransactionManager {
public:
	JointAccount() = default;
	JointAccount(int accNum, double balance);
	~JointAccount();

	void deposit(double amount) override;
	void withdraw(double amount) override;
	void transfer(Account& destination, double amount) override;
	void addCustomer(const std::string& customerName);
	void showBalance() const override;
	AccountType getAccountType() const override;
	void showTransactionHistory() const override;
	void logTransaction(const std::string& type, double amount, Account* toAccount=nullptr) override;
private:
	std::vector<std::string> jointOwners_;
};
