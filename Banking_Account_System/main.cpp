#include <iostream>
#include "header/account.h"
#include "header/customer.h"
#include "header/transaction.h"
#include "header/transactionManager.h"
#include <vector>

int main() {
    CheckingAccount obj(1, 1000.0, 500.0);
	SavingAccount saving_obj(2, 500.2, 2);
	JointAccount joint_obj(3, 200);
	joint_obj.addCustomer("Lyov");
	joint_obj.deposit(10);
	joint_obj.showTransactionHistory();
	std::vector<Account*> tmp;
	tmp.push_back(&obj);
	tmp.push_back(&saving_obj);
	//obj.deposit(10);
	//obj.withdraw(50);
	obj.transfer(saving_obj, 10);
	//saving_obj.deposit(1);
	saving_obj.showBalance();
	Customer obj2("Jack", "1-2-3-4-5-6-7-8-9", tmp);
	obj2.viewTransactionHistory();
	return 0;
}
