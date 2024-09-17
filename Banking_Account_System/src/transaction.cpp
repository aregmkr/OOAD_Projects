#include <iostream>
#include "../header/account.h"
#include "../header/transaction.h"

Transaction::Transaction() : fromAccount_{nullptr}, toAccount_{nullptr}, amount_{0}, transactionType_{" "} {}

Transaction::Transaction(Account* fromAccount, Account* toAccount, double amount, const std::string& transactionType) : fromAccount_{fromAccount}, toAccount_{toAccount}, amount_{amount}, transactionType_{transactionType}{}

void Transaction::log() {
    if (fromAccount_) {
        std::cout << "\033[32;1;4mFrom -> \033[0m" << toString(fromAccount_->getAccountType()) << std::endl;
    } else {
        std::cout << "\033[32;1;4mFrom -> \033[0mTerminal" << std::endl;
    }

    if (toAccount_) {
        std::cout << "\033[32;1;4mTo -> \033[0m" << toString(toAccount_->getAccountType()) << std::endl;
    } else {
        std::cout << "\033[32;1;4mTo -> \033[0mTerminal" << std::endl;
    }
    
    std::cout << "\033[32;1;4mAmount -> \033[0m" << getAmount() << std::endl;
    std::cout << "\033[32;1;4mTransaction type -> \033[0m" << transactionType_ << std::endl;
	std::cout << std::endl;
}

double Transaction::getAmount() const {
	return amount_;
}

Transaction::~Transaction() {
	fromAccount_ = nullptr;	
	toAccount_ = nullptr;
}
